#include "GL/freeglut.h"
#include "GL/gl.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "Board.h"

using namespace std;

#define WYS 20
#define SZER 25

Board b(WYS,SZER,0.08);

void keyboardFunkc(unsigned char key,int x,int y){
	switch(key){
		case 27: b.stop(); break;
		case'w': b.changeDirection(UP); break;
		case's': b.changeDirection(DOWN); break;
		case'a': b.changeDirection(LEFT); break;
		case'd': b.changeDirection(RIGHT); break;
	};
}

void draw(){
	b.draw();
}

void update(int v){
	b.update();
	if(b.status()){
		glutInitWindowSize(100, 100);
    		glutInitWindowPosition(100, 100);
    		glutCreateWindow("Snake");

	}
		
	glutPostRedisplay();
	glutTimerFunc(100,update,0);
}

int main(int argc, char **argv)
{

    	int snake, opcje;
    	srand(time(NULL));
    	glutInit(&argc, argv);

    	glutInitDisplayMode(GLUT_SINGLE);
    	glutInitWindowSize(600, 600);
    	glutInitWindowPosition(100, 100);
    	snake = glutCreateWindow("Snake");
    	glutKeyboardFunc(keyboardFunkc);
    	glClearColor(0.4, 0.4, 0.4, 0.4);	    
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(draw);
	glutTimerFunc(100,update,0);

    	glutMainLoop();
    	return 0;
}

