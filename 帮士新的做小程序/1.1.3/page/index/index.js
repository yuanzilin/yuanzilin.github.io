var app = getApp();
var template = require('../../template/template.js');
Page({
	data:{
    listDatas: [{
      headImg: '/imgs/index/icon_15.jpg',
      name: '老师A',
      desc: '内容内容内内容内容内容内容内容内容容内容内容',
      content: '内容内容内内容内容内容内容内容内容容内容内容',
      time: '预约时间',
    }, ],
    name:'张小明',
    book_sum:1,
    book_wait:1,
    book_commit:1,
    items1: [
      {checked:"{{true}}"},{},{},{},{},
    ],
    items2: [
      {},{},{},{},{},
    ],
    items3: [
      {},{},{},{},
    ],
    
    testlistDatas:[],
    
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
    template.tabbar("tabBar", 0, this);//0表示第一个tabbar
    //要是想要实现页面加载后就直接显示预约时间，只需要把下面那个myRequest函数的所有代码复制到这里就可以了
  },

  myRequest:function(){
    var that=this;
    wx.request({
      url:'https://easy-mock.com/mock/5d27643c6f219a537bb21467/example/me', 
      method:"GET",
      header:{
        'Content-Type':'json'
      },
      success:function(res){
        console.log(res.data);
        var data=res.data;
        that.setData({
          testlistDatas:data
        })
      },
      fail:function(){
        console.log("通信失败")
      }
    })
  },
  
  //事件处理函数
  bindViewTap:function(){
    wx.navigateTo({
      url:'../logs/logs'
    })
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },
  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

});

