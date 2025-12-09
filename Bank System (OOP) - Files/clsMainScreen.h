#pragma once
#include  <iomanip>
#include  "clsScreen.h"
#include  "clsUser.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
#include "Global.h"

class clsMainScreen :protected clsScreen
{

private:

	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9 ,eExit = 10
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10 ? ");
		return Choice;
	}

	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}


	static void _ShowAllClientsScreen()
	{
		//  cout << "\nClient List Screen Will be here...\n";

		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}
		clsClientListScreen::ShowClientsList();

	}

	static void _ShowAddNewClientsScreen()
	{
		// cout << "\nAdd New Client Screen Will be here...\n";
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		clsAddNewClientScreen::ShowAddNewClientScreen();

	}

	static void _ShowDeleteClientScreen()
	{
		// cout << "\nDelete Client Screen Will be here...\n";

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen Will be here...\n";

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		// cout << "\nFind Client Screen Will be here...\n"; 
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		clsFindClientScreen::ShowFindClientScreen();

	}

	static void _ShowTransactionsMenue()
	{
		//  cout << "\nTransactions Menue Will be here...\n";
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}
		clsTransactionsScreen::ShowTransactionMenue();

	}

	static void _ShowManageUsersMenue()
	{
		//cout << "\nUsers Menue Will be here...\n";
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _Logout()
	{
		//cout << "\nEnd Screen Will be here...\n";

		CurrentUser = clsUser::Find("", "");


	}

	static void _ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pShowLoginRegister))
		{
			return;
		}
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeMainScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;
		}

		clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
	}


	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		system("cls");
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListClients:
		{
			_ShowAllClientsScreen();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			_ShowAddNewClientsScreen();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
		{
			_ShowDeleteClientScreen();
			break;
		}
		case enMainMenueOptions::eUpdateClient:
		{
			_ShowUpdateClientScreen();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			_ShowFindClientScreen();
			break;
		}

		case enMainMenueOptions::eShowTransactionsMenue:
		{
			_ShowTransactionsMenue();

			break;
		}
		case enMainMenueOptions::eManageUsers:
		{
			_ShowManageUsersMenue();
			break;
		}

		case enMainMenueOptions::eLoginRegister:
		{
			_ShowLoginRegisterScreen();
			break;
		}

		case enMainMenueOptions::eCurrencyExchange:
		{
			_ShowCurrencyExchangeMainScreen();
			break;
		}
		case enMainMenueOptions::eExit:
		{
			_Logout();
			break;
		}

		}

		if (MainMenueOption != enMainMenueOptions::eExit)
			_GoBackToMainMenue();
	};


public:
	static void ShowMainMenue()
	{

		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}

};

