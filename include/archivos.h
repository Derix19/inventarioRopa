#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <string>
#include <fstream>
#include <vector>
#include "prenda.h"

using namespace std;

// Propósito: Leer una prenda desde una línea CSV
// Parámetros: archivo — ifstream por referencia, p — Prenda por referencia
// Retorno: bool (true si leyó correctamente)
bool leerPrendaCSV(ifstream &archivo, Prenda &p);

// Propósito: Cargar todas las prendas del CSV al vector
// Parámetros: nombreArchivo — string, prendas — vector por referencia
// Retorno: void
void cargarPrendas(const string &nombreArchivo, vector<Prenda> &prendas);

// Propósito: Guardar todas las prendas del vector al CSV
// Parámetros: nombreArchivo — string, prendas — vector por referencia const
// Retorno: void
void guardarPrendas(const string &nombreArchivo, const vector<Prenda> &prendas);

// Propósito: Cargar 10 registros iniciales si el archivo está vacío
// Parámetros: nombreArchivo — string, prendas — vector por referencia
// Retorno: void
void seedDatos(const string &nombreArchivo, vector<Prenda> &prendas);

#endif
