# Conclusiones

## Texturas

1. Las texturas aumentan el detalle visual de una escena sin crear geometría adicional.
2. Las coordenadas UV son esenciales para controlar cómo se proyecta la imagen sobre cada superficie.
3. Los modos `GL_REPEAT`, `GL_LINEAR` y `GL_NEAREST` modifican directamente la apariencia final de los materiales.

## Z-Buffer

1. El Z-Buffer resuelve automáticamente qué fragmentos deben verse y cuáles deben quedar ocultos.
2. `glEnable(GL_DEPTH_TEST)` es indispensable para escenas 3D con objetos superpuestos.
3. La limpieza del búfer de profundidad en cada frame evita artefactos visuales durante la animación.
