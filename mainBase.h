#pragma once
#include "CRatesList.h"

void ViewLineName(int left, int top, int padding, int  paddSub);//打印列名

void ViewUpdateTime(int left,int top,char* time);//打印更新时间

void updateRates(CRatesList* rate);//更新数据

int getTime();

void ViewUpdateTime(size_t time);