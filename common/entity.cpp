#include "entity.h"

Entity::Entity() {
	workplox = new Sprite("assets/kingkong.tga", 256, 256);
	workplox->posX = 400;
	workplox->posY = 400;
}

Entity::~Entity() {

}