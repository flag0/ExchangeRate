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
	inItBackGround(_width, _height, _backGround);//��ʼ���������,RGB(255, 255, 255)
}


void Draw::DrawInit()//��ʼ��
{
	cleardevice();//�ñ���ɫ�����Ļ
	printinItWord(_width,_height);//�������Ƽ�
	_lineHeight = _height / 9;
	printLine(_lineHeight, _width);//�������
}

int Draw::GetTop()
{
	return _lineHeight + 20;
}