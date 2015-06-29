#include "HelloWorldScene.h"
#include "CCell.h"
USING_NS_CC;
#include "CCoster.h"

HelloWorld::HelloWorld():_rotate(0),_flag(true){}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    _rotate = 30;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menuitem = MenuItemFont::create("spin", [this](Ref *sender)
                                         {
                                             CCoster::popCosterLayer();
                                         });
    
    menuitem->setPosition(Vec2(origin.x + menuitem->getContentSize().width,
                               origin.y + menuitem->getContentSize().height));
    auto menu = Menu::create(closeItem, menuitem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
//    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
//    
//    // position the label on the center of the screen
//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height));
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);
//
//    // add "HelloWorld" splash screen"
//    _wheel = Sprite::create("wheel.png");
//
//    // position the sprite on the center of the screen
//    _wheel->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//    // add the sprite as a child to this layer
//    this->addChild(_wheel, 0);
//    
//    _wheel->setScale(0.6f);
//    
//    
//    auto ce = CCell::create("1w.png");
//    this->addChild(ce);
//    ce->setPosition(100,100);
//    ce->setLight(true);
    
    
    return true;
}

float allRo = 0;
float per = 5;
void HelloWorld::runWheel(float dt)
{
    _wheel->setRotation(_wheel->getRotation()+per);
    allRo+=per;
    
    if (allRo<=360)
    {
        dt-=0.02;
        if (per<=10) {
            per += 1;
        }
        if (dt<=0.05)
        {
            dt=0.05;
        }
    }
    
    
    unschedule(schedule_selector(HelloWorld::runWheel));
    schedule(schedule_selector(HelloWorld::runWheel), dt);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
