#include <common/scene.h>

Scene::Scene() {
	Sprite* pencils = new Sprite("assets/pencils.tga", 128, 128);
	Sprite* kingkong = new Sprite("assets/kingkong.tga", 256, 256);
	Sprite* rgba = new Sprite("assets/rgba.tga", 521, 512);

	float rot_z = 0.0f;

	spriteList.push_back(pencils);
	spriteList.push_back(kingkong);
	spriteList.push_back(rgba);

	//use this to set position in the game scene
	///kingkong->posX = 300;
	///kingkong->posY = 400;
}

Scene::~Scene() {

}
