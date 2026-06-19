#include <iostream>
#include <vector>

#include "../include/busqueda.h"

using namespace std;

// ====== BUSQUEDA SECUENCIAL CON CONTEO ======
int busquedaSecuencial(const vector<Prenda> &prendas,
                       const string &codigoBuscado,
                       int &comparaciones) {

    comparaciones = 0;

    for (int i = 0; i < prendas.size(); i++) {

        // Contar cada comparacion
        comparaciones++;

        if (prendas[i].codigo == codigoBuscado) {
            return i;
        }
    }

    return -1;
}

// ====== BUSQUEDA BINARIA RECURSIVA CON CONTEO ======
int busquedaBinaria(const vector<Prenda> &prendas,
                    int left,
                    int right,
                    const string &codigoBuscado,
                    int &llamadas) {

    // Contar cada llamada recursiva
    llamadas++;

    if (left <= right) {

        int mid = left + (right - left) / 2;

        if (prendas[mid].codigo == codigoBuscado) {
            return mid;
        }

        if (codigoBuscado < prendas[mid].codigo) {
            return busquedaBinaria(prendas, left, mid - 1, codigoBuscado, llamadas);
        }

        return busquedaBinaria(prendas, mid + 1, right, codigoBuscado, llamadas);
    }

    return -1;
}
