#pragma once
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsUpdateClientScreen : protected	 clsScreen
{
private:

	enum _enChangeChooseMenue{ FirstName = 1 ,LastName = 2 , Email = 3 , Phone = 4 , PinCode = 5 , AccountBalance = 6 ,  All = 7 };

	static void _ShowChangeMenueScreen()
	{
		cout << "\n---------------------";
		cout << "\nUpdate Client Info: ";
		cout << "\n---------------------";
		cout << "\n[1]First Name ";
		cout << "\n[2]First Last ";
		cout << "\n[3]Email ";
		cout << "\n[4]Phone ";
		cout << "\n[5]Pin Code ";
		cout << "\n[6]Account Balance ";
		cout << "\n[7]All Info ";
		cout << "\n---------------------";
	}

	static void _ReadChangeClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter New FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter New LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter New Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter New Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter New PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter New AccountBalance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	}

	static void _ReadChangeClientFirstName(clsBankClient& Client)
	{
		cout << "\nEnter New FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

	}
					 
	static void _ReadChangeClientLastName(clsBankClient& Client)
	{
		cout << "\nEnter New LastName: ";
		Client.LastName = clsInputValidate::ReadString();

	}
					 
	static void _ReadChangeClientEmail(clsBankClient& Client)
	{
		cout << "\nEnter New Email: ";
		Client.Email = clsInputValidate::ReadString();

	}
					 
	static void _ReadChangeClientPhone(clsBankClient& Client)
	{
		cout << "\nEnter New Phone: ";
		Client.Phone = clsInputValidate::ReadString();

	}
					 
	static void _ReadChangeClientPinCode(clsBankClient& Client)
	{
		cout << "\nEnter New PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

	}
					 
	static void _ReadChangeClientAccountBalancee(clsBankClient& Client)
	{
		cout << "\nEnter New AccountBalance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	}

	static void  _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n-------------------------";
		cout << "\nFirstName       : " << Client.FirstName;
		cout << "\nLastName        : " << Client.LastName;
		cout << "\nFullName        : " << Client.FullName();
		cout << "\nEmail           : " << Client.Email;
		cout << "\nPhone           : " << Client.Phone;
		cout << "\nAcc. Number     : " << Client.AccountNumber();
		cout << "\nPassword        : " << Client.PinCode;
		cout << "\nBalance         : " << Client.AccountBalance;
		cout << "\n-------------------------\n";

	}

	static short _ReadChangeMenueOption()
	{
	     cout << "\nChoose What do you want to change[1 to 7]: ";
		;
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter Number between 1 to 7 ? ");
		return Choice;
	}

	static void _PerformChooseMenueScreen(_enChangeChooseMenue ChangeChooseOption , clsBankClient &Client1)
	{
		switch (ChangeChooseOption)
		{
		case _enChangeChooseMenue::FirstName:
		{
			_ReadChangeClientFirstName(Client1);
			break;
		}

		case _enChangeChooseMenue::LastName:
		{
			_ReadChangeClientLastName(Client1);
			break;
		}
		case _enChangeChooseMenue::Email:
		{
			_ReadChangeClientEmail(Client1);
			break;
		}
		case _enChangeChooseMenue::Phone:
		{
			_ReadChangeClientPhone(Client1);
			break;
		}
		case _enChangeChooseMenue::PinCode:
		{
			_ReadChangeClientPinCode(Client1);
			break;
		}
		case _enChangeChooseMenue::AccountBalance:
		{
			_ReadChangeClientAccountBalancee(Client1);
			break;
		}

		case _enChangeChooseMenue::All:
		{
			_ReadChangeClientInfo(Client1);
			break;
		}

		}
	}

public:

	static void ShowUpdateClientScreen()
	{

		_DrawScreenHeader("\tUpdate Client Screen");
		string AccountNumber = "";

		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		
		_ShowChangeMenueScreen();

		_PerformChooseMenueScreen(_enChangeChooseMenue(_ReadChangeMenueOption()), Client1);
		
		//_ReadClientInfo(Client1);

		clsBankClient::enSaveResult SaveResult;

		SaveResult = Client1.Save();

		switch (SaveResult)
		{

		case clsBankClient::enSaveResult::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(Client1);
			break;
		}

		case clsBankClient::enSaveResult::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		}
	}

};

