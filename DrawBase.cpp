#include "DrawBase.h"
#include "CTextBox.h"
#include <graphics.h>

void inItBackGround(int width, int height, int backGround)//初始化背景面板
{
	initgraph(width, height);
	setbkcolor(backGround);//设置背景色为白色
}

void printinItWord(size_t Width, size_t Height)
{
	int start = Width / 2 - 100;
	CTextBox txt;
	txt.SetFontFamily("微软雅黑");
	txt.SetFontSize(35);
	txt.SetPosition(start,10);
	txt.SetValue("外  汇  牌  价");
	txt.Display();
	txt.SetFontSize(18);
	txt.SetPosition(start + 30, Height / 12);
	txt.SetValue("EXCHANGE RATE");
	txt.Display();
}

void vLine(int xStart, int y, int xEnd, int color)
{
	for (int x = xStart; x <= xEnd; x++)
	{
		putpixel(x, y, color);
	}
}

void printLine(int h,size_t Width)
{
	//左红线

	for (size_t i = 0; i < 5; i++)
	{
		vLine(10, h +i, (Width - 20) / 3, RGB(192, 13, 61));
	}

	//中灰线
	for (size_t i = 0; i < 5; i++)
	{
		vLine((Width - 20) / 3, h + i, (Width - 20) / 3 *2, RGB(222, 222, 222));
	}
	//右红线
	for (size_t i = 0; i < 5; i++)
	{
		vLine((Width - 20) / 3 * 2, h + i,Width-10, RGB(192, 13, 61));
	}
}
