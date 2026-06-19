====================================================
  SISTEMA DE CONTROL DE INVENTARIO - TIENDA DE ROPA
====================================================

ASIGNATURA : Programacion I (SIS-112)
GESTION    : 1/2026
PARALELO   : 3
DOCENTE    : Pamela Shirley Valenzuela Fernandez
CARRERA    : Ingenieria de Sistemas

INTEGRANTES:
  - Integrante 1: ________________________________
  - Integrante 2: ________________________________

----------------------------------------------------
DESCRIPCION DEL PROYECTO
----------------------------------------------------
Sistema de gestion de inventario para una tienda de
ropa. Permite registrar prendas con sus atributos
(codigo, nombre, categoria, talla, color, cantidad
y precio) y realizar operaciones CRUD completas con
persistencia en archivos CSV.

----------------------------------------------------
ESTRUCTURA DEL PROYECTO
----------------------------------------------------
  prenda.h           -> Definicion del struct Prenda
  main.cpp           -> Programa principal y menu
  crud.h / crud.cpp  -> Crear, listar, modificar, eliminar
  archivos.h / .cpp  -> Lectura y escritura de CSV
  ordenacion.h / .cpp-> Bubble Sort optimizado por codigo
  busqueda.h / .cpp  -> Busqueda secuencial y binaria
  intercalacion.h/.cpp-> Intercalacion de dos inventarios
  utilidades.h / .cpp-> Menu principal
  inventario.csv     -> Archivo de datos principal (10 registros)
  inventario1.csv    -> Archivo auxiliar para intercalacion
  inventario2.csv    -> Archivo auxiliar para intercalacion

----------------------------------------------------
INSTRUCCIONES DE COMPILACION
----------------------------------------------------
Con g++ (Linux/Mac o terminal en Windows):

  g++ -o inventario main.cpp crud.cpp archivos.cpp
      ordenacion.cpp busqueda.cpp intercalacion.cpp
      utilidades.cpp

Con Dev-C++ (Windows):
  1. Abrir Dev-C++ 6.3 o superior
  2. Archivo -> Nuevo -> Proyecto -> Console Application (C++)
  3. Proyecto -> Agregar al Proyecto -> seleccionar todos los .cpp
  4. Presionar F10 para compilar y ejecutar

----------------------------------------------------
INSTRUCCIONES DE EJECUCION
----------------------------------------------------
Al ejecutar el programa aparece un menu con 8 opciones:

  1. Agregar prenda        -> Ingresa una nueva prenda al inventario
  2. Listar prendas        -> Muestra todas las prendas registradas
  3. Modificar prenda      -> Edita los datos de una prenda por codigo
  4. Eliminar prenda       -> Elimina una prenda por codigo
  5. Ordenar prendas       -> Ordena el inventario por codigo (Bubble Sort)
  6. Busqueda secuencial   -> Busca una prenda recorriendo todo el vector
  7. Busqueda binaria      -> Busca una prenda eficientemente (requiere orden)
  8. Intercalar archivos   -> Fusiona inventario1.csv e inventario2.csv
  0. Salir

NOTA: Los archivos CSV deben estar en la misma carpeta
      que el ejecutable generado.

====================================================
