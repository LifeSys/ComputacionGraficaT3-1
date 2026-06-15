# Computación Gráfica T3

Proyecto universitario de Computación Gráfica y Visual con C++, OpenGL clásico, FreeGLUT, Visual Studio 2022 y Windows x64.

## Ejercicios

- `textura01`: cuadrado texturizado con coordenadas UV y carga BMP.
- `textura02`: cubo Rubik con cuadrícula 3x3 y rotación.
- `textura03`: piso texturizado con `GL_REPEAT`.
- `z_buffer01`: demostración de profundidad con planos superpuestos.
- `z_buffer02`: escena con cubo, esfera, cilindro y Z-Buffer.

## Compilación en Visual Studio 2022

1. Instalar vcpkg.
2. Instalar FreeGLUT para x64:

   ```powershell
   vcpkg install freeglut:x64-windows
   vcpkg integrate install
   ```

3. Abrir `ComputacionGraficaT3.sln` en Visual Studio 2022.
4. Seleccionar `Debug | x64` o `Release | x64`.
5. Compilar el proyecto del ejercicio que se desea ejecutar.

Cada proyecto enlaza `freeglut.lib`, `opengl32.lib` y `glu32.lib`, e incluye rutas compatibles con `$(VcpkgRoot)installed\$(VcpkgTriplet)`.

## Texturas BMP

Los ejercicios `textura01` y `textura03` intentan cargar `textura01.bmp` y `piso.bmp`. Si esos archivos no existen, el programa crea una textura procedural tipo tablero, por lo que no falla al ejecutar.

## Documentación

La carpeta `docs/` contiene la introducción, explicación de texturas, explicación de Z-Buffer, conclusiones y guion para video.
