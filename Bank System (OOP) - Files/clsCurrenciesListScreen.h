#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class  clsCurrenciesListScreen :protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(10) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();
		


	}

public:


	static void ShowListCurrencies()
	{

		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();


		string Title = "\tCurrencies List Screen";
		string Subtitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency";

		_DrawScreenHeader(Title, Subtitle);

		//cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << setw(8) << left << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
	
		cout << setw(8) << left << "\n\t________________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Currency Available in the System!";
		else

			for (clsCurrency &C : vCurrencies)
			{

				_PrintCurrencyRecordLine(C);
				cout << endl;
			}

		cout << setw(8) << left << "\n\t________________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

