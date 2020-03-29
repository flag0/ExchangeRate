#include "CBox.h"

CBox::CBox()
{

}
CBox::CBox(int top, int left)
{
	_top = top;
	_left = left;
}


void CBox::SetPosition(int top, int left)
{
	_top = top;
	_left = left;
}

void CBox::GetPosition(int* top, int* left)
{
	*top = this->_top;
	*left = this->_left;
}