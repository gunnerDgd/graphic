#include <GL/glut.h>
#include <GL/gl.h>

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5,-0.5,0.0);
        glVertex3f(0.5,0.0,0.0);
        glVertex3f(0.0,0.5,0.0);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit              (&argc, argv);
    glutInitDisplayMode   (GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize    (640,480);
    glutCreateWindow("3D Tech- GLUT Tutorial");
    glutDisplayFunc(renderScene);
    glutMainLoop();
}