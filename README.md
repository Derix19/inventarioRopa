# 🧥 Sistema de Control de Inventario — Tienda de Ropa

**Universidad Católica Boliviana "San Pablo"**
Facultad de Ingeniería — Ingeniería de Sistemas
Asignatura: Programación I (SIS-112) | Gestión 1/2026

---

## 👥 Integrantes

| Nombre completo | Carrera |
|---|---|
| Apaza Colque Helen | Ingeniería Industrial |
| Aglaya Urquieta Velez | Ingeniería Industrial |

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
inventarioRopa/
├── include/              → Archivos .h (prototipos y structs)
│   ├── prenda.h
│   ├── crud.h
│   ├── archivos.h
│   ├── ordenacion.h
│   ├── busqueda.h
│   ├── intercalacion.h
│   ├── reporte.h
│   ├── colores.h
│   └── utilidades.h
├── src/                  → Archivos .cpp (implementación)
│   ├── crud.cpp
│   ├── archivos.cpp
│   ├── ordenacion.cpp
│   ├── busqueda.cpp
│   ├── intercalacion.cpp
│   ├── reporte.cpp
│   ├── colores.cpp
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
g++ -o inventario main.cpp src/crud.cpp src/archivos.cpp src/ordenacion.cpp src/busqueda.cpp src/intercalacion.cpp src/reporte.cpp src/utilidades.cpp src/colores.cpp
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

- **Primera ejecución:** el sistema carga automáticamente 10 prendas de prueba (seeding)
- **Opción 5:** ordena el inventario y muestra comparaciones e intercambios reales
- **Opción 7:** búsqueda binaria recursiva, muestra cantidad de llamadas
- **Opción 8:** fusiona `inventario1.csv` e `inventario2.csv` en `resultado.csv`, contando comparaciones reales
- **Opción 9:** compara eficiencia entre Bubble Sort e Intercalación con datos reales (no estimados)
- **Opción 10:** genera `data/reporte_inventario.html` → abre en navegador → Ctrl+P → Guardar como PDF
- Los archivos CSV se guardan en la carpeta `data/`

---

## 🎨 Aporte Propio: Mejora Visual en Consola

Se incorporó un módulo independiente `colores.h` / `colores.cpp` que mejora la experiencia del usuario:

- Códigos de color ANSI (verde = éxito, rojo = error/alerta, amarillo = advertencia, azul = títulos)
- `listarPrendas()` ahora muestra una **tabla alineada** con columnas fijas usando `setw()`
- Las prendas con **5 unidades o menos en stock** se resaltan automáticamente **en rojo** como alerta visual
- `habilitarColoresConsola()` activa el soporte de colores ANSI en Windows (vía `windows.h`); en Linux funciona sin configuración adicional

---

## 📌 Notas Técnicas

- Persistencia en archivos CSV separados por comas
- Bubble Sort optimizado con bandera `huboIntercambio`, cuenta comparaciones e intercambios reales
- Intercalación (Merge) con conteo real de comparaciones (no estimado)
- Búsqueda binaria recursiva con conteo de llamadas
- Búsqueda secuencial con conteo de comparaciones
- Seeding automático de 10 registros al detectar archivo vacío
- Reporte comparativo de eficiencia entre Bubble Sort e Intercalación con datos reales
- Generación de reporte exportable a PDF (vía HTML + impresión del navegador)
