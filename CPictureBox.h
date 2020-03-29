#pragma once
#include "CBox.h"
#include "bmpStruct.h"

class CPictureBox :public CBox
{
private:
	size_t _Width;
	size_t _Height;
	size_t _bitCount;//ɫ��
	BIT_MAP_HEADER* _bmpHeader;
	BIT_MAP_INFO* _bmpInfo;
	unsigned char* _pixelInfo = NULL;//������ʼλ��
	RGBQUAD* _cimage = NULL;//��ɫ����ʼλ��
public:
	int LoadBMPFromFile(const char* filename);
	int ShowPicture();
};