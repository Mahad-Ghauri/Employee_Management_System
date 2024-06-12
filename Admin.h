#ifndef ADMIN_H
#define ADMIN_H

#include "Manager.h"
#include <ctime>   // for time()
#include <cstdlib> // for rand()

void SetColor(int value)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

class Admin : public Manager
{
private:
    int _total_manager;
    int _manager_add;
    int _otp;

public:
    // Admin's
    Admin()
    {
        _total_employees = 0;
        _total_manager = 0;
    }

    bool Is_Strong_Username(const string &_user_name)
    {
        bool _has_upper_case = false;
        bool _has_lower_case = false;
        bool _has_symbol = false;

        for (int i = 0; i < _user_name.length(); i++) // loop executing on each character of the username.
        {
            if (isupper(_user_name[i])) // Built-in functions check for uppercase letters
            {
                _has_upper_case = true;
            }
            else if (islower(_user_name[i])) // Built-in functions  check for lowercase letters
            {
                _has_lower_case = true;
            }
            else if (ispunct(_user_name[i])) // Built-in functions  check for punctuation(symbol)
            {
                _has_symbol = true;
            }
            if (_has_upper_case == true && _has_lower_case == true && _has_symbol == true)
            {
                return true;
            }
        }
        return false;
    }

    void Admin_Sign_Up()
    {
        ifstream check_existingID("AdminUserPass.txt");
        string _enter_id;
        string existingID;
        register bool match;
        register bool found = false;

    point: // point declared here will come here if username requirements not met
        system("CLS");
        string username, password;

        SetColor(14);
        cout << "\t\t\t===============================================================" << endl;
        cout << "\t\t\t               Employee Management System                      " << endl;
        cout << "\t\t\t===============================================================" << endl;

        SetColor(15);
        cout << "\n\n\t\tPlease SIGN UP by adding username and password " << endl;

        cout << "\n\n\t\tEnter Username :  ";
        getline(cin, username);

        if (username.length() <= 6 || !Is_Strong_Username(username))
        {
            SetColor(12);
            cout << "\tThe username must consist of more than six characters "
                 << "and consist of at-least one upper case one lowercase and one symbol. " << endl;
            cout << endl;
            Sleep(5000);
            goto point;
        }
        else if (username.length() >= 20 || !Is_Strong_Username(username))
        {
            SetColor(12);
            cout << "\tThe username must consist of less than twenty characters "
                 << "and consist of at-least one upper case one lowercase and one symbol. " << endl;
            cout << endl;
            Sleep(3000);
            goto point;
        }

        SetColor(15);
        cout << "\n\n\t\tPassword : ";
        char pass; // Password is taken in char thats make it easy to convert it into asterik

        while ((pass = _getch()) != '\r') // loop will execute for each character until enter is pressed
        {
            if (pass >= 32 && pass <= 126)
            {
                cout << '*';
                password.push_back(pass); // will add new character.
            }
            else if (pass == 8 && password.length() > 0) // dealing with if backspace is pressed
            {
                password.pop_back(); // will remove last charcter
                cout << "\b \b";
            }
        }
        if (password.length() < 5)
        {
            SetColor(12);
            cout << " \t The password length should be more than 5  " << endl;
            Sleep(2000);
            goto point;
        }
        while (getline(check_existingID, existingID))
        { // this part checks if admin username already exists
            if (existingID == username)
            {
                found = true;
                break;
            }
        }
        check_existingID.close();
        if (found)
        {
            SetColor(10);
            cout << endl;
            cout << setw(80) << " =================================" << endl;
            cout << setw(80) << "| ID already exists.              |" << endl;
            cout << setw(80) << "| Redirecting to login page.....  |" << endl;
            cout << setw(80) << " =================================" << endl;
            Sleep(4000);
            system("CLS");
            SetColor(15);
            Admin_Login();
        }
        else
        {
            SetColor(15);    
            fstream file;
            file.open("AdminUserPass.txt", ios::out | ios::app);
            if (!file.is_open())
            {
                cout << "\tError opening file.";
            }

            file << username << "\n";
            file << password << "\n";
            file.close();

            SetColor(3);
            cout << "\n\n\t\tYour ID is being created.Please Wait ";

            SetColor(15);
            for (int i = 0; i < 4; i++) // used to make a delay on the screen
            {
                cout << ".";
                Sleep(1000);
            }

            SetColor(15);    
            Sleep(1000);
            cout << "\n\n\t\tYour ID HAS BEEN CREATED ";
            system("CLS");
        }
    }

    bool Admin_Login()
    {
    start: // start point will come here in case of logging out
        system("CLS");
        string username_1, pass_1, password, username;
        bool match = false; // bool found used to check conditions

        SetColor(14);
        cout << "\t\t\t===============================================================" << endl;
        cout << "\t\t\t               Employee Management System                      " << endl;
        cout << "\t\t\t===============================================================" << endl;

SetColor(15);    
        cout << "\n\n\t\tPlease Login by entering username and password " << endl;

        cout << "\n\n\t\tEnter Username:  ";
        getline(cin, username_1);
        cout << "\n\n\t\tPassword: ";
        char pass;
        while ((pass = _getch()) != '\r')
        {
            if (pass >= 32 && pass <= 126) // ASCII values of the characters
            {
                cout << '*';
                pass_1.push_back(pass); // push_back moves to the next character and its storing the password in pass_1 variable after going through its all characters
            }
            else if (pass == 8 && pass_1.length() > 0) // 8 refers to the ASCII value of backspace
            {
                pass_1.pop_back(); // pop back moves to the previous character
                cout << "\b \b";
            }
        }

        cout << "\n";

        ifstream file;
        file.open("AdminUserPass.txt");
        if (!file.is_open())
        {
            SetColor(12);
            cout << "\n\n\t\tAdmin with this username and password donot exist in your system " << endl;
            cout << "\n\t\tFirst of all SIGN-UP then do the login " << endl;
            Sleep(1000);
            return false;
        }

        while (getline(file, username) && file >> password) // reading until the data in the file is finished
        {
            file.ignore(1000, '\n'); // setting a limit of ignoring unwanted characters until newline characters (removes input buffer)
            if (username == username_1 && password == pass_1)
            {
                match = true;
                break;
            }
        }
        file.close();

        if (match)
        {

            // Doing 2 factor authentication for the admin login (for a scrueity purpose)

            _otp = Generate_OTP();
            int _user_otp;

            SetColor(3);
            cout << "\n";
            cout << "\t\t\t ________________________ " << endl;
            cout << "\t\t\t|                        |" << endl;
            cout << "\t\t\t|      OTP: " << setw(10) << left << _otp << "   |" << endl;
            cout << "\t\t\t|________________________|" << endl;

            Sleep(4000);
            system("CLS"); // for making the otp disappear after few seconds
        OTP:
        SetColor(15);    
            cout << "\n\t\tEnter the OTP: ";
            cin >> _user_otp;
            if (cin.fail())
            {
                SetColor(12);
                cout << "\t\tInvalid  Input!!! . Enter integers only " << endl;
                goto OTP;
            }

            SetColor(3);
            cout << "\n\t\t Checking for the authentication";

            SetColor(15);
            for (int i = 0; i < 4; i++)
            {
                cout << ".";
                Sleep(1000);
            }

            cout << "\n";

            if (_otp == _user_otp)
            {
                SetColor(10);
                cout << "\t\t\t    ______________________________________ " << endl;
                cout << "\t\t\t   |                                      |" << endl;
                cout << "\t\t\t   |       Authentication Successful      |" << endl;
                cout << "\t\t\t   |______________________________________|" << endl;

                Sleep(1000);
                system("CLS");

                SetColor(14);
                cout << "\n";
                cout << " \t \t \t \t Login Successful " << endl
                     << endl;

                cout << "\t\t\t===============================================================" << endl;
                cout << "\t\t\t                       Welcome  Admin                          " << endl;
                cout << "\t\t\t===============================================================" << endl;
                cout << "\n";
                Sleep(2000);

                bool found;
                char mainchoice, subchoice_a, subchoice_b;

                system("CLS");
                SetColor(15);    
                Set_Total_Employees();
                Set_Total_Managers();

            Menu:
                system("CLS");

                SetColor(11);
                cout << "\t\t\t------------Choose from below----------- " << endl;
                cout << "\t\t\t _______________________________________" << endl;
                cout << "\t\t\t|                                       |" << endl;
                cout << "\t\t\t|      1--> Manage Managers             |" << endl;
                cout << "\t\t\t|      2--> Manage Employees            |" << endl;
                cout << "\t\t\t|      3--> Exit the program            |" << endl;
                cout << "\t\t\t|_______________________________________|" << endl;
                mainchoice = getch();

                SetColor(15);    
                switch (mainchoice)
                {
                case '1':

                point_a:
                    system("CLS");

                    SetColor(11);
                    cout << "\t\t\t------------Choose from below----------- " << endl;
                    cout << "\t\t\t _______________________________________" << endl;
                    cout << "\t\t\t|                                       |" << endl;
                    cout << "\t\t\t|      1--> Number of managers          |" << endl;
                    cout << "\t\t\t|      2--> Add Managers                |" << endl;
                    cout << "\t\t\t|      3--> Search Managers             |" << endl;
                    cout << "\t\t\t|      4--> Delete Managers             |" << endl;
                    cout << "\t\t\t|      5--> Update Managers             |" << endl;
                    cout << "\t\t\t|      6--> Show All Managers           |" << endl;
                    cout << "\t\t\t|      7--> Managers Sign-Up            |" << endl;
                    cout << "\t\t\t|      8--> Managers Login              |" << endl;
                    cout << "\t\t\t|      9--> Go back                     |" << endl;
                    cout << "\t\t\t|_______________________________________|" << endl;
                    subchoice_a = getch();

                    SetColor(15);    
                    switch (subchoice_a)
                    {
                    case '1':
                    a:
                        Set_Number_Of_Managers();
                        if (Get_Total_Number_Of_Managers() >= Get_Number_Of_Managers())
                        {
                            goto point_a;
                        }
                        else
                        {
                            cout << "\t You have entered greater number of managers than ";
                            cout << "the total number of manager " << endl;
                            cout << "\t\tTotal Number of Managers: " << Get_Total_Number_Of_Managers() << endl;
                            Sleep(1000);
                            goto a;
                        }
                        break;

                    case '2':
                        if (Get_Total_Number_Of_Managers() >= Get_Manager_Number())
                        {
                            Add_Manager();
                        }
                        else
                        {
                            cout << "\t\tManager Count: " << Get_Manger_Count() << endl;
                            cout << "\t\tTotal Number of Managers: " << Get_Total_Number_Of_Managers() << endl;
                            cout << "\t\tMaximum number of managers are added " << endl;
                            Sleep(1000);
                            goto point_a;
                        }

                        Sleep(1000);
                        goto point_a;
                        break;

                    case '3':
                        Search_Manager_Data();
                        cin.ignore(132, '\n');
                        cin.get();
                        goto point_a;
                        break;

                    case '4':
                        Delete_Manager_Data();
                        goto point_a;
                        break;

                    case '5':
                        Update_Manager_Data();
                        goto point_a;
                        break;

                    case '6':
                        Show_All_Managers_Data();
                        cin.ignore(132, '\n');
                        cin.get();
                        goto point_a;
                        break;

                    case '7':
                        Manager_SignUp();
                        goto point_a;
                        break;

                    case '8':
                        found = Manager_Login(Get_ID());
                        ;
                        if (found == true)
                        {
                            goto point_a;
                        }
                        else if (found == false)
                        {
                            return false;
                        }
                        break;

                    case '9':
                        goto Menu;
                        break;

                    default:
                        SetColor(12);
                        cout << " Invalid choice ";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << "!";
                            Sleep(1000);
                        }
                        goto point_a;

                        break;
                    } // Finish of the  Manager cases

                    break; // Finish of maincase number 1

                case '2':

                point_b:
                    system("CLS");

                    SetColor(11);
                    cout << "\t\t\t------------Choose from below----------- " << endl;
                    cout << "\t\t\t _______________________________________" << endl;
                    cout << "\t\t\t|                                       |" << endl;
                    cout << "\t\t\t|      1--> Number of employees         |" << endl;
                    cout << "\t\t\t|      2--> Add Employee                |" << endl;
                    cout << "\t\t\t|      3--> Search Employee             |" << endl;
                    cout << "\t\t\t|      4--> Delete Employee             |" << endl;
                    cout << "\t\t\t|      5--> Update Employee             |" << endl;
                    cout << "\t\t\t|      6--> Show All Employees          |" << endl;
                    cout << "\t\t\t|      7--> Employee Sign-Up            |" << endl;
                    cout << "\t\t\t|      8--> Employee Login              |" << endl;
                    cout << "\t\t\t|      9--> Go Back                     |" << endl;
                    cout << "\t\t\t|_______________________________________|" << endl;
                    subchoice_b = getch();


                    SetColor(15);    
                    switch (subchoice_b)
                    {
                    case '1':
                    b:
                        Set_Number_Of_Employees();
                        if (Get_Total_Number_Of_Employee() >= Get_Number_Of_Employees())
                        {
                            Sleep(1000);
                            goto point_b;
                        }
                        else
                        {
                            cout << "\t You have greater number of employees than ";
                            cout << "the total number of employees " << endl;
                            cout << "\t\t Total Number of Employees: " << Get_Total_Number_Of_Employee() << endl;
                            Sleep(1000);
                            goto b;
                        }
                        break;

                    case '2':
                        if (Get_Total_Number_Of_Employee() >= Get_Employee_Number())
                        {

                            Add_Employee();
                        }
                        else
                        {
                            cout << "\t\t Employee Count: " << Get_Employee_Count() << endl;
                            cout << "\t\tTotal Number of Employees: " << Get_Total_Number_Of_Employee() << endl;
                            cout << "\t\tMaximum number of employees are added " << endl;
                            Sleep(1000);
                            goto point_b;
                        }
                        goto point_b;
                        break;

                    case '3':
                        Search_Employee_Data();
                        cin.ignore(132, '\n');
                        cin.get();
                        goto point_b;
                        break;

                    case '4':
                        Delete_Employee_Data();
                        goto point_b;
                        break;

                    case '5':
                        Update_Employee_Data();
                        goto point_b;
                        break;

                    case '6':
                        Show_All_Employees_Data();
                        cin.ignore(132, '\n');
                        cin.get();
                        goto point_b;
                        break;

                    case '7':
                        Employee_Sign_Up();
                        goto point_b;
                        break;

                    case '8':
                        found = Employee_Login(Get_ID());
                        if (found == true)
                        {
                            goto point_b;
                        }
                        else if (found == false)
                        {
                            return false;
                        }
                        break;

                    case '9':
                        Sleep(1000);
                        goto Menu;
                        break;

                    default:
                        SetColor(12);
                        cout << "\t\tInvalid choice ";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << "!";
                            Sleep(1000);
                        }
                        goto point_b;
                        break;
                    } // Finish of the cases of the Employees

                    break; // Finish of the maincase number 2

                case '3':
                    return false;
                    break;

                default:
                    SetColor(12);
                    cout << " Invalid Input ";
                    SetColor(15);    
                    for (int i = 0; i < 3; i++)
                    {
                        cout << "!";
                        Sleep(1000);
                    }
                    goto Menu;

                } // Finish of the main switch
            }
            else
            {
                SetColor(12);
                cout << "\t\t\t    ______________________________________ " << endl;
                cout << "\t\t\t   |                                      |" << endl;
                cout << "\t\t\t   |     Authentication Unsuccessful      |" << endl;
                cout << "\t\t\t   |______________________________________|" << endl;
                cout << "The login failed. Please try again." << endl;
                cin.ignore();
                Sleep(3000);
                goto start;
            }
        }
        else
        {
            cout << "\t\t The username and password didnot match in your system " << endl;
        }
    }

    void Password_Recovery_Option_For_Admin()
    {
        string username, password, username_1, password_1;
        bool match = false;

        SetColor(15);  
        cout << "\n\n\t\tEnter the username: ";
        getline(cin, username);

        cout << "\n\n\t\tEnter the last password that you have remembered: ";
        char pass;
        password.clear();
        while ((pass = _getch()) != '\r') // loop will execute for each character until enter is pressed
        {
            if (pass >= 32 && pass <= 126)
            {
                cout << '*';
                password.push_back(pass); // will add new character.
            }
            else if (pass == 8 && password.length() > 0) // dealing with if backspace is pressed
            {
                password.pop_back(); // will remove last character
                cout << "\b \b";
            }
        }

        ifstream file;
        file.open("AdminUserPass.txt");
        if (!file.is_open())
        {
            cout << "\n\n\t\tError opening the file " << endl;
            return;
        }

        while (getline(file, username_1) && file >> password_1)
        {
            file.ignore(1000, '\n'); // Ignore the rest of the line. Such as the password followed by whitespaces and special characters

            if (username == username_1 && password != password_1)
            {
                match = true;
                break;
            }
        }
        file.close();

        if (match)
        {
            cout << " \n ";
            cout << "\t\t Now enter the new username and password" << endl;

        point:
            cout << "\n\n\t\t Enter the username: ";
            getline(cin, username);
            if (username.length() <= 6 || !Is_Strong_Username(username))
            {
                SetColor(12);
                cout << "\tThe username must consist of more than six characters "
                     << "and consist of at least one upper case, one lower case, and one symbol." << endl;
                cout << endl;
                Sleep(3000);
                goto point;
            }
            else if (username.length() >= 20 || !Is_Strong_Username(username))
            {
                SetColor(12);
                cout << "\tThe username must consist of less than twenty characters "
                     << "and consist of at least one upper case, one lower case, and one symbol." << endl;
                cout << endl;
                Sleep(3000);
                goto point;
            }

            SetColor(15);  
            cout << "\n\n\t\tEnter the new password: ";
            char pass;
            password.clear();
            while ((pass = _getch()) != '\r') // Loop will execute for each character until enter is pressed
            {
                if (pass >= 32 && pass <= 126) // Check for ASCII character and if it is an ASCII character than pushbacks the character into the password string
                {
                    cout << '*';
                    password.push_back(pass); // will add new character if the entered character is ASCII character .
                }
                else if (pass == 8 && password.length() > 0) // dealing with if backspace is pressed. The ASCII value of the backspace is 8
                {
                    password.pop_back(); // will remove last character it will seem as backspace is pressed
                    cout << "\b \b";
                }
            }
            if (password.length() < 5)
            {
                SetColor(12);
                cout << "\t\t The password length should be more than 5  " << endl;
                Sleep(1000);
                goto point;
            }

            SetColor(15);  
            fstream file_1;
            file_1.open("temp.txt", ios::out | ios::app);
            if (!file_1.is_open())
            {
                SetColor(12);
                cout << "\n\n\t\tError opening the file " << endl;
                return;
            }
            file_1 << username << "\n";
            file_1 << password << "\n";
            file_1.close();

            remove("AdminUserPass.txt");
            rename("temp.txt", "AdminUserPass.txt");

            SetColor(3);  
            cout << "\n\n\t\tYour ID is being created. Please Wait ";
            SetColor(15);  
            for (int i = 0; i < 4; i++) // used to make a delay on the screen
            {
                cout << ".";
                Sleep(1000);
            }
            cout << "\n\n\t\tYour ID HAS BEEN CREATED ";
        }
        else
        {
            cout << "\n\n\t\tNo matching username and password found. " << endl;
            Sleep(2000);
        }
    }

    int Generate_OTP()
    {
        srand(time(0));

        return rand() % 9000 + 10000;
    }

    // Manager's

    void Set_Total_Managers()
    {

        int number;
        bool valid_input = false;

        while (!valid_input)
        {

            cout << "\n\n\t\t Enter the total manager you have in your company ";
            cin >> number;

            if (cin.fail())
            {
                cout << "\n\n\t\t Invalid Input. Please enter again " << endl;
                cin.clear();
                cin.ignore(132, '\n');
            }
            else
            {
                valid_input = true;
            }
        }

        _total_manager = number;
    }

    int Get_Total_Number_Of_Managers()
    {
        return _total_manager;
    }

    void Set_Number_Of_Managers()
    {
        int number;
        bool valid_input = false;

        while (!valid_input)
        {
            cout << "\n\n\t\t Enter the number of managers you want to enter: ";
            cin >> number;

            if (cin.fail())
            {
                cin.clear();           // clear the error flag
                cin.ignore(132, '\n'); // discard invalid input
                cout << "\n\n\t\t Invalid input. Please enter a valid number." << endl;
            }
            else
            {
                valid_input = true;
            }
        }

        _manager_add = number;
    }

    int Get_Number_Of_Managers()
    {
        return _manager_add;
    }
};

#endif