## 项目

### 功能介绍

外汇牌价看板是一个基于C/S应用程序，用于显示中国银行实时外汇牌价。

### 功能说明

1. 程序启动时，调用BOCRates接口库，取得牌价数据保存为磁盘文件，并按照上图的形式显示；

2. 需要显示的外币种类包括：阿联酋迪拉姆、澳大利亚元、巴西里亚尔、加拿大元、瑞士法郎、丹麦克朗、欧元、英镑、港币、印尼卢比、印度卢比、日元、韩国元、澳门元、林吉特、挪威克朗、新西兰元、菲律宾比索、卢布、沙特里亚尔、瑞典克朗、新加坡元、泰国铢、土耳其里拉、新台币、美元、南非兰特，共计27种；

3. 每页显示7种外汇牌价，一次显示一页，每页显示20秒后启动切换至下一页；

4. 每10分钟从服务器重新获取一次最新的汇率数据并显示，在最左上角显示外汇更新时间。

5. 当汇率接口服务器不能连接时，自动取出最后一次成功获取的汇率数据，并将其重新显示出来。

### 目录说明

```
flag/... 							旗帜图片目录
bmpStruct.h 						bmp位图结构体定义
BOCRates.h 		BOCRates.lib 		汇率库
CBox.h 			CBox.cpp 			定位类，用于确定绝对位置
CPictureBox.h 	CPictureBox.cpp 	图片打印类，用于打印旗帜
PicBase.h 		PicBase.cpp 		图片打印类调用的功能函数
CRatesList.h 	CRatesList.cpp 		汇率类，封装了汇率库
CTextBox.h 		CTextBox.cpp 		文字绘制类
Draw.h 			Draw.cpp 			绘制类，用于绘制头部标题即框线
DrawBase.h 		DrawBase.cpp 		绘制类所调用的功能函数
main.cpp 							主函数
mainBase.h 		mainBase.cpp 		主函数调用的功能函数
//项目配置文件
Project-ExchangeRate.vcxproj
Project-ExchangeRate.vcxproj.filters
Project-ExchangeRate.vcxproj.user
//数据文件，用于保存读取到的汇率
RateData.data
```

## 运行效果

![1585488799441](http://flag0.oss-cn-qingdao.aliyuncs.com/flag0/20200329213322-588620.png)