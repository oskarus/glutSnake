#include "GL/freeglut.h"
#include "GL/gl.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "Square.h"

using namespace std;
	
	Square::Square(){}

	void Square::drawEdge(){
		glColor3f(0.4, 0.4, 0.4);
		drawSquare(x,y,size);
		glColor3f(1, 1, 1);
		drawSquare(x,y,size*0.9);	
	}
	
	void Square::drawSnake(){
		glColor3f(1.0, 1.0, 1.0);
    		drawSquare(x,y,size);
    		glColor3f(0.4, 0.4, 0.4);
    		drawSquare(x,y,size*0.8);
    		glColor3f(1.0, 1.0, 1.0);
    		drawSquare(x,y,size*0.6);
	}
	
	void Square::drawApple(){
		glColor3f(1, 1, 1);
		drawSquare(x,y+(size/3),size/3);
		drawSquare(x,y-(size/3),size/3);
		drawSquare(x+(size/3),y,size/3);
		drawSquare(x-(size/3),y,size/3);
	}
	
	void Square::erease(){
		glColor3f(0.4, 0.4, 0.4);
		drawSquare(x,y,size);
	}
 	
	void Square::draw(){
		if(flag == 0){
			return;		
		}
		if(type == EMPTY){
			erease();
		}
		if(type == EDGE){
			drawEdge();
		}
		if(type == SNAKE){
			drawSnake();
		}
		if(type == APPLE){
			drawApple();
		}
		flag = 0;
	}
	
	void Square::setType(enum SquareType t){
		type = t;
		flag = 1;	
	}	
	
	enum SquareType Square::getType(){
		return type;
	}

	Square::Square(double x,double y,double size,enum SquareType t){
		this->x = x * size;
		this->y = y * size;
		this->size = size;
		setType(t);
	}

