#include <iostream>
#include <iomanip>
#include <vector>

#include "../include/crud.h"

using namespace std;

// ====== CREAR PRENDA ======
void crearPrenda(vector<Prenda> &prendas) {

    Prenda p;

    cout << "Ingrese codigo: ";
    getline(cin, p.codigo);

    cout << "Ingrese nombre: ";
    getline(cin, p.nombre);

    cout << "Ingrese categoria (Camisa/Pantalon/Vestido/etc): ";
    getline(cin, p.categoria);

    cout << "Ingrese talla (XS/S/M/L/XL): ";
    getline(cin, p.talla);

    cout << "Ingrese color: ";
    getline(cin, p.color);

    string cantStr, precStr;

    cout << "Ingrese cantidad en stock: ";
    getline(cin, cantStr);
    p.cantidad = stoi(cantStr);

    cout << "Ingrese precio (Bs.): ";
    getline(cin, precStr);
    p.precio = stof(precStr);

    prendas.push_back(p);

    cout << COLOR_VERDE << "\nPrenda registrada correctamente." << COLOR_RESET << endl;
}

// ====== LISTAR PRENDAS (TABLA ALINEADA CON COLORES) ======
// Aporte propio: tabla con columnas fijas usando setw() + colores ANSI
void listarPrendas(const vector<Prenda> &prendas) {

    if (prendas.empty()) {
        cout << COLOR_AMARILLO << "\nNo existen prendas registradas." << COLOR_RESET << endl;
        return;
    }

    // Encabezado en azul y negrita
    cout << COLOR_AZUL << COLOR_NEGRITA;
    cout << "\n" << string(95, '=') << endl;
    cout << "  INVENTARIO DE PRENDAS" << endl;
    cout << string(95, '=') << COLOR_RESET << endl;

    // Cabecera de columnas alineada
    cout << COLOR_NEGRITA
         << left  << setw(8)  << "Codigo"
         << left  << setw(20) << "Nombre"
         << left  << setw(12) << "Categoria"
         << left  << setw(7)  << "Talla"
         << left  << setw(14) << "Color"
         << right << setw(9)  << "Cantidad"
         << right << setw(13) << "Precio (Bs.)"
         << COLOR_RESET << endl;

    cout << string(95, '-') << endl;

    // Filas de datos, alternando color segun stock
    for (int i = 0; i < prendas.size(); i++) {

        // Resaltar en rojo si el stock es bajo (aporte propio: alerta visual)
        string colorFila = (prendas[i].cantidad <= 5) ? COLOR_ROJO : COLOR_CYAN;

        cout << colorFila
             << left  << setw(8)  << prendas[i].codigo
             << left  << setw(20) << prendas[i].nombre
             << left  << setw(12) << prendas[i].categoria
             << left  << setw(7)  << prendas[i].talla
             << left  << setw(14) << prendas[i].color
             << right << setw(9)  << prendas[i].cantidad
             << right << setw(13) << fixed << setprecision(2) << prendas[i].precio
             << COLOR_RESET << endl;
    }

    cout << string(95, '=') << endl;
    cout << COLOR_AMARILLO << "Nota: en " << COLOR_ROJO << "rojo" 
         << COLOR_AMARILLO << " se muestran prendas con stock bajo (<= 5 unidades)." 
         << COLOR_RESET << endl;
}

// ====== MODIFICAR PRENDA ======
void modificarPrenda(vector<Prenda> &prendas) {

    string codigoBuscado;

    cout << "Ingrese codigo de la prenda a modificar: ";
    getline(cin, codigoBuscado);

    for (int i = 0; i < prendas.size(); i++) {

        if (prendas[i].codigo == codigoBuscado) {

            cout << COLOR_VERDE << "\nPrenda encontrada.\n" << COLOR_RESET << endl;

            cout << "Nuevo nombre: ";
            getline(cin, prendas[i].nombre);

            cout << "Nueva categoria: ";
            getline(cin, prendas[i].categoria);

            cout << "Nueva talla: ";
            getline(cin, prendas[i].talla);

            cout << "Nuevo color: ";
            getline(cin, prendas[i].color);

            string cantStr, precStr;

            cout << "Nueva cantidad en stock: ";
            getline(cin, cantStr);
            prendas[i].cantidad = stoi(cantStr);

            cout << "Nuevo precio (Bs.): ";
            getline(cin, precStr);
            prendas[i].precio = stof(precStr);

            cout << COLOR_VERDE << "\nPrenda modificada correctamente." << COLOR_RESET << endl;
            return;
        }
    }

    cout << COLOR_ROJO << "\nPrenda no encontrada." << COLOR_RESET << endl;
}

// ====== ELIMINAR PRENDA ======
void eliminarPrenda(vector<Prenda> &prendas) {

    string codigoBuscado;

    cout << "Ingrese codigo de la prenda a eliminar: ";
    getline(cin, codigoBuscado);

    for (int i = 0; i < prendas.size(); i++) {

        if (prendas[i].codigo == codigoBuscado) {

            prendas.erase(prendas.begin() + i);
            cout << COLOR_VERDE << "\nPrenda eliminada correctamente." << COLOR_RESET << endl;
            return;
        }
    }

    cout << COLOR_ROJO << "\nPrenda no encontrada." << COLOR_RESET << endl;
}
