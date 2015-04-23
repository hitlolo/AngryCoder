#ifndef ANGRY_CODER_DATA
#define ANGRY_CODER_DATA

#define USING_NS_CCD                     using namespace CocosDenshion
#define USING_NS_UI                      using namespace ui

#define CC_SYNTHESIZE_SETONLY(varType, varName, funName)\
protected: varType varName;\
public: virtual void set##funName(varType var){ varName = var; }

#define GET_BUTTON(varRoot,varName)\
varName = dynamic_cast<ui::Button*>(varRoot->getChildByName(#varName))

#define GET_CHECKBOX(varRoot,varName)\
varName = dynamic_cast<ui::CheckBox*>(varRoot->getChildByName(#varName))

#define CENTER Point(Director::getInstance()->getVisibleSize().width/2,Director::getInstance()->getVisibleSize().height/2)


typedef enum class game_state
{
	LOGO = 0,
	MENU,
	GAME,
	OVER
}GAME_STATE;



#endif