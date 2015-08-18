
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {

        this._super();
        this._coin = 0;
        var self = this;

        var size = cc.winSize;

        var ui = ccs.load(res.MainScene_json);
        this.addChild(ui.node);

        this.btnVideo = ui.node.getChildByName("btnVideo");
        this.btnVideo.setEnabled(false);
        this.btnVideo.addClickEventListener(function(){
            sdkbox.PluginChartboost.show("Default");
        });

        this.btnReward = ui.node.getChildByName("btnReward");
        this.btnReward.setEnabled(false);
        this.btnReward.addClickEventListener(function(){
            sdkbox.PluginChartboost.show("Level Complete");
        });

        this._txtCoins = ui.node.getChildByName("txtCoins");

        sdkbox.PluginChartboost.init();
        sdkbox.PluginChartboost.cache("Default");
        sdkbox.PluginChartboost.cache("Level Complete");
        sdkbox.PluginChartboost.setListener({
            onChartboostCached : function (name) 
            {
                cc.log("onChartboostCached " + name) 
                self.btnVideo.setEnabled(true);
                self.btnReward.setEnabled(true);
            },
            onChartboostShouldDisplay : function (name) 
            {
                cc.log("onChartboostShouldDisplay " + name); 
                return true; 
            },
            onChartboostDisplay : function (name) { cc.log("onChartboostDisplay " + name) },
            onChartboostDismiss : function (name) { cc.log("onChartboostDismiss " + name) },
            onChartboostClose : function (name) { cc.log("onChartboostClose " + name) },
            onChartboostClick : function (name) { cc.log("onChartboostClick " + name) },
            onChartboostReward : function (name, reward) 
            {
                cc.log("onChartboostReward " + name + " reward " + reward);
                self._coin ++;
                self._txtCoins.setString(self._coin);
            },
            onChartboostFailedToLoad : function (name, e) { cc.log("onChartboostFailedToLoad " + name + " load error " + e) },
            onChartboostFailToRecordClick : function (name, e) { cc.log("onChartboostFailToRecordClick " + name + " click error " + e) },
            onChartboostConfirmation : function () { cc.log("onChartboostConfirmation") },
            onChartboostCompleteStore : function () { cc.log("onChartboostCompleteStore") },
        });

        return true;
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

