#ifndef ADMIN_H
#define ADMIN_H

#include "Manager.h"
#include <ctime>   // for time()
#include <cstdlib> // for rand()

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
        cout << "\n\n\t\tEmployee Management System : " << endl;
        cout << "\n\n\t\tPlease SIGN UP by adding username and password " << endl;
        cout << "\n\n\t\tEnter Username :  ";
        getline(cin, username);

        if (username.length() <= 6 || !Is_Strong_Username(username))
        {
            cout << "\tThe username must consist of more than six characters "
                 << "and consist of at-least one upper case one lowercase and one symbol. " << endl;
            cout << endl;
            Sleep(5000);
            goto point;
        }
        else if (username.length() >= 20 || !Is_Strong_Username(username))
        {
            cout << "\tThe username must consist of less than twenty characters "
                 << "and consist of at-least one upper case one lowercase and one symbol. " << endl;
            cout << endl;
            Sleep(5000);
            goto point;
        }

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
            cout << " \t The password length should be more than 5  " << endl;
            Sleep(2000);
            goto point;
        }
        while (check_existingID >> existingID)
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
            cout << endl;
            cout << setw(80) << " =================================" << endl;
            cout << setw(80) << "| ID already exists.              |" << endl;
            cout << setw(80) << "| Redirecting to login page.....  |" << endl;
            cout << setw(80) << " =================================" << endl;
            Sleep(4000);
            system("CLS");
            Admin_Login();
        }
        else
        {

            fstream file;
            file.open("AdminUserPass.txt", ios::out | ios::app);
            if (!file.is_open())
            {
                cout << "\tError opening file.";
            }

            file << username << "\n";
            file << password << "\n";
            file.close();
            cout << "\n\n\t\tYour ID is being created.Please Wait ";
            for (int i = 0; i < 4; i++) // used to make a delay on the screen
            {
                cout << ".";
                Sleep(1000);
            }
            cout << "\n\n\t\tYour ID HAS BEEN CREATED ";
        }
        Admin_Login(); // login function called.
    }

    bool Admin_Login()
    {
    start: // start point will come here in case of logging out
        system("CLS");
        string username_1, pass_1, password, username;
        bool match = false; // bool found used to check conditions

        cout << "\t\t\t===============================================================" << endl;
        cout << "\t\t\t               Employee Management System                      " << endl;
        cout << "\t\t\t===============================================================" << endl;

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

        // Doing 2 factor authentication for the admin login (for a scrueity purpose)

        _otp = Generate_OTP();
        int _user_otp;

        cout << " ________________________ " << endl;
        cout << "|                        |" << endl;
        cout << "|   OTP " << _otp << "          |" << endl;
        cout << "|________________________|" << endl;

        Sleep(5000);
        system("CLS"); // for making the otp disappear after few seconds
    OTP:
        cout << " Enter the OTP: ";
        cin >> _user_otp;
        if (cin.fail())
        {
            cout << " Invalid  Input!!! . Enter integers only " << endl;
            goto OTP;
        }

        cout << " Checking for the authentication";
        for (int i = 0; i < 4; i++)
        {
            cout << ".";
            Sleep(1000);
        }

        cout << "\n";

        if (_otp == _user_otp)
        {
            cout << "\t\t\t    ______________________________________" << endl;
            cout << "\t\t\t   |                                      |" << endl;
            cout << "\t\t\t   |       Authentication Successful      |" << endl;
            cout << "\t\t\t   |______________________________________|" << endl;

            Sleep(1000);
            system("CLS");

            ifstream file;
            file.open("AdminUserPass.txt");
            if (!file.is_open())
            {
                cout << "\t Error opening file ";
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

            if (match == true)
            {
                cout << "\n";
                cout << " \t \t \t \t Login Successful " << endl
                     << endl;
                cout << "\t\t\t===============================================================" << endl;
                cout << "\t\t\t                       Welcome  Admin                          " << endl;
                cout << "\t\t\t===============================================================" << endl;
                cout << "\n";
                Sleep(2000);
            }

            if (match == true)
            {
                bool found;
                char mainchoice, subchoice_a, subchoice_b;

                system("CLS");
                Set_Total_Employees();
                Set_Total_Managers();

            Menu:
                system("CLS");
                // Sleep(2000);
                cout << "\t\t\t------------Choose from below----------- " << endl;
                cout << "\t\t\t _______________________________________" << endl;
                cout << "\t\t\t|                                       |" << endl;
                cout << "\t\t\t|      1--> Manage Managers             |" << endl;
                cout << "\t\t\t|      2--> Manage Employees            |" << endl;
                cout << "\t\t\t|      3--> Exit the program            |" << endl;
                cout << "\t\t\t|_______________________________________|" << endl;
                mainchoice = getch();

                switch (mainchoice)
                {
                case '1':

                point_a:
                    system("CLS");
                    // Sleep(2000);
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
                            cout << " You have entered greater number of managers than ";
                            cout << "the total number of manager " << endl;
                            cout << " Total Number of Managers: " << Get_Total_Number_Of_Managers() << endl;
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
                            cout << " Manager Count: " << Get_Manger_Count() << endl;
                            cout << " Total Number of Managers: " << Get_Total_Number_Of_Managers() << endl;
                            cout << " Maximum number of managers are added " << endl;
                            goto start;
                        }
                        goto point_a;
                        break;

                    case '3':
                        Search_Manager_Data();
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
                        cout << " Invalid choice ";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << "!";
                            Sleep(1000);
                            goto point_a;
                        }
                    }

                    break; // Finish of maincase 1

                case '2':

                point_b:
                    system("CLS");
                    Sleep(2000);

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

                    switch (subchoice_b)
                    {
                    case '1':
                    b:
                        Set_Number_Of_Employees();
                        if (Get_Total_Employees() >= Get_Number_Of_Employees())
                        {
                            goto point_b;
                        }
                        else
                        {
                            cout << " You have greater number of employees than ";
                            cout << "the total number of employees " << endl;
                            cout << " Total Number of Employees: " << Get_Total_Employees() << endl;
                            goto b;
                        }
                        break;

                    case '2':
                        if (Get_Total_Employees() >= Get_Employee_Number())
                        {

                            Add_Employee();
                        }
                        else
                        {
                            cout << " Employee Count: " << Get_Employee_Count() << endl;
                            cout << " Total Number of Employees: " << Get_Total_Employees() << endl;
                            cout << " Maximum number of employees are added " << endl;
                            goto start;
                        }
                        goto point_b;
                        break;

                    case '3':
                        Search_Employee_Data();
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
                        goto Menu;
                        break;

                    default:
                        cout << " Invalid choice ";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << "!";
                            Sleep(1000);
                            goto point_b;
                        }
                        break;
                    }
                }
            }
        }
        else
        {
            cout << "\t\t\t    ______________________________________" << endl;
            cout << "\t\t\t   |                                      |" << endl;
            cout << "\t\t\t   |     Authentication Unsuccessful      |" << endl;
            cout << "\t\t\t   |______________________________________|" << endl;
            cout << "The login failed. Please try again." << endl;
            cin.ignore();
            Sleep(3000);
            goto start;
        }
    }

    void Password_Recovery_Option_For_Admin()
    {
        string username, password, username_1, password_1;
        bool match = false;

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
            file.ignore(1000, '\n');
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
                cout << "\tThe username must consist of more than six characters "
                     << "and consist of at least one upper case, one lower case, and one symbol." << endl;
                cout << endl;
                Sleep(3000);
                goto point;
            }
            else if (username.length() >= 20 || !Is_Strong_Username(username))
            {
                cout << "\tThe username must consist of less than twenty characters "
                     << "and consist of at least one upper case, one lower case, and one symbol." << endl;
                cout << endl;
                Sleep(3000);
                goto point;
            }

            cout << "\n\n\t\tEnter the new password: ";
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
            if (password.length() < 5)
            {
                cout << "\t\t The password length should be more than 5  " << endl;
                Sleep(1000);
                goto point;
            }

            fstream file_1;
            file_1.open("temp.txt", ios::out | ios::app);
            if (!file_1.is_open())
            {
                cout << "\n\n\t\tError opening the file " << endl;
                return;
            }
            file_1 << username << "\n";
            file_1 << password << "\n";
            file_1.close();

            remove("AdminUserPass.txt");
            rename("temp.txt", "AdminUserPass.txt");
            cout << "\n\n\t\tYour ID is being created. Please Wait ";
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
    a:
        int number;
        cout << "\n\n\t\t Enter the total manager you have in your company ";
        cin >> number;
        if (cin.fail())
        {
            cout << "\n\n\t\t Invalid Input. Please enter again " << endl;
            goto a;
        }

        _total_manager = number;
    }

    int Get_Total_Number_Of_Managers()
    {
        return _total_manager;
    }

    void Set_Number_Of_Managers()
    {
    a:
        int number;
        cout << "\n\n\t\t Enter the number of managers you want to enter ";
        cin >> number;
        if (cin.fail())
        {
            cout << "\n\n\t\t Invlaid Input. Please enter again " << endl;
            goto a;
        }
        _manager_add = number;
    }

    int Get_Number_Of_Managers()
    {
        return _manager_add;
    }
};

#endif