#include "mainBase.h"
#include "CTextBox.h"
#include "CRatesList.h"
#include "Draw.h"
#include <time.h>


void ViewLineName(int left, int top, int padding, int  paddSub)
{
	CTextBox txt;//���ִ�ӡ��
	txt.SetFontFamily("΢���ź�");
	txt.SetFontSize(23);
	txt.SetPosition(left + padding - paddSub, top);
	txt.SetValue("�ֻ������");
	txt.Display();

	txt.SetPosition(left + padding * 2 - paddSub, top);
	txt.SetValue("�ֳ������");
	txt.Display();

	txt.SetPosition(left + padding * 3 - paddSub, top);
	txt.SetValue("�ֻ�������");
	txt.Display();

	txt.SetPosition(left + padding * 4 - paddSub, top);
	txt.SetValue("�ֳ�������");
	txt.Display();

	txt.SetPosition(left + padding * 5 - paddSub, top);
	txt.SetValue("���������");
	txt.Display();
}


void strReplace(char** publishTime,char* time)
{
	strcpy(*publishTime, "����ʱ�䣺");
	int index = strlen(*publishTime);
	strncpy(*publishTime + index, time, 4);
	strcpy(*publishTime + index + 4, "��");

	char* Date = (char*)malloc(3);
	strncpy(Date, time + 5, 2);
	if (*Date == '0')
	{
		*(Date + 0) = *(Date + 1);
		*(Date + 1) = '\0';
	}
	else
	{
		*(Date + 2) = '\0';
	}

	strcat(*publishTime, Date);
	strcat(*publishTime, "��");
	strncpy(Date, time + 8, 2);
	if (*Date == '0')
	{
		*(Date + 0) = *(Date + 1);
		*(Date + 1) = '\0';
	}
	else
	{
		*(Date + 2) = '\0';
	}

	strcat(*publishTime, Date);
	strcat(*publishTime, "�� ");
	strcat(*publishTime, time + 11);

}


void ViewUpdateTime(int left, int top, char* time)
{
	CTextBox txt;//���ִ�ӡ��
	txt.SetFontFamily("΢���ź�");
	txt.SetFontSize(18);
	//2020-03-29 10:40:09
	char* publishTime = (char*)calloc(256,1);
	strReplace(&publishTime,time);//����ʱ�����ڴ���

	txt.SetPosition(left,top);
	txt.SetValue(publishTime);
	txt.Display();
	free(publishTime);
}

void updateRates(CRatesList* rate)
{
	int res = rate->ReadRateFromInternet();
	if (res == -1)
	{
		rate->ReadRateFromFile(FILEPATH);
	}
	else
	{
		rate->SaveRateToFile(FILEPATH);
	}
}

int getTime()
{
	time_t t;
	time(&t);//��ȡUnixʱ���,��λ����
	return t;
}

void ViewUpdateTime(size_t time)
{
	CTextBox txt;
	txt.SetFontFamily("΢���ź�");
	txt.SetFontSize(18);
	char* offsetTime = (char*)malloc(256);
	strcpy(offsetTime, "�����ϴθ����ѹ�ȥ��");
	int index = strlen(offsetTime);
	sprintf(offsetTime + index, "%d", getTime() - time);
	strcat(offsetTime, "��");
	txt.SetPosition(10, 60);
	txt.SetValue(offsetTime);
	txt.Display();
	free(offsetTime);
}
