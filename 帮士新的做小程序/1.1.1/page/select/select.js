Page({

  /**
   * 页面的初始数据
   */
  data: {
    teacher_pic:[{
       headImg: '/imgs/index/icon_16.jpg',
       teacher_name:"老师A",
      },
      { 
        headImg: '/imgs/index/icon_14.jpg',
        teacher_name: "老师B",
      },
      { headImg: '/imgs/index/icon_3.jpg',
        teacher_name: "老师C",
      },
      { headImg: '/imgs/index/icon_4.jpg',
        teacher_name: "老师D",
       }
    ]
  },
  goto_teacherdetail:function(){
    wx.navigateTo({
      url: '../mine/mine'
    })
  }

  
})