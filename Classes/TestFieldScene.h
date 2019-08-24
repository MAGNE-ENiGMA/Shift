#ifndef __TEST_FIELD_SCENE_H__
#define __TEST_FIELD_SCENE_H__

#include "cocos2d.h"
#include "DebugLogOutPut.h"

using namespace cocos2d;

#define LAYER_UI 5
#define LAYER_CHARACTER 4
#define LAYER_PARTICLE 3
#define LAYER_BACKGROUND 2
#define LAYER_BACKPARTICLE 1
#define LAYER_HIDEITEM 0

class TestFieldScene :public Scene {
public:
	static TestFieldScene* createScene();
	bool init();

	//画面を閉じる
	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

};


#endif // !__TEST_FIELD_H__
