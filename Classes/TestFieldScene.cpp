#include "TestFieldScene.h"
#include "Character.h"
#include "UserInput.h"
#include "ScreenParticle.h"

TestFieldScene* TestFieldScene::createScene() 
{
	TestFieldScene *pRet = new TestFieldScene();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
};

bool TestFieldScene::init() 
{
	if (!Scene::init())return false;

	Layer* la = LayerColor::create(Color4B::WHITE);
	addChild(la);

	Sprite* background = Sprite::create("background.png");
	background->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	background->setPosition(0, 0);
	la->addChild(background,LAYER_BACKGROUND);

	BlendFunc negativeBlend = { GL_ONE_MINUS_DST_COLOR, GL_ZERO };
	background->setBlendFunc(negativeBlend);

	//UserInput* controller=UserInput::createPlayer();
	//controller->setVisible(false);
	//la->addChild(controller,LAYER_UI);

	//Character* character=Character::create(PARAMETER());
	//character->setVisible(false);
	//la->addChild(character, LAYER_CHARACTER);

	//controller->playerCharacter = character;

	ParticleLauncher* PLB = ParticleLauncher::create(&this->_position, 4);
	PLB->setPosition(designResolutionSize.width*0.5f, designResolutionSize.height*0.5f);
	la->addChild(PLB, LAYER_BACKPARTICLE);

	//ParticleLauncher* PL = ParticleLauncher::create(&this->_position, 5);
	//PL->setPosition(designResolutionSize.width*0.5f, designResolutionSize.height*0.5f);
	//la->addChild(PL, LAYER_PARTICLE);

	//DebugLogOutPut* debug = DebugLogOutPut::create();
	//la->addChild(debug, LAYER_UI);
	//debug->setVisible(false);
	//debug->setStringPlayer(character);


		//�^�b�`����
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// �Ώۂ̃C�x���g�����s���ꂽ��A���ʂ̃C�x���g�͔�������Ȃ�����
	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(TestFieldScene::onTouchBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
};


bool TestFieldScene::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	//�Q�[���̏I��
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
	return true;
};
