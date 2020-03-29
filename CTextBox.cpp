#include "CTextBox.h"

void CTextBox::SetValue(const char* str) 
{
	_str = str;
}
void CTextBox::SetFontSize(int fontsize)
{
	_fontsize = fontsize;
}
void CTextBox::SetFontFamily(const char* fontFamily)
{
	_fontFamily = fontFamily;
}

void CTextBox::Display()
{
	// 在屏幕中央输出字符串
	settextcolor(BLACK);//设置输出文字颜色
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = _fontsize;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T(_fontFamily));		// 设置字体
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿
	settextstyle(&f);// 设置字体样式
	int top;
	int left;
	GetPosition(&top,&left);
	outtextxy(top, left ,_T(_str));
}