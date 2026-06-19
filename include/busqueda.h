#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include <string>
#include "prenda.h"

using namespace std;

// Propósito: Búsqueda secuencial recorriendo el vector uno por uno
// Parámetros: prendas — vector const por referencia,
//             codigoBuscado — string const por referencia,
//             comparaciones — int por referencia (retorno múltiple)
// Retorno: int (índice encontrado o -1)
int busquedaSecuencial(const vector<Prenda> &prendas,
                       const string &codigoBuscado,
                       int &comparaciones);

// Propósito: Búsqueda binaria recursiva sobre vector ordenado
// Parámetros: prendas — vector const por referencia,
//             left, right — límites int,
//             codigoBuscado — string const por referencia,
//             llamadas — int por referencia (retorno múltiple)
// Retorno: int (índice encontrado o -1)
int busquedaBinaria(const vector<Prenda> &prendas,
                    int left,
                    int right,
                    const string &codigoBuscado,
                    int &llamadas);

#endif
