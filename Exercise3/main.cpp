#include <GL/glut.h>
#include <vector>

using namespace std;

struct cube_rotate {
  GLfloat angle, x, y, z;
};

static GLfloat spin = 0;
GLfloat cube_size = 0.15;
GLfloat gap = 0.05;
vector<cube_rotate> cube_rotations[3][3][3];

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glShadeModel(GL_FLOAT);
  glEnable(GL_DEPTH_TEST);
}

void draw_cube(GLfloat x, GLfloat y, GLfloat z) {

  glPushMatrix();

  glTranslatef(
      (x - 1) * cube_size * 2 + x * gap,
      (y - 1) * cube_size * 2 + y * gap,
      (z - 1) * cube_size * 2 + z * gap);

  // front
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_QUADS);
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(cube_size, cube_size, cube_size);
  glVertex3f(-cube_size, cube_size, cube_size);
  glVertex3f(-cube_size, -cube_size, cube_size);
  glVertex3f(cube_size, -cube_size, cube_size);
  glEnd();

  // back
  glColor3f(1.0, 0.5, 0.0);
  glBegin(GL_QUADS);
  glNormal3f(0.0, 0.0, -1.0);
  glVertex3f(cube_size, cube_size, -cube_size);
  glVertex3f(cube_size, -cube_size, -cube_size);
  glVertex3f(-cube_size, -cube_size, -cube_size);
  glVertex3f(-cube_size, cube_size, -cube_size);
  glEnd();

  // left
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_QUADS);
  glNormal3f(-1.0, 0.0, 0.0);
  glVertex3f(-cube_size, cube_size, cube_size);
  glVertex3f(-cube_size, cube_size, -cube_size);
  glVertex3f(-cube_size, -cube_size, -cube_size);
  glVertex3f(-cube_size, -cube_size, cube_size);
  glEnd();

  // right
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_QUADS);
  glNormal3f(1.0, 0.0, 0.0);
  glVertex3f(cube_size, cube_size, cube_size);
  glVertex3f(cube_size, -cube_size, cube_size);
  glVertex3f(cube_size, -cube_size, -cube_size);
  glVertex3f(cube_size, cube_size, -cube_size);
  glEnd();

  // top
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_QUADS);
  glNormal3f(0.0, 1.0, 0.0);
  glVertex3f(-cube_size, cube_size, -cube_size);
  glVertex3f(-cube_size, cube_size, cube_size);
  glVertex3f(cube_size, cube_size, cube_size);
  glVertex3f(cube_size, cube_size, -cube_size);
  glEnd();

  // bottom
  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_QUADS);
  glNormal3f(0.0, -1.0, 0.0);
  glVertex3f(-cube_size, -cube_size, -cube_size);
  glVertex3f(cube_size, -cube_size, -cube_size);
  glVertex3f(cube_size, -cube_size, cube_size);
  glVertex3f(-cube_size, -cube_size, cube_size);
  glEnd();

  glPopMatrix();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glRotatef(-50.0, 1, 1, 0);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        draw_cube(i, j, k);
      }
    }
  }
  glutSwapBuffers();
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
  glFrustum(-1, 1, -1, 1, 0.0, 500);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 80.0, 200.0, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(spinDisplay);
  init();
  glutMainLoop();
  return 0;
}
