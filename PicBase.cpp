#include <math.h>
#include <graphics.h>


void showSingleImage(size_t Width, size_t Height, int top, int left, unsigned char* pixelInfo, RGBQUAD* cimage)//显示单色位图
{
	int paddingSize = Width % 4;

	for (int y = Height; y > 0; y--)
	{
		for (int x = 0; x < Width; x += 8)
		{
			int index = 0;
			for (int j = 7; j >= 0; j--)
			{
				index = (*pixelInfo & (int)pow(2, j)) >> j;
				putpixel(top + x + 7 - j,left + y, RGB(cimage[index].rgbRed, cimage[index].rgbGreen, cimage[index].rgbBlue));
			}
			switch (Width / 8)//当width<32时，会自动补足空位，这里需要跳过空位，当width>32时，即使width%32!=0,存在空位，但是因为空位较少，打印出来肉眼无法看出，可忽略
			{
			case 1:pixelInfo += 4; break;
			case 2:if (x == 8)pixelInfo += 3; else pixelInfo += 1; break;
			case 3:if (x == 24)pixelInfo += 2; else pixelInfo += 1; break;
			default:pixelInfo += 1; break;
			}
		}
		if (paddingSize)
		{
			pixelInfo += (4 - Width % 4);
		}
	}
}

void show16Image(size_t Width, size_t Height, int top, int left, unsigned char* pixelInfo, RGBQUAD* cimage)
{
	int paddingSize = Width % 4;

	for (int y = Height; y > 0; y--)
	{
		for (int x = 0; x < Width; x += 2)
		{
			size_t index = 0;
			index = *pixelInfo >> 4;//取高4位
			putpixel(top + x,left + y, RGB(cimage[index].rgbRed, cimage[index].rgbGreen, cimage[index].rgbBlue));

			index = *pixelInfo & 0x0F;//取低4位
			putpixel(top + x, left + y, RGB(cimage[index].rgbRed, cimage[index].rgbGreen, cimage[index].rgbBlue));
			pixelInfo += 1;
		}

		if (paddingSize)
		{
			pixelInfo += (4 - Width % 4);
		}
	}
}

void show256Image(size_t Width, size_t Height, int top, int left, unsigned char* pixelInfo, RGBQUAD* cimage)
{
	int paddingSize = Width % 4;

	for (int y = Height; y > 0; y--)
	{
		for (int x = 0; x < Width; x++)
		{
			int index = 0;
			index = *pixelInfo;
			putpixel(top + x, left + y, RGB(cimage[index].rgbRed, cimage[index].rgbGreen, cimage[index].rgbBlue));
			pixelInfo += 1;
		}

		if (paddingSize)
		{
			pixelInfo += (4 - Width % 4);
		}
	}
}

void show24Image(size_t Width, size_t Height, int top, int left, unsigned char* pixelInfo)
{
	int paddingSize = Width % 4;

	for (int y = Height; y > 0; y--)
	{
		for (int x = 0; x < Width; x++)
		{
			int b = pixelInfo[0];
			int g = pixelInfo[1];
			int r = pixelInfo[2];
			putpixel(top + x, left + y, RGB(r, g, b));
			pixelInfo += 3;
		}

		if (paddingSize)
		{
			pixelInfo += (4 - (Width * 3) % 4);
		}
	}
}