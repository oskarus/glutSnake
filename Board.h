#include <vector>
#include "Snake.h"

using namespace std;

class Board{
	//board[y][x]
	private: 
		vector<vector<Square*> > board;
		Snake* snake;
		int heigth, width, points;
		double scale;
		Square* apple;
		bool gameOver;
		bool pause;
		
		Board();

		void findXY(Square* s,int w[]);

		void spawnApple();

	public: 
		enum Direction dir;

		void stop();
	
		bool status();
	
		void changeDirection(enum Direction d);

		void draw();
	
		void reset();

		void update();

		Board(int heigth,int width,double scale);	
};
