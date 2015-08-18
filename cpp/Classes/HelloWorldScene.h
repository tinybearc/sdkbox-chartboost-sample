#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "PluginChartboost/PluginChartboost.h"

class HelloWorld : public cocos2d::Layer, sdkbox::ChartboostListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    cocos2d::ui::Button* _btnVideo;
    cocos2d::ui::Button* _btnReward;
    cocos2d::ui::Text* _txtCoin;
    int _coin;
    
    void onPlayVideo(cocos2d::Ref* pSender);
    void onPlayReward(cocos2d::Ref* pSender);
    
    void onChartboostCached(const std::string& name);
    bool onChartboostShouldDisplay(const std::string& name);
    void onChartboostDisplay(const std::string& name);
    void onChartboostDismiss(const std::string& name);
    void onChartboostClose(const std::string& name);
    void onChartboostClick(const std::string& name);
    void onChartboostReward(const std::string& name, int reward);
    void onChartboostFailedToLoad(const std::string& name, sdkbox::CB_LoadError e);
    void onChartboostFailToRecordClick(const std::string& name, sdkbox::CB_ClickError e);
    void onChartboostConfirmation();
    void onChartboostCompleteStore();
};

#endif // __HELLOWORLD_SCENE_H__
