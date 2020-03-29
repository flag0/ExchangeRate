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
	// ����Ļ��������ַ���
	settextcolor(BLACK);//�������������ɫ
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = _fontsize;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T(_fontFamily));		// ��������
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����
	settextstyle(&f);// ����������ʽ
	int top;
	int left;
	GetPosition(&top,&left);
	outtextxy(top, left ,_T(_str));
}