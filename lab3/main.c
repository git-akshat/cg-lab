#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3d(0.3,0.5,0.3);

    glPushMatrix();
    glTranslated(-1.0,1.2,-6);
    glScalef(2,2,2);
    glutSolidSphere(0.3,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.6,1.5,-6);
    glRotatef(45,1.0,0.0,0.0);
   // glScalef(2,2,2);
    glutWireSphere(0.3,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.0,1.2,-6);
    //glScalef(2,2,2);
    glutSolidTorus(0.25,0.5,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.6,-1.5,-6);
    glRotatef(45,1.0,0.0,0.0);
   // glScalef(2,2,2);
    glutWireTorus(0.25,0.5,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.6,1.5,-6);
    glRotatef(45,1.0,0.0,0.0);
   // glScalef(2,2,2);
    glutWireCone(0.5,1.5,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.0,-1.5,-6);
    glRotatef(90,1.0,0.0,0.0);
   // glScalef(2,2,2);
    glutSolidCone(0.7,1.5,50,50);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.0,0.0,-6);
    //glScalef(2,2,2);
    glutSolidTeapot(0.6);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.6,-1.5,-6);
    //glScalef(2,2,2);
    glutWireCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.0,-1.5,-6);
    //glScalef(2,2,2);
    glutSolidCube(1);
    glPopMatrix();

    glutSwapBuffers();
}
void resize(int w,int h)
{

    const float ar=(float)w/(float)h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar,ar,-1.0,1.0,2.0,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(700,600);
    glutInitWindowPosition(0.0,0.0);
    glutCreateWindow("lab3");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glClearColor(1,1,1,1);
    glutMainLoop();
    return 0;
}
