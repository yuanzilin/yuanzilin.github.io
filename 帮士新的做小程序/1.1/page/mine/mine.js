var app = getApp();
var server = require('../../utils/server');
// var template = require('../../template/template.js');
Page({
	data: {
    headImg: '/imgs/index/icon_16.jpg',
    name:'老师A',
    occupation:'副教授',
    mail:'xpdu@buaa.edu.cn',
    intro:'主要研究方向：软件工程、面向领域的应用建模、大数据分析、知识图谱构建、敏捷开发。主持或参与政府重大信息系统研发或咨询20余项。',
    tabbar: {}
  },

  onLoad: function (options) {
    // 页面初始化 options为页面跳转所带来的参数

    //调用函数
    app.editTabBar();
  },
  onReady: function () {
    // 页面渲染完成
  },
  onShow: function () {
    // 页面显示
  },
  onHide: function () {
    // 页面隐藏
  },
  onUnload: function () {
    // 页面关闭
  },
  
  // onLoad: function () {
  //   template.tabbar("tabBar", 1, this)//0表示第一个tabbar
  // },
  
	goto: function () {
    wx.switchTab({
      url: '../index/index'

    })
  }
});

