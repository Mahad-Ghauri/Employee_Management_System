#include "Admin.h"

int main()
{
start:
    Admin a1;
    Sleep(2000);
    system("CLS");
    cout << "\n";
    cout << "\t\t\t\t*************************************************" << endl;
    cout << "\t\t\t\t**=============================================**" << endl;
    cout << "\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t**|           MAG Inc, Corporation            |**" << endl;
    cout << "\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t**=============================================**" << endl;
    cout << "\t\t\t\t*************************************************" << endl;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\t\t\t***********************************************************************************" << endl;
    cout << "\t\t\t**===============================================================================**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                        EMPLOYEE MANAGEMENT SYSTEM                           |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t**|                                                     - Made By Mahad Team    |**" << endl;
    cout << "\t\t\t**===============================================================================**" << endl;
    cout << "\t\t\t***********************************************************************************" << endl;
    cout << "\n";
    cout << "\n\n\t\tSystem is loading pls wait";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(1000); // will freeze the program for given time stores time in millisec
    }

    system("CLS"); // Clear the screen
    char select;
    cout << "\n\n\t\tSelect 1 to SIGN UP by adding username and password." << endl;
    cout << "\n\n\t\tSelect 2 to Login." << endl;
    cout << "\n\n\t\tSelect 3 if you forgot your password." << endl;
    select = getch(); // to get small characters without displaying them.
    switch (select)
    {
    case '1':
        a1.Admin_Sign_Up();
        break;
    case '2':
    point:
        a1.Admin_Login();
        break;

    case '3':
        a1.Password_Recovery_Option_For_Admin();
        goto point;
        break;

    default:
        cout << "\n\n\t\tEnter a valid option ";
        goto start;
    }

    return 0;
}