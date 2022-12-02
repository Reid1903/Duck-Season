//
//  pausa.h
//  DuckHunting
//
//  Created by Mirna Pons Jiménez on 02/12/22.
//

#ifndef pausa_h
#define pausa_h

#include "cocos2d.h"

class pausa : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
     
    bool onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    CREATE_FUNC(pausa);
};
#endif /* pausa_h */
