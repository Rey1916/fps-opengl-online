/*
  FPS Scene in C++ with OpenGL (Gitpod Starter)
  --------------------------------------------
  Controls:
    - W/A/S/D : Move camera
    - Mouse   : Look around (not implemented in this minimal version)
*/

#include <GL/glut.h>
#include <cmath>

float cameraX = 0.0f, cameraZ = 5.0f;
float cameraAngle = 0.0f;

void initGL() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(cameraX, 1.0f, cameraZ,
              cameraX + sin(cameraAngle), 1.0f, cameraZ - cos(cameraAngle),
              0.0f, 1.0f, 0.0f);

    // Ground
    glColor3f(0.3f, 0.7f, 0.3f);
    glBegin(GL_QUADS);
        glVertex3f(-50.0f, 0.0f, -50.0f);
        glVertex3f(-50.0f, 0.0f,  50.0f);
        glVertex3f( 50.0f, 0.0f,  50.0f);
        glVertex3f( 50.0f, 0.0f, -50.0f);
    glEnd();

    // Simple obstacle (cube)
    glPushMatrix();
        glTranslatef(0.0f, 1.0f, 0.0f);
        glColor3f(0.8f, 0.2f, 0.2f);
        glutSolidCube(2.0f);
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    float speed = 0.2f;
    switch (key) {
        case 'w': cameraX += sin(cameraAngle) * speed; cameraZ -= cos(cameraAngle) * speed; break;
        case 's': cameraX -= sin(cameraAngle) * speed; cameraZ += cos(cameraAngle) * speed; break;
        case 'a': cameraAngle -= 0.1f; break;
        case 'd': cameraAngle += 0.1f; break;
    }
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / (double)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL FPS Scene - Gitpod Starter");

    initGL();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
