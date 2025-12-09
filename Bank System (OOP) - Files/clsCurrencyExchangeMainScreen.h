#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:
	enum enCurrencyExchangeMenueOption
	{
		eListCurrencies = 1, eFindCurrency = 2,
		eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5
	};


	static short _ReadCurrencyExchangeMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 ? ");
		return Choice;
	}


	static	void _ShowListCurrencies()
	{
		//cout << "\nScreen Will Be Here.\n";
		clsCurrenciesListScreen::ShowListCurrencies();
	}

	static	void _ShowFindCurrency()
	{
		//cout << "\nScreen Will Be Here.\n";

		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static	void _ShowUpdateRateScreen()
	{
		//cout << "\nScreen Will Be Here.\n";

		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();


	}

	static void _ShowCurrencyCalculator()
	{
		//cout << "\nScreen Will Be Here.\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowCurrenciesMenue();
	}



	static void _PerfromCurrenciesExchangeMainMenue(enCurrencyExchangeMenueOption Option)
	{

		system("cls");
		switch (Option)

		{
		case enCurrencyExchangeMenueOption::eListCurrencies:
		{
			_ShowListCurrencies();
			break;
		}
		case enCurrencyExchangeMenueOption::eFindCurrency:
		{
			_ShowFindCurrency();
			break;
		}
		case enCurrencyExchangeMenueOption::eUpdateRate:
		{
			_ShowUpdateRateScreen();
			break;
		}
		case enCurrencyExchangeMenueOption::eCurrencyCalculator:
		{
			_ShowCurrencyCalculator();
			break;
		}
		case enCurrencyExchangeMenueOption::eMainMenue:
		{

		}

		}

		if (Option != enCurrencyExchangeMenueOption::eMainMenue)
		{
			_GoBackToCurrencyExchangeMenue();
		}

	}

public:

	static void ShowCurrenciesMenue()
	{

		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromCurrenciesExchangeMainMenue((enCurrencyExchangeMenueOption)_ReadCurrencyExchangeMenueOption());
	}

};

