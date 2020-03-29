#include "CPictureBox.h"
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include "PicBase.h"


int CPictureBox::LoadBMPFromFile(const char* filename)
{
	//����������ڴӴ����ļ�����λͼ
	//����Ĳ�����filename;
	//Step 1. ���ļ� ������ļ�ʧ�ܣ�����-1
	//Step 2. �ж��ļ��Ƿ���BMP�ļ���������ǣ�����-2
	//Step 3. �ж��ļ���С�Ƿ����20M, ����ǣ�����-3

	//����ļ�<20M, ��Ӵ��̶���ȫ���ļ����ݵ��ڴ�(malloc)
	//Ϊ�˱��ں������������Ĳ�������������Ժ�������ڲ�Ӧ����ȷ֪��BMP�Ļ�����Ϣ����ȡ��߶ȡ�ɫ�
	//������һ�������߶����ָ��ָ���ļ����ݵĲ�ͬ����
	//  a. BIT_MAP_HEADER 
	//  b. BIT_MAP_INFO
	//  c. ��ɫ�����ݵ���ʼλ�ã�����еĻ�)
	//  d. �������ݵ���ʼλ��


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

	unsigned char* pixelInfo = (unsigned char*)malloc(sizeof(char));//�����������ݵ���ʼλ��
	RGBQUAD* cimage = (RGBQUAD*)malloc(sizeof(RGBQUAD) * 256);//�����ɫ�����ʼλ��
	

	tag = (char*)freeBuffer;
	bmpHeader = (BIT_MAP_HEADER*)((DWORD)freeBuffer + 0x2);
	bmpInfo = (BIT_MAP_INFO*)((DWORD)bmpHeader + sizeof(*bmpHeader));


	if (tag[0] != 'B' && tag[1] != 'M') return -2; //�ж��Ƿ�Ϊbmp
	if (bmpHeader->Size > 1024 * 1024 * 20) return -3;//�ж��Ƿ����20M

	pixelInfo = (unsigned char*)((DWORD)freeBuffer + bmpHeader->OffBits);//����������ʼλ��

	if (bmpInfo->BitCount != 24)//�ж��Ƿ��е�ɫ��
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

	fclose(fp);//�ر��ļ�
	return 1;
}

int CPictureBox::ShowPicture()//���Ѿ������ڴ��λͼ��ʾ����
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

