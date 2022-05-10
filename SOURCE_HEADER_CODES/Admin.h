#ifndef _ADMIN_H_
#define _ADMIN_H_

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "Student.h"
#include "Faculty.h"
#include "Functions.h"

using namespace std;

class Admin
{
    string sur_name;
    string Name;

    string ID;
    string Password;
    
    friend int check_credentials(const string &, const string &);

public:
    int add_students();

    int add_courses();

    void intro();

    int view_courses();

    int add_students_courses(const string &student_id);

    void view_profile();
};

#endif
