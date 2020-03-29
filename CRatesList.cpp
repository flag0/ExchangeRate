#include "CRatesList.h"
#include <malloc.h>
#include <io.h>
#include <string.h>

int CRatesList::GetCount()
{
	return _recordCount;
}

ExchangeRate* CRatesList::GetRateByIndex(int index)
{
	return _firstRecord + index;
}

CRatesList::~CRatesList()
{

	if (_firstRecord != NULL)
	{
		free(_firstRecord);
	}
}
int CRatesList::SaveRateToFile(const char* path)
{
	//成功返回1 不成功返回-1
	FILE* fp = fopen(path,"wb");
	if (_firstRecord == NULL) return -1;
	fwrite(_firstRecord,sizeof(*_firstRecord), _recordCount, fp);
	fclose(fp);
	return 1;
}
int CRatesList::ReadRateFromFile(const char* path)
{
	//成功返回1 不成功返回-1
	FILE* fp = fopen(path, "rb");
	if (fp == NULL) return -1;
	size_t fileSize = filelength(fileno(fp));
	_firstRecord = (ExchangeRate*)malloc(fileSize);
	fread(_firstRecord, fileSize, 1, fp);
	fclose(fp);
	return 1;
}

int CRatesList::ReadRateFromInternet()
{
	//成功返回1 不成功返回-1
	ExchangeRate* newRecord = (ExchangeRate*)malloc(sizeof(ExchangeRate)*27);
	ExchangeRate* oldRecord = NULL;
	_recordCount = ReadAllBOCRates(&oldRecord);
	
	size_t ni = 0;
	for (size_t i = 0; i < _recordCount; i++)
	{
		if (strcmp((oldRecord + i)->CurrencyCode, "CNY") == 0) continue;
		*(newRecord + ni) = *(oldRecord + i);
		ni++;
	}

	_recordCount -= 1;
	
	if (_recordCount != 27)
	{
		return -1;
	}
	_firstRecord = newRecord;

	return 1;
}

int CRatesList::GetCurrencyName(ExchangeRate* rates,char** CurrentName)
{
	if (rates == NULL && CurrentName == NULL) return -1;

	strcpy(*CurrentName, rates->CurrencyName);
	size_t index = strlen(rates->CurrencyName);
	const char* str= "/";
	strcat(*CurrentName, str);
	strcpy(*CurrentName + index + 1, rates->CurrencyCode);
	return 1;
}

ExchangeRate* CRatesList::GetRatesByPage(int pageIndex, int pageSize, int* recordCount)
{
	if ((_recordCount - pageIndex * pageSize) > 7)
	{
		*recordCount = 7;
	}
	else
	{
		*recordCount = (_recordCount - pageIndex * pageSize);
	}
	return _firstRecord + pageIndex * pageSize;
}
