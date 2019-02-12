#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glColor3d(1,0,0);

glPushMatrix();
glTranslated(-1.0,1.2,-6);
glScalef(2,2,2);
glutSolidSphere(0.3,50,50);
glPopMatrix();


glPushMatrix();
glTranslated(-2.6,1.5,-6);
glRotatef(45,1.0,0.0,0.0);
glutWireSphere(0.9,50,50);
glPopMatrix();


glPushMatrix();
glTranslated(1.0,1.2,-6);
glutSolidTorus(0.25,0.5,50,50);
glPopMatrix();


glPushMatrix();
glTranslated(2.6,2.0,-6);
glRotatef(45,1.0,0.0,0.0);
glutWireTorus(0.25,0.5,50,50);
glPopMatrix();


glPushMatrix();
glTranslated(-2.6,-1.5,-6);
glRotatef(45,1.0,0.0,0.0);
glutWireCone(1,1.5,50,50);
glPopMatrix();


glPushMatrix();
glTranslated(-1.0,-1.5,-6);
glRotatef(90,1.0,0.0,0.0);
glutSolidCone(1,1.5,50,50);
glPopMatrix();


glPushMatrix();
glTranslated(1.0,-1.5,-6);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(2.6,-1.5,-6);
glutWireCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(2.0,0.0,-6);
glutSolidTeapot(0.6);
glPopMatrix();

glutSwapBuffers();
}

void resize(int w, int h)
{

glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();

glOrtho(-4.0,4.0,-4.0,4.0,-10.0,10.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}



int main(int argc, char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutInitWindowPosition(0.0,0.0);
glutCreateWindow("Tea Pot");
glutReshapeFunc(resize);
glutDisplayFunc(display);
glClearColor(1,1,1,1);
glutMainLoop();
return 0;
}
