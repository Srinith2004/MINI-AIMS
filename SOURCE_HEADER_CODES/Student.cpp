#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "Admin.h"
#include "Student.h"
#include "Faculty.h"
#include "Functions.h"

int Student::checking(const string &A)
{
    ifstream checking("student_courses.txt");
    string w1, w2;

    while (checking >> w1 >> w2 >> w2)
    {
        if (w1 == this->ID && w2 == A)
        {
            return 0;
        }
        checking >> w1 >> w1;
    }
    checking.close();
    return 1;
}

void Student::intro()
{
    cout << "What would you like to do:\n\n"
         << endl;
    cout << "1. View Profile" << endl;
    cout << "2. View Courses" << endl;
    cout << "3. ADD/REMOVE Courses" << endl;
    cout << "4. Exit\n"
         << endl;
}

void Student::view_profile()
{
    cout << "Name : " << this->sur_name << ' ' << this->Name << "\n"
         << endl;
    cout << "ID :" << this->ID << "\n"
         << endl;
}

void Student::view_courses()
{
    ifstream check_1("student_courses.txt");

    string A, B;

    int k = 1;
    cout << "S.No"
         << " | "
         << "Course Name"
         << " | "
         << "Course ID"
         << " | "
         << "Instructor"
         << " | "
         << "Grade\n"
         << endl;
    while (check_1 >> A)
    {
        getline(check_1, B);
        if (A == this->ID)
        {
            cout << k;
            replace(B);
            cout << "\n";
            k++;
        }
    }
    check_1.close();
}

int Student::add_courses_sub(int opt, const string &I)
{
    int k = 0, l = 0;
    string line, course_ID;

    switch (opt)
    {
    case 1:
    {
        int a;
        k++;
        ifstream newone("courses.txt");
        while (newone >> a)
        {
            getline(newone, line);
            if (a == 1)
            {
                cout << k << ' ';
                replace(line);
                cout << "\n";
                k++;
            }
        }
        k = 0;
        cout << "\n\n\n";
        newone.close();
        cout << "Press 1 to go back \n >" << endl;
        cin >> opt;
        opt = 1;
        l = 1;
        system("cls");
        break;
    }
    case 2:
    {
        cout << "Enter the Course ID you want to register:";
        cin >> course_ID;

        ofstream newfilepointer("student_courses.txt", ios::app);
        ifstream check("courses.txt");

        string A, B, C;
        int f;

        if (checking(course_ID) == 1)
        {
            while (check >> f >> A >> B >> C)
            {
                if (f == 1 && A == course_ID)
                {
                    newfilepointer << this->ID << ' ' << C << ' ' << A << ' ' << B << ' ' << "N/A\n";
                    k = 1;
                    break;
                }
            }
            if (k == 0)
            {
                cout << "Please enter correct course ID" << endl;
                sleep(1);
                system("cls");
            }
        }
        else
        {
            cout << "You are already registered to this course !!" << endl;
            sleep(1);
            system("cls");
        }
        newfilepointer.close();
        check.close();
        l = 1;
        break;
    }
    case 3:
    {
        cout << "Enter the Course ID you want to de-register:" << endl;
        cin >> course_ID;

        ifstream in("student_courses.txt", ios::in);
        ofstream of("temp1.txt", ios::app);

        string A, B, C, D, E;

        while (in >> A >> B >> C >> D >> E)
        {
            if (C == course_ID && A == this->ID && (E == "N/A" || I == "*"))
            {
                k = 1;
            }
            else
            {
                of << A << ' ' << B << ' ' << C << ' ' << D << ' ' << E << "\n";
            }
        }
        in.close();
        of.close();
        remove("student_courses.txt");
        rename("temp1.txt", "student_courses.txt");
        if (k == 0)
        {
            cout << "Please enter correct course ID (or) Can't de-register because garde is given" << endl;
            sleep(1);
            system("cls");
        }
        l = 1;
        break;
    }
    default:
    {
        break;
    }
    }
    if (k == 1)
    {
        cout << "Updated!!";
        sleep(1);
        system("cls");
    }
    return l;
}

int Student::add_courses(const string &Q)
{
    int opt = 0;

    cout << "The courses you are registered to are \n\n\n";

    this->view_courses();

    cout << "\n\n";

    cout << "Choose of the following :\n\n"
         << endl;
    cout << "1 . View other available courses" << endl;
    cout << "2 . ADD COURSE" << endl;
    cout << "3 . REMOVE COURSE" << endl;
    cout << "4 . Back" << endl;
    cin >> opt;

    return add_courses_sub(opt, Q);
}