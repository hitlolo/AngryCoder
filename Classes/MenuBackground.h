#ifndef ANGRY_CODER_MENU_BACK
#define ANGRY_CODER_MENU_BACK

#include "cocos2d.h"
#include "GameData.h"
USING_NS_CC;


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