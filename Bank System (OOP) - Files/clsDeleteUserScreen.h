#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsDeleteUserScreen : protected clsScreen
{

private:

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\tDelete User Screen");

		string UserName = "";

		cout << "\nPlease Enter User Name ? ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found, Please enter anthoer one ? ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);

		cout << "\nAre you sure do you want to delete this User y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			if (UserName != "Admin")
			{


				if (User1.Delete())
				{
					cout << "\nUser Deleted Successfully.\n";
					_PrintUser(User1);

				}
				else
				{
					//But I know Delete() Function will not return false  (hhhhh)
					cout << "\nError User Was not Deleted\n";
				}
			}
			else
			{
				cout << "\nYou Can't Delete Admin.\n";
			}

		}
		else
		{
			cout << "\nDeleted Action Canceled.\n";
		}
	}




};

