#ifndef INTERCALACION_H
#define INTERCALACION_H

#include <vector>
#include "prenda.h"

using namespace std;

// Propósito: Intercalar dos vectores ordenados en uno solo
// Parámetros: v1, v2 — vectores const por referencia
// Retorno: vector<Prenda> resultado ordenado
vector<Prenda> intercalarPrendas(const vector<Prenda> &v1,
                                 const vector<Prenda> &v2);

#endif
