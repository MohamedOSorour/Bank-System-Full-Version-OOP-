#pragma once
#include "clsString.h"
#include <fstream>
class clsCurrency
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
	{
		vector<string>vString = clsString::Split(Line, Separator);
		return clsCurrency(enMode::UpdateMode, vString[0], vString[1], vString[2], stof(vString[3]));
	}
	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
	{
		string CurrencyLine = "";
		CurrencyLine += Currency.Country() + Separator;
		CurrencyLine += Currency.CurrencyCode() + Separator;
		CurrencyLine += Currency.CurrencyName() + Separator;
		CurrencyLine += to_string(Currency.Rate()) + Separator;
		return CurrencyLine;
	}
	static vector<clsCurrency> _LoadCurrencyDataFromFile()
	{
		fstream MyFile;
		vector<clsCurrency> vCurrencies;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrencies;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency>& vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		string DataLine;
		if (MyFile.is_open())
		{
			for (clsCurrency& Currency : vCurrencies)
			{
				DataLine = _ConvertCurrencyObjectToLine(Currency);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsCurrency>vCurrencies;
		vCurrencies = _LoadCurrencyDataFromFile();
		for (clsCurrency& Currency : vCurrencies)
		{
			if (Currency.CurrencyCode() == CurrencyCode())
			{
				Currency = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyName = CurrencyName;
		_CurrencyCode = CurrencyCode;
		_Rate = Rate;
	}
	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}
	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	float Rate()
	{
		return _Rate;
	}
	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (CurrencyCode == Currency.CurrencyCode())
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static vector<clsCurrency>GetAllUSDRates()
	{
		return _LoadCurrencyDataFromFile();
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}
	static bool IsCurrencyExistByCountry(string Country)
	{
		clsCurrency Currency = clsCurrency::FindByCountry(Country);
		return (!Currency.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}
	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate());

	}

};

