#include <GL/glut.h>

static GLfloat spin = 0;

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLOAT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);

  glMatrixMode(GL_MODELVIEW);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -5.0f);
  gluLookAt(2.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glPointSize(5.0);
  glBegin(GL_LINE_LOOP);

  // front
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);

  // back
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, 1.0f, -1.0f);

  // lines between
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);

  glEnd();

  glTranslatef(0.0, 0.0, -5.0);
  glutWireCube(2.0);

  glPushMatrix();
  glRotatef(spin, 0.0, 1.0, 0.0);
  glTranslatef(2.0, 0.0, 0.0);
  glutWireCube(1.0);
  glPopMatrix();

  glutSwapBuffers();

  glFlush();
}

void spinDisplay(void) {
  spin = spin + 0.1;
  if (spin > 360.0)
    spin = spin - 360.0;
  glutPostRedisplay();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(spinDisplay);
  glutMainLoop();
  return 0;
}
