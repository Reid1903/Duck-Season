#include "HelloWorldScene.h"
#include <AudioEngine.h>

USING_NS_CC;
float  speedP=500;
float speedY=150;
int loco=5;
int pd = 0;
float speedTx=0, speedTy=0;
int punto=0;



 
Scene* HelloWorld::createScene()
{
    
    // 'scene' is an autorelease object
       auto scene = Scene::createWithPhysics();
        
       scene -> getPhysicsWorld () -> setGravity(Vect(0,0));
       // 'layer' is an autorelease object
       auto layer = HelloWorld::create();
       scene -> getPhysicsWorld() ->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
       // add layer as a child to scene
       scene->addChild(layer);
       // return the scene
       return scene;
}





bool HelloWorld::eliminarPato(cocos2d::Touch* toque)
{
    
    
    if(loco>0)
    {
        Sprite* pregunta;
        auto posicionToque = toque->getLocation();
        bool fue=false;        AudioEngine::play2d("Dis.mp3", false, 1.0f);
        
        for(auto i = _patos.begin(); i!=_patos.end(); i++)
        {
            pregunta = *i;
            if(pregunta -> getBoundingBox().containsPoint(posicionToque))
            {
                pregunta->setPosition(Vec2(1400,1000));
                loco=loco+2;
                punto++;
            }
        }
        }
       if(loco==4)
       {
           bala3->setColor(Color3B::BLACK);
       }
        if(loco==2)
        {
            bala2->setColor(Color3B::BLACK);
        }
        
        if(loco==1)
        {
            bala->setColor(Color3B::BLACK);
        
        }
        loco--;
        printf("%d\n",loco);
        return true;
    }
    
    
    
  


void HelloWorld::balas()
{
    bala = Sprite::create("bala.png");
    bala2 = Sprite::create("bala.png");
    bala3 = Sprite::create("bala.png");
    bala->setAnchorPoint(Vec2::ZERO);
    bala2->setAnchorPoint(Vec2::ZERO);
    bala3->setAnchorPoint(Vec2::ZERO);
    bala->setPosition(Vec2(20,30));
    bala2->setPosition(Vec2(40,30));
    bala3->setPosition(Vec2(60,30));
    this->addChild(bala, 1);
    this->addChild(bala2, 1);
    this->addChild(bala3, 1);
    _balas.pushBack(bala);
    _balas.pushBack(bala2);
    _balas.pushBack(bala3);
}




void HelloWorld::inicializarFisica(cocos2d::Sprite* sprite)
{
    
    auto cuerpo = PhysicsBody::createCircle(sprite -> getContentSize().width / 2);
    cuerpo -> setContactTestBitmask(true);
    cuerpo -> setDynamic(true);
    sprite->setPhysicsBody(cuerpo);
}

void HelloWorld::preguntar(float dt)
{
    if(pd == 6)
    {
        unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::agregarPato));
        schedule(CC_SCHEDULE_SELECTOR(HelloWorld::agregarPato), 2, CC_REPEAT_FOREVER, 1.5);
        speedP = 1000;
    }
    
    if(pd == 20)
    {
        unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::agregarPato));
        schedule(CC_SCHEDULE_SELECTOR(HelloWorld::agregarPato), 0.5, CC_REPEAT_FOREVER, 1.5);
        speedP = 1500;
    }
    
    
}

void HelloWorld::agregarPato(float dt)
{
    auto director = Director::getInstance();
    auto tamano = director -> getWinSize();
    if(speedP<=1800)
    {
        speedP=speedP+50;
    }
    Sprite* pato = Sprite::create("pajaro.png");
    pato -> setAnchorPoint(Vec2::ZERO);
    pato -> setPosition(Vec2(0, CCRANDOM_0_1()*400+100));
    inicializarFisica(pato);
    pato->getPhysicsBody()->setVelocity(Vect(speedP, speedY));
    _patos.pushBack(pato);
    this -> addChild(pato,1);
    pd++;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    
    auto muro = PhysicsBody::createEdgeBox(Size(1440,900), PhysicsMaterial(1,0,0), 1);
    auto nodoMuro = Node::create();
    nodoMuro -> setPosition(Point(origin.x+visibleSize.width / 2, 1350));
    nodoMuro->setPhysicsBody(muro);
    nodoMuro -> setTag(12);
    this -> addChild(nodoMuro);
    auto escuchador = EventListenerTouchOneByOne().create();
    escuchador->onTouchBegan = CC_CALLBACK_1(HelloWorld::eliminarPato, this);
    escuchador->onTouchMoved = [] (cocos2d::Touch* toque, cocos2d::Event * evento) {return true;};
    escuchador->onTouchEnded = [] (cocos2d::Touch* toque, cocos2d::Event * evento) {return true;};
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(escuchador, this);
    balas();
                                           
    

    if ( !Scene::init())
    {
        return false;
    }
    
    auto SpriteFondo= Sprite::create("19872298.jpg");
    SpriteFondo -> setAnchorPoint(Vec2(0,0));
    SpriteFondo -> setPosition(0,0);
    addChild(SpriteFondo, 0);
    
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
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
    score = Label::createWithTTF("Score: " + std::to_string(punto), "fonts/Marker Felt", 60);
    score -> setAnchorPoint(Vec2(0,0));
    score -> setPosition(1200, 700);
    schedule(CC_SCHEDULE_SELECTOR(HelloWorld::agregarPato), 6, CC_REPEAT_FOREVER, 1.5);
    schedule(CC_SCHEDULE_SELECTOR(HelloWorld::preguntar), 6, CC_REPEAT_FOREVER, 0);
    
  
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
}
