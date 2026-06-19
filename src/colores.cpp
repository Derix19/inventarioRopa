#include "../include/colores.h"

#ifdef _WIN32
#include <windows.h>
#endif

// ====== HABILITAR COLORES ANSI EN CONSOLA WINDOWS ======
void habilitarColoresConsola() {

#ifdef _WIN32
    // En Windows 10/11 hay que activar el modo de procesamiento
    // de secuencias de escape ANSI en la consola
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD modo = 0;

    GetConsoleMode(hOut, &modo);
    SetConsoleMode(hOut, modo | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
    // En Linux/Mac no se necesita nada adicional
}
