#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "Admin.h"
#include "Faculty.h"
#include "Functions.h"

using namespace std;

class Student
{
    string sur_name;
    string Name;

    string ID;
    string Password;

    friend class Admin;
    friend int checking(const string &);
    friend int check_credentials(const string &, const string &);

public:
    int checking(const string &A);

    void intro();

    void view_profile();

    void view_courses();

    int add_courses_sub(int opt, const string &I);

    int add_courses(const string &Q);
};

#endif
