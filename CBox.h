#pragma once
#include <graphics.h>
class CBox
{
private:
		int _top = 0;
		int _left = 0;
public:
		/*在C++的类中，允许两个函数的名称相同，但是参数数量、类型不同*/
		CBox();
		CBox(int top, int left);
		void SetPosition(int top, int left);
		void GetPosition(int* _top,int* _left);
};

