#include "GameMenu.h"

bool GameMenu::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	this->addBackgroundLayer();
	this->addButtonLayer();
	return true;
}

void GameMenu::addBackgroundLayer()
{
	auto background = MenuBackground::create();
	this->addChild(background);
}

void GameMenu::addButtonLayer()
{

}