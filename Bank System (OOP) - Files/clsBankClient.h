#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"

using namespace std;

class clsBankClient :public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewClient = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string>vClientData;

		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1],
			vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));


	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string StClientRecord = "";

		StClientRecord += Client.FirstName + Seperator;
		StClientRecord += Client.LastName + Seperator;
		StClientRecord += Client.Email + Seperator;
		StClientRecord += Client.Phone + Seperator;
		StClientRecord += Client.AccountNumber() + Seperator;
		StClientRecord += Client.PinCode + Seperator;
		StClientRecord += to_string(Client.AccountBalance);

		return StClientRecord;
	}

	static void	_SaveClientDataToFile(vector<clsBankClient>& vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); //Write mode

		string DataLine;
		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				if (C.MarkedForDelete() == false)
				{
					//we only write records that are not marked for delete
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}

	static vector<clsBankClient>_LoadClientsDataFromFile()
	{
		vector < clsBankClient>_vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);  //Read Mdoe

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				//Bad Way beecause Make an Object in any Read
				//clsBankClient Client = _ConvertLineToClientObject(Line);
				//_vClients.push_back(Client);

				//best way not make object for any Read
				_vClients.push_back(_ConvertLineToClientObject(Line));
			}

			MyFile.close();

		}

		return _vClients;

	}

	void _Update()
	{
		vector<clsBankClient>_vClients;

		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;

				break;
			}
		}

		_SaveClientDataToFile(_vClients);

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string  DataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << DataLine << endl;

			MyFile.close();
		}

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string Username, string Sperator = "#//#")
	{
		string Record = "";
		Record += clsDate::GetSystemDateTimeString() + Sperator;
		Record += AccountNumber() + Sperator;
		Record += DestinationClient.AccountNumber() + Sperator;
		Record += to_string(Amount) + Sperator;
		Record += to_string(AccountBalance) + Sperator;
		Record += to_string(DestinationClient.AccountBalance) + Sperator;
		Record += Username;

		return Record;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string Username, string Sperator = "#//#")
	{
		fstream MyFile;
		string Line = _PrepareTransferLogRecord(Amount, DestinationClient, Username);

		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << Line << endl;

			MyFile.close();
		}
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferLogRecord staTransferLog;

		vector<string> vLines;
		vLines = clsString::Split(Line, Seperator);

		staTransferLog.DateTime = vLines[0];
		staTransferLog.SourceAccountNumber = vLines[1];
		staTransferLog.DestinationAccountNumber = vLines[2];
		staTransferLog.Amount = stof(vLines[3]);
		staTransferLog.SourceBalanceAfter = stof(vLines[4]);
		staTransferLog.DestinationBalanceAfter = stof(vLines[5]);
		staTransferLog.Username = vLines[6];

		return staTransferLog;
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return  _AccountNumber;
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


	//No UI Related code inside object 

	/*void Print()
	{
		cout << "\nClient Card:";
		cout << "\n-------------------------";
		cout << "\nFirstName       : " << FirstName;
		cout << "\nLastName        : " << LastName;
		cout << "\nFullName        : " << FullName();
		cout << "\nEmail           : " << Email;
		cout << "\nPhone           : " << Phone;
		cout << "\nAcc. Number     : " << _AccountNumber;
		cout << "\nPassword        : " << PinCode;
		cout << "\nBalance         : " << _AccountBalance;
		cout << "\n-------------------------\n";

	}*/

	static clsBankClient Find(string AccountNumber)
	{
		//vector<clsBankClient>vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);  //Red Mode


		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

				//vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		//vector<clsBankClient>vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);  //Red Mode

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

				//vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return (!Client1.IsEmpty());  //is Not Empty return true	
	}


	bool Delete()
	{
		vector<clsBankClient>vClients;
		vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}

		}

		_SaveClientDataToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExist = 2 };


	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			//if (IsEmpty())
		//	{
			return enSaveResult::svFaildEmptyObject;

			//	}

		}


		case enMode::UpdateMode:
		{

			_Update();
			return enSaveResult::svSucceeded;

			break;
		}

		case enMode::AddNewClient:

			//This Will add New record to file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResult::svFaildAccountNumberExist;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}

		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewClient, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;

		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{

			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(float Amount, clsBankClient& DestinationClient, string Username)
	{
		if (Amount > AccountBalance)
		{

			return false;
		}
		else
		{
			Withdraw(Amount);
			DestinationClient.Deposit(Amount);
			_RegisterTransferLog(Amount, DestinationClient, Username);
			return true;
		}
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalance = 0;

		for (clsBankClient Client : vClients)
		{
			TotalBalance += Client.AccountBalance;
		}

		return TotalBalance;


	}



	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount = 0;
		float SourceBalanceAfter = 0;
		float DestinationBalanceAfter = 0;
		string Username;
	};



	static vector<stTransferLogRecord> GetTransferLogList()
	{
		vector<stTransferLogRecord>vTransferLogRecord;


		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);


		if (MyFile.is_open())
		{
			string Line;

		stTransferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{
				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);
			}


			MyFile.close();

		}

		return vTransferLogRecord;
	}




};

