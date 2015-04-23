#ifndef ANGRY_CODER_LOGO
#define ANGRY_CODER_LOGO

#include "cocos2d.h"
#include "GameController.h"

USING_NS_CC;

class GameLogo :public Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(GameLogo);
	virtual bool init() override;

private:
	void startLoading();
	void showLogoAndLoad();
	void loadRes();
	void loadPng();
	void loadSpriteFramesAfterPNGOver(Texture2D* texture);
	void overLoading();

	//GameController goto menu state
	void startGame();
};

#endif