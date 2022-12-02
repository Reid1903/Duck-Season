#include "MenuInicio.h"
#include <AudioEngine.h>
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* MenuInicio::createScene()
{
    
    return MenuInicio::create();
    
}

void MenuInicio::menuStart(Ref *pSender)
{
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(scene);

}

bool MenuInicio::init()
{
    auto titulo = Label::createWithTTF("Duck Season", "fonts/Marker Felt.ttf", 120);
    titulo -> setPosition(720, 750);
    titulo -> setColor(Color3B::ORANGE);
    this->addChild(titulo,1);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto closeItem = MenuItemImage::create(
                                           "QUIT.png",
                                           "QUIT.png",
                                           CC_CALLBACK_1(MenuInicio::menuCloseCallback, this));
    auto closeItem2 = MenuItemImage::create(
                                           "play.png",
                                           "play.png",
                                           CC_CALLBACK_1(MenuInicio::menuStart, this));

        closeItem->setPosition(Vec2(800,200));
    closeItem2->setPosition(Vec2(800, 500));
        


    auto menu = Menu::create(closeItem,closeItem2, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu,1);
    

    return true;
}



void MenuInicio::menuCloseCallback(Ref* pSender)
{

    
    Director::getInstance()->end();
}


