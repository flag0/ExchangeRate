#include "Draw.h"
#include "CRatesList.h"
#include <graphics.h>
#include <conio.h>
#include "CPictureBox.h"
#include "CTextBox.h"
#include "mainBase.h"
#include <math.h>

int main()
{
	CRatesList CRate;//������
	Draw draw(1280,720,RGB(255,255,255));
	draw.DrawInit();
	int top = draw.GetTop();
	top += 30;

	CPictureBox picture;//ͼƬ��ӡ��
	CTextBox txt;//���ִ�ӡ��
	txt.SetFontFamily("΢���ź�");

	char* currencyName = (char*)malloc(128);
	int left = 120;
	int padding = 215;
	//��ӡ����
	txt.SetFontSize(20);
	
	updateRates(&CRate);//��������

	float PageSize = 7;
	int CountPage = ceil(CRate.GetCount() / PageSize);

	size_t time = getTime();

	while (true)
	{
		//�ж�ʱ��
		if ((getTime()-time)/60 >= 10)//�������10���ӣ������һ��ʱ��
		{
			time = getTime();
			updateRates(&CRate);//��������
		}
		for (size_t i = 0; i < CountPage; i++)
		{
			draw.DrawInit();//��ʼ�����
			ViewUpdateTime(time);
			ViewLineName(left, top - 30, padding, 30);//��ӡ����
			//��ӡ����
			int recordCount = 0;
			ExchangeRate* record = CRate.GetRatesByPage(i, PageSize, &recordCount);
			ViewUpdateTime(1050, draw.GetTop() - 40, record->PublishTime);		//��ӡ����ʱ��
			for (size_t j = 0; j < recordCount; j++)
			{
				CRate.GetCurrencyName((record + j), &currencyName);
				txt.SetPosition(left, top + (720 - top) / 7 * j + 10);
				txt.SetValue(currencyName);
				txt.Display();
				//�ֻ������
				txt.SetPosition(left + padding, top + (720 - top) / 7 * j + 10);
				sprintf(currencyName, "%.2f", (record + j)->BuyingRate);
				txt.SetValue(currencyName);
				txt.Display();

				txt.SetPosition(left + padding * 2, top + (720 - top) / 7 * j + 10);
				sprintf(currencyName, "%.2f", (record + j)->SellingRate);
				txt.SetValue(currencyName);
				txt.Display();

				txt.SetPosition(left + padding * 3, top + (720 - top) / 7 * j + 10);
				sprintf(currencyName, "%.2f", (record + j)->CashBuyingRate);
				txt.SetValue(currencyName);
				txt.Display();

				txt.SetPosition(left + padding * 4, top + (720 - top) / 7 * j + 10);
				sprintf(currencyName, "%.2f", (record + j)->CashSellingRate);
				txt.SetValue(currencyName);
				txt.Display();

				txt.SetPosition(left + padding * 5, top + (720 - top) / 7 * j + 10);
				sprintf(currencyName, "%.2f", (record + j)->MiddleRate);
				txt.SetValue(currencyName);
				txt.Display();

				//��ӡ����
				char* flagPath = (char*)malloc(64);
				strcpy(flagPath, "flag//");
				int index = strlen(flagPath);
				strcpy(flagPath + index, (record + j)->CurrencyCode);
				strcat(flagPath, ".bmp");
				picture.LoadBMPFromFile(flagPath);
				picture.SetPosition(10, top + (720 - top) / 7 * j);
				picture.ShowPicture();
			}

			Sleep(1000 * 20);//sleep 20��
		}
	}


	getch();
	closegraph();
	free(currencyName);
	//��ӡͼƬ��
	//��ӡ������
	//��ҳ
	return 1;
}
