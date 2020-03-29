#include "DrawBase.h"
#include "CTextBox.h"
#include <graphics.h>

void inItBackGround(int width, int height, int backGround)//��ʼ���������
{
	initgraph(width, height);
	setbkcolor(backGround);//���ñ���ɫΪ��ɫ
}

void printinItWord(size_t Width, size_t Height)
{
	int start = Width / 2 - 100;
	CTextBox txt;
	txt.SetFontFamily("΢���ź�");
	txt.SetFontSize(35);
	txt.SetPosition(start,10);
	txt.SetValue("��  ��  ��  ��");
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
	//�����

	for (size_t i = 0; i < 5; i++)
	{
		vLine(10, h +i, (Width - 20) / 3, RGB(192, 13, 61));
	}

	//�л���
	for (size_t i = 0; i < 5; i++)
	{
		vLine((Width - 20) / 3, h + i, (Width - 20) / 3 *2, RGB(222, 222, 222));
	}
	//�Һ���
	for (size_t i = 0; i < 5; i++)
	{
		vLine((Width - 20) / 3 * 2, h + i,Width-10, RGB(192, 13, 61));
	}
}
