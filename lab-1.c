#include<GL/glut.h>
void draw_points();
void draw_lines();
void draw_line_strip();
void draw_line_loop();
void draw_triangles();
void draw_triangle_strip();
void draw_triangle_fan();
void draw_quads();
void draw_quad_strip();
void draw_polygon();

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(1.0,0.0,0.0);
    gluOrtho2D(0.0,50.0,0.0,50.0);
}

void display()
{
    int ch;
    while(1)
    {
        printf("\n1.GL_POINTS \n2.GL_LINES \n3.GL_LINE_STRIP \n4.GL_LINE_LOOP \n5.GL_TRIANGLE\n6.GL_TRIANGLE_STRIP \n7.GL_TRIANGLE_FAN \n8.GL_QUADS \n9.GL_QUAD_STRIP \n10.GL_POLYGON \n11.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(5.0);
        switch(ch)
        {
            case 1:draw_points();
                    break;

            case 2:draw_lines();
                    break;

            case 3:draw_line_strip();
                    break;

            case 4:draw_line_loop();
                    break;

            case 5:draw_triangles();
                    break;

            case 6:draw_triangle_strip();
                    break;

            case 7:draw_triangle_fan();
                    break;

            case 8:draw_quads();
                    break;

            case 9:draw_quad_strip();
                    break;

            case 10:draw_polygon();
                    break;

            case 11: exit(0);

            default:printf("\n invalid choice");
        }
        glEnd();
        glFlush();
    }
}

void main(int argc,char**argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(500,100);
    glutCreateWindow("Labset 1");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}

void draw_points()
{
    glBegin(GL_POINTS);
    glVertex2f(10.0,10.0);
    glVertex2f(20.0,20.0);
}
void draw_lines()
{
    glBegin(GL_LINES);
    glVertex2f(10.0,10.0);
    glVertex2f(20.0,20.0);
}
void draw_line_strip()
{
    glBegin(GL_LINE_STRIP);
    glVertex2f(10.0,10.0);
    glVertex2f(20.0,5.0);
    glVertex2f(30.0,10.0);
    glVertex2f(40.0,5.0);
}
void draw_line_loop()
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(10.0,10.0);
    glVertex2f(20.0,5.0);
    glVertex2f(30.0,10.0);
    glVertex2f(40.0,5.0);
    glVertex2f(10.0,30.0);
}
void draw_triangles()
{
    glBegin(GL_TRIANGLES);
    glVertex2f(10.0,10.0);
    glVertex2f(20.0,20.0);
    glVertex2f(30.0,10.0);

}
void draw_triangle_strip()
{

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(10.0,10.0);
    glVertex2f(20.0,20.0);
    glVertex2f(30.0,10.0);
    glVertex2f(40.0,20.0);
}
void draw_triangle_fan()
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(10.0,10.0);
    glVertex2f(20.0,20.0);
    glVertex2f(30.0,10.0);
    glVertex2f(40.0,20.0);
}
void draw_quads()
{
    glBegin(GL_QUADS);
    glVertex2f(10.0,10.0);
    glVertex2f(10.0,20.0);
    glVertex2f(30.0,10.0);
    glVertex2f(30.0,20.0);
}
void draw_quad_strip()
{
    glBegin(GL_QUAD_STRIP);
    glVertex2f(10.0,10.0);
    glVertex2f(30.0,10.0);
    glVertex2f(10.0,20.0);
    glVertex2f(30.0,20.0);
    glVertex2f(20.0,30.0);
    glVertex2f(30.0,30.0);
}
void draw_polygon()
{
    glBegin(GL_POLYGON);
    glVertex2f(10.0,10.0);
    glVertex2f(30.0,10.0);
    glVertex2f(10.0,20.0);
    glVertex2f(30.0,20.0);
    glVertex2f(20.0,30.0);
}

