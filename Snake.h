#include <vector>
#include "Square.h"

using namespace std;

class Snake{
	private: 
		vector<Square*> segments;
		int size;
		bool isDead;
	
		Snake();	
	
	public: 
		~Snake();
	
		Snake(Square* s1,Square* s2,Square* s3);

		bool status();

		int getSize();

		void moove(Square* next);
	
		Square* getHead();
	
};
