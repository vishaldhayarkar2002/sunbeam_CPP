#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

// ================= BANK ACCOUNT =================

class BankAccount
{
protected:
    int accountNo;
    string accountHolderName;
    string mobileNo;
    double balance;

public:

    BankAccount()
    {
        accountNo = 0;
        balance = 0;
    }

    virtual void acceptAccount(int accNo)
    {
        accountNo = accNo;

        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, accountHolderName);

        cout << "Enter Mobile Number: ";
        cin >> mobileNo;

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    virtual void displayAccount()
    {
        cout << "\nAccount Number : " << accountNo << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Mobile Number  : " << mobileNo << endl;
        cout << "Balance        : " << balance << endl;
    }

    int getAccountNo()
    {
        return accountNo;
    }

    virtual void deposit(double amount)
    {
        balance += amount;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance.\n";
        }
    }

    double getBalance()
    {
        return balance;
    }

    virtual ~BankAccount()
    {
    }
};


// ================= SAVINGS ACCOUNT =================

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:

    void acceptAccount(int accNo) 
    {
        BankAccount::acceptAccount(accNo);

        cout << "Enter Interest Rate: ";
        cin >> interestRate;
    }

    void displayAccount() 
    {
        BankAccount::displayAccount();

        cout << "Account Type  : Savings Account" << endl;
        cout << "Interest Rate : " << interestRate << "%" << endl;
    }
};


// ================= CURRENT ACCOUNT =================

class CurrentAccount : public BankAccount
{
private:
    double overdraftLimit;

public:

    void acceptAccount(int accNo) 
    {
        BankAccount::acceptAccount(accNo);

        cout << "Enter Overdraft Limit: ";
        cin >> overdraftLimit;
    }

    void displayAccount() 
    {
        BankAccount::displayAccount();

        cout << "Account Type    : Current Account" << endl;
        cout << "Overdraft Limit : " << overdraftLimit << endl;
    }

    void withdraw(double amount) 
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
        }
        else
        {
            cout << "Amount exceeds overdraft limit.\n";
        }
    }
};


// ================= MAIN =================

int main()
{
    BankAccount* accounts[5];

    int count = 0;
    int choice;

    do
    {
        cout << "\n========== BANK ACCOUNT MANAGEMENT ==========\n";
        cout << "1. Add a new Account\n";
        cout << "2. Display all Accounts\n";
        cout << "3. Search Account\n";
        cout << "4. Deposit Amount\n";
        cout << "5. Withdraw Amount\n";
        cout << "6. Display Account Type\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
            // =====================================
            // ADD ACCOUNT
            // =====================================

            case 1:
            {
                if (count == 5)
                {
                    cout << "Maximum 5 accounts reached.\n";
                    break;
                }

                int accNo;
                int type;

                cout << "Enter Account Number: ";
                cin >> accNo;

                // Check duplicate account number
                bool exists = false;

                for (int i = 0; i < count; i++)
                {
                    if (accounts[i]->getAccountNo() == accNo)
                    {
                        exists = true;
                        break;
                    }
                }

                if (exists)
                {
                    cout << "Account Number already exists.\n";
                    break;
                }

                cout << "\n1. Savings Account\n";
                cout << "2. Current Account\n";
                cout << "Enter Account Type: ";
                cin >> type;

                if (type == 1)
                {
                    accounts[count] = new SavingsAccount();
                }
                else if (type == 2)
                {
                    accounts[count] = new CurrentAccount();
                }
                else
                {
                    cout << "Invalid account type.\n";
                    break;
                }

                accounts[count]->acceptAccount(accNo);

                count++;

                cout << "Account added successfully.\n";

                break;
            }


            // =====================================
            // DISPLAY ALL ACCOUNTS
            // =====================================

            case 2:
            {
                if (count == 0)
                {
                    cout << "No accounts available.\n";
                    break;
                }

                for (int i = 0; i < count; i++)
                {
                    cout << "\n-----------------------------";
                    accounts[i]->displayAccount();
                }

                break;
            }


            // =====================================
            // SEARCH ACCOUNT
            // =====================================

            case 3:
            {
                int accNo;
                bool found = false;

                cout << "Enter Account Number: ";
                cin >> accNo;

                for (int i = 0; i < count; i++)
                {
                    if (accounts[i]->getAccountNo() == accNo)
                    {
                        cout << "Account Found\n";
                        accounts[i]->displayAccount();

                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Account Number not found.\n";
                }

                break;
            }


            // =====================================
            // DEPOSIT
            // =====================================

            case 4:
            {
                int accNo;
                double amount;
                bool found = false;

                cout << "Enter Account Number: ";
                cin >> accNo;

                for (int i = 0; i < count; i++)
                {
                    if (accounts[i]->getAccountNo() == accNo)
                    {
                        found = true;

                        cout << "Enter Amount to Deposit: ";
                        cin >> amount;

                        if (amount <= 0)
                        {
                            cout << "Invalid deposit amount.\n";
                        }
                        else
                        {
                            accounts[i]->deposit(amount);

                            cout << "Amount deposited successfully.\n";
                            cout << "Updated Balance: "
                                 << accounts[i]->getBalance()
                                 << endl;
                        }

                        break;
                    }
                }

                if (!found)
                {
                    cout << "Account Number not found.\n";
                }

                break;
            }


            // =====================================
            // WITHDRAW
            // =====================================

            case 5:
            {
                int accNo;
                double amount;
                bool found = false;

                cout << "Enter Account Number: ";
                cin >> accNo;

                for (int i = 0; i < count; i++)
                {
                    if (accounts[i]->getAccountNo() == accNo)
                    {
                        found = true;

                        cout << "Enter Amount to Withdraw: ";
                        cin >> amount;

                        if (amount <= 0)
                        {
                            cout << "Invalid withdrawal amount.\n";
                        }
                        else
                        {
                            accounts[i]->withdraw(amount);

                            cout << "Current Balance: "
                                 << accounts[i]->getBalance()
                                 << endl;
                        }

                        break;
                    }
                }

                if (!found)
                {
                    cout << "Account Number not found.\n";
                }

                break;
            }


            // =====================================
            // DISPLAY ACCOUNT TYPE
            // =====================================

            case 6:
            {
                int accNo;
                bool found = false;

                cout << "Enter Account Number: ";
                cin >> accNo;

                for (int i = 0; i < count; i++)
                {
                    if (accounts[i]->getAccountNo() == accNo)
                    {
                        if (typeid(*accounts[i]) ==
                            typeid(SavingsAccount))
                        {
                            cout << "Account Type: Savings Account\n";
                        }
                        else if (typeid(*accounts[i]) ==
                                 typeid(CurrentAccount))
                        {
                            cout << "Account Type: Current Account\n";
                        }

                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Account Number not found.\n";
                }

                break;
            }


            // =====================================
            // EXIT
            // =====================================

            case 7:
            {
                cout << "Program terminated.\n";
                break;
            }


            default:
            {
                cout << "Invalid menu choice.\n";
            }
        }

    } while (choice != 7);


    // ================= DEALLOCATION =================

    for (int i = 0; i < count; i++)
    {
        delete accounts[i];
    }

    return 0;
}