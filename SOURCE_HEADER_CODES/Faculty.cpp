#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "Admin.h"
#include "Student.h"
#include "Faculty.h"
#include "Functions.h"

void Faculty::intro()
{
    cout << "What would you like to do:\n\n"
         << endl;
    cout << "1. View Profile" << endl;
    cout << "2. View Students" << endl;
    cout << "3. Exit\n"
         << endl;
}

void Faculty::view_profile()
{
    cout << "Name : " << this->sur_name << ' ' << this->Name << "\n"
         << endl;
    cout << "ID :" << this->ID << "\n"
         << endl;
    cout << "Instructor for courses :" << endl;

    ifstream cour("courses.txt");

    string A, B, C;
    int a, k = 1;

    while (cour >> a >> A >> B >> C)
    {
        if (B == this->sur_name + '_' + this->Name)
        {
            cout << k << ' ';
            replace(C);
            cout << '\t';
            cout << A << endl;
        }
    }
    cour.close();
}

int Faculty::view_students(const string &cour_id)
{
    string waste;
    string p;
    string grade;
    string n;

    int k = 1;
    int l = 0;
    ifstream newone("student_courses.txt");

    if (check_course(cour_id, this->sur_name + '_' + this->Name) == 1)
    {
        cout << "S.No"
             << " | "
             << "Student_ID"
             << " | "
             << "Grade\n\n"
             << endl;
        ;
        while (newone >> p >> waste >> waste >> n >> grade)
        {
            if (waste == cour_id)
            {
                cout << k << " | " << p << " | " << grade << endl;
                k++;
            }
        }
        newone.close();

        cout << "What would you like to do:\n\n"
             << endl;
        cout << "1 . Give Grades " << endl;
        cout << "2 . Back" << endl;
        cin >> k;

        switch (k)
        {
        case 1:
        {
            string id, waste2;

            cout << "Enter the Student Id whose grade you would like to change :";
            cin >> id;

            if (checking_student1(id, cour_id) == 0)
            {
                ifstream point("student_courses.txt", ios::in);
                ofstream of("temp3.txt", ios::app);

                while (point >> p >> waste >> waste2 >> n >> grade)
                {
                    if (id == p && waste2 == cour_id && grade == "N/A")
                    {
                        cout << "Enter the grade of the student :";
                        cin >> grade;
                        of << p << ' ' << waste << ' ' << waste2 << ' ' << n << ' ' << grade << endl;
                    }
                    else
                    {
                        of << p << ' ' << waste << ' ' << waste2 << ' ' << n << ' ' << grade << endl;
                    }
                }
                point.close();
                of.close();
                remove("student_courses.txt");
                rename("temp3.txt", "student_courses.txt");
                k = 0;
            }
            else
            {
                cout << "Please check the student ID (or) Grade has already been given" << endl;
                sleep(1);
                system("cls");
            }
            l = 1;
            system("cls");
            break;
        }
        default:
        {
            break;
        }
        }
        if (k == 0)
        {
            cout << "Updated!!";
            sleep(1);
            system("cls");
        }
    }
    else
    {
        cout << "Please enter correct course-Id" << endl;
        sleep(1);
        system("cls");
    }
    return l;
}