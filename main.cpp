#include <iostream>
#include <vector>
#include <string>

#include "include/prenda.h"
#include "include/crud.h"
#include "include/archivos.h"
#include "include/ordenacion.h"
#include "include/busqueda.h"
#include "include/intercalacion.h"
#include "include/reporte.h"
#include "include/utilidades.h"
#include "include/colores.h"

using namespace std;

int main() {

    // Aporte propio: habilitar colores ANSI en consola (Windows/Linux)
    habilitarColoresConsola();

    vector<Prenda> prendas;

    // Ruta del archivo de datos
    string archivo = "data/inventario.csv";

    // Seeding: cargar datos iniciales si el archivo esta vacio
    seedDatos(archivo, prendas);

    // Cargar prendas desde archivo
    if (prendas.empty()) {
        cargarPrendas(archivo, prendas);
    }

    int opcion;

    do {

        mostrarMenu();

        cin >> opcion;
        cin.ignore();

        switch(opcion) {

        // ==========================
        // AGREGAR PRENDA
        // ==========================
        case 1:
            crearPrenda(prendas);
            guardarPrendas(archivo, prendas);
            break;

        // ==========================
        // LISTAR PRENDAS
        // ==========================
        case 2:
            listarPrendas(prendas);
            break;

        // ==========================
        // MODIFICAR PRENDA
        // ==========================
        case 3:
            modificarPrenda(prendas);
            guardarPrendas(archivo, prendas);
            break;

        // ==========================
        // ELIMINAR PRENDA
        // ==========================
        case 4:
            eliminarPrenda(prendas);
            guardarPrendas(archivo, prendas);
            break;

        // ==========================
        // ORDENAR BUBBLE SORT
        // ==========================
        case 5: {
            int comparaciones = 0, intercambios = 0;
            ordenarBubbleSort(prendas, comparaciones, intercambios);
            guardarPrendas(archivo, prendas);
            cout << "\nPrendas ordenadas correctamente." << endl;
            cout << "Comparaciones: " << comparaciones << endl;
            cout << "Intercambios : " << intercambios  << endl;
            break;
        }

        // ==========================
        // BUSQUEDA SECUENCIAL
        // ==========================
        case 6: {
            if (prendas.empty()) {
                cout << "\nNo existen prendas registradas.\n";
                break;
            }

            string codigoBuscado;
            int comparaciones = 0;

            cout << "\nIngrese codigo a buscar (secuencial): ";
            getline(cin, codigoBuscado);

            int posicion = busquedaSecuencial(prendas, codigoBuscado, comparaciones);

            cout << "Comparaciones realizadas: " << comparaciones << endl;

            if (posicion != -1) {
                cout << "\n===== PRENDA ENCONTRADA =====\n";
                cout << "Codigo    : " << prendas[posicion].codigo    << endl;
                cout << "Nombre    : " << prendas[posicion].nombre    << endl;
                cout << "Categoria : " << prendas[posicion].categoria << endl;
                cout << "Talla     : " << prendas[posicion].talla     << endl;
                cout << "Color     : " << prendas[posicion].color     << endl;
                cout << "Cantidad  : " << prendas[posicion].cantidad  << endl;
                cout << "Precio    : Bs. " << prendas[posicion].precio << endl;
            }
            else {
                cout << "\nPrenda no encontrada.\n";
            }
            break;
        }

        // ==========================
        // BUSQUEDA BINARIA
        // ==========================
        case 7: {
            if (prendas.empty()) {
                cout << "\nNo existen prendas registradas.\n";
                break;
            }

            // Requiere orden previo
            int compOrd = 0, intOrd = 0;
            ordenarBubbleSort(prendas, compOrd, intOrd);

            string codigoBuscado;
            int llamadas = 0;

            cout << "\nIngrese codigo a buscar (binaria): ";
            getline(cin, codigoBuscado);

            int posicion = busquedaBinaria(prendas, 0, prendas.size() - 1,
                                           codigoBuscado, llamadas);

            cout << "Llamadas recursivas: " << llamadas << endl;

            if (posicion != -1) {
                cout << "\n===== PRENDA ENCONTRADA =====\n";
                cout << "Codigo    : " << prendas[posicion].codigo    << endl;
                cout << "Nombre    : " << prendas[posicion].nombre    << endl;
                cout << "Categoria : " << prendas[posicion].categoria << endl;
                cout << "Talla     : " << prendas[posicion].talla     << endl;
                cout << "Color     : " << prendas[posicion].color     << endl;
                cout << "Cantidad  : " << prendas[posicion].cantidad  << endl;
                cout << "Precio    : Bs. " << prendas[posicion].precio << endl;
            }
            else {
                cout << "\nPrenda no encontrada.\n";
            }
            break;
        }

        // ==========================
        // INTERCALACION
        // ==========================
        case 8: {
            vector<Prenda> prendas1, prendas2;

            cargarPrendas("data/inventario1.csv", prendas1);
            cargarPrendas("data/inventario2.csv", prendas2);

            int c1 = 0, i1 = 0, c2 = 0, i2 = 0;
            ordenarBubbleSort(prendas1, c1, i1);
            ordenarBubbleSort(prendas2, c2, i2);

            vector<Prenda> resultado = intercalarPrendas(prendas1, prendas2);

            guardarPrendas("data/resultado.csv", resultado);

            cout << "\nIntercalacion realizada correctamente." << endl;
            cout << "Archivo generado: data/resultado.csv"    << endl;
            cout << "Total prendas fusionadas: " << resultado.size() << endl;
            break;
        }

        // ==========================
        // REPORTE COMPARATIVO
        // ==========================
        case 9: {
            if (prendas.empty()) {
                cout << "\nNo existen prendas registradas.\n";
                break;
            }

            vector<Prenda> copia = prendas;
            int comparaciones = 0, intercambios = 0;
            ordenarBubbleSort(copia, comparaciones, intercambios);
            reporteComparativo(comparaciones, intercambios);
            break;
        }

        // ==========================
        // GENERAR REPORTE PDF
        // ==========================
        case 10:
            generarReportePDF(prendas, "data/reporte_inventario");
            break;

        // ==========================
        // SALIR
        // ==========================
        case 0:
            guardarPrendas(archivo, prendas);
            cout << "\nSaliendo del sistema...\n";
            break;

        default:
            cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}
