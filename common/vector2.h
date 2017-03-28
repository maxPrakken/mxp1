#ifndef VECTOR2_H
#define VECTOR2_H

#include <vector>
#include <math.h>

class Vector2 {

	public:
		int x;
		int y;

		Vector2();

		Vector2(int x_, int y_);
		
		virtual ~Vector2();

		void add(Vector2 vec);

		void sub(Vector2 vec);

		void mult(Vector2 vec);

		void div(Vector2 vec);

		void normalize();

		int mag();
		

	private:

};

#endif // !VECTOR2_H
