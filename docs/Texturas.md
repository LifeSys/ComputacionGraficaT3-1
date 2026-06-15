# Texturas

## Coordenadas UV

Las coordenadas UV indican qué punto de una textura se asigna a cada vértice. Normalmente `u` y `v` van de `0.0` a `1.0`; valores mayores repiten la textura cuando se usa `GL_REPEAT`.

## `glTexImage2D`

`glTexImage2D` copia los píxeles de una imagen hacia una textura 2D de OpenGL. En este proyecto se cargan BMP de 24 bits y, si no existen, se genera una textura procedural de tablero para evitar fallos de ejecución.

## `glBindTexture`

`glBindTexture(GL_TEXTURE_2D, id)` selecciona la textura activa. Todas las primitivas dibujadas después usan esa textura mientras `GL_TEXTURE_2D` permanezca habilitado.

## `GL_REPEAT`

`GL_REPEAT` hace que OpenGL repita la imagen cuando las coordenadas UV superan el rango `[0, 1]`. Se usa en el piso texturizado para cubrir una superficie grande con una imagen pequeña.

## `GL_LINEAR`

`GL_LINEAR` interpola texeles vecinos y produce transiciones suaves. Es útil para pisos y superficies donde la textura puede verse ampliada o reducida.

## `GL_NEAREST`

`GL_NEAREST` toma el texel más cercano sin interpolación. Produce un aspecto pixelado que puede ser útil para estilos retro o para observar claramente los píxeles originales.
