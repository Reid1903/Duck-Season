//
//  ronda2.h
//  DuckHunting
//
//  Created by Mirna Pons Jiménez on 30/11/22.
//

#ifndef ronda2_h
#define ronda2_h

#include "cocos2d.h"

class ronda2 : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene(int dt);
    
    virtual bool init();
    
   
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void update(float dt);
    
    
    CREATE_FUNC(ronda2);

    
private:
    cocos2d::Sprite* _SP;
    cocos2d::Sprite* bala;
    cocos2d::Sprite* bala2;
    cocos2d::Sprite* bala3;
  
    cocos2d::Vector<cocos2d::Sprite*> _patos;
    cocos2d::Vector<cocos2d::Sprite*> _enemigo;
    cocos2d::Vector<cocos2d::Sprite*> _balas;
    cocos2d::Label* score;
    float  speedP=500;
    float speedY=150;
    float  speedPf=800;
    float speedYf=150;
    int loco=5;
    int pd = 0;
    float speedTx=0, speedTy=0;
    void agregarPato(float);
    void preguntar(float);
    void inicializarFisica(cocos2d::Sprite* sprite);
    void inicializarFisica2(cocos2d::Sprite* sprite);
    void toque();
    bool eliminarPato(cocos2d::Touch* toque);
    bool eliminarFenix(cocos2d::Touch* toque);
    void zero(float);
    void balas();
    bool onKeyPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event* event);
    void agregarEnemigo(float);
};

#endif /* ronda2_h */
