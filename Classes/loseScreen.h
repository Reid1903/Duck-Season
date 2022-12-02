//
//  loseScreen.h
//  DuckHunting
//
//  Created by Mirna Pons Jiménez on 02/12/22.
//

#ifndef loseScreen_h
#define loseScreen_h

#include "cocos2d.h"

class lose : public cocos2d::Scene
{
public:
    
    static cocos2d::Scene* createScene(int dt);
    
    virtual bool init();
    
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
     
    bool onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);

    CREATE_FUNC(lose);
    
};



#endif /* loseScreen_h */
