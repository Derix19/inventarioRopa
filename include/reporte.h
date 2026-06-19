#ifndef REPORTE_H
#define REPORTE_H

#include <vector>
#include <string>
#include "prenda.h"

using namespace std;

// Propósito: Generar un reporte en formato PDF con el listado del inventario
// Parámetros: prendas — vector const por referencia,
//             nombreArchivo — nombre del PDF a generar
// Retorno: void
void generarReportePDF(const vector<Prenda> &prendas,
                       const string &nombreArchivo);

#endif
