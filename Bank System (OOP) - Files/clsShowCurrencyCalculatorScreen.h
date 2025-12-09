#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsShowCurrencyCalculatorScreen :protected clsScreen
{

private:

	static void _PrintCurrencyConverter(clsCurrency Currency1)
	{
		cout << "\nConvert From:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency1.Country();
		cout << "\nCode       : " << Currency1.CurrencyCode();
		cout << "\nName       : " << Currency1.CurrencyName();
		cout << "\nRate(1$) = : " << Currency1.Rate();

		cout << "\n_____________________________\n";

	}



public:

	static void ShowCurrencyCalculator()
	{
		_DrawScreenHeader("\tCalculate Currency Screen");

		cout << "\n\nPlease Enter Currency1 Code: ";
		string Currency1Code = clsInputValidate::ReadString();

		clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);

		while (!Currency1.IsCurrencyExist(Currency1Code))
		{
			cout << "\n Currecny is not found,Please Enter Another one: ";
			Currency1Code = clsInputValidate::ReadString();
		}


		cout << "\n\nPlease Enter Currency2 Code: ";
		string Currency2Code = clsInputValidate::ReadString();

		clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);

		while (!Currency2.IsCurrencyExist(Currency2Code))
		{
			cout << "\n Currecny is not found,Please Enter Another one: ";
			Currency2Code = clsInputValidate::ReadString();

		}



		cout << "\nEnter Amount to Exchange: ";
		float Amount = clsInputValidate::ReadFloatNumber();

		if (clsString::UpperAllString(Currency2Code) == "USD")
		{
			_PrintCurrencyConverter(Currency1);

			cout << Amount << " " << Currency1Code << " = " << Amount / Currency2.Rate() << " USD\n";
		}


		







	}
};

