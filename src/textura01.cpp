#include "BmpTexture.h"

GLuint textureId = 0;
float angle = 0.0f;

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.5f, -1.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.5f, -1.5f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.5f,  1.5f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5f,  1.5f, 0.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void Reshape(int width, int height) {
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, static_cast<double>(width) / height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Timer(int) {
    angle += 0.4f;
    if (angle > 360.0f) angle -= 360.0f;
    glutPostRedisplay();
    glutTimerFunc(16, Timer, 0);
}

void Init() {
    glClearColor(0.10f, 0.12f, 0.16f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    textureId = CreateOpenGlTexture("textura01.bmp", false, GL_LINEAR);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("textura01 - Cuadrado texturizado");
    Init();
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutTimerFunc(16, Timer, 0);
    glutMainLoop();
    return 0;
}
