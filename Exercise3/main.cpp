#include <GL/glut.h>

static GLfloat spin = 0;

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.5);
  glMatrixMode(GL_PROJECTION);
  glFrustum(-10.0, 10.0, -10.0, 10.0, 0.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

void cube(GLfloat transx, GLfloat transy, GLfloat tranz, GLfloat spinx, GLfloat spiny, GLfloat spinz) {
  glLoadIdentity();
  glRotatef(spin, spinx, spiny, spinz);
  glTranslatef(transx, transy, tranz);
  glutWireCube(0.25);
}

void side(GLfloat cubesize, GLfloat tranz, GLfloat spinx, GLfloat spiny, GLfloat spinz) {
  glPushMatrix();
  cube(0.0, 0.0, tranz, spinx, spiny, spinz);
  cube(-cubesize, 0.0, tranz, spinx, spiny, spinz);
  cube(cubesize, 0.0, tranz, spinx, spiny, spinz);
  cube(0.0, cubesize, tranz, spinx, spiny, spinz);
  cube(-cubesize, cubesize, tranz, spinx, spiny, spinz);
  cube(cubesize, cubesize, tranz, spinx, spiny, spinz);
  cube(0.0, -cubesize, tranz, spinx, spiny, spinz);
  cube(-cubesize, -cubesize, tranz, spinx, spiny, spinz);
  cube(cubesize, -cubesize, tranz, spinx, spiny, spinz);
  glPopMatrix();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 1.0, 0.0);
  side(0.25, 0.0, 0.0, 0.0, 1.0);
  side(0.25, -0.25, 0.0, 1.0, 0.0);
  side(0.25, 0.25, 0.0, 0.0, 0.0);
  glutSwapBuffers();

  glFlush();
}

void spinDisplay() {
  spin = spin + 0.01;
  if (spin > 360)
    spin = 0;
  glutPostRedisplay();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 0.0, 20.0);
  /*  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);*/
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
