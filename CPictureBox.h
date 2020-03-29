#pragma once
#include "CBox.h"
#include "bmpStruct.h"

class CPictureBox :public CBox
{
private:
	size_t _Width;
	size_t _Height;
	size_t _bitCount;//色深
	BIT_MAP_HEADER* _bmpHeader;
	BIT_MAP_INFO* _bmpInfo;
	unsigned char* _pixelInfo = NULL;//像素起始位置
	RGBQUAD* _cimage = NULL;//调色板起始位置
public:
	int LoadBMPFromFile(const char* filename);
	int ShowPicture();
};