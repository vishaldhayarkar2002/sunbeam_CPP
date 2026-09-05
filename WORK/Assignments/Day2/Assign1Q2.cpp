#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    void initDate()
    {
        day = 1;
        month = 1;
        year = 2000;
    }

    void printDateOnConsole()
    {
        cout << "Date: "
             << day << "/"
             << month << "/"
             << year << endl;
    }

    void acceptDateFromConsole()
    {
        cout << "Enter day: ";
        cin >> day;

        cout << "Enter month: ";
        cin >> month;

        cout << "Enter year: ";
        cin >> year;
    }

    bool isLeapYear()
    {
        if ((year % 400 == 0) ||
            (year % 4 == 0 && year % 100 != 0))
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Date d;
    int choice;

    d.initDate();

    do
    {
        cout << "\n===== DATE MENU =====" << endl;
        cout << "1. Initialize Date" << endl;
        cout << "2. Accept Date" << endl;
        cout << "3. Print Date" << endl;
        cout << "4. Check Leap Year" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                d.initDate();
                cout << "Date initialized." << endl;
                break;

            case 2:
                d.acceptDateFromConsole();
                break;

            case 3:
                d.printDateOnConsole();
                break;

            case 4:
                if(d.isLeapYear())
                    cout << "It is a Leap Year." << endl;
                else
                    cout << "It is not a Leap Year." << endl;
                break;

            case 5:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 5);

    return 0;
}