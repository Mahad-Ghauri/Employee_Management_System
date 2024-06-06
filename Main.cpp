#include "Admin.h"

int main()
{

    Admin a1;
    Sleep(2000);
    system("CLS");
    cout << "\n";
    cout << "\t\t\t\t\t*************************************************" << endl;
    cout << "\t\t\t\t\t**|===========================================|**" << endl;
    cout << "\t\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t\t**|           MAA Inc, Corporation            |**" << endl;
    cout << "\t\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t\t**|===========================================|**" << endl;
    cout << "\t\t\t\t\t*************************************************" << endl;
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
    cout << "\n\n\t\tSystem is loading please wait";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(1000); // will freeze the program for given time stores time in millisec
    }

    system("CLS"); // Clear the screen
    bool found = true;
    char select;
    while (found)
    {

        start:
        system("CLS");
        cout << "\n\n";
        cout << "\t\t\t _____________________________________________ " << endl;
        cout << "\t\t\t|                                             |" << endl;
        cout << "\t\t\t|          1--> To SIGN UP                    |" << endl;
        cout << "\t\t\t|          2--> To Login.                     |" << endl;
        cout << "\t\t\t|          3--> Forgot your Password          |" << endl;
        cout << "\t\t\t|          4--> To exit te program            |" << endl;
        cout << "\t\t\t|_____________________________________________|" << endl;
        select = getch(); // to get small characters without displaying them.
        switch (select)
        {
        case '1':
            a1.Admin_Sign_Up();
            break;

        case '2':
            if (a1.Admin_Login() == false)
            {
                goto start;
            }

            break;

        case '3':
            a1.Password_Recovery_Option_For_Admin();
            break;

        case '4':
            found = false;
            break;

        default:
            cout << "\n\n\t\tEnter a valid option ";
            Sleep(1000);
            goto start;
        }
    }

    return 0;
}