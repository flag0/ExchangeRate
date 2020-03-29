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
	CRatesList CRate;//汇率类
	Draw draw(1280,720,RGB(255,255,255));
	draw.DrawInit();
	int top = draw.GetTop();
	top += 30;

	CPictureBox picture;//图片打印类
	CTextBox txt;//文字打印类
	txt.SetFontFamily("微软雅黑");

	char* currencyName = (char*)malloc(128);
	int left = 120;
	int padding = 215;
	//打印内容
	txt.SetFontSize(20);
	
	updateRates(&CRate);//更新数据

	float PageSize = 7;
	int CountPage = ceil(CRate.GetCount() / PageSize);

	size_t time = getTime();

	while (true)
	{
		//判断时间
		if ((getTime()-time)/60 >= 10)//如果大于10分钟，则更新一次时间
		{
			time = getTime();
			updateRates(&CRate);//更新数据
		}
		for (size_t i = 0; i < CountPage; i++)
		{
			draw.DrawInit();//初始化面板
			ViewUpdateTime(time);
			ViewLineName(left, top - 30, padding, 30);//打印列名
			//打印汇率
			int recordCount = 0;
			ExchangeRate* record = CRate.GetRatesByPage(i, PageSize, &recordCount);
			ViewUpdateTime(1050, draw.GetTop() - 40, record->PublishTime);		//打印更新时间
			for (size_t j = 0; j < recordCount; j++)
			{
				CRate.GetCurrencyName((record + j), &currencyName);
				txt.SetPosition(left, top + (720 - top) / 7 * j + 10);
				txt.SetValue(currencyName);
				txt.Display();
				//现汇买入价
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

				//打印国旗
				char* flagPath = (char*)malloc(64);
				strcpy(flagPath, "flag//");
				int index = strlen(flagPath);
				strcpy(flagPath + index, (record + j)->CurrencyCode);
				strcat(flagPath, ".bmp");
				picture.LoadBMPFromFile(flagPath);
				picture.SetPosition(10, top + (720 - top) / 7 * j);
				picture.ShowPicture();
			}

			Sleep(1000 * 20);//sleep 20秒
		}
	}


	getch();
	closegraph();
	free(currencyName);
	//打印图片类
	//打印文字类
	//翻页
	return 1;
}
