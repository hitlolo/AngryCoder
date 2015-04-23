#include "MenuBackground.h"


bool MenuBackground::init()
{
	if (!Layer::init())
	{
		return false;
	}

	this->initBackGroundFromTMX();

	return true;
}

void MenuBackground::initBackGroundFromTMX()
{
	m_tmxMap = TMXTiledMap::create("menu.tmx");

	auto floors = m_tmxMap->getObjectGroup("Floors");
	auto items = m_tmxMap->getObjectGroup("Items");

	this->initFloor(floors);
	this->initItems(items);

	this->addChild(m_tmxMap);

	
	Node *rootNode = CSLoader::createNode("Node.csb");//传入Studio2.x的资源路径 
	//m_tmxMap->addChild(rootNode,2);//假设this是即将显示的scene 
	auto sp = Sprite::create();
	sp->addChild(rootNode);
	//加载动画： 
	ActionTimeline *action = CSLoader::createTimeline("Node.csb");
	rootNode->runAction(action);
	//sp->runAction(action);
	action->gotoFrameAndPlay(0, 20, true);
	m_tmxMap->addChild(sp, 2);
}

void MenuBackground::initFloor(TMXObjectGroup* floors)
{
	ValueVector objectsVector = floors->getObjects();
	for (auto def : objectsVector)
	{
		auto floorDef = def.asValueMap();
		std::string filename = floorDef["png"].asString();
		float positionX		 = floorDef["x"].asFloat();
		float positionY		 = floorDef["y"].asFloat();
		int   z				 = floorDef["zOrder"].asInt();
		Sprite*   floor      = Sprite::createWithSpriteFrameName(filename.c_str());
		
		floor->setPosition(positionX, positionY);
		floor->setZOrder(z);
		floor->setAnchorPoint(Vec2(0, 0));
		m_tmxMap->addChild(floor);
	}
}

void MenuBackground::initItems(TMXObjectGroup* items)
{
	ValueVector objectsVector = items->getObjects();
	for (auto def : objectsVector)
	{
		auto itemDef = def.asValueMap();
		std::string filename = itemDef["png"].asString();
		float positionX      = itemDef["x"].asFloat();
		float positionY      = itemDef["y"].asFloat();
		int   z              = itemDef["zOrder"].asInt();
		Sprite*   item = Sprite::createWithSpriteFrameName(filename.c_str());

		item->setPosition(positionX, positionY);
		item->setZOrder(z);
		item->setAnchorPoint(Vec2(0, 0));
		m_tmxMap->addChild(item);
	}
}