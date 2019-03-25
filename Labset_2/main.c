#include <stdio.h>
#include<GL/glut.h>

void display2D()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

	glBegin(GL_QUADS);      // wall
	glColor3f(1,1,1);       // white
	glVertex2d(0.5,-0.2);
	glVertex2d(0.5,0.4);
	glVertex2d(-0.5,0.4);
	glVertex2d(-0.5,-0.2);
	glEnd();

	glBegin(GL_TRIANGLES);  //roof
	glColor3f(1.0,0.4,0.4); //pink
	glVertex2d(0,0.8);
	glVertex2d(0.5,0.4);
	glVertex2d(-0.5,0.4);
	glEnd();

	glBegin(GL_QUADS);      //door
	glColor3f(0, 0.5, 0.5); //green
	glVertex2d(0.1,-0.2);
	glVertex2d(0.1,0.15);
	glVertex2d(-0.1,0.15);
	glVertex2d(-0.1,-0.2);
	glEnd();

	glBegin(GL_QUADS);      //right window
	glColor3f(1, 0.4, 0.4); //pink
	glVertex2d(0.4,-0.05);
	glVertex2d(0.4,0.15);
	glVertex2d(0.2,0.15);
	glVertex2d(0.2,-0.05);
	glEnd();

	glBegin(GL_QUADS);      //left window
	glColor3f(1, 0.4, 0.4); //pink
	glVertex2d(-0.4,-0.05);
	glVertex2d(-0.4,0.15);
	glVertex2d(-0.2,0.15);
	glVertex2d(-0.2,-0.05);
	glEnd();

	glFlush();
}

void display3D()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,0.0);

	glBegin(GL_LINES);
	glVertex2f(0.2,0.2);
	glVertex2f(-0.2,0.2);

	glVertex2f(-0.2,-0.2);
	glVertex2f(0.2,-0.2);

	glVertex2f(0.2,0.2);
	glVertex2f(0.2,-0.2);

	glVertex2f(-0.2,0.2);
	glVertex2f(-0.2,-0.2);

	glVertex2f(0.3,0.3);
	glVertex2f(-0.1,0.3);

	glVertex2f(-0.1,-0.1);
	glVertex2f(0.3,-0.1);

	glVertex2f(0.3,0.3);
	glVertex2f(0.3,-0.1);

	glVertex2f(-0.1,0.3);
	glVertex2f(-0.1,-0.1);

	glVertex2f(0.2,0.2);
	glVertex2f(0.3,0.3);

	glVertex2f(-0.2,-0.2);
	glVertex2f(-0.1,-0.1);

	glVertex2f(-0.2,0.2);
	glVertex2f(-0.1,0.3);

	glVertex2f(0.2,-0.2);
	glVertex2f(0.3,-0.1);

	glEnd();
	glFlush();
}

void init2D(int ch)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	if(ch==1)
		glutCreateWindow("2D Orthogonal Projection");
	else
		glutCreateWindow("2D Perspective Projection");

	glutDisplayFunc(display2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(ch==1)
		gluOrtho2D(-2.0,2.0,-2.0,2.0);
	else
		gluPerspective(100.0,1.0,1.0,100.0);

	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init3D(int ch)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	if(ch==1)
		glutCreateWindow("3D Orthogonal Projection");
	else
		glutCreateWindow("3D Perspective Projection");
	glutDisplayFunc(display3D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(ch==1)
		glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	else
		glFrustum(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
	int ch;
	glutInit(&argc,argv);
	printf("Enter your choice: \n 1: 2D orthogoal Projection \n 2: 2D Perspective Projection \n 3: 3D orthogoal Projection\n 4: 3D Perspective Projection\n");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: init2D(1);
				 break;
		case 2: init2D(2);
				 break;
		case 3: init3D(1);
				 break;
		case 4: init3D(2);
				 break;
	}
	glutMainLoop();
	return 0;
}
