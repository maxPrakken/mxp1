#include <common/scene.h>

Scene::Scene() {

	float rot_z = 0.0f;

	test = new Entity();

	this->addChild(test);

	//spriteList.push_back(test->sprite);
	entityList.push_back(test);

	//use this to set position in the game scene
	///kingkong->posX = 300;
	///kingkong->posY = 400;
}

Scene::~Scene() {

}

void Scene::updateScene(float deltaTime) {
	this->_updateEntity(this, deltaTime);
	//std::cout << "im updating" << std::endl;
	
	movement();
}

void Scene::_updateEntity(Entity* entity, float deltaTime) {
	entity->update(deltaTime);
	//update the children
	std::vector<Entity*> children = entity->children();
	std::vector<Entity*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		this->_updateEntity(*child, deltaTime);
	}
}

void Scene::movement() {
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


