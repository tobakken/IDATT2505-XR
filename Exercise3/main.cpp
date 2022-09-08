#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;

struct cube_rotate {
  GLfloat angle, x, y, z;
};

static GLfloat spin = 0;
static bool boolSpin = true;
GLfloat cube_size = 0.15;
GLfloat gap = 0.05;
vector<cube_rotate> cube_rotations[3][3][3];
char selected = 'a';

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glShadeModel(GL_FLOAT);
  glEnable(GL_DEPTH_TEST);
}

void draw_cube(int x, int y, int z) {
  vector<cube_rotate> rot = cube_rotations[x][y][z];
  glPushMatrix();

  glTranslatef(
      (x - 1) * cube_size * 2 + (x - 1) * gap,
      (y - 1) * cube_size * 2 + (y - 1) * gap,
      (z - 1) * cube_size * 2 + (z - 1) * gap);

  for (int i = 0; i < rot.size(); ++i) {
    glRotatef(rot[i].angle, rot[i].x, rot[i].y, rot[i].z);
  }

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

void spinDisplay() {
  if (boolSpin)
    spin = spin + 0.02;
  glutPostRedisplay();
}

void draw_rubix() {
  switch (selected) {
  case 'a':
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if (j != 0)
            draw_cube(i, j, k);
        }
      }
    }

    glRotatef(spin, 0.0, 1.0, 0.0);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        draw_cube(i, 0, j);
      }
    }
    glutIdleFunc(spinDisplay);
    if (spin > 90) {
      boolSpin = false;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          cube_rotate rotation;
          rotation.angle = 90.0;
          rotation.y = 1.0;
          cube_rotations[i][0][j].push_back(rotation);
        }
      }
      spin = 0;
    }
    break;
  case 's':
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if (i != 0)
            draw_cube(i, j, k);
        }
      }
    }
    glRotatef(spin, 1.0, 0.0, 0.0);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        draw_cube(0, i, j);
      }
    }
    glutIdleFunc(spinDisplay);
    if (spin > 90) {
      boolSpin = false;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          cube_rotate rotation;
          rotation.angle = spin;
          rotation.x = 1.0;
          cube_rotations[0][i][j].push_back(rotation);
        }
      }
      spin = 0;
    }
    break;
  case 'd':
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          if (k != 0)
            draw_cube(i, j, k);
        }
      }
    }
    glRotatef(spin, 0.0, 0.0, 1.0);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        draw_cube(i, j, 0);
      }
    }
    glutIdleFunc(spinDisplay);
    if (spin > 90) {
      boolSpin = false;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          cube_rotate rotation;
          rotation.angle = spin;
          rotation.x = 1.0;
          cube_rotations[i][j][0].push_back(rotation);
        }
      }
      spin = 0;
    }

    break;
  }
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glRotatef(-20.0, 1, 1, 0);
  draw_rubix();

  glutSwapBuffers();
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1, 1, -1, 1, 0.0, 500);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
void keyboardfunc(unsigned char key, int x, int y) {
  switch (key) {
  case 'a':
    selected = 'a';
    boolSpin = true;
    break;
  case 's':
    selected = 's';
    boolSpin = true;
    break;
  case 'd':
    selected = 'd';
    boolSpin = true;
    break;
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboardfunc);
  init();
  glutMainLoop();
  return 0;
}
