#ifndef RENDERER_H
#define RENDERER_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <mxp1/shader.h>
#include <mxp1/sprite.h>
#include <mxp1/texture.h>
#include <mxp1/camera.h>
#include <mxp1/scene.h>
#include <mxp1/sprite.h>
#include <mxp1/input.h>


class Renderer
{
    public:

        Renderer();
        virtual ~Renderer();

		void renderScene(Scene* scene);

        void renderSprite(Sprite* sprite, float rot);
        GLFWwindow* window() { return _window; };

        int width() { return window_width; };
        int height() { return window_height; };

		Entity* entity;

    private:
        int init();

        GLFWwindow* _window;
        int window_width;
        int window_height;

        std::string fragment_shader;
        std::string vertex_shader;

        GLuint programID;
        GLuint vertexPosition_modelspaceID;
        GLuint vertexUVID;
        GLuint matrixID;
        GLuint textureID;

        glm::mat4 ProjectionMatrix;
};

#endif /* RENDERER_H */
