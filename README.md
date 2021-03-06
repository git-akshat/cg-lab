# computer-graphics
#### 1. Write a program to demonstrate the following OpenGL primitives with either RGB or indexed colors(as suggested by examiner):
- GL_POINTS
- GL_LINES 
- GL_LINE_STRIP 
- GL_LINE_LOOP
- GL_TRIANGLES 
- GL_TRIANGLE_STRIP
- GL_TRIANGLE_FAN
- GL_QUADS 
- GL_QUAD_STRIP
- GL_POLYGON 

#### 2. Write a program to demonstrate the two views, orthographic view and perspective view, of OpenGL by consider a 2D and a 3D with any two primitives.

#### 3. Write a program to deisgn a scenery by using the following OpenGL buit-in shapes.


| glutSolidSphere(float radius, int slices, int stacks) | Circle | Sphere | Choose an integer 20-100 for the slices and stacks arguments; the higher the number, the more accurate the sphere/circle. |
| ---------------------------------------------- | ------ | ------ | ------------------------------------------------- |
| glutSolidCube(double size) | Square | Cube | |
| glutSolidCone(double base, double height, int slices, int stacks) | Triangle | Cone | The greater the slices argument is, the smoother the cone will appear. |
| glutSolidTorus(double innerRadius, double outerRadius, int nSides, int rings) |  | Torus | |
| glutSolidTeapot(float radius) | | | |

#### 4. Write a recursive program to construct a 3D Sierpinski gasket with polygons.

#### 5. Write a program to demonstrate the plotting of implicit functions with marching squares technique.

#### 6. Write a simple CAD program to model the polygons as follows:
* Creating 2D polygons.
* Selection of a Polygon.
* Deletion of a polygon.

#### 7.Write a program to demonstrate the OpenGL transformation functions with any of the suitable primitive for the following transformations:
* Translate
* Scale
* Roate

#### 8. Write an animated program to construct a car like structure on a track and perform the following in a menu:
* start the car
* change dirction of moving car from left to right and vise versa.
* increase and decrease the speed
* stop the car.
* a sub menu to change color of the car body.

#### 9. Write a program to fill a 3D cube with a set of six colors for its six faces with the Zbuffer hidden surface removal algorithm. Allow the user to view all faces of the cube with rotation.

#### 10. Write a program to fill the a star like structure with any one of the following algorithms:
* Flood fill
* Scan-Line fill


## For running open gl programs in linux

### (1) Install these libraries `
` sudo apt-get install freeglut3-dev `

### (2) For compiling program
` gcc main.c  -lGL  -lGLU  -lglut `
