#pragma once

void showSingleImage(size_t Width, size_t Height,int x,int y, unsigned char* pixelInfo, RGBQUAD* cimage);
void show16Image(size_t Width, size_t Height, int x, int y, unsigned char* pixelInfo, RGBQUAD* cimage);
void show256Image(size_t Width, size_t Height, int x, int y, unsigned char* pixelInfo, RGBQUAD* cimage);
void show24Image(size_t Width, size_t Height, int top, int left, unsigned char* pixelInfo);