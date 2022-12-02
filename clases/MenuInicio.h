



#ifndef MenuInicio_h
#define MenuInicio_h
#include "cocos2d.h"


class MenuInicio : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuStart(cocos2d::Ref* pSender);
    
    
    
    CREATE_FUNC(MenuInicio);

  
    
    
};


#endif /* MenuInicio_h */
