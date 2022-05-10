/* 

    Code by Dasari Srinith (cs21btech11015)

    compile the code as
        g++ -c Admin.cpp Faculty.cpp Student.cpp Functions.cpp main.cpp
        g++ -o output Admin.o Faculty.o Student.o Functions.o main.o
    to get executable file with name "output"

    Information about text files:
        * DATABASE.txt --> Has information of users in the order of
            (Type of user) (Surname) (Name) (Id) (Password)
                |
                |__\  1-> Admin
                    /  2-> Student
                        3-> Faculty

        * courses.txt --> Has information of courses at IITH in the order of
            (Mode) (CourseID) (Instructor name{Has hyphenes to connect two names just to read/*ignore/*}) (CourseName)  
            |
            |__\  0-> Closed(Not floated)
                / 1-> Open(floated)      

        * student_courses.txt --> Has information of all students who registered to courses in the order of
            (StduentID) (CourseName) (CourseID) (Instructor) (Grade)
    
    Discription of few methods of class can be understood by what is being printed from the else statement.

    In this model of mini AIMS , the faculty can teach different courses.

    NOTE : Adding Faculty in and removing out from IITH is not a feature in this model.
    
*/


#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include "Admin.h"
#include "Faculty.h"
#include "Student.h"
#include "Functions.h"

using namespace std;

Admin X;

Student Y;

Faculty Z;

int login(int type)  // For the options the user can have after entering proper credentials.
{
    int a=0,t=0,v=0;

    switch(type)
    {
        case 1:
        {
            X.intro();    
            cin>>a;
            system("cls");

            switch(a)
            {
                case 1:
                {
                    X.view_profile();
                    cout<<"\n\n\n";
                    cout<<"1 .Back"<<endl;
                    cin>>v;
                    break;
                }
                case 2:
                {
                    int l;
                    l = X.add_students();
                    while(l==1)
                    {
                        l=X.add_students();
                    }
                    break;
                }
                case 3:
                {
                    int l;
                    l = X.add_courses();
                    while (l==1)
                    {
                        l =X.add_courses();
                    }
                    break;
                }
                case 4:
                {
                    int l;
                    l = X.view_courses();
                    while(l==1)
                    {
                       l = X.view_courses();
                    }
                    break;
                }
                case 5:
                {
                    string student_id;
                    int opt=0,a;

                    cout << "Enter the sudent ID whose courses you would like to change: "<<endl;
                    cin>> student_id;

                    int l;
                    l = X.add_students_courses(student_id);
                    while(l==1)
                    {
                        l = X.add_students_courses(student_id);
                    }
                    break;
                }
                default:
                {
                    t=1;
                    break;
                }
            }
            break;
        }
        
        case 2:
        {
            Y.intro();
            cin>>a;
            system("cls");  
            
            switch(a)
            {
                case 1:
                {
                    Y.view_profile();
                    cout<<"\n\n\n";
                    cout<<"1 .Back"<<endl;
                    cin>>v;
                    break;
                }
                case 2:
                {
                    Y.view_courses();
                    cout<<"\n\n\n";
                    cout<<"1 .Back"<<endl;
                    cin>>v;
                    break;
                }
                case 3:
                {
                    int l;
                    l = Y.add_courses("N/A");
                    while(l==1)
                    {
                        l=Y.add_courses("N/A");
                    }
                    break;
                }
                default :
                {
                    t=1;
                    break;
                }
            }
            break;
        }
       
        case 3:
        {
            Z.intro();
            cin>>a;
            system("cls");

            switch(a)
            {
                case 1:
                {
                    Z.view_profile();
                    cout<<"\n\n\n";
                    cout<<"1 .Back"<<endl;
                    cin>>v;
                    break;
                }
                case 2:
                {
                    string B;
                    int l;

                    cout<<"Enter the course -ID from your courses for which you want to see the students registered :"<<endl;
                    cin >> B;
                   
                    l = Z.view_students(B);
                    while(l==1)
                    {
                        l=Z.view_students(B);
                    }
                    break;
                }
                default:
                {
                    t=1;
                    break;
                }
            }
            break;
        }
       
        default:
        {
            break;
        }
    }
    if(t==1)
    {
        cout<<"Thankyou!!"<<endl;
        cout<<"Exiting in 3..";
        sleep(1);
        cout<<"2..";
        sleep(1);
        cout<<"1..";
        sleep(1);
    }
    else
    {
        system("cls");
    }
    return t;
}

int check_credentials(const string& id,const string& pass)  //Checking the credentials submitted
{
    string sur_name;
    string student_name;

    string user_ID;
    string user_Password;

    int typeofman;
       
    ifstream check("DATABASE.txt");
    string subtype;

    while(check >> typeofman >> sur_name >> student_name >> user_ID >> user_Password)
    {
        if(id == user_ID && pass == user_Password)
        {
            switch (typeofman)
            {
                case 1:
                {
                    X.sur_name = sur_name;
                    X.Name = student_name;
                    X.ID = user_ID;
                    X.Password = user_Password;
                    break;
                }
                case 2:
                {
                    Y.sur_name = sur_name;
                    Y.Name = student_name;
                    Y.ID = user_ID;
                    Y.Password = user_Password;
                    break;
                }
                case 3:
                {
                    Z.sur_name = sur_name;
                    Z.Name = student_name;
                    Z.ID = user_ID;
                    Z.Password = user_Password;
                    break;
                }
                default:                    
                {
                    break;
                }
            }
            return typeofman;
        }
    }
    return 0;         
}

int main()
{  
    system("cls");

    string login_id;
    string login_pass;
    int type,t;
    
    cout << "Welcome!!\n\n"<<endl;
    cout << "ENTER YOUR ID AND PASSWORD\n\n"<<endl;
    cout << "ID : ";
    cin >> login_id;
    cout << "\nPASSWORD : ";
    cin >> login_pass;

    system("cls");

    while((type=check_credentials(login_id,login_pass))==0)
    {
        cout<<"Please enter the proper credentials"<<endl;
        sleep(1);

        system("cls");

        cout << "Welcome!!\n\n"<<endl;
        cout << "ENTER YOUR ID AND PASSWORD\n\n"<<endl;
        cout << "ID : ";
        cin >> login_id;
        cout << "\nPASSWORD : ";
        cin >> login_pass;

        system("cls");
    }

    cout << "Login Succesful!" << endl;
    sleep(1);
    system("cls");
    
    t = login(type);

    while (t==0)
    {
        t = login(type);
    }
    return 0;
}
