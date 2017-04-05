#ifndef SCENE_H
#define SCENE_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/sprite.h>
#include <common/print.h>
#include <common/entity.h>
#include <common/input.h>

class Scene: public Entity {
	public:
		Scene(); 
		virtual ~Scene();

		void updateScene(float deltaTime);

		void movement();

		Entity* test;

		std::vector<Entity*>entityList;

	private:

		void _updateEntity(Entity* entity, float deltaTime);

		bool _isRunning;

	protected:


};

#endif // !SCENE_H
