// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/renderer.h>
#include <common/sprite.h>
#include <common/scene.h>
#include <common/core.h>

int main( void )
{
	
	Core* core = new Core();
	Scene* myScene = new Scene();

    do {
		core->runScene(myScene);

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(core->getRenderer().window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(core->getRenderer().window()) == 0 );

    //delete pencils;
    //delete kingkong;
    //delete rgba;

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
