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
    list:[]
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
    //this.onRequest();
  },

  onRequest:function(){
    var that=this;
    wx.request({
      url: 'http://jsonplaceholder.typicode.com/users',
      method:"GET",
      header:{
        'Content-Type':'json'
      },
      success:function(res){
        console.log(res.data);
        var date=res.data;
        that.setData({
          list:date
        })
      },
      fail:function(){
        console.log("接口调用失败")
      }
    })
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
    var that = this;//把this对象复制到临时变量that
    wx.request({
      url:'http://jsonplaceholder.typicode.com/users',
      data:{  
      },
      header:{
        'content-type':'application/json'//默认值
      },
      success:function(res){
        console.log(res.data)
        console.log(res.data);
        this.userData = res.data; //无效不能实时的渲染到页面
        that.setData({ userData: res.data });//和页面进行绑定可以动态的渲染到页面
      }
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

