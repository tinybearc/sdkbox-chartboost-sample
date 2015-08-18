#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}

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
    
    FileUtils::getInstance()->addSearchPath("res");
    
    sdkbox::PluginChartboost::init();
    sdkbox::PluginChartboost::cache(sdkbox::CB_Location_Default);
    sdkbox::PluginChartboost::cache(sdkbox::CB_Location_LevelComplete);
    sdkbox::PluginChartboost::setListener(this);
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
    
    _btnVideo = rootNode->getChildByName<ui::Button*>("btnVideo");
    _btnVideo->addClickEventListener(CC_CALLBACK_1(HelloWorld::onPlayVideo, this));
    _btnVideo->setEnabled(false);
    
    _btnReward = rootNode->getChildByName<ui::Button*>("btnReward");
    _btnReward->addClickEventListener(CC_CALLBACK_1(HelloWorld::onPlayReward, this));
    _btnReward->setEnabled(false);
    
    _txtCoin = rootNode->getChildByName<ui::Text*>("txtCoins");
    
    auto btnClose = rootNode->getChildByName<ui::Button*>("btnClose");
    btnClose->addClickEventListener(CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    return true;
}

/**
 * Button callback
 */

void HelloWorld::onPlayVideo(Ref *pSender)
{
    sdkbox::PluginChartboost::show(sdkbox::CB_Location_Default);
}

void HelloWorld::onPlayReward(Ref* sender)
{
    sdkbox::PluginChartboost::show(sdkbox::CB_Location_LevelComplete);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

/**
 * Chartboost callbacks
 */
void HelloWorld::onChartboostCached(const std::string& name)
{
    _btnReward->setEnabled(true);
    _btnVideo->setEnabled(true);
}

bool HelloWorld::onChartboostShouldDisplay(const std::string& name)
{
    CCLOG("Should display: %s", name.c_str());
    return true;
}

void HelloWorld::onChartboostDisplay(const std::string& name)
{
    CCLOG("on display: %s", name.c_str());
}

void HelloWorld::onChartboostDismiss(const std::string& name)
{
    CCLOG("on dismiss: %s", name.c_str());
}

void HelloWorld::onChartboostClose(const std::string& name)
{
    CCLOG("on close: %s", name.c_str());
}

void HelloWorld::onChartboostClick(const std::string& name)
{
    CCLOG("on click: %s", name.c_str());
}

void HelloWorld::onChartboostReward(const std::string& name, int reward)
{
    CCLOG("on reward: %s", name.c_str());
    
    _coin += reward;
    _txtCoin->setString(to_string(_coin));
}

void HelloWorld::onChartboostFailedToLoad(const std::string& name, sdkbox::CB_LoadError e)
{
    CCLOG("on failed to load: %s", name.c_str());
}

void HelloWorld::onChartboostFailToRecordClick(const std::string& name, sdkbox::CB_ClickError e)
{
    CCLOG("on failed to record click: %s", name.c_str());
}

void HelloWorld::onChartboostConfirmation()
{
    CCLOG("on confirmation");
}

void HelloWorld::onChartboostCompleteStore()
{
    CCLOG("on complete store");
}






