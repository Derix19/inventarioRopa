#include <iostream>
#include "../include/utilidades.h"
#include "../include/colores.h"

using namespace std;

// ====== MENU PRINCIPAL (con colores - aporte propio) ======
void mostrarMenu() {

    cout << COLOR_AZUL << COLOR_NEGRITA;
    cout << "\n=====================================" << endl;
    cout << "   INVENTARIO - TIENDA DE ROPA       " << endl;
    cout << "=====================================" << COLOR_RESET << endl;

    cout << "1.  Agregar prenda"            << endl;
    cout << "2.  Listar prendas"            << endl;
    cout << "3.  Modificar prenda"          << endl;
    cout << "4.  Eliminar prenda"           << endl;
    cout << "5.  Ordenar (Bubble Sort)"     << endl;
    cout << "6.  Busqueda secuencial"       << endl;
    cout << "7.  Busqueda binaria"          << endl;
    cout << "8.  Intercalar archivos"       << endl;
    cout << "9.  Reporte comparativo"       << endl;
    cout << "10. Generar reporte PDF"       << endl;
    cout << COLOR_ROJO << "0.  Salir" << COLOR_RESET << endl;

    cout << COLOR_AZUL << "=====================================" << COLOR_RESET << endl;
    cout << "Seleccione una opcion: ";
}
