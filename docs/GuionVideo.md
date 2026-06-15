# Guion para video de 10 minutos

## 0:00 - 1:00 | Presentación

Presentar el objetivo del trabajo: demostrar texturas y Z-Buffer con C++, OpenGL clásico, FreeGLUT, Visual Studio 2022 y vcpkg en Windows x64.

## 1:00 - 2:00 | Base técnica

Explicar la estructura del proyecto, el uso de `#include <GL/freeglut.h>`, la creación de ventanas con FreeGLUT y el enlace con `freeglut.lib`, `opengl32.lib` y `glu32.lib`.

## 2:00 - 3:20 | textura01.cpp

Mostrar el cuadrado texturizado. Explicar la carga BMP, el respaldo procedural si no existe el archivo, las coordenadas UV entre `0` y `1`, `glGenTextures`, `glBindTexture` y `glTexImage2D`.

## 3:20 - 4:40 | textura02.cpp

Mostrar el cubo Rubik. Explicar la cuadrícula 3x3 por cara, los colores, el cubo base oscuro, la rotación animada y la prueba de profundidad.

## 4:40 - 6:00 | textura03.cpp

Mostrar el piso texturizado. Explicar `GL_REPEAT`, UV mayores que `1`, filtrado `GL_LINEAR` y cómo una imagen pequeña puede cubrir una superficie grande.

## 6:00 - 7:20 | z_buffer01.cpp

Mostrar dos planos superpuestos. Explicar que el Z-Buffer determina cuál está delante aunque la escena rote y aunque el orden de dibujo no sea suficiente.

## 7:20 - 8:50 | z_buffer02.cpp

Mostrar cubo, esfera y cilindro. Explicar `glEnable(GL_DEPTH_TEST)`, `glDepthFunc`, `gluPerspective`, `gluLookAt` y la oclusión correcta entre sólidos.

## 8:50 - 10:00 | Cierre

Concluir que las texturas aportan detalle visual y el Z-Buffer aporta coherencia espacial. Indicar que el proyecto queda listo para compilar en Debug x64 y Release x64 con FreeGLUT instalado mediante vcpkg.
