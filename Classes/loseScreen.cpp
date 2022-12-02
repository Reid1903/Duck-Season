//
//  loseScreen.cpp
//  DuckHunting
//
//  Created by Mirna Pons Jiménez on 02/12/22.
//

#include "loseScreen.h"
#include "MenuInicio.h"

USING_NS_CC;


int contador;
Scene* lose::createScene(int dt)
{
    contador=dt;
    return lose::create();
}



bool lose::init()
{
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto titulo = Label::createWithTTF("Your Score: " + std::to_string(contador),"fonts/Marker Felt.ttf", 120);
    titulo -> setPosition(720, 450);
    titulo -> setColor(Color3B::WHITE);
    this->addChild(titulo,1);
   
    auto closeItem = MenuItemImage::create(
                                           "back.png",
                                           "back.png",
                                           CC_CALLBACK_1(lose::menuCloseCallback, this));

        closeItem->setPosition(Vec2(700,120));
    

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    
    return true;
}




void lose::menuCloseCallback(Ref* pSender)
{
    auto scene = MenuInicio::createScene();
    Director::getInstance()->replaceScene(scene);
}


