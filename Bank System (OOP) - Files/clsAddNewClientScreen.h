#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsAddNewClientScreen	:protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter AccountBalance: ";
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
		cout << "\nPassword        : " << Client. PinCode;
		cout << "\nBalance         : " << Client.AccountBalance;
		cout << "\n-------------------------\n";

	}


public:

	static void ShowAddNewClientScreen()
	{
		
		_DrawScreenHeader("\t   Add New Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResult SaveReuslt;

		SaveReuslt = NewClient.Save();

		switch (SaveReuslt)
		{

		case clsBankClient::enSaveResult::svSucceeded:
		{
			cout << "\nAccount Addeded Successfully :-) \n";
			_PrintClient(NewClient);
			break;
		}

		case clsBankClient::enSaveResult::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}

		case clsBankClient::enSaveResult::svFaildAccountNumberExist:
			cout << "\nFaild because account already in Used";
			break;
		}


	}



};

