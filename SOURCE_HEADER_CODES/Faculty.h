#ifndef _FACULTY_H_
#define _FACULTY_H_

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "Admin.h"
#include "Student.h"
#include "Functions.h"

using namespace std;

class Faculty
{
    string sur_name;
    string Name;

    string ID;
    string Password;

    friend class Admin;
    friend int check_credentials(const string &, const string &);

public:
    void intro();

    void view_profile();

    int view_students(const string &cour_id);
};

#endif
