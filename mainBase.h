#pragma once
#include "CRatesList.h"

void ViewLineName(int left, int top, int padding, int  paddSub);//��ӡ����

void ViewUpdateTime(int left,int top,char* time);//��ӡ����ʱ��

void updateRates(CRatesList* rate);//��������

int getTime();

void ViewUpdateTime(size_t time);