#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>

#define MAX_POLY 8
#define MAX_VER 30
#define TRUE 1
#define FALSE 0

typedef struct polygon
{
    int color;
    int used;
    int xmin, xmax,ymin,ymax;
    int nvtcs;
    int x[MAX_VER],y[MAX_VER];
}polygon;

int picking = FALSE;
int del = FALSE;
int in_poly = -1;
int present_color = 0;

GLsizei wh =500, ww = 500;
GLfloat colors[2][3]= {{1.0,0.0,0.0},{0.0,1.0,0.0}};

polygon polys[MAX_POLY];
int pick_poly(int x,int y);

void myReshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)w, 0.0,(GLdouble)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0,0,w,h);
    ww = w;
    wh= h;
}


void myinit()
{
    int i;
    glClearColor(1.0,1.0,1.0,0.0);
    /* mark all polygons unused */
    for(i=0;i<MAX_POLY;i++)
    polys[i].used = FALSE;
}


void Mymouse(int btn, int st,int x, int y)
{
    int i,j;
    y=wh-y;
    
    if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN && !picking  )
    {
    /* adding vertices*/
    	if(in_poly>=0)
       	{
        	if(polys[in_poly].nvtcs == MAX_VER)
            {
                printf("Exceeds maximum number of vertices\n");
                exit(0);
            }
            i= polys[in_poly].nvtcs;
            polys[in_poly].x[i]=x;
            polys[in_poly].y[i]=y;
            polys[in_poly].nvtcs++;
       	}
    }
    
    if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN && picking && !del)
   	{
    	picking= FALSE;
    	j= pick_poly(x,y);
    	if(j>=0)
    	{
         /* highlight selected poylgon with select color*/
          polys[j].color = present_color;
          present_color =0;
          in_poly = -1;
     	}
        glutPostRedisplay();
    }
    
    if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN && picking && del)
    {
    	/*delete polygon*/
    	picking= FALSE;
    	j= pick_poly(x,y);
    	if(j>=0)
    	{
    		polys[j].used = FALSE;
    	    del=FALSE;
    	    in_poly = -1;
    	}
    	glutPostRedisplay();
	}
}


int pick_poly(int x, int y)
{
    /* find first polygon in which we are in bounding box */
    int i;
    for(i=0; i<MAX_POLY; i++)
    {
        if(polys[i].used)
        	if((x>=polys[i].xmin) && (x<=polys[i].xmax) &&
           	(y>=polys[i].ymin) && (y<=polys[i].ymax))
           	{
                in_poly =i;
                return i;
           	}
    }

    printf("not in a polygon\n");
    return -1;
}


void mainmenu(int id)
{
    int i;
    switch(id)
    {
        case 1: /*create a new polygon */

                  /*find a polygon which is not in use now */
           		picking = FALSE;
            	del = FALSE;
            	for(i=0; i< MAX_POLY;i++)
            	    if(polys[i].used == FALSE)
            	    	break;
            
            	if(i == MAX_POLY)
            	{
            	    printf("Exceeded maximum number of polygons\n");
            	    exit(0);
            	}
            	/*Give the details of the polygon*/
            	polys[i].color =present_color;
            	polys[i].used = TRUE;
            	polys[i].nvtcs =0;
            	in_poly= i;
                break;
                
        case 2: /*  end polygon and find bounding box and center*/
                if(in_poly>=0)
            	{
                	/*initialize the bouning box and center to frist vertex */
                	polys[in_poly].xmax = polys[in_poly].xmin = polys[in_poly].x[0];
                	polys[in_poly].ymax = polys[in_poly].ymin = polys[in_poly].y[0];
	
                	/* now find the actual center and limits of bounding box*/
                	for(i=1;i<polys[in_poly].nvtcs;i++)
                	{
                	    if(polys[in_poly].x[i] < polys[in_poly].xmin)
                	        polys[in_poly].xmin = polys[in_poly].x[i];
                	    else if(polys[in_poly].x[i] > polys[in_poly].xmax)
                	        polys[in_poly].xmax = polys[in_poly].x[i];
                	    if(polys[in_poly].y[i] < polys[in_poly].ymin)
                	        polys[in_poly].ymin = polys[in_poly].y[i];
                	    else if(polys[in_poly].y[i] > polys[in_poly].ymax)
                	        polys[in_poly].ymax = polys[in_poly].y[i];
                	}

           	 	}
            	in_poly = -1;
            	glutPostRedisplay();
            	break;
            	
        case 3: /* set picking mode */
                picking = TRUE;
                present_color =1;
                del = FALSE;
                break;
                
        case 4: /* delete a polygon */
                picking = TRUE;
                del = TRUE;
                break;
                
        case 5: /* set picking mode */
                picking = TRUE;
                present_color =0;
                del = FALSE;
                break;
                
        case 6: exit(0);
     }
}


void display()
{
    /* display all active polygons */
    int i,j;
    glClear(GL_COLOR_BUFFER_BIT);
    for(i=0;i<MAX_POLY;i++)
    {
        if(polys[i].used)
        {
            glColor3fv(colors[polys[i].color]);
            glBegin(GL_POLYGON);
            for(j=0;j<polys[i].nvtcs;j++)
            glVertex2i(polys[i].x[j], polys[i].y[j]);
            glEnd();
        }
    }
    glFlush();
}


int main(int argc,char **argv)
{
   	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Polygon Modeler");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    myinit();
	/* Create Menu*/
    glutCreateMenu(mainmenu);
    glutAddMenuEntry("new polygon", 1);
    glutAddMenuEntry("end polygon",2);
    glutAddMenuEntry("Select polygon", 3);
    glutAddMenuEntry("delete polygon", 4);
    glutAddMenuEntry("deselect", 5);
    glutAddMenuEntry("quit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMouseFunc(Mymouse);
    glutMainLoop();
    return 0;
}

