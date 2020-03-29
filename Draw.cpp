#include "Draw.h"
#include "DrawBase.h"
#include <graphics.h>

Draw::Draw()
{

}

Draw::Draw(int width, int height, int backGround)
{
	_width = width;
	_height = height;
	_backGround = backGround;
	inItBackGround(_width, _height, _backGround);//初始化背景面板,RGB(255, 255, 255)
}


void Draw::DrawInit()//初始化
{
	cleardevice();//用背景色清空屏幕
	printinItWord(_width,_height);//输出外汇牌价
	_lineHeight = _height / 9;
	printLine(_lineHeight, _width);//输出红线
}

int Draw::GetTop()
{
	return _lineHeight + 20;
}