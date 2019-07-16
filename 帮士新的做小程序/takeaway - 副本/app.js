var server = require('./utils/server');
App({
	
	onShow: function () {
		console.log('App Show')
	},
	onHide: function () {
		console.log('App Hide')
	},

  onLaunch: function () {
    //调用API从本地缓存中获取数据
    var logs = wx.getStorageSync('logs') || []
    logs.unshift(Date.now())
    wx.setStorageSync('logs', logs)
  },
  getUserInfo: function (cb) {
    var that = this
    if (this.globalData.userInfo) {
      typeof cb == "function" && cb(this.globalData.userInfo)
    } else {
      //调用登录接口
      wx.login({
        success: function () {
          wx.getUserInfo({
            success: function (res) {
              that.globalData.userInfo = res.userInfo
              typeof cb == "function" && cb(that.globalData.userInfo)
            }
          })
        }
      })
    }
  },

  editTabBar: function () {
    var tabbar = this.globalData.tabbar,
      currentPages = getCurrentPages(),
      _this = currentPages[currentPages.length - 1],
      pagePath = _this.__route__;
    (pagePath.indexOf('/') != 0) && (pagePath = '/' + pagePath);
    for (var i in tabbar.list) {
      tabbar.list[i].selected = false;
      (tabbar.list[i].pagePath == pagePath) && (tabbar.list[i].selected = true);
    }
    _this.setData({
      tabbar: tabbar
    });
  },
  globalData: {
    userInfo: null,
    tabbar: {
      
      color: "#878787",
      selectedColor: "#000",
      borderStyle: "black",
      backgroundColor: "#fcfcfc",
      list: [
        {
          pagePath: "/page/index/index",
          text: "首页",
          iconPath: "/imgs/tabBar/mine_2.png",
          selectedIconPath: "/imgs/tabBar/mine_2.png",
          selected: true
        },
        {
          pagePath: "/page/select/select",
          text: "导师选择",
          iconPath: "/imgs/tabBar/mine_2.png",
          selectedIconPath: "/imgs/tabBar/mine_2.png",
          selected: false
        },
        {
          pagePath: "/page/thinking/thinking",
          text: "心得感悟",
          iconPath: "/imgs/tabBar/mine_2.png",
          selectedIconPath: "/imgs/tabBar/mine_2.png",
          selected: false
        }
      ],
      position: "bottom"
    }
  }
})
