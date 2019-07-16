Page({
  data:{
    clickId:0,
    teacher_pic:[{
      headImg: '/imgs/index/icon_16.jpg',
      teacher_name: "老师A",
      time:"2019.11.11",
      },
      {
        headImg: '/imgs/index/icon_16.jpg',
        teacher_name: "老师A",
        time: "2019.11.11",
      },
      {
        headImg: '/imgs/index/icon_16.jpg',
        teacher_name: "老师A",
        time: "2019.11.11",
      },
      {
        headImg: '/imgs/index/icon_16.jpg',
        teacher_name: "老师A",
        time: "2019.11.11",
      },
      {
        headImg: '/imgs/index/icon_16.jpg',
        teacher_name: "老师A",
        time: "2019.11.11",
      },
    ],
    
  },
  changeColor: function (e) {
    // 设置背景颜色数据
    this.setData({
      clickId:e.currentTarget.id,
    });
  }
})