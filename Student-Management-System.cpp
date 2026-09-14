#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

// ================= Student Class =================

class Student
{
protected:
    int studentId;
    string studentName;
    string mobileNo;

public:

    Student()
    {
        studentId = 0;
    }

    virtual void acceptStudent(int id)
    {
        studentId = id;

        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, studentName);

        cout << "Enter Mobile Number: ";
        cin >> mobileNo;
    }

    virtual void displayStudent()
    {
        cout << "Student ID   : " << studentId << endl;
        cout << "Student Name : " << studentName << endl;
        cout << "Mobile No    : " << mobileNo << endl;
    }

    int getStudentId()
    {
        return studentId;
    }

    virtual ~Student()
    {
    }
};


// ================= RegularStudent Class =================

class RegularStudent : public Student
{
private:
    int semester;

public:

    void acceptStudent(int id)
    {
        Student::acceptStudent(id);

        cout << "Enter Semester: ";
        cin >> semester;
    }

    void displayStudent()
    {
        Student::displayStudent();

        cout << "Student Type : Regular Student" << endl;
        cout << "Semester     : " << semester << endl;
    }
};


// ================= DistanceStudent Class =================

class DistanceStudent : public Student
{
private:
    string studyCenter;

public:

    void acceptStudent(int id)
    {
        Student::acceptStudent(id);

        cout << "Enter Study Center: ";
        cin.ignore();
        getline(cin, studyCenter);
    }

    void displayStudent()
    {
        Student::displayStudent();

        cout << "Student Type : Distance Student" << endl;
        cout << "Study Center : " << studyCenter << endl;
    }
};


// ================= Exception Class =================

class StudentException
{
private:
    string message;

public:

    StudentException(string msg)
    {
        message = msg;
    }

    string getMessage()
    {
        return message;
    }
};


// ================= Main =================

int main()
{
    Student* students[5];

    int count = 0;
    int choice;

    do
    {
        cout << "\========== STUDENT MANAGEMENT SYSTEM ==========";
        cout << "1. Add a new Student"<<endl;
        cout << "2. Display all Students"<<endl;
        cout << "3. Search Student by ID"<<endl;
        cout << "4. Display Student Type"<<endl;
        cout << "5. Display Regular Students"<<endl;
        cout << "6. Exit";

        cout << "Enter Choice: "<<endl;
        cin >> choice;

        try
        {
            switch (choice)
            {
                // =========================================
                // 1. ADD STUDENT
                // =========================================

                case 1:
                {
                    if (count == 5)
                    {
                        throw StudentException(
                            "Maximum 5 students reached."
                        );
                    }

                    int id;
                    int type;

                    cout << "Enter Student ID: "<<endl;
                    cin >> id;

                    // Check duplicate ID
                    bool exists = false;

                    for (int i = 0; i < count; i++)
                    {
                        if (students[i]->getStudentId() == id)
                        {
                            exists = true;
                            break;
                        }
                    }

                    if (exists)
                    {
                        cout << "Student ID already exists."<<endl;
                        break;
                    }

                    cout << "\n1. Regular Student\n";
                    cout << "2. Distance Student\n";

                    cout << "Enter Student Type: ";
                    cin >> type;

                    if (type == 1)
                    {
                        students[count] = new RegularStudent();
                    }
                    else if (type == 2)
                    {
                        students[count] = new DistanceStudent();
                    }
                    else
                    {
                        throw StudentException(
                            "Invalid student type."
                        );
                    }

                    students[count]->acceptStudent(id);

                    count++;

                    cout << "\nStudent added successfully.\n";

                    break;
                }


                // =========================================
                // 2. DISPLAY ALL STUDENTS
                // =========================================

                case 2:
                {
                    if (count == 0)
                    {
                        throw StudentException(
                            "No students available."
                        );
                    }

                    for (int i = 0; i < count; i++)
                    {
                        cout << "\n-----------------------------\n";

                        students[i]->displayStudent();
                    }

                    break;
                }


                // =========================================
                // 3. SEARCH STUDENT
                // =========================================

                case 3:
                {
                    int id;
                    bool found = false;

                    cout << "Enter Student ID: ";
                    cin >> id;

                    for (int i = 0; i < count; i++)
                    {
                        if (students[i]->getStudentId() == id)
                        {
                            cout << "\nStudent Found\n";
                            cout << "-----------------------------\n";

                            students[i]->displayStudent();

                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        throw StudentException(
                            "Student ID not found."
                        );
                    }

                    break;
                }


                // =========================================
                // 4. DISPLAY STUDENT TYPE
                // =========================================

                case 4:
                {
                    int id;
                    bool found = false;

                    cout << "Enter Student ID: ";
                    cin >> id;

                    for (int i = 0; i < count; i++)
                    {
                        if (students[i]->getStudentId() == id)
                        {
                            cout << "\nStudent Type: ";

                            if (typeid(*students[i]) ==
                                typeid(RegularStudent))
                            {
                                cout << "Regular Student";
                            }
                            else if (typeid(*students[i]) ==
                                     typeid(DistanceStudent))
                            {
                                cout << "Distance Student";
                            }

                            cout << endl;

                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        throw StudentException(
                            "Student ID not found."
                        );
                    }

                    break;
                }


                // =========================================
                // 5. DISPLAY REGULAR STUDENTS
                // =========================================

                case 5:
                {
                    bool found = false;

                    cout << "\n====== REGULAR STUDENTS ======\n";

                    for (int i = 0; i < count; i++)
                    {
                        if (typeid(*students[i]) ==
                            typeid(RegularStudent))
                        {
                            students[i]->displayStudent();

                            cout << "-----------------------------\n";

                            found = true;
                        }
                    }

                    if (!found)
                    {
                        cout << "No Regular Students available.\n";
                    }

                    break;
                }


                // =========================================
                // 6. EXIT
                // =========================================

                case 6:
                {
                    cout << "\nProgram terminated.\n";
                    break;
                }


                // =========================================
                // INVALID CHOICE
                // =========================================

                default:
                {
                    throw StudentException(
                        "Invalid menu choice."
                    );
                }
            }
        }
        catch (StudentException& e)
        {
            cout << "\nException: "
                 << e.getMessage() << endl;
        }

    } while (choice != 6);


    // ================= Deallocation =================

    for (int i = 0; i < count; i++)
    {
        delete students[i];
    }

    return 0;
}