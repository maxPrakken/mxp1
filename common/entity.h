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

		virtual void update(float deltaTime);

		//transform
		Vector2 position;
		float rotation;
		Vector2 scale;

		Sprite* sprite;

		Sprite* getSprite() { return sprite; }

		void addChild(Entity* child);

		void removeChild(Entity* child);

		const std::vector<Entity*>& children() { return _children; };

	private:
		std::vector<Entity*> _children;

		Entity* _parent;

		int _guid; 
		static int _nextGuid;
};

#endif // !ENTITY_H
