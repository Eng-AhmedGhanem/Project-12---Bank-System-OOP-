#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalances.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
class clsTransactionsScreen : protected clsScreen
{

private:

	enum enMainTransactionOptions
	{
		eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eTransfer = 4 , eShowTransferLog = 5 ,  eShowMainMenue = 6
	};

	static short  _ReadTransactionMenueOption()
	{
		cout << setw(37) << left << "" << "Choose What do you want to change[1 to 6]: ";
		;
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6 ? ");
		return Choice;
	}

	static void _ShowDepositScreen()
	{
	//	cout << "\nDeposit Screen Will be here";

		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\nWithdraw Screen Will be here";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		//cout << "\nTotal Balance Screen Will be here";

		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "\n Screen Will be here";
		clsTransferLogScreen::ShowTransferLogScreen();


	}
	
	static void _GoBackToTransactionMenue()
	{
		cout << setw(37) << left << "" << "\n\n\nPress any key to go back to transaction Menue...\n";

		system("pause>0");
		ShowTransactionMenue();
	}

	static void _PerfromtTransactionMenueOption(enMainTransactionOptions TransactionMenueOption)
	{
		system("cls");
		switch (TransactionMenueOption)
		{

		case enMainTransactionOptions::eDeposit:
		{
			_ShowDepositScreen();
			break;
		}
		case enMainTransactionOptions::eWithdraw:
		{
			_ShowWithdrawScreen();
			break;
		}
		case enMainTransactionOptions::eShowTotalBalance:
		{
			_ShowTotalBalanceScreen();
			break;
		}

		case enMainTransactionOptions::eTransfer:
		{
			_ShowTransferScreen();
			break;
		}

		case enMainTransactionOptions::eShowTransferLog:
		{
			_ShowTransferLogScreen();
			break;
		}

		case enMainTransactionOptions::eShowMainMenue:
		{
			//do nothing here the main screen will called
		}

		}

		if (TransactionMenueOption != enMainTransactionOptions::eShowMainMenue)
		{
			_GoBackToTransactionMenue();
		}
	};


public:

	static void ShowTransactionMenue()
	{
		system("cls");
		_DrawScreenHeader("\t Transaction Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Show Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromtTransactionMenueOption((enMainTransactionOptions)_ReadTransactionMenueOption());
	}
};

