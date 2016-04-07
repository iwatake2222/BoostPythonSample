#ifndef CLASS_A_H
#define CLASS_A_H

class ClassA {
public:
	typedef enum {
		RED   = 0,
		GREEN = 1,
		BLUE  = 2,
	} COLOR;

	typedef struct {
		int x;
		int y;
	} VECTOR_2D;

public:
	ClassA(int a);
	int a;
	int getA();
	VECTOR_2D getVector();
	COLOR setGetColor(COLOR color);
};

#endif /* CLASS_A_H */
