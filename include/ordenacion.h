#ifndef ORDENACION_H
#define ORDENACION_H

#include <vector>
#include "prenda.h"

using namespace std;

// Propósito: Ordenar por codigo usando Bubble Sort optimizado
//            contando comparaciones e intercambios
// Parámetros: prendas — vector por referencia,
//             comparaciones — int por referencia (retorno múltiple),
//             intercambios  — int por referencia (retorno múltiple)
// Retorno: void
void ordenarBubbleSort(vector<Prenda> &prendas,
                       int &comparaciones,
                       int &intercambios);

// Propósito: Mostrar reporte comparativo de ambos algoritmos
// Parámetros: compBubble, intercBubble — resultados del Bubble Sort
// Retorno: void
void reporteComparativo(int compBubble, int intercBubble);

#endif
