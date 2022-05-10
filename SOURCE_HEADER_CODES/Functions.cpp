#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "Admin.h"
#include "Student.h"
#include "Faculty.h"
#include "Functions.h"

void replace(const string &B) 
{
    int i = 0;
    for (i = 0; i < B.length(); i++)
    {
        if (B[i] == '_')
        {
            cout << ' ';
        }
        if (B[i] == ' ')
        {
            cout << " | ";
        }
        if (B[i] != '_' && B[i] != ' ')
        {
            cout << B[i];
        }
    }
}

int check_course(const string &A, const string &B)
{
    ifstream cour("courses.txt");

    string p, q;
    int a;

    while (cour >> a >> p >> q)
    {
        if (p == A && q == B)
        {
            return 1;
            break;
        }
        cour >> q;
    }
    cour.close();
    return 0;
}

int checking_student(const string &A) 
{
    ifstream checking("DATABASE.txt");
    string w1;
    int a;

    while (checking >> a >> w1 >> w1 >> w1)
    {
        if (w1 == A && a == 2)
        {
            return 0;
        }
        checking >> w1;
    }
    checking.close();
    return 1;
}

int checking_student1(const string &A, const string &B)
{
    ifstream checking("student_courses.txt");
    string w1, w2, w3;

    while (checking >> w1 >> w2 >> w2 >> w3 >> w3)
    {
        if (w1 == A && w2 == B && w3 == "N/A")
        {
            return 0;
        }
    }
    checking.close();
    return 1;
}

int checking_faculty(const string &A)
{
    ifstream checking("DATABASE.txt");
    string w1, w2;
    int a;

    while (checking >> a >> w1 >> w2)
    {
        if (w1 + ' ' + w2 == A && a == 3)
        {
            return 1;
        }
        checking >> w1 >> w2;
    }
    checking.close();
    return 0;
}

int checking_course(const string &A)
{
    ifstream checking("courses.txt");
    string w1;
    int a;

    while (checking >> a >> w1)
    {
        if (w1 == A)
        {
            return 0;
        }
        checking >> w1 >> w1;
    }
    checking.close();
    return 1;
}
