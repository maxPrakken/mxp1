#include "entity.h"

#include <iostream>

int Entity::_nextGuid = 0;

Entity::Entity() {

	_guid = _nextGuid;
	_nextGuid++;

	sprite = new Sprite("assets/kingkong.tga", 256, 256);
	//sprite = NULL;
	sprite->posX = 400;
	sprite->posY = 400;

	position = Vector2(0, 0);
	rotation = 0.0f;
	scale = Vector2(1, 1);
}

Entity::~Entity() {

}

void Entity::update(float deltaTime) {

	//this->sprite->posX += 10;
}

void Entity::addChild(Entity* child) {
	if (child->_parent != NULL) {
		child->_parent->removeChild(child);
	}
	child->_parent = this;
	this->_children.push_back(child);
}

void Entity::removeChild(Entity* child)
{
	std::vector< Entity* >::iterator it = _children.begin();
	while (it != _children.end()) {
		if ((*it)->_guid == child->_guid) {
			it = _children.erase(it);
		}
		else {
			++it;
		}
	}
}