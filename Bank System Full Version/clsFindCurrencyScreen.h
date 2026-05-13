#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include <iostream>
using namespace std;
class clsFindCurrencyScreen:protected clsScreen
{
private:
	static void PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrencyCard:";
		cout << "\n___________________";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n___________________\n";
	}
public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2);
		if (Choice == 1)
		{
			cout << "\nPlease Enter Currency Code: ";
			string CurrencyCode = clsInputValidate::ReadString();
			while (!clsCurrency::IsCurrencyExist(CurrencyCode))
			{
				cout << "\nCurrency Code is not found, choose another one: ";
				CurrencyCode = clsInputValidate::ReadString();
			}
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			if (!Currency.IsEmpty())
			{
				cout << "\nCurrency Found :-)\n";
			}
			else
			{
				cout << "\nCurrency Was not Found :-(\n";
			}
			PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nPlease Enter Country: ";
			string Country = clsInputValidate::ReadString();
			while (!clsCurrency::IsCurrencyExistByCountry(Country))
			{
				cout << "\nCurrency Country is not found, choose another one: ";
				Country = clsInputValidate::ReadString();
			}
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			if (!Currency.IsEmpty())
			{
				cout << "\nCurrency Found :-)\n";
			}
			else
			{
				cout << "\nCurrency Was not Found :-(\n";
			}
			PrintCurrencyCard(Currency);
		}
	}
};

