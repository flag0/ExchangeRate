#pragma once
#include "CBox.h"

class CTextBox : public CBox
{
private :
	const char* _str;
	size_t _fontsize;
	const char* _fontFamily;
public:
	void SetValue(const char* str);
	void Display();
	void SetFontSize(int fontsize);
	void SetFontFamily(const char* fontFamily);
};

