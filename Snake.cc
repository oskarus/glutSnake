#include "GL/freeglut.h"
#include "GL/gl.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "Snake.h"

using namespace std;

	Snake::Snake(){}		 
	Snake::~Snake(){
		for(int i=0;i<segments.size();i++){
			segments[i]->setType(EMPTY);
		}
	}
	
	Snake::Snake(Square* s1,Square* s2,Square* s3){
		size = 3;
		isDead = false;
		segments.push_back(s3);
		segments.push_back(s2);
		segments.push_back(s1);
			for(int i=0;i<segments.size();i++){
			segments[i]->setType(SNAKE);
		}
	}

	bool Snake::status(){
		return isDead;	
	}

	int Snake::getSize(){
		return size;
	}	

	void Snake::moove(Square* next){
		if(next->getType() == EDGE || next->getType() == SNAKE){
			isDead = true;
			return;
		}
		if(next->getType() == APPLE)
			size++;
		
		segments.push_back(next);
		segments.back()->setType(SNAKE);
	
		if(size < segments.size()){
			segments[0]->setType(EMPTY);
			segments.erase(segments.begin());
		}
	}
	
	Square* Snake::getHead(){
		return segments.back();
	}	
