#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

	static  bool _Login()
	{
		bool LoginFaild = false;
		short FaildLoginCount = 0;

		string UserName, Password;

		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;

				cout << "\n[Invlaid UserName/Password]\n";
				cout << "You have " << (3 - FaildLoginCount) << " Trial(s) to Login\n\n";
			}

			if (FaildLoginCount == 3)
			{
				cout << "\nYou are Locked after 3 faild trails\n";
				return false;
			}

			cout << "\nEnter UserName? ";
			UserName = clsInputValidate::ReadString();

			cout << "Enter Password? ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();


		} while (LoginFaild);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
		return true;

		//this is Good Way
		// 
		//while (true)
		//{
		//	cout << "Enter UserName? ";
		//	UserName = clsInputValidate::ReadString();
		//
		//	cout << "Enter Password? ";
		//	Password = clsInputValidate::ReadString();
		//
		//	CurrentUser = clsUser::Find(UserName, Password);
		//
		//	if (!CurrentUser.IsEmpty())
		//	{
		//		break;
		//	}
		//	cout << "\n Invlaid UserName/Password\n";
		//
		//}
		//clsMainScreen::ShowMainMenue();
	}

public:



	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();

	}

};

