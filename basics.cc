#include "GL/freeglut.h"
#include "GL/gl.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "basics.h"

using namespace std;

void drawSquare(double x,double y,double size){
	/*glBegin(GL_TRIANGLES);
                glVertex3f(x-(size/2), y+(size/2), 0);
                glVertex3f(x+(size/2), y+(size/2), 0);
                glVertex3f(x+(size/2), y-(size/2), 0);
        glEnd();

	glBegin(GL_TRIANGLES);
                glVertex3f(x-(size/2), y+(size/2), 0);
                glVertex3f(x+(size/2), y-(size/2), 0);
                glVertex3f(x-(size/2), y-(size/2), 0);
        glEnd();
	glFlush();*/
	glBegin(GL_POLYGON);
                glVertex3f(x-(size/2), y+(size/2), 0);
                glVertex3f(x-(size/2), y-(size/2), 0);
		glVertex3f(x+(size/2), y-(size/2), 0);
		glVertex3f(x+(size/2), y+(size/2), 0);
        glEnd();
	glFlush();
}
