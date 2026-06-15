#include <GL/freeglut.h>

float angle = 0.0f;

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 7, 0, 0, 0, 0, 1, 0);
    glRotatef(angle, 0, 1, 0);
    glColor3f(1, 0, 0); glBegin(GL_QUADS); glVertex3f(-1.8f,-1.0f, 0.4f); glVertex3f(0.8f,-1.0f,0.4f); glVertex3f(0.8f,1.0f,0.4f); glVertex3f(-1.8f,1.0f,0.4f); glEnd();
    glColor3f(0, 0.4f, 1); glBegin(GL_QUADS); glVertex3f(-0.8f,-1.2f,-0.4f); glVertex3f(1.8f,-1.2f,-0.4f); glVertex3f(1.8f,1.2f,-0.4f); glVertex3f(-0.8f,1.2f,-0.4f); glEnd();
    glutSwapBuffers();
}
void Reshape(int width, int height) { if (height == 0) height = 1; glViewport(0,0,width,height); glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluPerspective(45.0, static_cast<double>(width)/height, 0.1, 100.0); glMatrixMode(GL_MODELVIEW); }
void Timer(int) { angle += 0.5f; glutPostRedisplay(); glutTimerFunc(16, Timer, 0); }
int main(int argc, char** argv) { glutInit(&argc, argv); glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); glutInitWindowSize(800, 600); glutCreateWindow("z_buffer01 - Prueba de profundidad"); glClearColor(0.08f,0.08f,0.10f,1); glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LESS); glutDisplayFunc(Display); glutReshapeFunc(Reshape); glutTimerFunc(16, Timer, 0); glutMainLoop(); return 0; }
