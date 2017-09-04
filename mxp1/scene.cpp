#include <mxp1/scene.h>

Scene::Scene() {

	float rot_z = 0.0f;

}

Scene::~Scene() {

}

void Scene::updateScene(float deltaTime) {
	this->_updateEntity(this, deltaTime);
	//std::cout << "im updating" << std::endl;
	
	
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




