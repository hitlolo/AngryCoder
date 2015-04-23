#ifndef ANGRY_CODER_CONTROLLER
#define ANGRY_CODER_CONTROLLER

#include "cocos2d.h"
#include "GameData.h"
#include "GameLogo.h"
#include "GameMenu.h"
#include  "HelloWorldScene.h"


USING_NS_CC;

class GameController
{

public:
	static GameController* getInstance();
	 GameController();
	~GameController();

public:
	//interface
	void  goState(const GAME_STATE = GAME_STATE::LOGO);

	void  backToLastScene();


private:
	static GameController* _controller;
	void nextScene(Scene*);
	void pushSceneBySlideInR(Scene*);
	void pushSceneByFadeIn(Scene*);


private:
	void logo();
	void menu();
	void game();
	void over();

private:

	CC_SYNTHESIZE(GAME_STATE, curGameState, CurGameState);
	CC_SYNTHESIZE(Scene*, curScene, CurScene);
};

#endif