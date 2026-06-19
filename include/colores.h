#ifndef COLORES_H
#define COLORES_H

// ====== CODIGOS DE COLOR ANSI PARA CONSOLA ======
// Aporte propio: mejora visual en consola con colores
// Funciona en Windows 10/11 (Dev-C++ 6.3 con TDM-GCC) y en Linux

#define COLOR_RESET   "\033[0m"
#define COLOR_VERDE   "\033[32m"   // Exito / confirmaciones
#define COLOR_ROJO    "\033[31m"   // Errores
#define COLOR_AMARILLO "\033[33m"  // Advertencias
#define COLOR_AZUL    "\033[34m"   // Titulos / encabezados
#define COLOR_CYAN    "\033[36m"   // Datos destacados
#define COLOR_NEGRITA "\033[1m"    // Texto en negrita

// Propósito: Habilitar el procesamiento de codigos ANSI en consola de Windows
// Parámetros: ninguno
// Retorno: void
void habilitarColoresConsola();

#endif
