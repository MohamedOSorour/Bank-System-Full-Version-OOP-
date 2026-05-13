#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsTransferScreen :protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
      /*  cout << "\nPlease enter AccountNumber? ";*/
        cin >> AccountNumber;
        return AccountNumber;
    }
public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t   Transfer Screen");
        cout << "\nPlease enter account number to transfer from: ";
        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nPlease enter account number to transfer to: ";
        AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client2 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client2);

        double TransferAmount = 0;
        cout << "\nEnter Transfer Amount: ";
        TransferAmount = clsInputValidate::ReadDblNumberBetween(0, Client1.AccountBalance);
        char Choice = 'n';
        cout << "\nAre you sure you want to perform this operation? y/n? ";
        cin >> Choice;
        if (tolower(Choice) == 'y')
        { 
            Client1.Transfer(TransferAmount, Client2);
            cout << "\nTransfer Done Successfully!\n";
            _PrintClient(Client1);
            _PrintClient(Client2);
        }
        else
        {
            cout << "\nOperation was canceled!\n";
        }
        
    }
};

