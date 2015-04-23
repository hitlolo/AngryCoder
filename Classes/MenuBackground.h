#ifndef ANGRY_CODER_MENU_BACK
#define ANGRY_CODER_MENU_BACK

#include "cocos2d.h"
#include "GameData.h"
#include "ui/CocosGUI.h"//UI相关的头文件 
#include"cocostudio/CocoStudio.h"//
USING_NS_CC;
using namespace cocostudio::timeline;


class MenuBackground :public Layer
{
public:
	CREATE_FUNC(MenuBackground);
	virtual bool init() override;

private:
	void initBackGroundFromTMX();
	void initFloor(TMXObjectGroup* floors);
	void initItems(TMXObjectGroup* items);

private:
	TMXTiledMap    *m_tmxMap;
};




#endif