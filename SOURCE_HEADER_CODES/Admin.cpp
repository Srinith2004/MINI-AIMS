#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "Admin.h"
#include "Student.h"
#include "Faculty.h"
#include "Functions.h"

void Admin::intro()  // Prints the options we have at the beginning as a Admin .
{
    cout << "What would you like to do:\n\n"
         << endl;
    cout << "1. View Profile" << endl;
    cout << "2. ADD/REMOVE Students" << endl;
    cout << "3. ADD/REMOVE Courses" << endl;
    cout << "4. View Courses" << endl;
    cout << "5. ADD/REMOVE Courses from Student" << endl;
    cout << "6. Exit\n"
         << endl;
}

int Admin::add_students()  // Adds / Removes Students from IITH .
{
    int k = 1, opt = 0, l = 0;

    cout << "The Students registered at IITH are \n\n\n";

    ifstream newone("DATABASE.txt");

    string A, B, C;
    int type;

    while (newone >> type >> A >> B >> C)
    {
        if (type == 2)
        {
            cout << k << " | ";
            cout << A << "  " << B << " | " << C;
            cout << "\n";
            k++;
        }
        newone >> C;
    }
    k = 0;
    cout << "\n\n\n";
    newone.close();

    cout << "Choose of the following :\n\n"
         << endl;
    cout << "1 . ADD Student" << endl;
    cout << "2 . REMOVE Student" << endl;
    cout << "3 . Back" << endl;
    cin >> opt;

    string line;

    switch (opt)
    {
    case 1:
    {
        Student new_student;

        cout << "Enter the new Student's Sur name :" << endl;
        cin >> new_student.sur_name;

        cout << "Enter the new Student's name :" << endl;
        cin >> new_student.Name;

        cout << "Enter the Student's ID :" << endl;
        cin >> new_student.ID;

        cout << "Enter the Student's Password :" << endl;
        cin >> new_student.Password;

        ofstream newfilepointer("DATABASE.txt", ios::app);

        if (checking_student(new_student.ID) == 1)
        {
            newfilepointer << '2' << ' ' << new_student.sur_name
                           << ' ' << new_student.Name << ' ' << new_student.ID
                           << ' ' << new_student.Password << "\n";
            k = 1;
        }
        else
        {
            cout << "A Student is already registered with that ID!!" << endl;
            sleep(1);
            system("cls");
        }
        newfilepointer.close();
        l = 1;
        break;
    }
    case 2:
    {
        cout << "Enter the Student ID you want to de-register from IITH :" << endl;
        cin >> A;

        ifstream in("DATABASE.txt", ios::in);
        ofstream of("temp5.txt", ios::app);

        string D, E;
        int a;

        while (in >> a >> B >> C >> D >> E)
        {
            if (A == D)
            {
                k = 1;
            }
            else
            {
                of << a << ' ' << B << ' ' << C << ' ' << D << ' ' << E << "\n";
            }
        }
        in.close();
        of.close();
        remove("DATABASE.txt");
        rename("temp5.txt", "DATABASE.txt");

        if (k == 0)
        {
            cout << "Please enter correct Student ID (or) Can't de-register because No student exist" << endl;
            sleep(1);
            system("cls");
        }
        else
        {
            ifstream in1("student_courses.txt", ios::in);
            ofstream of1("temp6.txt", ios::app);

            while (in1 >> D)
            {
                getline(in1, E);
                if (D != A)
                {
                    of1 << D << ' ' << E << "\n";
                }
            }
            in1.close();
            of1.close();
            remove("student_courses.txt");
            rename("temp6.txt", "student_courses.txt");
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

int Admin::add_courses()  //  Adds / Removes courses from IITH .
{
    int k = 1, opt = 0, l = 0;

    ifstream cour("courses.txt");
    cout << "The courses available at present are \n\n\n"
         << endl;

    int a;
    string line;
    while (cour >> a)
    {
        getline(cour, line);
        if (a == 1)
        {
            cout << k << " | " << "Open";
            replace(line);
            cout << "\n";
            k++;
        }
        else
        {
            cout << k << " | " << "Closed";
            replace(line);
            cout << "\n";
            k++;
        }
    }
    k = 0;
    cout << "\n\n\n";
    cour.close();

    cout << "Choose of the following :\n\n"
         << endl;
    cout << "1 . ADD Course" << endl;
    cout << "2 . REMOVE Course" << endl;
    cout << "3 . Back" << endl;
    cin >> opt;

    switch (opt)
    {
    case 1:
    {
        Course B;

        cout << "Enter the new Course's name :" << endl;
        getline(cin, B.course_name);
        getline(cin, B.course_name);

        cout << "Enter the Course's ID :" << endl;
        cin >> B.course_ID;

        cout << "Enter the new Course's Instructor :" << endl;
        getline(cin, B.course_instructor);
        getline(cin, B.course_instructor);

        cout << "Do you want this Course to be open or closed ?" << endl;
        cout << "Enter 1 for open and 0 for closed" << endl;
        cin >> B.status;

        if (checking_faculty(B.course_instructor) == 1 && checking_course(B.course_ID) == 1)
        {
            ofstream newfilepointer("courses.txt", ios::app);

            newfilepointer << B.status << ' ' << B.course_ID << ' ';

            int i = 0;
            for (i = 0; i < B.course_instructor.length(); i++)
            {
                if (B.course_instructor[i] == ' ')
                {
                    newfilepointer << '_';
                }
                else
                {
                    newfilepointer << B.course_instructor[i];
                }
            }

            i = 0;
            newfilepointer << ' ';
            for (i = 0; i < B.course_name.length(); i++)
            {
                if (B.course_name[i] == ' ')
                {
                    newfilepointer << '_';
                }
                else
                {
                    newfilepointer << B.course_name[i];
                }
            }

            newfilepointer << "\n";

            newfilepointer.close();
            k = 1;
        }
        else
        {
            cout << "A Course is already present!! (OR) Instructor do not exist" << endl;
            sleep(1);
            system("cls");
        }
        l = 1;
        break;
    }
    case 2:
    {
        string A, B, C;

        cout << "Enter the Course ID you want to de-register from IITH :" << endl;
        cin >> line;

        if (checking_course(line) == 0)
        {
            ifstream in("courses.txt", ios::in);
            ofstream of("temp8.txt", ios::app);

            int a;

            while (in >> a >> A >> B >> C)
            {
                if (A == line)
                {
                    k = 1;
                }
                else
                {
                    of << a << ' ' << A << ' ' << B << ' ' << C << "\n";
                }
            }
            in.close();
            of.close();
            remove("courses.txt");
            rename("temp8.txt", "courses.txt");

            string line1;

            ifstream in1("student_courses.txt", ios::in);
            ofstream of1("temp9.txt", ios::app);

            while (in1 >> A >> B >> C)
            {
                getline(in1, line1);
                if (line != C)
                {
                    of1 << A << ' ' << B << C << line1 << "\n";
                }
            }
            in1.close();
            of1.close();
            remove("student_courses.txt");
            rename("temp9.txt", "student_courses.txt");
        }
        else
        {
            cout << "Please enter correct Course ID (or) Can't de-register because No course exist" << endl;
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

int Admin::view_courses()  // View the courses present at IITH .
{
    ifstream cour("courses.txt");
    cout << "The courses available at present are \n\n\n"
         << endl;

    int a;
    string line;
    int k = 1;
    while (cour >> a)
    {
        getline(cour, line);
        if (a == 1)
        {
            cout << k << " | " << "Open";
            replace(line);
            cout << "\n";
            k++;
        }
        else
        {
            cout << k << " | " << "Closed";
            replace(line);
            cout << "\n";
            k++;
        }
    }
    cour.close();

    cout << "What would you like to do?\n\n"
         << endl;
    cout << "1.Change the availability of course" << endl;
    cout << "2.Exit" << endl;

    cin >> k;
    a = 0;
    switch (k)
    {
    case 1:
    {
        cout << "Enter the course Id for which you would you like to change its availability?\n\n"
             << endl;
        cin >> line;

        string A, B, C;
        int lam;

        if (checking_course(line) == 0)
        {
            ifstream inte("courses.txt", ios::in);
            ofstream of("temp.txt", ios::app);

            while (inte >> lam >> A >> B >> C)
            {
                if (A == line)
                {
                    if (lam == 1)
                    {
                        of << '0' << ' ' << A << ' ' << B << ' ' << C << "\n";
                    }
                    else
                    {
                        of << '1' << ' ' << A << ' ' << B << ' ' << C << "\n";
                    }
                }
                else
                {
                    of << lam << ' ' << A << ' ' << B << ' ' << C << "\n";
                }
            }
            inte.close();
            of.close();

            remove("courses.txt");
            rename("temp.txt", "courses.txt");
            k = 0;
        }
        else
        {
            cout << "Please enter correct course-ID" << endl;
            sleep(1);
        }
        a = 1;
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
    return a;
}

int Admin::add_students_courses(const string &student_id)  // Adds / Removes students from any course .
{
    int opt = 0, a = 0;
    if (checking_student(student_id) == 0)
    {
        Student STUDENT;
        STUDENT.ID = student_id;

        cout << "The courses the student registered to are \n\n\n";

        STUDENT.view_courses();

        cout << "Choose of the following :\n\n"
             << endl;
        cout << "1 . ADD COURSE" << endl;
        cout << "2 . REMOVE COURSE" << endl;
        cout << "3 . Back" << endl;
        cin >> opt;

        switch (opt)
        {
        case 1:
        {
            a = STUDENT.add_courses_sub(2, "*");
            break;
        }

        case 2:
        {
            a = STUDENT.add_courses_sub(3, "*");
            break;
        }
        default:
        {
            break;
        }
        }
    }
    else
    {
        cout << "Please enter corect student ID" << endl;
        sleep(1);
    }
    return a;
}

void Admin::view_profile()  // View the profile of the admin .
{
    cout << "Name : " << this->Name << "\n"
         << endl;
    cout << "ID :" << this->ID << "\n"
         << endl;
}