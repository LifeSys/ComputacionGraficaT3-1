#include <GL/freeglut.h>

float angleX = 25.0f;
float angleY = -35.0f;

void DrawFace(float z, float r, float g, float b) {
    glColor3f(r, g, b);
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            const float x0 = -1.5f + col;
            const float y0 = -1.5f + row;
            const float gap = 0.04f;
            glBegin(GL_QUADS);
            glVertex3f(x0 + gap, y0 + gap, z);
            glVertex3f(x0 + 1.0f - gap, y0 + gap, z);
            glVertex3f(x0 + 1.0f - gap, y0 + 1.0f - gap, z);
            glVertex3f(x0 + gap, y0 + 1.0f - gap, z);
            glEnd();
        }
    }
}

void DrawRubikCube() {
    glColor3f(0.02f, 0.02f, 0.02f);
    glutSolidCube(3.08);
    DrawFace(1.56f, 1.0f, 0.0f, 0.0f);
    glPushMatrix(); glRotatef(180, 0, 1, 0); DrawFace(1.56f, 1.0f, 0.5f, 0.0f); glPopMatrix();
    glPushMatrix(); glRotatef(90, 0, 1, 0); DrawFace(1.56f, 0.0f, 0.2f, 1.0f); glPopMatrix();
    glPushMatrix(); glRotatef(-90, 0, 1, 0); DrawFace(1.56f, 0.0f, 0.8f, 0.0f); glPopMatrix();
    glPushMatrix(); glRotatef(90, 1, 0, 0); DrawFace(1.56f, 1.0f, 1.0f, 1.0f); glPopMatrix();
    glPushMatrix(); glRotatef(-90, 1, 0, 0); DrawFace(1.56f, 1.0f, 1.0f, 0.0f); glPopMatrix();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 8, 0, 0, 0, 0, 1, 0);
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);
    DrawRubikCube();
    glutSwapBuffers();
}

void Reshape(int width, int height) {
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluPerspective(45.0, static_cast<double>(width) / height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Timer(int) { angleY += 0.6f; glutPostRedisplay(); glutTimerFunc(16, Timer, 0); }

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("textura02 - Cubo Rubik 3x3");
    glClearColor(0.12f, 0.12f, 0.12f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(Display); glutReshapeFunc(Reshape); glutTimerFunc(16, Timer, 0);
    glutMainLoop();
    return 0;
}
