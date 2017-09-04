#include <mxp1/input.h>

///use getkey Input::_getKey(keycode);

Input * Input::_instance = NULL;
Input * Input::getInstance()
{
	if (_instance == NULL) {
		_instance = new Input();
	}
	return _instance;
}

bool Input::_getKey(int key)
{
	return getInstance()->getKey(key);
}

bool Input::_getKey(char key) {
	return getInstance()->getKey(key);
}

bool Input::_getKeyDown(char key) {
	return getInstance()->getKeyDown(key);
}

bool Input::_getMouse(int button) {
	return getInstance()->getMouse(button);
}

bool Input::_getMouseDown(int button) {
	return getInstance()->getMouseDown(button);
}

Input::Input()
{
	_window = NULL;

	_windowWidth = 0;
	_windowHeight = 0;

	int i;
	for (i = 0; i<GLFW_KEY_LAST; i++) {
		_keys[i] = false;
		_keysUp[i] = false;
		_keysDown[i] = false;
	}
	for (i = 0; i<GLFW_MOUSE_BUTTON_LAST; i++) {
		_mouse[i] = false;
		_mouseUp[i] = false;
		_mouseDown[i] = false;
	}
}

Input::~Input()
{

}

void Input::updateInput(GLFWwindow* w)
{
	_window = w;

	glfwPollEvents();

	// 32-97 = ' ' to '`'
	int i;
	for (i = 32; i<97; i++) {
		_handleKey(i);
	}
	// Func + arrows + esc, etc
	for (i = 255; i<GLFW_KEY_LAST; i++) {
		_handleKey(i);
	}
	//  window size
	glfwGetWindowSize(_window, &_windowWidth, &_windowHeight);

	glfwGetCursorPos(_window, &_mouseX, &_mouseY);

	// Fix cursor position if window size is different from the set resolution
	_mouseX = ((float)SWIDTH / _windowWidth) * _mouseX;
	_mouseY = ((float)SHEIGHT / _windowHeight) * _mouseY;

	// mouse buttons
	for (i = 0; i<GLFW_MOUSE_BUTTON_LAST; i++) {
		_handleMouse(i);
	}
}

void Input::_handleMouse(int button)
{
	if (glfwGetMouseButton(_window, button) == GLFW_PRESS) {
		if (_mouse[button] == false) { // if first time pressed down
			_mouse[button] = true;
			_mouseDown[button] = true;
			//std::cout << "DOWN: " << button << std::endl;
		}
		else {
			// not the first time this is pressed
			// keys[button] is still true;
			_mouseDown[button] = false;
		}
	}
	if (glfwGetMouseButton(_window, button) == GLFW_RELEASE) {
		if (_mouse[button] == true) { // still pressed
			_mouse[button] = false;
			_mouseUp[button] = true;
			//std::cout << "UP: " << button << std::endl;
		}
		else {
			_mouseUp[button] = false;
		}
	}
}

void Input::_handleKey(int key)
{
	if (glfwGetKey(_window, key) == GLFW_PRESS) {
		if (_keys[key] == false) { // if first time pressed down
			_keys[key] = true;
			_keysDown[key] = true;
			//std::cout << "DOWN: " << key << std::endl;
		}
		else {
			// not the first time this is pressed
			// keys[key] is still true;
			_keysDown[key] = false;
		}
	}
	if (glfwGetKey(_window, key) == GLFW_RELEASE) {
		if (_keys[key] == true) { // still pressed
			_keys[key] = false;
			_keysUp[key] = true;
			//std::cout << "UP: " << key << std::endl;
		}
		else {
			_keysUp[key] = false;
		}
	}
}


