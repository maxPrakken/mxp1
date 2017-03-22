// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/renderer.h>
#include <common/sprite.h>
#include <common/scene.h>

int main( void )
{
	

    Renderer renderer;
	Scene* myScene = new Scene();

    do {
		renderer.renderScene(myScene);

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(renderer.window()) == 0 );

    //delete pencils;
    //delete kingkong;
    //delete rgba;

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
