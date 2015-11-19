
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

-- MainScene.RESOURCE_FILENAME = "MainScene.csb"

function MainScene:onCreate()

    self._coin = 0

    self.btnVideo = cc.MenuItemFont:create("btnVideo"):onClicked(function()
        sdkbox.PluginChartboost:show("Default")
    end)
    self.btnVideo:setEnabled(false)

    self.btnReward = cc.MenuItemFont:create("btnReward"):onClicked(function()
        sdkbox.PluginChartboost:show("Level Complete");
    end)
    self.btnReward:setEnabled(false)

    local menu = cc.Menu:create(self.btnVideo, self.btnReward)
        :move(display.cx, display.cy)
        :addTo(self)
        :alignItemsVerticallyWithPadding(20)

    local txt = cc.Label:createWithSystemFont("Coins:", "Arial", 38)
        :move(display.width - 200, display.height - 100)
        :addTo(self)

    self._txtCoins = cc.Label:createWithSystemFont("0", "Arial", 38)
        :move(txt:getPositionX() + 70, txt:getPositionY())
        :addTo(self)

    sdkbox.PluginChartboost:init()
    sdkbox.PluginChartboost:cache("Default")
    sdkbox.PluginChartboost:cache("Level Complete")
    sdkbox.PluginChartboost:setListener(function(args)
        if "onChartboostCached" == args.func then
            print("onChartboostCached " .. args.name) 
            self.btnVideo:setEnabled(true)
            self.btnReward:setEnabled(true)
        elseif "onChartboostShouldDisplay" == args.func then
            print("onChartboostShouldDisplay " .. args.name)
            return true
        elseif "onChartboostDisplay" == args.func then
            print("onChartboostDisplay " .. args.name)
        elseif "onChartboostDismiss" == args.func then
            print("onChartboostDismiss " .. args.func)
        elseif "onChartboostClose" == args.func then
            print("onChartboostClose " .. args.func)
        elseif "onChartboostClick" == args.func then
            print("onChartboostClick " .. args.func)
        elseif "onChartboostReward" == args.func then
            print("onChartboostReward " .. args.func .. " reward " .. args.reward)
            self._coin = self._coin + 1
            self._txtCoins:setString(self._coin)
        elseif "onChartboostFailedToLoad" == args.func then
            print("onChartboostFailedToLoad " .. args.name .. " load error " .. args.e)
        elseif "onChartboostFailToRecordClick" == args.func then
            print("onChartboostFailToRecordClick " .. args.name .. " click error " .. args.e)
        elseif "onChartboostConfirmation" == args.func then
            print("onChartboostConfirmation")
        elseif "onChartboostCompleteStore" == args.func then
            print("onChartboostCompleteStore")
        end
    end)
end

return MainScene
