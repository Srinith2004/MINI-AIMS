#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> 
#include <unistd.h>
#include "Admin.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

int checking(const string&);

int checking_student(const string&);

int checking_course(const string &);

int checking_faculty(const string &);

int checking_student1(const string &,const string&);

void replace(const string& B);

int check_course(const string & A,const string &B);

int check_credentials(const string& id,const string& pass);

class Course
{
    string course_name;
    string course_ID;
    string course_instructor;
    int status;
    friend class Admin;
};

#endif
