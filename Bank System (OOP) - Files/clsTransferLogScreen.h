#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
class clsTransferLogScreen : protected clsScreen
{



private:

    static void _PrinTransferLogScreenRecordLine(clsBankClient::stTransferLogRecord TransferLog)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLog.DateTime;
        cout << "| " << setw(8) << left << TransferLog.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLog.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLog.Amount;
        cout << "| " << setw(10) << left << TransferLog.SourceBalanceAfter;
        cout << "| " << setw(10) << left << TransferLog.DestinationBalanceAfter;
        cout << "| " << setw(8) << left << TransferLog.Username;
    }

public:

    static void ShowTransferLogScreen()
    {

        vector <clsBankClient::stTransferLogRecord> vTransferLog = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLog.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLog.size() == 0)
            cout << "\t\t\t\tNo Transger Log Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLog)
            {
                _PrinTransferLogScreenRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

