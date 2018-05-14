#include "GL/freeglut.h"
#include "GL/gl.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <ctime>
#include "Board.h"

using namespace std;

	Board::Board(){}

	void Board::findXY(Square* s,int w[]){
		for(int y = 0;y < heigth;y ++){
			for(int x = 0;x < width;x ++){
				if(s == board[y][x]){
					w[0] = x;
					w[1] = y;	
					return;	
				}
			}
		}
	}

	void Board::spawnApple(){
		bool working = true;		
		int x,y;
		while(working){
			x = 1 + (rand()%(width - 2));
			y = 1 + (rand()%(heigth - 2));
			
			if(board[y][x]->getType() != SNAKE){
				board[y][x]->setType(APPLE);
				working = false;
				apple = board[y][x];
			}
		}
	}
 
	void Board::stop(){
		if(!pause)
			pause = true;
		else
			pause = false;
	}

	bool Board::status(){
		return gameOver;
	}
	
	void Board::changeDirection(enum Direction d){
		if(dir == UP && d == DOWN){return;}
		if(dir == DOWN && d == UP){return;}
		if(dir == LEFT && d == RIGHT){return;}
		if(dir == RIGHT && d == LEFT){return;}
		
		dir = d;
	}

	void Board::draw(){	
		char text[16];
	
		glColor3f(0.4, 0.4, 0.4);
		drawSquare(0,1.1,1);
	
		sprintf(text,"POINTS: %d",points);
		glColor3f(1, 1, 1);
		glRasterPos3f(0, 0.8,0);
		for (char *c=text; *c != '\0'; c++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
		}
		for(int y = 0;y < heigth;y ++){
			for(int x = 0;x < width;x ++){
				board[y][x]->draw();
			}
		}
	}
	
	void Board::reset(){
		delete snake;
		points = 0;
		snake = new Snake(board[heigth/2][(width/2) + 2],
				board[heigth/2][(width/2) + 1],
				board[heigth/2][(width/2)]);
		dir = RIGHT;
		gameOver = false;
			
	}

	void Board::update(){
		if(pause){
			return;
		}
			
		if(snake->status()){
			reset();
			return;
		}
			
		int head[2],size = snake->getSize(); 
		findXY(snake->getHead(),head);
	

		int x = head[0], y = head[1];
		
		if(dir == DOWN){
			snake->moove(board[y-1][x]);
		}
		if(dir == UP){
			snake->moove(board[y+1][x]);
		}
		if(dir == LEFT){
			snake->moove(board[y][x-1]);
		}
		if(dir == RIGHT){
			snake->moove(board[y][x+1]);
		}
	
		if(snake->getSize() != size){
			apple = NULL;
			points ++;		
		}
		if(apple == NULL){
			spawnApple();
		}
	}

	Board::Board(int heigth,int width,double scale){
		this->heigth = heigth;
		this->width = width;
		this->scale = scale;
	
		apple = NULL;		
		dir = RIGHT;
		gameOver = false;
		pause = false;
		points = 0;

		double offset = -2;
		
		for(int y = 0;y < heigth;y ++){
			board.push_back(vector<Square*>());
			for(int x = 0;x < width;x ++){
				if(y == 0 || y == (heigth - 1) ||
				 x == 0 || x == (width - 1))
				{
					board[y].push_back(new Square(x-(width/2),
					y-(heigth/2)+offset,scale,EDGE));		
				}
				else{
					board[y].push_back(new Square(x-(width/2),
					y-(heigth/2)+offset,scale,EMPTY));
				}
			}
		}
		snake = new Snake(board[heigth/2][(width/2) + 2],
				board[heigth/2][(width/2) + 1],
				board[heigth/2][(width/2)]);		
	}	

