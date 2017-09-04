#include <renderer.h>
#include <input.h>
#include <core.h>

#include "myScene.h"

int main() {

	//Renderer* renderer = new Renderer();
	myScene* scene = new myScene();
	Core* core = new Core();

	while (!glfwWindowShouldClose(&core.getRenderer()->window())) 
	{
		Input::getInstance()->updateInput(renderer->window());
		//scene->update(deltatiem)

	}
	delete renderer;
}