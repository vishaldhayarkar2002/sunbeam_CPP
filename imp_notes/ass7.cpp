#include <iostream>
#include <vector>
using namespace std;


// ================= EMPLOYEE =================

class Employee
{
protected:
    int id;
    string name;
    double salary;

public:

    Employee()
    {
        id = 0;
        name = "";
        salary = 0;
    }

    Employee(int id, string name, double salary)
    {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    virtual void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual string getDesignation()
    {
        return "Employee";
    }

    virtual ~Employee()
    {
    }
};


// ================= MANAGER =================

class Manager : virtual public Employee
{
public:

    Manager()
    {
    }

    Manager(int id, string name, double salary)
        : Employee(id, name, salary)
    {
    }

    void display() override
    {
        cout << "Designation: Manager" << endl;
        Employee::display();
    }

    string getDesignation() override
    {
        return "Manager";
    }
};


// ================= SALESMAN =================

class Salesman : virtual public Employee
{
public:

    Salesman()
    {
    }

    Salesman(int id, string name, double salary)
        : Employee(id, name, salary)
    {
    }

    void display() override
    {
        cout << "Designation: Salesman" << endl;
        Employee::display();
    }

    string getDesignation() override
    {
        return "Salesman";
    }
};


// ================= SALESMANAGER =================

class SalesManager : public Manager, public Salesman
{
public:

    SalesManager()
    {
    }

    SalesManager(int id, string name, double salary)
        : Employee(id, name, salary),
          Manager(),
          Salesman()
    {
    }

    void display() override
    {
        cout << "Designation: SalesManager" << endl;
        Employee::display();
    }

    string getDesignation() override
    {
        return "SalesManager";
    }
};


// ================= MAIN =================

int main()
{
    vector<Employee*> employees;

    int choice;

    do
    {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Add Manager" << endl;
        cout << "2. Add Salesman" << endl;
        cout << "3. Add SalesManager" << endl;
        cout << "4. Display count of all employees" << endl;
        cout << "5. Display All Managers" << endl;
        cout << "6. Display All Salesman" << endl;
        cout << "7. Display All SalesManagers" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;


        // ================= ADD MANAGER =================

        if (choice == 1)
        {
            int id;
            string name;
            double salary;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Salary: ";
            cin >> salary;

            Manager* m = new Manager(id, name, salary);

            // UPCASTING
            Employee* e = m;

            employees.push_back(e);

            cout << "Manager added successfully!" << endl;
        }


        // ================= ADD SALESMAN =================

        else if (choice == 2)
        {
            int id;
            string name;
            double salary;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Salary: ";
            cin >> salary;

            Salesman* s = new Salesman(id, name, salary);

            // UPCASTING
            Employee* e = s;

            employees.push_back(e);

            cout << "Salesman added successfully!" << endl;
        }


        // ================= ADD SALESMANAGER =================

        else if (choice == 3)
        {
            int id;
            string name;
            double salary;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Salary: ";
            cin >> salary;

            SalesManager* sm =
                new SalesManager(id, name, salary);

            // UPCASTING
            Employee* e = sm;

            employees.push_back(e);

            cout << "SalesManager added successfully!" << endl;
        }


        // ================= COUNT =================

        else if (choice == 4)
        {
            int managerCount = 0;
            int salesmanCount = 0;
            int salesManagerCount = 0;

            for (Employee* e : employees)
            {
                if (e->getDesignation() == "Manager")
                {
                    managerCount++;
                }
                else if (e->getDesignation() == "Salesman")
                {
                    salesmanCount++;
                }
                else if (e->getDesignation() == "SalesManager")
                {
                    salesManagerCount++;
                }
            }

            cout << "\nManager Count: "
                 << managerCount << endl;

            cout << "Salesman Count: "
                 << salesmanCount << endl;

            cout << "SalesManager Count: "
                 << salesManagerCount << endl;
        }


        // ================= DISPLAY MANAGERS =================

        else if (choice == 5)
        {
            cout << "\n===== ALL MANAGERS =====" << endl;

            for (Employee* e : employees)
            {
                if (e->getDesignation() == "Manager")
                {
                    e->display();
                    cout << endl;
                }
            }
        }


        // ================= DISPLAY SALESMAN =================

        else if (choice == 6)
        {
            cout << "\n===== ALL SALESMAN =====" << endl;

            for (Employee* e : employees)
            {
                if (e->getDesignation() == "Salesman")
                {
                    e->display();
                    cout << endl;
                }
            }
        }


        // ================= DISPLAY SALESMANAGERS =================

        else if (choice == 7)
        {
            cout << "\n===== ALL SALESMANAGERS =====" << endl;

            for (Employee* e : employees)
            {
                if (e->getDesignation() == "SalesManager")
                {
                    e->display();
                    cout << endl;
                }
            }
        }


        else if (choice == 0)
        {
            cout << "Program ended." << endl;
        }

        else
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);


    // Free memory
    for (Employee* e : employees)
    {
        delete e;
    }

    return 0;
}