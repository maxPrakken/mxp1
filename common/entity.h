#ifndef ENTITY_H
#define ENTITY_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include <common/print.h>
#include <common/sprite.h>
#include <common/vector2.h>

class Entity {
	public:
		Entity();
		virtual ~Entity();

		Sprite* workplox;

	private:

};

#endif // !ENTITY_H
