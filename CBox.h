#pragma once
#include <graphics.h>
class CBox
{
private:
		int _top = 0;
		int _left = 0;
public:
		/*��C++�����У���������������������ͬ�����ǲ������������Ͳ�ͬ*/
		CBox();
		CBox(int top, int left);
		void SetPosition(int top, int left);
		void GetPosition(int* _top,int* _left);
};

