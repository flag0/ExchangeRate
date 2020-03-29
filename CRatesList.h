#pragma once
#include "BOCRates.h"
#pragma comment(lib, "BOCRates.lib")
#include <stdio.h>
#define FILEPATH "RateData.data"

class CRatesList
{
private:
	ExchangeRate* _firstRecord = NULL;
	int _recordCount = 0;
public:
	~CRatesList();
	int GetCount();
	ExchangeRate* GetRateByIndex(int index);
	int SaveRateToFile(const char* path);
	int ReadRateFromFile(const char* path);
	int ReadRateFromInternet();
	int GetCurrencyName(ExchangeRate* rates, char** CurrentName);
	ExchangeRate* GetRatesByPage(int pageIndex, int pageSize, int* recordCount);
};