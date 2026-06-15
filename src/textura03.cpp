#include "BmpTexture.h"
#include <cmath>

GLuint floorTexture = 0;
float cameraAngle = 0.0f;

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(5.0 * sin(cameraAngle), 3.0, 5.0 * cos(cameraAngle), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, floorTexture);
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-5, 0, -5);
    glTexCoord2f(6, 0); glVertex3f( 5, 0, -5);
    glTexCoord2f(6, 6); glVertex3f( 5, 0,  5);
    glTexCoord2f(0, 6); glVertex3f(-5, 0,  5);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void Reshape(int width, int height) {
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluPerspective(60.0, static_cast<double>(width) / height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Timer(int) { cameraAngle += 0.01f; glutPostRedisplay(); glutTimerFunc(16, Timer, 0); }

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 650);
    glutCreateWindow("textura03 - Piso texturizado con GL_REPEAT");
    glClearColor(0.48f, 0.66f, 0.90f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    floorTexture = CreateOpenGlTexture("piso.bmp", true, GL_LINEAR);
    glutDisplayFunc(Display); glutReshapeFunc(Reshape); glutTimerFunc(16, Timer, 0);
    glutMainLoop();
    return 0;
}
