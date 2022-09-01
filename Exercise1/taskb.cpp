#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glShadeModel(GL_FLAT);
}

void points() {
  glVertex3f(0.0, 2.0, 0.0);
  glVertex3f(1.5, 1.5, 0.0);
  glVertex3f(2.0, 0.0, 0.0);
  glVertex3f(1.5, -1.5, 0.0);
  glVertex3f(0.0, -2.0, 0.0);
  glVertex3f(-1.5, -1.5, 0.0);
  glVertex3f(-2.0, 0.0, 0.0);
  glVertex3f(-1.5, 1.5, 0.0);
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glLoadIdentity();
  glTranslatef(-10.0, 5.0, -20.0);
  glPointSize(5.0);
  glBegin(GL_POINTS);
  points();
  glEnd();

  glLoadIdentity();
  glTranslatef(-5.0, 5.0, -20.0);
  glBegin(GL_LINES);
  points();
  glEnd();

  glLoadIdentity();
  glTranslatef(0.0, 5.0, -20.0);
  glBegin(GL_LINE_STRIP);
  points();
  glEnd();

  glLoadIdentity();
  glTranslatef(5.0, 5.0, -20.0);
  glBegin(GL_LINE_LOOP);
  points();
  glEnd();

  glLoadIdentity();
  glTranslatef(10.0, 5.0, -20.0);
  glBegin(GL_TRIANGLES);
  points();
  glEnd();

  glLoadIdentity();
  glTranslatef(-10.0, -5.0, -20.0);
  glBegin(GL_TRIANGLE_STRIP);
  points();
  glEnd();

  glLoadIdentity();
  glTranslatef(-5.0, -5.0, -20.0);
  glBegin(GL_TRIANGLE_FAN);
  points();
  glEnd();

  glLoadIdentity();
  glTranslatef(0.0, -5.0, -20.0);
  glBegin(GL_QUADS);
  points();
  glEnd();

  glLoadIdentity();
  glTranslatef(5.0, -5.0, -20.0);
  glBegin(GL_QUAD_STRIP);
  points();
  glEnd();

  glLoadIdentity();
  glTranslatef(10.0, -5.0, -20.0);
  glBegin(GL_POLYGON);
  points();
  glEnd();

  glFlush();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(2000, 1000);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
