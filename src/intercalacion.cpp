#include <iostream>
#include <vector>

#include "../include/intercalacion.h"

using namespace std;

// ====== INTERCALACION DE DOS VECTORES ORDENADOS ======
vector<Prenda> intercalarPrendas(const vector<Prenda> &v1,
                                 const vector<Prenda> &v2) {

    vector<Prenda> resultado;
    int i = 0, j = 0;

    while (i < v1.size() && j < v2.size()) {

        if (v1[i].codigo <= v2[j].codigo) {
            resultado.push_back(v1[i]);
            i++;
        }
        else {
            resultado.push_back(v2[j]);
            j++;
        }
    }

    while (i < v1.size()) { resultado.push_back(v1[i]); i++; }
    while (j < v2.size()) { resultado.push_back(v2[j]); j++; }

    return resultado;
}
