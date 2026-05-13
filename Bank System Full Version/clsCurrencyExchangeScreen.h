#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen:protected clsScreen
{
private:
	enum enExchangeCurrenciesOptions
	{
		eCurrenciesList = 1,eFindCurrencies=2
		,eUpdateRate=3,eCurrencyCalculator=4
		,eShowMainMenue=5
	};
	static short ReadCurrencyExchangeMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}
	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesList();
	}
	static void _ShowFindCurrenciesScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _GoBackToExchangeMenueScreen()
	{
		cout << "\n\nPress any key to go back to Exchange Currencies Menue...";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}
	static void _PerformCurrencyExchangeMenueOption(enExchangeCurrenciesOptions ExchangeMenueOption)
	{
		switch (ExchangeMenueOption)
		{
		case enExchangeCurrenciesOptions::eCurrenciesList:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToExchangeMenueScreen();
			break;

		case enExchangeCurrenciesOptions::eFindCurrencies:
			system("cls");
			_ShowFindCurrenciesScreen();
			_GoBackToExchangeMenueScreen();
			break;

		case enExchangeCurrenciesOptions::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToExchangeMenueScreen();
			break;

		case enExchangeCurrenciesOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToExchangeMenueScreen();
			break;

		case enExchangeCurrenciesOptions::eShowMainMenue:
		{
			// Do Nothing Here!!!!
		}

		}
	}
public:
	static void ShowCurrencyExchangeScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pExchangeCurrencies))
		{
			return;// this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("    Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currencies.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyExchangeMenueOption((enExchangeCurrenciesOptions)ReadCurrencyExchangeMenueOption());
	}
};

