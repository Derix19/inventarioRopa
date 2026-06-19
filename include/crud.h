#ifndef CRUD_H
#define CRUD_H

#include <vector>
#include "prenda.h"
#include "colores.h"

using namespace std;

// ====== PROTOTIPOS CRUD ======

// Propósito: Agregar una nueva prenda al vector
// Parámetros: prendas — vector por referencia
// Retorno: void
void crearPrenda(vector<Prenda> &prendas);

// Propósito: Mostrar todas las prendas en consola
// Parámetros: prendas — vector por referencia const
// Retorno: void
void listarPrendas(const vector<Prenda> &prendas);

// Propósito: Modificar datos de una prenda por codigo
// Parámetros: prendas — vector por referencia
// Retorno: void
void modificarPrenda(vector<Prenda> &prendas);

// Propósito: Eliminar una prenda por codigo
// Parámetros: prendas — vector por referencia
// Retorno: void
void eliminarPrenda(vector<Prenda> &prendas);

#endif
