#pragma once
class Draw
{
private:
	size_t _width;
	size_t _height;
	int _backGround;
	int _lineHeight;
public:
	Draw();
	Draw(int width, int height,int backGround);
	void DrawInit();
	int GetTop();//��ȡ���ݲ��ֵ�topSize
};