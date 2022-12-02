//
//  pausa.cpp
//  DuckHunting
//
//  Created by Mirna Pons Jiménez on 02/12/22.
//

#include "pausa.h"

USING_NS_CC;

Scene* pausa::createScene()
{
    return pausa::create();
}



bool pausa::init()
{
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto titulo = Label::createWithTTF("Pause", "fonts/Marker Felt.ttf", 120);
    titulo -> setPosition(720, 450);
    titulo -> setColor(Color3B::WHITE);
    this->addChild(titulo,1);
    auto listenerKeyboard = EventListenerKeyboard().create();
    listenerKeyboard->onKeyPressed = CC_CALLBACK_2(pausa::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, this);
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(pausa::menuCloseCallback, this));
    
    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
    }
    else
    {
        
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    
    return true;
}

bool pausa::onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event *event)
{

    
    if (key == EventKeyboard::KeyCode::KEY_ESCAPE){
        Director::getInstance()->popScene();
        
    }
        
}


void pausa::menuCloseCallback(Ref* pSender)
{

    
    Director::getInstance()->end();
}


