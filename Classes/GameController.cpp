#include "GameController.h"

GameController* GameController::_controller = nullptr;


GameController* GameController::getInstance()
{
	if (_controller == nullptr)
	{
		_controller = new GameController();
		return _controller;
	}
	else
		return _controller;
}

GameController::GameController()

{
	setCurGameState(GAME_STATE::LOGO);
}

GameController::~GameController()
{
	CC_SAFE_DELETE(_controller);
}

void GameController::goState(const GAME_STATE state)
{
	setCurGameState(state);
	switch (state)
	{
	case GAME_STATE::LOGO:
		logo();
		break;
	case GAME_STATE::MENU:
		menu();
		break;
	case GAME_STATE::GAME:
		game();
		break;
	case GAME_STATE::OVER:
		over();
		break;
	}
}

void GameController::logo()
{
	auto logo = GameLogo::createScene();
	Director::getInstance()->runWithScene(logo);
}

void GameController::menu()
{
	auto menu = GameMenu::create();
	this->nextScene(menu);
}

void GameController::game()
{
	/*auto game = GameScene::create(map);
	this->pushSceneByFadeIn(game);*/
}

void GameController::over()
{

}


void GameController::nextScene(Scene* next_scene)
{
	this->setCurScene(next_scene);
	auto trasition = TransitionCrossFade::create(0.6f, next_scene);
	Director::getInstance()->replaceScene(trasition);
}

void  GameController::pushSceneBySlideInR(Scene* next_scene)
{
	this->setCurScene(next_scene);
	auto trasition = TransitionSlideInR::create(0.6f, next_scene);
	Director::getInstance()->pushScene(trasition);
}

void  GameController::pushSceneByFadeIn(Scene* next_scene)
{
	this->setCurScene(next_scene);
	auto trasition = TransitionProgressInOut::create(0.6f, next_scene);
	Director::getInstance()->pushScene(trasition);
}

void GameController::backToLastScene()
{
	Director::getInstance()->popScene();
}

//int GameController::getLevelPassed()
//{
//	int temLevel = 0;
//	temLevel = UserDefault::getInstance()->getIntegerForKey("level");
//	if (temLevel)
//	{
//		level = temLevel;
//		return temLevel;
//	}
//	else
//		return level;
//}

//void GameController::setLevelPassed(int level)
//{
//	UserDefault::getInstance()->setIntegerForKey("level", level);
//	this->level = level;
//}