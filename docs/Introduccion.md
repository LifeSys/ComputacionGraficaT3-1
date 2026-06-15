# Introducción

Este proyecto reúne cinco ejercicios de Computación Gráfica y Visual desarrollados en C++ con OpenGL clásico, FreeGLUT y Visual Studio 2022 para Windows x64.

## Texturas en OpenGL

Una textura es una imagen que se aplica sobre una primitiva geométrica. En OpenGL clásico se cargan sus píxeles en memoria de GPU, se activa `GL_TEXTURE_2D`, se enlaza la textura con `glBindTexture` y se asignan coordenadas UV a cada vértice.

## Z-Buffering

El Z-Buffer o búfer de profundidad almacena la distancia de cada fragmento respecto de la cámara. Al activar `glEnable(GL_DEPTH_TEST)`, OpenGL descarta fragmentos ocultos por geometría más cercana.

## Aplicaciones

Las texturas permiten representar materiales como pisos, paredes, madera, metal o imágenes decorativas sin incrementar la geometría. El Z-Buffer permite escenas 3D con oclusión correcta entre cubos, esferas, cilindros y otros objetos.

## Importancia

Ambas técnicas son fundamentales para lograr escenas tridimensionales claras, realistas y ordenadas: las texturas agregan detalle visual y el Z-Buffer garantiza la visibilidad correcta de los objetos.
