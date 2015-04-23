#ifndef ANGRY_CODER_MENU
#define ANGRY_CODER_MENU

#include "cocos2d.h"

#include "MenuBackground.h"

USING_NS_CC;

class GameMenu:public Scene
{
public:
	CREATE_FUNC(GameMenu);
	virtual bool init() override;
private:
	void addBackgroundLayer();
	void addButtonLayer();
};





#endif