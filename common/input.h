/**
 * @file input.h
 *
 * @brief The Input header file.
 *
 * This file is part of RT2D, a 2D OpenGL framework.
 *
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *   - Initial commit
 *   - [meruiden] scaling of window
 */

#ifndef INPUT_H
#define INPUT_H

#define SWIDTH 1920
#define SHEIGHT 1080

#include <glfw3.h>

class Input
{
public:
	static Input* getInstance();
	static bool _getKey(int key);
	static bool _getMouse(int button);
	static bool _getMouseDown(int button);

	void setWindow(GLFWwindow* w) { _window = w; };
	bool getKey(int key) { return _keys[key]; }

	void updateInput(GLFWwindow* w);

	bool getMouse(int button) { return _mouse[button]; }

	bool getKeyDown(int key) { return _keysDown[key]; }
	
	bool getKeyDown(char key) { return getKeyDown((int)key); }
	
	bool getMouseDown(int button) { return _mouseDown[button]; }

	bool getKeyUp(int key) { return _keysUp[key]; }
	
	bool getKeyUp(char key) { return getKeyUp((int)key); }
	
	bool getMouseUp(int button) { return _mouseUp[button]; }

	double getMouseX() { return _mouseX; }
	
	double getMouseY() { return _mouseY; }
	
	void setMouse(double x, double y) { glfwSetCursorPos(_window, x, y); };

	int getWindowWidth() { return _windowWidth; }
	
	int getWindowHeight() { return _windowHeight; }

private:
	static Input* _instance;
	Input();
	virtual ~Input();
	void _handleKey(int key);
	void _handleMouse(int key); 

	bool _keys[GLFW_KEY_LAST]; 
	bool _keysUp[GLFW_KEY_LAST]; 
	bool _keysDown[GLFW_KEY_LAST]; 

	bool _mouse[GLFW_MOUSE_BUTTON_LAST];
	bool _mouseUp[GLFW_MOUSE_BUTTON_LAST];
	bool _mouseDown[GLFW_MOUSE_BUTTON_LAST]; 

	double _mouseX; 
	double _mouseY; 

	int _windowWidth; 
	int _windowHeight; 
	GLFWwindow* _window;
};

#endif /* INPUT_H */
