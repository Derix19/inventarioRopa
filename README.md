# 🧥 Sistema de Control de Inventario — Tienda de Ropa

**Universidad Católica Boliviana "San Pablo"**
Facultad de Ingeniería — Ingeniería de Sistemas
Asignatura: Programación I (SIS-112) | Gestión 1/2026

---

## 👥 Integrantes

| Nombre completo | Carrera |
|---|---|
| Aglaya Jhoselin Urquieta Velez | Ingeniería de Sistemas |
| Helen Apaza Colque | Ingeniería de Sistemas |

---

## 📋 Dominio de Datos

El sistema gestiona el inventario de una **Tienda de Ropa**. La entidad principal es `Prenda` con los siguientes campos:

| Campo | Tipo C++ | Descripción |
|---|---|---|
| codigo | string | Código único. Ej: P001 |
| nombre | string | Nombre de la prenda. Ej: Camisa Oxford |
| categoria | string | Tipo de prenda. Ej: Camisa, Pantalon |
| talla | string | Talla. Ej: XS, S, M, L, XL |
| color | string | Color de la prenda |
| cantidad | int | Unidades en stock |
| precio | float | Precio en bolivianos (Bs.) |

---

## 📁 Estructura del Proyecto

```
inventarioFinal/
├── include/              → Archivos .h (prototipos y structs)
│   ├── prenda.h
│   ├── crud.h
│   ├── archivos.h
│   ├── ordenacion.h
│   ├── busqueda.h
│   ├── reporte.h
│   └── utilidades.h
├── src/                  → Archivos .cpp (implementación)
│   ├── crud.cpp
│   ├── archivos.cpp
│   ├── ordenacion.cpp
│   ├── busqueda.cpp
│   ├── reporte.cpp
│   └── utilidades.cpp
├── data/                 → Archivos de datos CSV
│   ├── inventario.csv
│   ├── inventario1.csv
│   └── inventario2.csv
└── main.cpp              → Solo llamadas a funciones
```

---

## ⚙️ Compilación

### Con g++ (terminal):
```bash
g++ -o inventario main.cpp src/crud.cpp src/archivos.cpp src/ordenacion.cpp src/busqueda.cpp src/reporte.cpp src/utilidades.cpp
```

### Con Dev-C++ 6.3:
1. Archivo → Nuevo → Proyecto → Console Application (C++)
2. Proyecto → Agregar al Proyecto → seleccionar todos los `.cpp` de `src/` y el `main.cpp`
3. Presionar **F10** para compilar y ejecutar

---

## 🚀 Guía de Uso Rápido

Al ejecutar el programa aparece el menú:

```
1.  Agregar prenda
2.  Listar prendas
3.  Modificar prenda
4.  Eliminar prenda
5.  Ordenar (Bubble Sort)
6.  Busqueda secuencial
7.  Busqueda binaria
8.  Intercalar archivos
9.  Reporte comparativo
10. Generar reporte PDF
0.  Salir
```

- **Primera ejecución:** el sistema carga automáticamente 10 prendas de prueba
- **Opción 5:** ordena el inventario y muestra comparaciones e intercambios
- **Opción 9:** compara eficiencia entre Bubble Sort e Intercalación
- **Opción 10:** genera `data/reporte_inventario.html` → abre en navegador → Ctrl+P → Guardar como PDF
- Los archivos CSV se guardan en la carpeta `data/`

---

## 📌 Notas Técnicas

- Persistencia en archivos CSV separados por comas
- Bubble Sort optimizado con bandera `huboIntercambio`
- Búsqueda binaria recursiva con conteo de llamadas
- Búsqueda secuencial con conteo de comparaciones
- Seeding automático de 10 registros al detectar archivo vacío
