#ifndef PRENDA_H
#define PRENDA_H

#include <string>

using namespace std;

// ====== STRUCT PRINCIPAL ======
struct Prenda {
    string codigo;
    string nombre;
    string categoria;
    string talla;
    string color;
    int    cantidad;
    float  precio;
};

#endif
