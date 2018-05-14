#include <vector>
#include "basics.h"

using namespace std;

class Square{
	private: 
		double x, y, size;
		enum SquareType type;
		int flag;
	
		Square();
		void drawEdge();
		void drawSnake();
		void drawApple();
		void erease();
	
	public: 
		void draw();	
		void setType(enum SquareType t);
		enum SquareType getType();
		Square(double x,double y,double size,enum SquareType t);
	
};

