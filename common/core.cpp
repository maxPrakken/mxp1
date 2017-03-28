#include "core.h"

Core::Core() {
	_deltaTime = 0;
}

Core::~Core() {

}

void Core::runScene(Scene* scene) {
	//update deltatime
	_calculateDeltaTime();

	scene->updateScene((float)_deltaTime); 

	_renderer.renderScene(scene);

}

double Core::_calculateDeltaTime()
{
	static double lastTime = glfwGetTime();
	double startTime = glfwGetTime();
	_deltaTime = startTime - lastTime;
	lastTime = startTime;

	return _deltaTime;
}