#include "game/myScene.h"

myScene::myScene() {
	test = new Entity();

	addChild(test);

	//spriteList.push_back(test->sprite);
	entityList.push_back(test);

	//use this to set position in the game scene
	///kingkong->posX = 300;
	///kingkong->posY = 400;
}

myScene::~myScene() {

}

void myScene::update(float deltaTime) {
	movement();
}

void myScene::movement() {
	if (Input::_getKey('W')) {
		test->sprite->posY -= 2;
	}

	if (Input::_getKey('A')) {
		test->sprite->posX -= 2;
	}

	if (Input::_getKey('S')) {
		test->sprite->posY += 2;
	}

	if (Input::_getKey('D')) {
		test->sprite->posX += 2;
	}
}
