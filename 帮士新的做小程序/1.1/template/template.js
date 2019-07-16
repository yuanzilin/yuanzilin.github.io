//初始化数据
function tabbarinit() {
  return [
    {
      "current": 0,
      "pagePath": "/page/index/index",
      "iconPath": "/imgs/tabBar/mine_2.png",
      "selectedIconPath": "/imgs/tabBar/mine_1.png",
      "text": "首页"
    },
    {
      "current": 0,
      "pagePath": "/page/select/select",
      "iconPath": "/imgs/tabBar/mine_2.png",
      "selectedIconPath": "/imgs/tabBar/mine_1.png",
      "text": "导师选择"

    },
    {
      "current": 0,
      "pagePath": "/page/thinking/thinking",
      "iconPath": "/imgs/tabBar/mine_2.png",
      "selectedIconPath": "/imgs/tabBar/mine_1.png",
      "text": "心得感悟"
    }
  ]

}
//tabbar 主入口
function tabbarmain(bindName = "tabdata", id, target) {
  var that = target;
  var bindData = {};
  var otabbar = tabbarinit();
  otabbar[id]['iconPath'] = otabbar[id]['selectedIconPath']//换当前的icon
  otabbar[id]['current'] = 1;
  bindData[bindName] = otabbar
  that.setData({ bindData });
}

module.exports = {
  tabbar: tabbarmain
}
