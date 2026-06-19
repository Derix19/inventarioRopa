#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include "../include/reporte.h"

using namespace std;

// ====== GENERAR REPORTE PDF ======
// Se genera un archivo HTML con formato de reporte
// que puede abrirse en el navegador e imprimirse como PDF
void generarReportePDF(const vector<Prenda> &prendas,
                       const string &nombreArchivo) {

    if (prendas.empty()) {
        cout << "\nNo hay prendas para generar el reporte." << endl;
        return;
    }

    // Nombre del archivo HTML
    string archivoHTML = nombreArchivo + ".html";

    ofstream archivo(archivoHTML);

    if (!archivo) {
        cout << "Error al crear el reporte." << endl;
        return;
    }

    // Obtener fecha actual
    time_t ahora = time(0);
    string fechaStr = string(ctime(&ahora));
    // Quitar el salto de linea al final
    if (!fechaStr.empty() && fechaStr.back() == '\n')
        fechaStr.pop_back();

    // Escribir HTML con estilo de reporte PDF
    archivo << "<!DOCTYPE html>" << endl;
    archivo << "<html lang='es'>" << endl;
    archivo << "<head>" << endl;
    archivo << "<meta charset='UTF-8'>" << endl;
    archivo << "<title>Reporte de Inventario - Tienda de Ropa</title>" << endl;
    archivo << "<style>" << endl;
    archivo << "  body { font-family: Arial, sans-serif; margin: 40px; color: #333; }" << endl;
    archivo << "  h1 { color: #1F3864; text-align: center; border-bottom: 3px solid #1F3864; }" << endl;
    archivo << "  h3 { color: #555; text-align: center; }" << endl;
    archivo << "  table { width: 100%; border-collapse: collapse; margin-top: 20px; }" << endl;
    archivo << "  th { background-color: #1F3864; color: white; padding: 10px; text-align: left; }" << endl;
    archivo << "  td { padding: 8px 10px; border-bottom: 1px solid #ddd; }" << endl;
    archivo << "  tr:nth-child(even) { background-color: #f2f2f2; }" << endl;
    archivo << "  .footer { margin-top: 30px; text-align: center; font-size: 12px; color: #888; }" << endl;
    archivo << "  @media print { body { margin: 20px; } }" << endl;
    archivo << "</style>" << endl;
    archivo << "</head>" << endl;
    archivo << "<body>" << endl;

    archivo << "<h1>REPORTE DE INVENTARIO</h1>" << endl;
    archivo << "<h3>Tienda de Ropa — Sistema de Control de Inventario</h3>" << endl;
    archivo << "<h3>UCB San Pablo — Programacion I (SIS-112)</h3>" << endl;
    archivo << "<p style='text-align:center'>Generado: " << fechaStr << "</p>" << endl;
    archivo << "<p style='text-align:center'>Total de prendas registradas: <strong>"
            << prendas.size() << "</strong></p>" << endl;

    archivo << "<table>" << endl;
    archivo << "<tr>" << endl;
    archivo << "  <th>#</th>" << endl;
    archivo << "  <th>Codigo</th>" << endl;
    archivo << "  <th>Nombre</th>" << endl;
    archivo << "  <th>Categoria</th>" << endl;
    archivo << "  <th>Talla</th>" << endl;
    archivo << "  <th>Color</th>" << endl;
    archivo << "  <th>Cantidad</th>" << endl;
    archivo << "  <th>Precio (Bs.)</th>" << endl;
    archivo << "</tr>" << endl;

    for (int i = 0; i < prendas.size(); i++) {
        archivo << "<tr>" << endl;
        archivo << "  <td>" << i + 1                << "</td>" << endl;
        archivo << "  <td>" << prendas[i].codigo    << "</td>" << endl;
        archivo << "  <td>" << prendas[i].nombre    << "</td>" << endl;
        archivo << "  <td>" << prendas[i].categoria << "</td>" << endl;
        archivo << "  <td>" << prendas[i].talla     << "</td>" << endl;
        archivo << "  <td>" << prendas[i].color     << "</td>" << endl;
        archivo << "  <td>" << prendas[i].cantidad  << "</td>" << endl;
        archivo << "  <td>" << prendas[i].precio    << "</td>" << endl;
        archivo << "</tr>" << endl;
    }

    archivo << "</table>" << endl;
    archivo << "<div class='footer'>" << endl;
    archivo << "  <p>Aglaya Jhoselin Urquieta Velez — Helen Apaza Colque</p>" << endl;
    archivo << "  <p>Para guardar como PDF: Ctrl+P → Guardar como PDF</p>" << endl;
    archivo << "</div>" << endl;
    archivo << "</body>" << endl;
    archivo << "</html>" << endl;

    archivo.close();

    cout << "\nReporte generado: " << archivoHTML << endl;
    cout << "Abrelo en tu navegador y usa Ctrl+P para guardarlo como PDF." << endl;
}
