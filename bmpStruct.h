#pragma once
typedef struct BitMapHeader
{
	long Size;//�ļ���С
	short Reserved1;//�����֣�������
	short Reserved2;//�����֣�ͬ��
	long OffBits;//ʵ��λͼ���ݵ�ƫ���ֽ�������ǰ�������ֳ���֮��
}BIT_MAP_HEADER;

typedef struct BitMapInfo
{
	long   Size;             //ָ���˽ṹ��ĳ��ȣ�Ϊ40   
	long   Width;            //λͼ��   
	long   Height;           //λͼ��   
	short  Planes;           //ƽ������Ϊ1   
	short  BitCount;         //������ɫλ����������1��2��4��8��16��24���µĿ�����32   
	long   Compression;      //ѹ����ʽ��������0��1��2������0��ʾ��ѹ��   
	long   SizeImage;        //ʵ��λͼ����ռ�õ��ֽ���   
	long   XPelsPerMeter;    //X����ֱ���   
	long   YPelsPerMeter;    //Y����ֱ���   
	long   ClrUsed;          //ʹ�õ���ɫ�������Ϊ0�����ʾĬ��ֵ(2^��ɫλ��)   
	long   ClrImportant;     //��Ҫ��ɫ�������Ϊ0�����ʾ������ɫ������Ҫ��
} BIT_MAP_INFO;

typedef struct EXRNAME//�ṹ�������ʼ��
{
	char key[4];
	char name[10];
	char flagPath[255];
};