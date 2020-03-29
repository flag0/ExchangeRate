#include "CPictureBox.h"
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include "PicBase.h"


int CPictureBox::LoadBMPFromFile(const char* filename)
{
	//这个函数用于从磁盘文件读入位图
	//传入的参数是filename;
	//Step 1. 打开文件 如果打开文件失败，返回-1
	//Step 2. 判断文件是否是BMP文件，如果不是，返回-2
	//Step 3. 判断文件大小是否大于20M, 如果是，返回-3

	//如果文件<20M, 则从磁盘读入全部文件数据到内存(malloc)
	//为了便于后续其他方法的操作，读入完成以后，在类的内部应该明确知道BMP的基本信息（宽度、高度、色深）
	//并且有一个（或者多个）指针指向文件数据的不同部分
	//  a. BIT_MAP_HEADER 
	//  b. BIT_MAP_INFO
	//  c. 调色板数据的起始位置（如果有的话)
	//  d. 像素数据的起始位置


	FILE* fp = fopen(filename,"rb");
	if (fp == NULL)
	{
		return -1;
	}

	long fileSize = filelength(fileno(fp));
	void* freeBuffer = (void*)calloc(fileSize, 1);
	
	fread(freeBuffer, fileSize, 1, fp);
	
	char* tag = (char*)malloc(sizeof(char) * 2);
	BIT_MAP_HEADER* bmpHeader = (BIT_MAP_HEADER*)malloc(sizeof(bmpHeader));
	BIT_MAP_INFO* bmpInfo = (BIT_MAP_INFO*)malloc(sizeof(BIT_MAP_INFO));

	unsigned char* pixelInfo = (unsigned char*)malloc(sizeof(char));//定义像素数据的起始位置
	RGBQUAD* cimage = (RGBQUAD*)malloc(sizeof(RGBQUAD) * 256);//定义调色板的起始位置
	

	tag = (char*)freeBuffer;
	bmpHeader = (BIT_MAP_HEADER*)((DWORD)freeBuffer + 0x2);
	bmpInfo = (BIT_MAP_INFO*)((DWORD)bmpHeader + sizeof(*bmpHeader));


	if (tag[0] != 'B' && tag[1] != 'M') return -2; //判断是否为bmp
	if (bmpHeader->Size > 1024 * 1024 * 20) return -3;//判断是否大于20M

	pixelInfo = (unsigned char*)((DWORD)freeBuffer + bmpHeader->OffBits);//像素数据起始位置

	if (bmpInfo->BitCount != 24)//判断是否有调色板
	{
		cimage = (RGBQUAD*)((DWORD)bmpInfo + sizeof(*bmpInfo));
		_cimage = cimage;
	}

	_Width = bmpInfo->Width;
	_Height = bmpInfo->Height;
	_bitCount = bmpInfo->BitCount;


	_bmpHeader = bmpHeader;
	_bmpInfo = bmpInfo;

	_pixelInfo = pixelInfo;

	fclose(fp);//关闭文件
	return 1;
}

int CPictureBox::ShowPicture()//将已经载入内存的位图显示出来
{
	int top = 10;
	int left = 20;
	GetPosition(&top, &left);

	switch (_bitCount)
	{
	case 1:showSingleImage(_Width, _Height,top,left, _pixelInfo,_cimage); break;
	case 4:show16Image(_Width, _Height, top, left, _pixelInfo, _cimage); break;
	case 8:show256Image(_Width, _Height, top, left, _pixelInfo, _cimage); break;
	case 24:show24Image(_Width, _Height, top, left, _pixelInfo); break;
	default:break;
	}

	return 0;
}

