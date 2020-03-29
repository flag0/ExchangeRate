#pragma once
typedef struct BitMapHeader
{
	long Size;//文件大小
	short Reserved1;//保留字，不考虑
	short Reserved2;//保留字，同上
	long OffBits;//实际位图数据的偏移字节数，即前三个部分长度之和
}BIT_MAP_HEADER;

typedef struct BitMapInfo
{
	long   Size;             //指定此结构体的长度，为40   
	long   Width;            //位图宽   
	long   Height;           //位图高   
	short  Planes;           //平面数，为1   
	short  BitCount;         //采用颜色位数，可以是1，2，4，8，16，24，新的可以是32   
	long   Compression;      //压缩方式，可以是0，1，2，其中0表示不压缩   
	long   SizeImage;        //实际位图数据占用的字节数   
	long   XPelsPerMeter;    //X方向分辨率   
	long   YPelsPerMeter;    //Y方向分辨率   
	long   ClrUsed;          //使用的颜色数，如果为0，则表示默认值(2^颜色位数)   
	long   ClrImportant;     //重要颜色数，如果为0，则表示所有颜色都是重要的
} BIT_MAP_INFO;

typedef struct EXRNAME//结构体数组初始化
{
	char key[4];
	char name[10];
	char flagPath[255];
};