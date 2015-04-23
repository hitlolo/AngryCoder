#include "GameLogo.h"


Scene* GameLogo::createScene()
{
	auto scene = Scene::create();
	auto logo = GameLogo::create();
	scene->addChild(logo);
	return scene;
}

bool GameLogo::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//init

	startLoading();

	return true;
}

void GameLogo::startLoading()
{
	this->showLogoAndLoad();
}

void GameLogo::showLogoAndLoad()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originPoint = Director::getInstance()->getVisibleOrigin();
	auto logo = Sprite::create("logo.png");
	logo->setPosition(originPoint.x + visibleSize.width / 2, originPoint.y + visibleSize.height / 2);
	this->addChild(logo);

	logo->setName("logo");
	logo->setOpacity(10);
	logo->runAction(Sequence::create(FadeTo::create(2.0f, 255), CallFunc::create(CC_CALLBACK_0(GameLogo::loadRes, this)), nullptr));
}

void  GameLogo::loadRes()
{
	this->loadItemPng();
	this->loadHeroPng();
//	this->loadMusicAndEffects();
	this->overLoading();
}



void  GameLogo::loadItemPng()
{
	Director::getInstance()->getTextureCache()->addImageAsync("spritesheet.png", CC_CALLBACK_1(GameLogo::loadItemFramesAfterPNGOver, this));
}

void GameLogo::loadHeroPng()
{
	Director::getInstance()->getTextureCache()->addImageAsync("herosheet.png", CC_CALLBACK_1(GameLogo::loadHeroFramesAfterPNGOver, this));
}


void GameLogo::loadItemFramesAfterPNGOver(Texture2D* texture)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spritesheet.plist", texture);
}

void GameLogo::loadHeroFramesAfterPNGOver(Texture2D* texture)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("herosheet.plist", texture);
}
//void GameLogo::loadMusicAndEffects()
//{
//	//	GameSound::getInstance()->preLoad();
//}

void GameLogo::overLoading()
{

	CallFunc* startGame = CallFunc::create(std::bind(&GameLogo::startGame, this));
	this->getChildByName("logo")->runAction(Sequence::create(FadeOut::create(2.0f), startGame, nullptr));
}


void GameLogo::startGame()
{
	GameController::getInstance()->goState(GAME_STATE::MENU);
}
