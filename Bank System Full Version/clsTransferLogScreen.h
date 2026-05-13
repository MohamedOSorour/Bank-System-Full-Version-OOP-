#pragma once
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsUser.h"
using namespace std;
class clsTransferLogScreen :protected clsScreen
{
private:
	static void PrintTransferRecordLine(clsBankClient::stTransferRecord TransferRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(25) << left << TransferRecord.DateTime;
		cout << "| " << setw(10) << left << TransferRecord.SAcc;
		cout << "| " << setw(10) << left << TransferRecord.DAcc;
		cout << "| " << setw(10) << left << TransferRecord.TransferedAmount;
		cout << "| " << setw(10) << left << TransferRecord.SBalance;
		cout << "| " << setw(10) << left << TransferRecord.DBalance;
		cout << "| " << setw(10) << left << TransferRecord.User;
	}
public:
	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferRecord> vTransferRecords = clsBankClient::GetTransferLogList();
		string Title = "	Transfer Log List Screen";
		string SubTitle= "\t    (" + to_string(vTransferRecords.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(10) << "S.Acc";
		cout << "| " << left << setw(10) << "D.Acc";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "S.Balance";
		cout << "| " << left << setw(10) << "D.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferRecords.size() == 0)
			cout << "\t\t\t\tNo Transfers Available In the System!";
		else
		{
			for (clsBankClient::stTransferRecord Record : vTransferRecords)
			{
				PrintTransferRecordLine(Record);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

