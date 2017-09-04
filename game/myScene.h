#ifndef MYSCENE_H
#define MYSCENE_H

#include <scene.h>

class myScene : public Scene {
public :
	myScene();
	
	virtual ~myScene();

	virtual void update(float deltaTime);

	void movement();

	Entity* test;

	

private:

};

#endif // !MYSCENE.H
