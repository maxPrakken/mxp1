
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
	static bool _getKey(char key);
	static bool _getKeyDown(char key);
	static bool _getMouse(int button);
	static bool _getMouseDown(int button);

	void setWindow(GLFWwindow* w) { _window = w; };

	//updates this class
	void updateInput(GLFWwindow* w);

	//get key as int when holding
	bool getKey(int key) { return _keys[key]; }

	//gets key as char when holding ''
	bool getKey(char key) {return getKey((int)key); }

	//gets key as int when pressed down
	bool getKeyDown(int key) { return _keysDown[key]; }
	
	//gets key as char when pressed down ''
	bool getKeyDown(char key) { return getKeyDown((int)key); }

	//get key as int when comming up again
	bool getKeyUp(int key) { return _keysUp[key]; }

	//gets key as char when comming up again ''
	bool getKeyUp(char key) { return getKeyUp((int)key); }


	//gets mouseclick as int when holding
	bool getMouse(int button) { return _mouse[button]; }
	
	//gets mouseclick as int when pressing down
	bool getMouseDown(int button) { return _mouseDown[button]; }
	
	//gets mouseclick as int when getting up again
	bool getMouseUp(int button) { return _mouseUp[button]; }

	//gets mouse X position
	double getMouseX() { return _mouseX; }
	
	//gets mouse Y position
	double getMouseY() { return _mouseY; }
	
	//sets mouse position to X Y position
	void setMouse(double x, double y) { glfwSetCursorPos(_window, x, y); };


	//gets the width of the current open window
	int getWindowWidth() { return _windowWidth; }
	
	//gets the height of the current open window
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
