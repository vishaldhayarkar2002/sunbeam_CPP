#include<iostream> 
#include<string>
using namespace std; 

class Date
{
    private: 
    int day; 
    int month; 
    int year; 
    
    public: 
    Date( void ) : day(8) , month(9) , year(2026)
    {   }
    
    Date(int day , int month , int year)  : day(day) , month(month) , year(year)
    {   }
    
    void acceptDate( void )
    {
        cout<<"Day : "; 
        cin>>day; 
        cout<<"Month : "; 
        cin>>month; 
        cout<<"Year : "; 
        cin>>year; 
    }
    
    void printDate( void )
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl; 
    }
}; 

class Person 
{
    private: 
    string name; 
    string address; 
    Date birthdate; // Association 
    
    public: 
    Person( void ) : name("") , address("")
    {   }
    
    Person(string name , string address) : name(name) , address(address)
    {   }
    
    Person(string name , string address , Date birthdate)  : name(name) , address(address) , birthdate(birthdate)
    {   }
    
    Person(string name , string address , int day , int month , int year) : name(name) , address(address) , birthdate(day,month,year)
    {   }
    
    void accept( void )
    {
        cout<<"Name : "; 
        cin>>name; 
        cout<<"Address : "; 
        cin>>address; 
        cout<<"Enter Birthdate Details:\n";
        this->birthdate.acceptDate( ); //IMP
    }
    
    void print( void )
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Address : "<<address<<endl; 
        cout<<"Birthdate : ";
        this->birthdate.printDate( );   //  IMP
    }
}; 

class Student
{
    private:
    int id;
    double marks;
    string course;
    Date joiningDate; // Association
    Date endDate;     // Association

    public:
    Student( void ) : id(0), marks(0.0), course("")
    {   }

    Student(int id, double marks, string course) : id(id), marks(marks), course(course)
    {   }

    Student(int id, double marks, string course, Date joiningDate, Date endDate) 
        : id(id), marks(marks), course(course), joiningDate(joiningDate), endDate(endDate)
    {   }

    Student(int id, double marks, string course, int jDay, int jMonth, int jYear, int eDay, int eMonth, int eYear)
        : id(id), marks(marks), course(course), joiningDate(jDay, jMonth, jYear), endDate(eDay, eMonth, eYear)
    {   }

    void accept( void )
    {
        cout<<"ID : ";
        cin>>id;
        cout<<"Marks : ";
        cin>>marks;
        cout<<"Course : ";
        cin>>course;
        cout<<"Enter Joining Date Details:\n";
        this->joiningDate.acceptDate();
        cout<<"Enter End Date Details:\n";
        this->endDate.acceptDate();
    }

    void print( void )
    {
        cout<<"ID : "<<id<<endl;
        cout<<"Marks : "<<marks<<endl;
        cout<<"Course : "<<course<<endl;
        cout<<"Joining Date : ";
        this->joiningDate.printDate();
        cout<<"End Date : ";
        this->endDate.printDate();
    }
};

// Test functionality 1: User Inputs via accept()
int main()
{
    cout << "--- Testing Person Class (User Input) ---\n";
    Person p; 
    p.accept( ); 
    p.print( ); 
    
    cout << "\n--- Testing Student Class (User Input) ---\n";
    Student s;
    s.accept( );
    s.print( );
    
    return 0;
}

// Test functionality 2: Directly passing parameters to constructor
int main2()
{
    cout << "--- Testing Person with direct initialization ---\n";
    Person p("Amit", "Mumbai", 15, 8, 2000); 
    p.print( ); 
    
    cout << "\n--- Testing Student with direct initialization ---\n";
    Student s(101, 85.5, "B.Tech", 1, 8, 2024, 30, 5, 2028);
    s.print();
    return 0;
}

// Test functionality 3: Passing existing Date objects to constructor
int main1()
{
    cout << "--- Testing classes using existing Date Objects ---\n";
    Date dob(20, 5, 1999); 
    Person p("Sandeep", "Pune", dob); 
    p.print( ); 
    
    Date join(1, 9, 2023);
    Date end(31, 5, 2027);
    Student s(102, 92.0, "M.Tech", join, end);
    s.print();
    return 0;
}
