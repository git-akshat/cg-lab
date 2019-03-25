#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

// house wall
glPushMatrix();
glColor3d(2,2,2);
glTranslated(2,-2,2);
glutSolidCube(1.8);
glPopMatrix();

// house roof
glPushMatrix();
glColor3f(1.0,0.5,0.5);
glTranslated(2,-1.3,2);
glRotatef(270,1.0,0.0,0.0);
glutSolidCone(1.3,1.1,50,50);
glPopMatrix();

// house left window
glPushMatrix();
glColor3f(1.0,0.5,0.5);
glTranslated(2.5,-1.8,1);
glutSolidCube(0.45);
glPopMatrix();

//house right window
glPushMatrix();
glColor3f(1.0,0.5,0.5);
glTranslated(1.5,-1.8,1);
glutSolidCube(0.45);
glPopMatrix();

//house door
glPushMatrix();
glColor3f(1.0,0.5,0.5);
glTranslated(2,-2.5,1);
glScaled(0.45,0.8,1);
glutSolidCube(1);
glPopMatrix();

//sun
glPushMatrix();
glColor3f(0.9,0.8,0);
glTranslated(3.0,3.0,-8);
glScalef(2,2,2);
glutSolidSphere(0.3,50,50);
glPopMatrix();

// tree
glPushMatrix();
glColor3f(1,0.5,0);
glTranslated(-3,-2.7, 0);
glRotatef(90,1.0,0.0,0.0);
glutSolidTorus(0.1,0.25,25,25);
glPopMatrix();

glPushMatrix();
glColor3f(1,0.5,0);
glTranslated(-3,-2.5, 0);
glRotatef(90,1.0,0.0,0.0);
glutSolidTorus(0.1,0.25,25,25);
glPopMatrix();

glPushMatrix();
glColor3f(1,0.5,0);
glTranslated(-3,-2.3, 0);
glRotatef(90,1.0,0.0,0.0);
glutSolidTorus(0.1,0.25,25,25);
glPopMatrix();

glPushMatrix();
glColor3f(1,0.5,0);
glTranslated(-3,-2.1, 0);
glRotatef(90,1.0,0.0,0.0);
glutSolidTorus(0.1,0.25,25,25);
glPopMatrix();

glPushMatrix();
glColor3f(1,0.5,0);
glTranslated(-3,-1.9, 0);
glRotatef(90,1.0,0.0,0.0);
glutSolidTorus(0.1,0.25,25,25);
glPopMatrix();

//tree leaves
glPushMatrix();
glColor3f(0.5,1,0.5);
glTranslated(-3,-1.8,0);
glRotatef(270,1.0,0.0,0.0);
glutWireCone(1,1,50,50);
glPopMatrix();

//clouds
glPushMatrix();
glColor3d(1,1,1);
glTranslated(-3.0,3.0,8);
glScalef(3,2,2);
glutSolidSphere(0.3,50,50);
glPopMatrix();

glPushMatrix();
glColor3d(1,1,1);
glTranslated(-2.0,2.8,8);
glScalef(3,2,2);
glutSolidSphere(0.3,50,50);
glPopMatrix();

glPushMatrix();
glColor3d(1,1,1);
glTranslated(-1.3,3.0,8);
glScalef(3,2,2);
glutSolidSphere(0.3,50,50);
glPopMatrix();


/*glPushMatrix();
glTranslated(-2.6,1.5,-6);
glRotatef(45,1.0,0.0,0.0);
glutWireSphere(0.1,50,50);
glPopMatrix();

glPushMatrix();
glTranslated(2.6,2.0,-6);
glRotatef(45,1.0,0.0,0.0);
glutWireTorus(0.25,0.5,50,50);
glPopMatrix();



*/glPushMatrix();
glTranslated(2.1,-2.55,-6);
glRotatef(90,1.0,0.0,0.0);
glutSolidTeapot(0.05);
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
glutInitWindowPosition(50,50);
glutCreateWindow("Scenery");
glutReshapeFunc(resize);
glutDisplayFunc(display);
glClearColor(0.6,0.6,1,1);
glutMainLoop();
return 0;
}
