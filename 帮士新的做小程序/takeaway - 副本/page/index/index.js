var app = getApp();
var template = require('../../template/template.js');
Page({
	data:{
    listDatas: [{
      headImg: '/imgs/index/icon_15.jpg',
      name: '老师A',
      desc: '内容内容内容内容内容',
      time: '预约时间'
    }, {
      headImg: '/imgs/index/icon_15.jpg',
      name: '老师B',
        desc: '内容内容内容内容内容',
      time: '预约时间'
    },],
    name:'张小明',
    book_sum:1,
    book_wait:1,
    book_commit:1,
    items: [
      { name: ''},
      { name: '' },
      { name: '' },
      { name: '' },
      { name: '' },
    ],
    items2: [
      { name: '' },
      { name: '' },
      { name: '' },
      { name: '' },
    ],
    'message':'message-string',
    'userData':[{id:"id1",name:"name1"},{id:"id2",name:"name2"}]
  },
  onShow: function () {
    app.editTabBar();    //显示自定义的底部导航
  },
  tologs: function () {     //按钮的绑定事件，点击跳转至logs
    wx.redirectTo({
      url: '../mine/mine',
    })
  },
  /*
    生命周期函数：监听页面加载
  */
  onLoad: function () {
    template.tabbar("tabBar", 0, this)//0表示第一个tabbar
    this.onRequest();
  },
  
  nextPage:function(){
    console.log("下拉触发该函数");
  },
  //事件处理函数
  bindViewTap:function(){
    wx.navigateTo({
      url:'../logs/logs'
    })
  },

  requesetFunc:function(){
    wx.request({
      url: 'https://yuanzilin.github.io/',
      method: 'GET',
      header: {
        'Content-Type': 'json' // 使用这个能正常获取数据
      },
      success: function (res) {
        console.log(res);
      }
    })
  },

  send:function(){
    wx.request({
      url:'https://easy-mock.com/mock/5d27643c6f219a537bb21467/example/me',
      data:{  
      },
      header:{
        'content-type':'application/json'//默认值
      },
      success:function(res){
        console.log(res.data)
        
      }
    })
  }
});

