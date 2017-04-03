#ifndef CORE_H
#define CORE_H

// Include standard headers
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <common/renderer.h>
#include <common/entity.h>
#include <common/scene.h>
#include <glfw3.h>

class Core {
	public:

		Core();
		virtual ~Core();

		Renderer getRenderer() { return _renderer; }

		//starts running the scene on startup
		void runScene(Scene* scene);

		//calculates deltatime
		float deltaTime() { return (float)_deltaTime; }

	private:
		Renderer _renderer;

		double _calculateDeltaTime();
		double _deltaTime;

};

#endif // !CORE_H
