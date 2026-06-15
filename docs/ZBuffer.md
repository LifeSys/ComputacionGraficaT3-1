# Z-Buffer

## Concepto

El Z-Buffer es una memoria auxiliar que almacena la profundidad del fragmento más cercano a la cámara para cada píxel de la ventana.

## Algoritmo

1. Se limpia el búfer de color y el de profundidad con `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)`.
2. Cada fragmento generado por la rasterización calcula un valor de profundidad.
3. OpenGL compara ese valor con el valor ya almacenado.
4. Si el nuevo fragmento está más cerca, se dibuja y actualiza el Z-Buffer.
5. Si está más lejos, se descarta.

## Ventajas

- No requiere ordenar manualmente los objetos por distancia.
- Funciona con geometría compleja e intersecciones parciales.
- Permite combinar cubos, esferas, cilindros y planos con oclusión correcta.

## `glEnable(GL_DEPTH_TEST)`

La llamada `glEnable(GL_DEPTH_TEST)` activa la prueba de profundidad. Sin esta llamada, los objetos se dibujan según el orden de las instrucciones y pueden aparecer visualmente incorrectos.
