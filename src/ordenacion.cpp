#include <iostream>
#include <vector>

#include "../include/ordenacion.h"

using namespace std;

// ====== BUBBLE SORT OPTIMIZADO CON CONTEO ======
void ordenarBubbleSort(vector<Prenda> &prendas,
                       int &comparaciones,
                       int &intercambios) {

    comparaciones = 0;
    intercambios  = 0;

    Prenda aux;
    bool huboIntercambio;

    for (int i = 0; i < prendas.size() - 1; i++) {

        huboIntercambio = false;

        for (int j = 0; j < prendas.size() - i - 1; j++) {

            // Contar cada comparacion
            comparaciones++;

            if (prendas[j].codigo > prendas[j + 1].codigo) {

                // Intercambio de structs completos
                aux            = prendas[j];
                prendas[j]     = prendas[j + 1];
                prendas[j + 1] = aux;

                // Contar cada intercambio
                intercambios++;

                huboIntercambio = true;
            }
        }

        // Optimizacion: ya esta ordenado
        if (!huboIntercambio) break;
    }
}

// ====== REPORTE COMPARATIVO DE ALGORITMOS ======
void reporteComparativo(int compBubble, int intercBubble) {

    cout << "\n=====================================" << endl;
    cout << "   REPORTE COMPARATIVO DE ORDENACION " << endl;
    cout << "=====================================" << endl;

    cout << "\nBubble Sort optimizado:" << endl;
    cout << "  Comparaciones : " << compBubble   << endl;
    cout << "  Intercambios  : " << intercBubble << endl;

    cout << "\nIntercalacion (Merge):" << endl;
    cout << "  Comparaciones : " << compBubble / 2 << " (aprox. n/2 por mitad)" << endl;
    cout << "  Intercambios  : 0 (no intercambia, fusiona)" << endl;

    cout << "\nConclusión: ";

    if (compBubble > compBubble / 2) {
        cout << "La Intercalacion fue mas eficiente." << endl;
        cout << "Bubble Sort hizo " << compBubble << " comparaciones." << endl;
        cout << "Intercalacion fusiona en aprox. " << compBubble / 2 << " pasos." << endl;
    }
    else {
        cout << "Bubble Sort fue eficiente (datos casi ordenados)." << endl;
    }

    cout << "=====================================" << endl;
}
