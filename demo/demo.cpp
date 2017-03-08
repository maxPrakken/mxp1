// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/renderer.h>
#include <common/sprite.h>

int main( void )
{
    Renderer renderer;

    Sprite* pencils = new Sprite("assets/pencils.tga", 128, 128);
    Sprite* kingkong = new Sprite("assets/kingkong.tga", 256, 256);
    Sprite* rgba = new Sprite("assets/rgba.tga", 521, 512);

    float rot_z = 0.0f;

    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        renderer.renderSprite(pencils, 400, 300, 0.0f);
        renderer.renderSprite(kingkong, 900, 400, 0.0f);
        renderer.renderSprite(rgba, renderer.width()/2, renderer.height()/2, rot_z);
        rot_z += 0.03f;

        // Swap buffers
        glfwSwapBuffers(renderer.window());
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(renderer.window()) == 0 );

    delete pencils;
    delete kingkong;
    delete rgba;

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
