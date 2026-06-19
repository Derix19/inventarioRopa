#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "../include/archivos.h"

using namespace std;

// ====== LEER UNA LINEA DEL CSV ======
bool leerPrendaCSV(ifstream &archivo, Prenda &p) {

    string linea;

    if (!getline(archivo, linea)) return false;

    if (linea.empty()) return false;

    stringstream ss(linea);
    string cantStr, precStr;

    getline(ss, p.codigo,    ',');
    getline(ss, p.nombre,    ',');
    getline(ss, p.categoria, ',');
    getline(ss, p.talla,     ',');
    getline(ss, p.color,     ',');
    getline(ss, cantStr,     ',');
    getline(ss, precStr,     ',');

    p.cantidad = stoi(cantStr);
    p.precio   = stof(precStr);

    return true;
}

// ====== CARGAR PRENDAS DESDE CSV ======
void cargarPrendas(const string &nombreArchivo, vector<Prenda> &prendas) {

    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cout << "Archivo no encontrado. Iniciando inventario vacio." << endl;
        return;
    }

    Prenda temp;

    while (leerPrendaCSV(archivo, temp)) {
        prendas.push_back(temp);
    }

    archivo.close();
}

// ====== GUARDAR PRENDAS EN CSV ======
void guardarPrendas(const string &nombreArchivo, const vector<Prenda> &prendas) {

    ofstream archivo(nombreArchivo);

    if (!archivo) {
        cout << "Error al crear archivo." << endl;
        return;
    }

    for (int i = 0; i < prendas.size(); i++) {
        archivo << prendas[i].codigo    << ","
                << prendas[i].nombre    << ","
                << prendas[i].categoria << ","
                << prendas[i].talla     << ","
                << prendas[i].color     << ","
                << prendas[i].cantidad  << ","
                << prendas[i].precio
                << endl;
    }

    archivo.close();
}

// ====== SEEDING: CARGA AUTOMATICA DE 10 REGISTROS ======
void seedDatos(const string &nombreArchivo, vector<Prenda> &prendas) {

    // Verificar si el archivo ya tiene datos
    ifstream verificar(nombreArchivo);
    bool estaVacio = true;

    if (verificar) {
        string linea;
        if (getline(verificar, linea) && !linea.empty()) {
            estaVacio = false;
        }
    }
    verificar.close();

    // Si ya tiene datos, no hacer nada
    if (!estaVacio) return;

    cout << "\nArchivo vacio detectado. Cargando datos iniciales..." << endl;

    // 10 registros de prueba
    Prenda iniciales[] = {
        {"P001", "Camisa Oxford",       "Camisa",   "M",  "Blanco",      15, 120.50},
        {"P002", "Jeans Slim Fit",      "Pantalon", "32", "Azul Oscuro",  8, 250.00},
        {"P003", "Vestido Floral",      "Vestido",  "S",  "Rosado",       5, 180.75},
        {"P004", "Chompa Polar",        "Chompa",   "L",  "Gris",        12, 310.00},
        {"P005", "Blusa Manga Larga",   "Blusa",    "M",  "Verde",       20,  95.00},
        {"P006", "Falda Midi",          "Falda",    "S",  "Negro",        7, 160.00},
        {"P007", "Pantalon Cargo",      "Pantalon", "34", "Caqui",       10, 220.00},
        {"P008", "Polo Basico",         "Polo",     "XL", "Blanco",      30,  75.50},
        {"P009", "Chaqueta Denim",      "Chaqueta", "M",  "Azul Claro",   6, 340.00},
        {"P010", "Shorts Deportivos",   "Short",    "L",  "Negro",       18,  85.00}
    };

    for (int i = 0; i < 10; i++) {
        prendas.push_back(iniciales[i]);
    }

    guardarPrendas(nombreArchivo, prendas);

    cout << "10 registros iniciales cargados correctamente." << endl;
}
