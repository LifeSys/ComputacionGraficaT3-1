#include <GL/freeglut.h>

float angle = 0.0f;

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 3, 9, 0, 0, 0, 0, 1, 0);
    glRotatef(angle, 0, 1, 0);
    glColor3f(0.9f, 0.1f, 0.1f); glPushMatrix(); glTranslatef(-2.2f, 0, 0); glutSolidCube(1.8); glPopMatrix();
    glColor3f(0.1f, 0.7f, 0.2f); glPushMatrix(); glTranslatef(0.0f, 0, -0.6f); glutSolidSphere(1.1, 32, 24); glPopMatrix();
    glColor3f(0.1f, 0.35f, 1.0f); glPushMatrix(); glTranslatef(2.2f, -1.0f, 0.2f); glRotatef(-90, 1, 0, 0); glutSolidCylinder(0.75, 2.1, 32, 12); glPopMatrix();
    glutSwapBuffers();
}
void Reshape(int width, int height) { if (height == 0) height = 1; glViewport(0,0,width,height); glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluPerspective(50.0, static_cast<double>(width)/height, 0.1, 100.0); glMatrixMode(GL_MODELVIEW); }
void Timer(int) { angle += 0.7f; if (angle > 360.0f) angle -= 360.0f; glutPostRedisplay(); glutTimerFunc(16, Timer, 0); }
int main(int argc, char** argv) { glutInit(&argc, argv); glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); glutInitWindowSize(900, 650); glutCreateWindow("z_buffer02 - Cubo, esfera y cilindro"); glClearColor(0.06f,0.07f,0.09f,1); glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LEQUAL); glutDisplayFunc(Display); glutReshapeFunc(Reshape); glutTimerFunc(16, Timer, 0); glutMainLoop(); return 0; }
