#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsUpdateCurrencyRateScreen:protected clsScreen
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
	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Currency");
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

		char Choice = 'n';
		cout << "\nAre you sure you want to update this currency y/n ? ";
		cin >> Choice;
		if (tolower(Choice) == 'y')
		{
			cout << "\nUpdate Currency Rate:";
			cout << "\n___________________";
			cout << "\nEnter New Rate: ";
			float NewRate = clsInputValidate::ReadFloatNumber();
			
			Currency.UpdateRate(NewRate);

			cout << "\nCurrency Updated Successfully :-)\n";
			PrintCurrencyCard(Currency);
		}

	}
};

