#include "Admin.h"

/*
1--> SetConsoleTextAttribute is Window API which is peresent inn the <windows.h> header file
2--> GetStdHandle is another WIndow API which is also present in <windows.h> header file
3--> The STD_OUTPUT_HANDLE  is a const that is used to specify that we want to handle the standard output device (Console Screen)
4--> It's the colour attribute that you want to set and it is passed to SetConsoleTextAttribute
*/



int main()
{

    Admin a1;

    system("CLS");

    cout << "\n";

    SetColor(14);

    cout << "\t\t\t\t\t\t\t*************************************************" << endl;
    cout << "\t\t\t\t\t\t\t**|===========================================|**" << endl;
    cout << "\t\t\t\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t\t\t\t**|           MAA Inc, Corporation            |**" << endl;
    cout << "\t\t\t\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t\t\t\t**|                                           |**" << endl;
    cout << "\t\t\t\t\t\t\t**|===========================================|**" << endl;
    cout << "\t\t\t\t\t\t\t*************************************************" << endl;
    cout << "\n";
    cout << "\n";
    cout << "\n";

    SetColor(14); 

    cout << "\t\t\t\t\t***********************************************************************************" << endl;
    cout << "\t\t\t\t\t**===============================================================================**" << endl;
    cout << "\t\t\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t\t\t**|                        EMPLOYEE MANAGEMENT SYSTEM                           |**" << endl;
    cout << "\t\t\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t\t\t**|                                                                             |**" << endl;
    cout << "\t\t\t\t\t**|                                                     - Made By Mahad Team    |**" << endl;
    cout << "\t\t\t\t\t**===============================================================================**" << endl;
    cout << "\t\t\t\t\t***********************************************************************************" << endl;
    cout << "\n";

    SetColor(3);
    cout << "\n\n\t\tSystem is loading please wait";

    SetColor(15); // White color
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(1000);
    }

    system("CLS");

    bool found = true;
    char select;
    while (found)
    {
    start:
        system("CLS");
        cout << "\n\n";
        SetColor(11); 
        cout << "\t\t\t _____________________________________________ " << endl;
        cout << "\t\t\t|                                             |" << endl;
        cout << "\t\t\t|          1--> To SIGN UP                    |" << endl;
        cout << "\t\t\t|          2--> To Login.                     |" << endl;
        cout << "\t\t\t|          3--> Forgot your Password          |" << endl;
        cout << "\t\t\t|          4--> To exit the program           |" << endl;
        cout << "\t\t\t|_____________________________________________|" << endl;

        SetColor(15);    

        select = getch(); 
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
            SetColor(12); 
            cout << "\n\n\t\tEnter a valid option ";
            Sleep(1000);
            goto start;
        }
    }

    return 0;
}