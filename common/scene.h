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

class Scene {
	public:
		Scene(); 
		virtual ~Scene();

		std::vector<Sprite*>spriteList;

	private:


	protected:


};

#endif // !SCENE_H
