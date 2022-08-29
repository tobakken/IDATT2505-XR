#include <GL/glut.h>

void init(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen and the depth buffer
  glLoadIdentity();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0f, 0.0f, 0.0f); // Set the color to red
  glTranslatef(-1.5f, 0.0f, -1.0f);
  glBegin(GL_TRIANGLES);          // Start drawing using the polygon primitive GL_TRIANGLES
  glVertex3f(0.0f, 1.0f, 0.0f);   // Top
  glVertex3f(-1.0f, -1.0f, 0.0f); // Bottom left
  glVertex3f(1.0f, -1.0f, 0.0f);  // Bottom right
  glEnd();
  glFlush();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glLoadIdentity();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 300);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
