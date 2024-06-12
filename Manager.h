#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee
{
private:
    int _manager_count;
    int _manager_number;
    int _employee_add;
    char choice;

    string _manager_designation;
    int _manager_leaves;
    string _experience;

public:
    Manager() // Default Constructor
    {
        _manager_designation = " Manager ";
        _manager_count = 0;
        _manager_number = 0;
    }

    void Set_Number_Of_Employees()
    {
    a:
        int number;
        cout << " Enter the number of employees you want to enter ";
        cin >> number;
        if (cin.fail())
        {
            Set_Colour(12);
            cout << " Invlaid Input. Please enter again " << endl;
            goto a;
        }
        _employee_add = number;
    }

    int Get_Number_Of_Employees()
    {
        return _employee_add;
    }

    int Get_Manager_Number()
    {
        return _manager_number;
    }

    int Get_Manger_Count()
    {
        return _manager_count;
    }

    void Set_ID(string id)
    {
        set_ID(id); // Called a member function of the base class
    }

    string Get_ID() const
    {
        return get_ID(); // Called a member function of the base class
    }

    // Main member fucntions

    void Add_Manager()
    {
        string id;
        ifstream file;
        file.open("ManagersData.txt", ios::in);

        system("CLS");

        Set_Colour(15);
        cout << "\n";
        cout << "\t Enter the following information of the Manager " << endl;
        cout << endl;

        // Validate manager ID
        bool valid_id = false;
        while (!valid_id)
        {
            cout << "\t Enter the manager ID: ";
            cin >> _id;

            if (!file)
            {
                file.clear();
                valid_id = true;
            }
            else
            {
                while (file >> id)
                {
                    file.ignore();
                    if (id == _id)
                    {
                        cout << "\t An manager with this ID already exists " << endl;
                        file.close();
                        file.open("ManagersData.txt", ios::in);
                        break;
                    }
                }
                if (file.eof())
                {
                    valid_id = true;
                }
                file.clear();
                file.seekg(0, ios::beg);
            }
        }

        cin.ignore();

        Set_Colour(15);
        // Validate manager name
        bool valid_name = false;
        while (!valid_name)
        {
            cout << "\t Manager name: ";
            getline(cin, _name);
            valid_name = true;
            for (char i = 0; i < _name.length(); i++)
            {
                if (isdigit(_name[i]))
                {
                    Set_Colour(12);
                    cout << endl;
                    cout << "\t Invalid input! Enter alphabets only. " << endl;
                    valid_name = false;
                    break;
                }
            }
        }

        Set_Colour(15);
        // Validate manager age
        bool valid_age = false;
        while (!valid_age)
        {
            cout << "\t Manager age: ";
            cin >> _age;
            if (cin.fail())
            {
                Set_Colour(12);
                cin.clear();
                cin.ignore(132, '\n');
                cout << endl;
                cout << "\t Invalid input! Enter integers only " << endl;
            }
            else
            {
                valid_age = true;
            }
            if (_age < 0)
            {
                Set_Colour(12);
                cout << " The age cannot be negative " << endl;
            }
        }

        cin.ignore();
        Set_Colour(15);
        // No validation needed for experience and address
        cout << "\t Manager Experience: ";
        getline(cin, _experience);

        /* No validation on experience because it can be 4.5 years */

        cout << "\t Manager address: ";
        getline(cin, _address);

        /*for (char i = 0; i < _address.length(); i++)
        {
            if (isdigit(_address[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;

            }
        }

        There is no validation for address because it can contain the house-number , street-number and
        also the zip code of the city based upon the user input

        */

        // Validate phone number
        bool valid_phone = false;
        while (!valid_phone)
        {
            cout << "\t Manager phone number: ";
            cin >> _phone_number;
            if (cin.fail() || _phone_number < 0)
            {
                Set_Colour(12);
                cin.clear();
                cin.ignore(132, '\n');
                cout << endl;
                cout << "\t Invalid input! Enter positive integers only " << endl;
            }
            else
            {
                valid_phone = true;
            }
        }

        /*
            int count = 0;
            while (_phone_number != 0)
            {
             _phone_number = _phone_number / 10;
             ++count;
            }

            while (count != 11 || _phone_number < 0)
            {
                cout << "=============================================================" << endl;
                cout << "Phone number must have 11 digits only and cannot be negative." << endl;
                cout << "=============================================================" << endl;
                cin >> _phone_number;
            }

            string num = to_string(_phone_number);
            while (num.size() != 11 || _phone_number < 0)
            {
            cout << "=============================================================" << endl;
            cout << "Phone number must have 11 digits only and cannot be negative." << endl;
            cout << "=============================================================" << endl;
            cin >> _phone_number;
            } */

        // cin.ignore();

        // Validate manager designation
        bool valid_choice = false;
        while (!valid_choice)
        {
            cout << "\t\t\t Designation of the managers: " << endl;
            cout << "\t\t\tWhat is the type of the managers " << endl;
            Set_Colour(11);
            cout << "\t\t\t-------------Choose from below--------------" << endl;
            cout << "\t\t\t____________________________________________" << endl;
            cout << "\t\t\t|                                           |" << endl;
            cout << "\t\t\t|        1-> HR Manager                     |" << endl;
            cout << "\t\t\t|        2-> Marketing Manager              |" << endl;
            cout << "\t\t\t|        3-> Sales Manager                  |" << endl;
            cout << "\t\t\t|        4-> Team Leader                    |" << endl;
            cout << "\t\t\t|___________________________________________|" << endl;
            choice = getch();

            Set_Colour(15);
            switch (choice)
            {
            case '1':
                _manager_designation = "HR Manager";
                _salary = 70000;
                _manager_leaves = 6;
                valid_choice = true;
                break;
            case '2':
                _manager_designation = "Marketing Head";
                _salary = 100000;
                _manager_leaves = 4;
                valid_choice = true;
                break;
            case '3':
                _manager_designation = "Sales Head";
                _salary = 90000;
                _manager_leaves = 5;
                valid_choice = true;
                break;
            case '4':
                _manager_designation = "Team Leader";
                _salary = 100000;
                _manager_leaves = 8;
                valid_choice = true;
                break;
            default:
                Set_Colour(12);
                cout << "\t Invalid choice!!! . Please enter again " << endl;
                break;
            }
        }

        // Saving the data in the file
        ofstream file_write;
        file_write.open("ManagersData.txt", ios::out | ios::app);
        if (!file_write.is_open())
        {
            Set_Colour(12);
            cout << " Error opening the file " << endl;
            return;
        }
        Set_Colour(15);
        file_write << _id << "\n";
        file_write << _name << "\n";
        file_write << _age << "\n";
        file_write << _experience << "\n";
        file_write << _phone_number << "\n";
        file_write << _manager_designation << "\n";
        file_write << _salary << "\n";
        file_write << _manager_leaves << "\n";
        file_write << _address << "\n";

        file_write.close();

        Sleep(1000);
        cout << "\t Manager added successfully! " << endl;
        _manager_count++;
        _manager_number++;
    }

    void Show_All_Managers_Data()
    {
        ifstream file;
        file.open("ManagersData.txt");

        // For debugging the filing in the code if the file is not able to be opened due to any reason
        if (!file.is_open())
        {
            Set_Colour(12);
            cout << "\tError opening file.";
            return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age;
        file.ignore();
        getline(file, _experience);
        file >> _phone_number;
        file.ignore();
        getline(file, _manager_designation);
        file >> _salary >> _manager_leaves;
        file.ignore();
        getline(file, _address);

        while (!file.eof()) // The loop will itrate from the start of the file to the end of the file
        {
            Set_Colour(14);
            cout << "\n";
            cout << "\n\t\t *************************************************************************" << endl;
            cout << "\t\t ||\t                    Data of Manager"
                 << "\t\t\t        || " << endl;
            cout << "\t\t ||_____________________________________________________________________||" << endl;
            cout << "\t\t ||                                                                     ||" << endl;
            cout << "\t\t || Manager ID                        : " << setw(25) << left << _id << "\t||" << endl;
            cout << "\t\t || Manager Name                      : " << setw(25) << left << _name << "\t||" << endl;
            cout << "\t\t || Manager Age                       : " << setw(25) << left << _age << "\t||" << endl;
            cout << "\t\t || Manager Experience                : " << setw(25) << left << _experience << "\t||" << endl;
            cout << "\t\t || Manager Phone Number              : " << setw(25) << left << _phone_number << "\t||" << endl;
            cout << "\t\t || Manager Designation               : " << setw(25) << left << _manager_designation << "\t||" << endl;
            cout << "\t\t || Manager Salary                    : " << setw(25) << left << _salary << "\t||" << endl;
            cout << "\t\t || Manager Leaves                    : " << setw(25) << left << _manager_leaves << "\t||" << endl;
            cout << "\t\t || Manager Address                   : " << setw(25) << left << _address << "\t||" << endl;
            cout << "\t\t ||                                                                     ||";
            cout << "\n\t\t *************************************************************************" << endl;
            cout << "\n";

            Sleep(1000); // Stops for 1 second

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age;
            file.ignore();
            getline(file, _experience);
            file >> _phone_number;
            file.ignore();
            getline(file, _manager_designation);
            file >> _salary >> _manager_leaves;
            file.ignore();
            getline(file, _address);
        }
        file.close();

        Set_Colour(15);
    }

    void Search_Manager_Data()
    {

        string search_id;
        cout << "Search the data by entering the id : ";
        cin >> search_id;

        register int found = false; // A flag variable

        fstream file;
        file.open("ManagersData.txt", ios::in);
        // Faliure in opening of the file
        if (!file.is_open())
        {
            Set_Colour(12);
            cout << "\tError opening file.";
            return;
        }

        Set_Colour(15);
        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age;
        file.ignore();
        getline(file, _experience);
        file >> _phone_number;
        file.ignore();
        getline(file, _manager_designation);
        file >> _salary >> _manager_leaves;
        file.ignore();
        getline(file, _address);
        while (!file.eof())
        {
            if (search_id == _id)
            {
                Set_Colour(14);
                cout << "\n";
                cout << "\n\t\t *************************************************************************" << endl;
                cout << "\t\t ||\t                    Data of Manager"
                     << "\t\t\t        || " << endl;
                cout << "\t\t ||_____________________________________________________________________||" << endl;
                cout << "\t\t ||                                                                     ||" << endl;
                cout << "\t\t || Manager ID                        : " << setw(25) << left << _id << "\t||" << endl;
                cout << "\t\t || Manager Name                      : " << setw(25) << left << _name << "\t||" << endl;
                cout << "\t\t || Manager Age                       : " << setw(25) << left << _age << "\t||" << endl;
                cout << "\t\t || Manager Experience                : " << setw(25) << left << _experience << "\t||" << endl;
                cout << "\t\t || Manager Phone Number              : " << setw(25) << left << _phone_number << "\t||" << endl;
                cout << "\t\t || Manager Leaves                    : " << setw(25) << left << _manager_leaves << "\t||" << endl;
                cout << "\t\t || Manager Designation               : " << setw(25) << left << _manager_designation << "\t||" << endl;
                cout << "\t\t || Manager Address                   : " << setw(25) << left << _address << "\t||" << endl;
                cout << "\t\t ||                                                                     ||";
                cout << "\n\t\t *************************************************************************" << endl;
                cout << "\n";
                found = true; // To check whether the id of the Manager is found or not
                Sleep(5000);
                break;
            }

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age;
            file.ignore();
            getline(file, _experience);
            file >> _phone_number;
            file.ignore();
            getline(file, _manager_designation);
            file >> _salary >> _manager_leaves;
            file.ignore();
            getline(file, _address);
        }

        Set_Colour(15);
        file.close();

        if (found == false)
        {
            cout << "\tData of this id id not present";
            Sleep(2000);
        }
    }

    void Delete_Manager_Data()
    {
        string delete_id;
        register bool found = false; // A flag variblvariable

        cout << "\tEnter the ID of the Manager you want to fire and delete the data: ";
        cin >> delete_id;

        fstream file, file_1;
        file.open("ManagersData.txt", ios::in);
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            return;
        }

        file_1.open("temp.txt", ios::out | ios::app); // Created a file for storing all the data of the Manager of the company that you donot want to delete
        if (!file_1.is_open())                        // and then this file is renamed
        {
            cout << "\tError opening file.";
            return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age;
        file.ignore();
        getline(file, _experience);
        file >> _phone_number;
        file.ignore();
        getline(file, _manager_designation);
        file >> _salary >> _manager_leaves;
        file.ignore();
        getline(file, _address);

        while (!file.eof())
        {
            // The employes whose ID do not match the delete_id their data is saved in another file named temp by using the trick of reversing the .eof() built-in function
            if (delete_id != _id)
            {
                file_1 << _id << "\n";
                file_1 << _name << "\n";
                file_1 << _age << "\n";
                file_1 << _experience << "\n";
                file_1 << _phone_number << "\n";
                file_1 << _manager_designation << "\n";
                file_1 << _salary << "\n";
                file_1 << _manager_leaves << "\n";
                file_1 << _address << "\n";
            }
            if (delete_id == _id) // only to check wheter the id exsists or not
            {
                found = true;
            }

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age;
            file.ignore();
            getline(file, _experience);
            file >> _phone_number;
            file.ignore();
            getline(file, _manager_designation);
            file >> _salary >> _manager_leaves;
            file.ignore();
            getline(file, _address);
        }

        file.close();
        file_1.close();

        remove("ManagersData.txt");
        rename("temp.txt", "ManagersData.txt"); // Renamed the file so donot get confusede in accessing the files containing the data of the Manager
        if (found == false)
        {
            cout << "\tTheir is no data of any Manager with this id " << endl;
        }
        else
        {
            _manager_count--;
            cout << "\tData Deleted Successfully." << endl;
            Sleep(2000);
        }
    }

    void Update_Manager_Data() // You want to update the employee information without the employee applying for the promotion or updation of his data
    {
        string promote_id;
        char choose;
        register bool found = false; // A flag variable

        cout << "\tEnter the Manager ID to update data: ";
        cin >> promote_id;

        fstream file, file_1;
        file.open("ManagersData.txt", ios::in);

        if (!file.is_open())
        {
            cout << "\tError opening file.";
            return;
        }

        file_1.open("promote.txt", ios::out);

        if (!file_1.is_open())
        {
            cout << "\tError opening file.";
            return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age;
        file.ignore();
        getline(file, _experience);
        file >> _phone_number;
        file.ignore();
        getline(file, _manager_designation);
        file >> _salary >> _manager_leaves;
        file.ignore();
        getline(file, _address);

        while (!file.eof())
        {
            if (promote_id == _id)
            {
                cout << "\n\t\t   Manager ID found. Update the information" << endl;
                cout << "\t\t  What do you want to update " << endl;
                Set_Colour(14);
                cout << "\t\t   -------------Choose from below------------- " << endl;
                cout << "\n\t\t    __________________________________________ ";
                cout << "\n\t\t   |                                          |";
                cout << "\n\t\t   |  1--> Designation                        |"
                     << "\n\t\t   |  2--> Address                            |"
                     << "\n\t\t   |  3--> Phone Number                       |"
                     << "\n\t\t   |  4--> Salary                             |"
                     << "\n\t\t   |  5--> Total Leaves                       |";
                cout << "\n\t\t   |__________________________________________|" << endl;
                choose = getch();

                /*
                All this is now not necessary because taking the input in getch() a built-in function that is used to take character only
                the user is unable to write  56 as in  ' int ' data_type


                if (cin.fail())
                {
                    cout << " \n";
                    cout << " \t\t\t   Error! Please choose from the below " << endl;
                    cout << " \n";
                    cout << "\n\t\t\t   -------------Choose from below------------- " << endl;
                    cout << "\n\t\t    ___________________________________________ ";
                    cout << "\n\t\t   |                                           |";
                    cout << "\n\t\t   |  1--> Designation                         |"
                         << "\n\t\t   |  2--> Address                             |"
                         << "\n\t\t   |  3--> Phone Number                        |"
                         << "\n\t\t   |  4--> Salary                              |"
                         << "\n\t\t   |  5--> Total Leaves                        |";
                    cout << "\n\t\t   |___________________________________________|" << endl;
                    // Built-in function   This function returns true when an input failure occurs. In this case it would be an input that is not an integer.
                    //  If the cin fails then the input buffer is kept in an error state.  Buffer is region of memory used to store data temporarily
                    cin.clear();

                    // Built-in function    This function to remove undesirable characters from the input buffer
                    cin.ignore(132, '\n');
                    cin >> choose;
                }

                */

                Set_Colour(15);
                system("CLS");
                switch (choose)
                {
                case '1':
                a:
                    cout << "\tEnter the new designation: ";
                    cin.ignore();
                    getline(cin, _manager_designation);
                    for (char i = 0; i < _manager_designation.length(); i++)
                    {
                        if (isdigit(_manager_designation[i]))
                        {
                            Set_Colour(12);
                            cout << " Invalid Input!!! . Enter alphabets only " << endl;
                            goto a;
                        }
                    }

                    break;

                    Set_Colour(15);
                case '2':
                    cout << "\n\tEnter the new address: ";
                    cin.ignore();
                    getline(cin, _address);

                    /*   There is no validation for address because it can contain the house-number , street-number and
                    also the zip code of the city based upon the user input */

                    break;

                case '3':
                b:
                    cout << "\n\tEnter the new phone number: ";
                    cin >> _phone_number;
                    if (cin.fail())
                    {
                        Set_Colour(12);
                        cout << " Invalid Input!!! Enter integers only " << endl;
                        goto b;
                    }
                    while (_phone_number < 0)
                    {
                        Set_Colour(12);
                        cout << "==================================" << endl;
                        cout << "Phone number cannot be negative." << endl;
                        cout << "==================================" << endl;
                        cin >> _phone_number;
                    }

                    /*
                    int count = 0;
                    while (_phone_number != 0)
                    {
                     _phone_number = _phone_number / 10;
                     ++count;
                    }

                    while (count != 11 || _phone_number < 0)
                    {
                        cout << "=============================================================" << endl;
                        cout << "Phone number must have 11 digits only and cannot be negative." << endl;
                        cout << "=============================================================" << endl;
                        cin >> _phone_number;
                    }

                    string num = to_string(_phone_number);
                    while (num.size() != 11 || _phone_number < 0)
                    {
                    cout << "=============================================================" << endl;
                    cout << "Phone number must have 11 digits only and cannot be negative." << endl;
                    cout << "=============================================================" << endl;
                    cin >> _phone_number;
                    } */

                    break;

                    Set_Colour(15);
                case '4':
                c:
                    cout << "\n\tEnter the new salary: ";
                    cin >> _salary;
                    if (cin.fail())
                    {
                        Set_Colour(12);
                        cout << " Invlid Input!!!  Enter integers only " << endl;
                        goto c;
                    }

                    // Non negative and non zero salary vaidation
                    if (_salary <= 0)
                    {
                        Set_Colour(12);
                        cout << " The salary must be non-negative and greater than zero " << endl;
                        goto c;
                    }

                    break;

                    Set_Colour(15);
                case '5':
                d:
                    cout << "\n\tEnter the new total leaves: ";
                    cin >> _manager_leaves;
                    if (cin.fail())
                    {
                        Set_Colour(12);
                        cout << " Invalid Input!!! Enter integers only " << endl;
                        goto d;
                    }

                    break;

                default:
                    cout << "\n\t Invalid Input .No such update of data available" << endl;
                    Set_Colour(15);
                    system("CLS");
                }

                found = true;
            }

            file_1 << _id << "\n";
            file_1 << _name << "\n";
            file_1 << _age << "\n";
            file_1 << _experience << "\n";
            file_1 << _phone_number << "\n";
            file_1 << _manager_designation << "\n";
            file_1 << _salary << "\n";
            file_1 << _manager_leaves << "\n";
            file_1 << _address << "\n";

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age;
            file.ignore();
            getline(file, _experience);
            file >> _phone_number;
            file.ignore();
            getline(file, _manager_designation);
            file >> _salary >> _manager_leaves;
            file.ignore();
            getline(file, _address);
        }

        file.close();
        file_1.close();

        Set_Colour(15);
        remove("ManagersData.txt");
        rename("promote.txt", "ManagersData.txt");

        // Show prompt that the data of the Manager is updated successfully
        if (found == true)
        {
            cout << "\tData Updated Successfully." << endl;
            Sleep(5000);
        }
        else
        {
            cout << "\tManager ID not found." << endl;
            Sleep(5000);
        }
    }

    void Manager_Applying_for_Leave()
    {
        string id, _leave_type, emp_name;
        int _leave_days;

        char choose;
        bool found = false; // A flag variable

        cout << "Enter your id: ";
        cin >> id;

        fstream file, file_1;
        file.open("ManagersData.txt", ios::in);
        if (!file.is_open())
        {
            cout << "\tError opening file." << endl;
            return;
        }

        file_1.open("promote.txt", ios::out);
        if (!file_1.is_open())
        {
            cout << "\tError opening file." << endl;
            return;
        }

        // Reading from the file to take the id of the Manager and match whether a Manager with this id exists or not
        // Also to update the Manager leaves if their leave is accepted
        while (file >> _id >> ws && getline(file, _name) && file >> _age >> ws && getline(file, _experience) && file >> _phone_number >> ws && getline(file, _manager_designation) && file >> _salary >> _manager_leaves >> ws && getline(file, _address))
        {
            if (id == _id)
            {
                cout << "\n\t\t   Manager ID found. " << endl;
            start:

                Set_Colour(11);
                cout << "\n\t\t  Which type of leave do you want to apply for? ";
                cout << "\n\t\t\t   -------------Choose from below------------- " << endl;
                cout << "\n\t\t    __________________________________________ ";
                cout << "\n\t\t   |                                          |";
                cout << "\n\t\t   |  1--> Sick Leave                         |"
                     << "\n\t\t   |  2--> Personal Leave                     |"
                     << "\n\t\t   |  3--> Study Leave                        |"
                     << "\n\t\t   |  4--> Annual Leave                       |"
                     << "\n\t\t   |  5--> Maternity Leave                    |";
                cout << "\n\t\t   |__________________________________________|" << endl;
                choose = getch();

                // Clear input buffer if invalid input
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(132, '\n');
                    goto start;
                }

                // Process the leave application based on user choice
                const string TO = "CEO"; // Means writing the application to the CEO

                Set_Colour(15);
                switch (choose)
                {
                case '1': // Sick Leave
                    _leave_type = "sick leave";
                    _leave_days = get_Leave_Days(_leave_type);
                    Sick_Leave_Application(get_Illness_Reason(), get_Illness_Symptoms(), _leave_days, emp_name, TO);
                    break;

                case '2': // Personal Leave
                    _leave_type = "personal leave";
                    _leave_days = get_Leave_Days(_leave_type);
                    Personal_Leave_Application(get_Personal_Reason(), _leave_days, emp_name, TO);
                    break;

                case '3': // Study Leave
                    _leave_type = "study leave";
                    _leave_days = get_Leave_Days(_leave_type);
                    Study_Leave_Application(get_Study_Reason(), get_Study_Field(), _leave_days, emp_name, TO);
                    break;

                case '4': // Annual Leave
                    _leave_type = "annual leave";
                    _leave_days = get_Leave_Days(_leave_type);
                    Annual_Leave_Application(get_Annual_Reason(), _leave_days, emp_name, TO);
                    break;

                case '5': // Maternity Leave
                    _leave_type = "maternity leave";
                    _leave_days = get_Leave_Days(_leave_type);
                    Materity_Leave_Application(get_Maternity_Reason(), _leave_days, emp_name, TO);
                    break;

                default:
                    Set_Colour(12);
                    cout << "\n\t Invalid Input !!!." << endl;
                    Set_Colour(15);
                    goto start;
                }

                // Update leave days if the application is approved
                if (Application_Approval())
                {
                    Application_Accepted();
                    _manager_leaves += _leave_days;
                }
                else
                {
                    Application_Rejected();
                }

                found = true;
            }

            // Write updated data to the new file
            file_1 << _id << "\n";
            file_1 << _name << "\n";
            file_1 << _age << "\n";
            file_1 << _experience << "\n";
            file_1 << _phone_number << "\n";
            file_1 << _manager_designation << "\n";
            file_1 << _salary << "\n";
            file_1 << _manager_leaves << "\n";
            file_1 << _address << "\n";
        }

        file.close();
        file_1.close();

        Set_Colour(15);

        remove("ManagersData.txt");
        rename("promote.txt", "ManagersData.txt");

        // Show prompt that the data of the Manager is updated successfully
        if (found)
        {
            cout << "\tThanks for applying for the leave." << endl;
        }
        else
        {
            cout << "\tManager ID not found." << endl;
        }
    }

    void Mark_Manager_Attendance()
    {

        register string id;
        bool is_checking_in;
        cout << " Enter the id of the manager: ";
        cin >> id;

        is_checking_in = Match_Manager_ID(id);

        if (is_checking_in == true)
        {
            Set_ID(id);
            // Increment attendance for the Manager
            int count;
            count = Get_Manager_Attendance_Count(Get_ID()) + 1;

            fstream file;
            file.open("ManagerAttendance.txt", ios::out | ios::app);
            if (!file.is_open())
            {
                cout << "Unable to open file.";
                return;
            }
            file << _id << " " << count << endl;
            file.close();

            cout << " Your attendance has been marked " << endl;
        }
        else
        {
            cout << " Such an ID donot exist in our system " << endl;
        }
    }

    int Get_Manager_Attendance_Count(const string &_manager_id)
    {
        ifstream file;
        file.open("ManagerAttendance.txt");
        // if (!file.is_open())
        // {
        //     cout << "Unable to open file.";
        //     return 0;
        // }

        string id;
        int count;

        while (file >> id >> count)
        {
            if (id == _manager_id)
            {
                file.close();
                cout << " Your Attendance count is: " << count << endl;
            }
        }
        file.close();
    }

    bool Strong_Username(const string &_username)
    {
        bool _has_upper_case = false;
        bool _has_lower_case = false;
        bool _has_symbol = false;

        for (int i = 0; i < _username.length(); i++) // loop executing on each character of the username.
        {
            if (isupper(_username[i])) // Built-in functions check for uppercase letters
            {
                _has_upper_case = true;
            }
            else if (islower(_username[i])) // Built-in functions  check for lowercase letters
            {
                _has_lower_case = true;
            }
            else if (ispunct(_username[i])) // Built-in functions  check for punctuation(symbol)
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

    void Manager_SignUp()
    {
        string _enter_id;
        register bool match;

        cout << " Enter your manager ID to sign-up ";
        cin >> _enter_id;

        // cin.ignore();

        match = Match_Manager_ID(_enter_id);

        cout << " The manager id has  been found " << endl;
        Sleep(2000);

        if (match)
        {
        point: // point declared here will come here if username requirements not met
            system("CLS");
            string username, password;
            Set_ID(_enter_id);

            Set_Colour(14);
            cout << "\t\t\t===============================================================" << endl;
            cout << "\t\t\t               Employee Management System                      " << endl;
            cout << "\t\t\t===============================================================" << endl;

            Set_Colour(15);
            cout << "\n\n\t\tPlease SIGN UP by adding username and password " << endl;
            cout << "\n\n\t\tEnter Username :  ";
            getline(cin, username);

            if (username.length() <= 6 || !Strong_Username(username))
            {
                Set_Colour(12);
                cout << "\tThe username must consist of more than six characters "
                     << "and consist of at-least one upper case one lowercase and one symbol. " << endl;
                cout << endl;
                Sleep(2000);
                goto point;
            }
            else if (username.length() >= 20 || !Strong_Username(username))
            {
                Set_Colour(12);
                cout << "\tThe username must consist of less than twenty characters "
                     << "and consist of at-least one upper case one lowercase and one symbol. " << endl;
                cout << endl;
                Sleep(2000);
                goto point;
            }

            Set_Colour(15);
            cout << "\n\n\t\tPassword : ";
            char pass; // Password is taken in char thats make it easy to convert it into assteterics

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
                Set_Colour(12);
                cout << " \t The password length should be more than 5  " << endl;
                Sleep(2000);
                goto point;
            }

            Set_Colour(15);
            fstream file;
            file.open("ManagerUserPass.txt", ios::out | ios::app);
            if (!file.is_open())
            {
                cout << "\tError opening file.";
            }

            file << username << "\n";
            file << password << "\n";
            file.close();

            Set_Colour(11);
            cout << "\n\n\t\tYour ID is being created.Please Wait ";
            Set_Colour(15);
            for (int i = 0; i < 4; i++) // used to make a delay on the screen
            {
                cout << ".";
                Sleep(1000);
            }
            cout << "\n\n\t\tYour ID HAS BEEN CREATED ";
            // Manager_Login(_enter_id); // login function called.
        }
        else
        {
            cout << " Such an ID donot exist in your system " << endl;
        }
    }

    bool Manager_Login(string _user_id)
    {
        string id, check_id, name;
        bool found = false;
        Parking obj;

    start: // start point will come here in case of logging out
        system("ClS");
        string username_1, pass_1, password, username;
        register bool match = false; // bool found used to check conditions

        Set_Colour(14);
        cout << "\t\t\t===============================================================" << endl;
        cout << "\t\t\t               Employee Management System                      " << endl;
        cout << "\t\t\t===============================================================" << endl;

        Set_Colour(15);
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
                pass_1.push_back(pass); // push_back moves to the next character and its storing the password in pass_1 variavble after going thriugh its all characters
            }
            else if (pass == 8 && pass_1.length() > 0) // 8 referes to the ASCII value of backspace
            {
                pass_1.pop_back(); // pop back moves to the previos character
                cout << "\b \b";
            }
        }
        cout << "\n";

        ifstream file;
        file.open("ManagerUserPass.txt");

        if (!file.is_open())
        {
            cout << "\t Error opening file ";
        }

        while (getline(file, username) && file >> password) // reading until the data in the file is finished
        {
            if (username == username_1 && password == pass_1)
            {
                match = true;
                break;
                Set_Colour(14);
                cout << "\n";
                cout << " \t \t \t \t Login Successful " << endl
                     << endl;
                cout << "\t\t\t===============================================================" << endl;
                cout << "\t\t\t                         Welcome                               " << endl;
                cout << "\t\t\t===============================================================" << endl;
                cout << "\n";
                Set_Colour(15);
                Sleep(2000);
            }
            file.ignore(1000, '\n'); // setting a limit of ignoring unwanted characters until newline characters(removes input buffer)
        }
        file.close();

        if (match == true)
        {
            char mainchoice, subchoice;
            bool found;

        Menu:
            system("CLS");

            Set_Colour(11);
            cout << "\t\t\t------------Choose from below----------- " << endl;
            cout << "\t\t\t _______________________________________ " << endl;
            cout << "\t\t\t|                                       |" << endl;
            cout << "\t\t\t|    1--> Manage employees              |" << endl;
            cout << "\t\t\t|    2--> Manage your own information   |" << endl;
            cout << "\t\t\t|    3--> Exit the program              |" << endl;
            cout << "\t\t\t|_______________________________________|" << endl;
            mainchoice = getch();

            Set_Colour(15);
            switch (mainchoice)
            {
            case '1':
            point_a:
                system("CLS");

                Set_Colour(11);
                cout << "\t\t\t------------Choose from below----------- " << endl;
                cout << "\t\t\t _______________________________________ " << endl;
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
                subchoice = getch();

                Set_Colour(15);
                switch (subchoice)
                {
                case '1':
                a:
                    Set_Number_Of_Employees();
                    if (Get_Total_Number_Of_Employee() >= Get_Number_Of_Employees())
                    {
                        goto point_a;
                    }
                    else
                    {
                        cout << " You have greater number of employees than ";
                        cout << "the total number of employees " << endl;
                        cout << " Total Number of Employees: " << Get_Total_Number_Of_Employee() << endl;
                        goto a;
                    }
                    break;

                case '2':
                    if (Get_Total_Number_Of_Employee() >= Get_Employee_Number())
                    {

                        Add_Employee();
                    }
                    else
                    {
                        cout << " Employee Count: " << Get_Employee_Count() << endl;
                        cout << " Total Number of Employees: " << Get_Total_Number_Of_Employee() << endl;
                        cout << " Maximum number of employees are added " << endl;
                        goto start;
                    }
                    goto point_a;
                    break;

                case '3':
                    Search_Employee_Data();
                    cin.ignore(132, '\n');
                    cin.get();
                    goto point_a;
                    break;

                case '4':
                    Delete_Employee_Data();
                    goto point_a;
                    break;

                case '5':
                    Update_Employee_Data();
                    goto point_a;
                    break;

                case '6':
                    Show_All_Employees_Data();
                    cin.ignore(132, '\n');
                    cin.get();
                    goto point_a;
                    break;

                case '7':
                    Employee_Sign_Up();
                    goto point_a;
                    break;

                case '8':
                    found = Employee_Login(Get_ID());
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
                    Set_Colour(11);
                    cout << " Invalid choice ";
                    Set_Colour(15);
                    for (int i = 0; i < 3; i++)
                    {
                        cout << "!";
                        Sleep(1000);
                        goto point_a;
                    }
                    break;
                }

                break;

            case '2':
            point_b:
                Set_Colour(11);
                system("CLS");
                cout << "\t\t\t-------------Choose from below--------------" << endl;
                cout << "\t\t\t __________________________________________ " << endl;
                cout << "\t\t\t|                                          |" << endl;
                cout << "\t\t\t|       1--> To Mark Attendance            |" << endl;
                cout << "\t\t\t|       2--> To see your information       |" << endl;
                cout << "\t\t\t|       3--> To apply for leaves           |" << endl;
                cout << "\t\t\t|       4--> To update your information    |" << endl;
                cout << "\t\t\t|       5--> To See your attendance        |" << endl;
                cout << "\t\t\t|       6--> To Check-in and Check-out     |" << endl;
                cout << "\t\t\t|       7--> To Apply for Promotion        |" << endl;
                cout << "\t\t\t|       8--> To Go Back                    |" << endl;
                cout << "\t\t\t|__________________________________________|" << endl;

                subchoice = getch();

                Set_Colour(15);
                switch (subchoice)
                {
                case '1':
                    Mark_Manager_Attendance();
                    goto point_b;
                    break;

                case '2':
                    Show_This_Manager_Information(Get_ID());
                    cin.ignore(132, '\n');
                    cin.get();
                    goto point_b;
                    break;

                case '3':
                    Manager_Applying_for_Leave();
                    goto point_b;
                    break;

                case '4':
                    Update_Manager_Data();
                    goto point_b;
                    break;

                case '5':
                    cout << " Your attendance count is: " << Get_Manager_Attendance_Count(Get_ID()) << endl;
                    goto point_b;
                    break;

                case '6':
                point:
                    cout << "Enter the id of the Manager: " << endl;
                    cin >> id;
                    cin.ignore();
                    found = Match_Employee_ID(id);
                    if (found)
                    {
                        cout << "Enter the name of the Manager: " << endl;
                        getline(cin, name);
                        char option;

                    point_c:
                        Set_Colour(11);
                        cout << "Do you want to check in or check out? " << endl;
                        cout << " __________________________________________ " << endl;
                        cout << "|                                          |" << endl;
                        cout << "|           1--> Check In                  |" << endl;
                        cout << "|           2--> Check Out                 |" << endl;
                        cout << "|__________________________________________|" << endl;
                        option = getch();

                        Set_Colour(15);
                        switch (option)
                        {
                        case '1':
                        {
                            ifstream check_existing("checkIn_info.txt");

                            while (check_existing >> check_id)
                            {
                                string temp_name;
                                getline(check_existing, temp_name); // Consume the newline character
                                getline(check_existing, temp_name);
                                if (check_id == id)
                                {
                                    found = true;
                                    break;
                                }
                            }
                            check_existing.close();
                            if (found)
                            {
                                cout << " Manager is already parked." << endl;
                                goto point;
                            }
                            else
                            {
                                obj.Allot_Spots(name, id);
                                obj.Check_in();
                                goto point;
                            }
                            break;
                        }
                        case '2':
                        {
                            ifstream check_existing("checkIn_info.txt");

                            while (check_existing >> check_id)
                            {
                                string temp_name;
                                getline(check_existing, temp_name); // Consume the newline character
                                getline(check_existing, temp_name);
                                if (check_id == id)
                                {
                                    found = true;
                                    break;
                                }
                            }
                            check_existing.close();
                            if (found) // found  = 1  When 1 the condition is true
                            {
                                obj.Dismiss_Spots(id);
                                obj.Check_out();
                            }
                            else
                            {
                                cout << "Manager not found." << endl;
                                goto a;
                            }
                            break;
                        }
                        default:
                        {
                            Set_Colour(12);
                            cout << "Select a valid option. " << endl;
                            Set_Colour(15);
                            goto point_c;
                            break;
                        }
                        }
                    }
                    else
                    {
                        cout << " An employee with such ID donot exist in our system " << endl;
                        Sleep(2000);
                        goto a;
                    }

                    goto point_b;
                    break;

                case '7':
                    Manager_Applying_For_Promotion(Get_ID());
                    goto point_b;
                    break;

                case '8':
                    goto Menu;
                    break;

                default:
                    Set_Colour(12);
                    cout << " Invlaid Choice ";
                    Set_Colour(15);
                    for (int i = 0; i < 4; i++)
                    {
                        cout << "!";
                        Sleep(1000);
                    }
                    goto point_b;
                    break;
                }

                break;

            case '3':
                return true;
                break;

            default:
                Set_Colour(12);
                cout << " Invalid choice ";
                Set_Colour(15);
                for (int i = 0; i < 3; i++)
                {
                    cout << "!";
                    Sleep(1000);
                    goto Menu;
                }
                break;
            }
        }
    }

    // This member funciton is used to match whether a manager with this id exsits in your system or not
    bool Match_Manager_ID(const string &_manager_id)
    {

        register int found = false; // A flag variable

        fstream file;
        file.open("ManagersData.txt", ios::in);
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            return false;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age >> _experience >> _phone_number;
        file.ignore();
        getline(file, _manager_designation);
        file >> _salary >> _manager_leaves;
        file.ignore();
        getline(file, _address);

        while (!file.eof())
        {
            if (_manager_id == _id)
            {
                found = true; // To check whether the id of the Manager is found or not
                return true;
                break;
            }

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age >> _experience >> _phone_number;
            file.ignore();
            getline(file, _manager_designation);
            file >> _salary >> _manager_leaves;
            file.ignore();
            getline(file, _address);
        }

        file.close();

        if (found == false)
        {
            cout << "\tData of this id id not present";
            return false;
        }
    }

    // This member function is used to display the information of a specific id
    void Show_This_Manager_Information(const string &_manager_id)
    {
        // register int found = false; // A flag variable
        fstream file;
        file.open("ManagersData.txt", ios::in);
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age;
        file.ignore();
        getline(file, _experience);
        file >> _phone_number;
        file.ignore();
        getline(file, _manager_designation);
        file >> _salary >> _manager_leaves;
        file.ignore();
        getline(file, _address);
        while (!file.eof())
        {
            if (_manager_id == _id)
            {

                Set_Colour(14);
                cout << "\n";
                cout << "\n\t\t *************************************************************************" << endl;
                cout << "\t\t ||\t                    Data of Manager:         " << _manager_id
                     << "\t\t ||" << endl;
                cout << "\t\t ||_____________________________________________________________________||" << endl;
                cout << "\t\t ||                                                                     ||" << endl;
                cout << "\t\t || Manager ID                        : " << setw(25) << left << _id << "\t||" << endl;
                cout << "\t\t || Manager Name                      : " << setw(25) << left << _name << "\t||" << endl;
                cout << "\t\t || Manager Age                       : " << setw(25) << left << _age << "\t||" << endl;
                cout << "\t\t || Manager Phone Number              : " << setw(25) << left << _phone_number << "\t||" << endl;
                cout << "\t\t || Manager Designation               : " << setw(25) << left << _manager_designation << "\t||" << endl;
                cout << "\t\t || Manager Designation               : " << setw(25) << left << _salary << "\t||" << endl;
                cout << "\t\t || Manager Leaves                    : " << setw(25) << left << _manager_leaves << "\t||" << endl;
                cout << "\t\t || Manager Address                   : " << setw(25) << left << _address << "\t||" << endl;
                cout << "\t\t ||                                                                     ||";
                cout << "\n\t\t *************************************************************************" << endl;
                cout << "\n";
                // found = true; // To check whether the id of the Manager is found or not
                Sleep(2000);
                break;
            }

            Set_Colour(15);

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age;
            file.ignore();
            getline(file, _experience);
            file >> _phone_number;
            file.ignore();
            getline(file, _manager_designation);
            file >> _salary >> _manager_leaves;
            file.ignore();
            getline(file, _address);
        }

        file.close();

        cout << " Your attendance count is " << Get_Manager_Attendance_Count(_manager_id);

        /*if (found == false)
        {
            cout << "\tData of this id id not present";
        }*/
    }

    // Last day added member functions ( can have slight issues )

    // Making the member function for promotion of the manager at new designation
    void Manager_Applying_For_Promotion(const string &_manager_id)
    {
        // string promote_id;

        char main_choice, sub_choice;
        register bool found = false; // A flag variable

        /*cout << "\tEnter the Manager ID for promotion: ";
        cin >> promote_id;*/

        fstream file, file_1;
        file.open("ManagersData.txt", ios::in);
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            return;
        }

        file_1.open("promote.txt", ios::out);
        if (!file_1.is_open())
        {
            cout << "\tError opening file.";
            return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age;
        file.ignore();
        getline(file, _experience);
        file >> _phone_number;
        file.ignore();
        getline(file, _manager_designation);
        file >> _salary >> _manager_leaves;
        file.ignore();
        getline(file, _address);

        while (!file.eof())
        {
            if (_manager_id == _id)
            {
            Menu:
                Set_Colour(11);
                cout << "\n\t\t\t-------------Choose from below------------- " << endl;
                cout << "\t\t    __________________________________________ " << endl;
                cout << "\t\t   |                                          |" << endl;
                cout << "\t\t   |  1--> Promote to a new designation       |" << endl;
                cout << "\t\t   |__________________________________________|" << endl;
                main_choice = getch();

                Sleep(3000);
                system("CLS");
                Set_Colour(15);

                switch (main_choice)
                {
                case '1':

                f:
                    cout << "\t\t\t Designation of the managers: " << endl;
                    cout << "\t\t\t On which designatoin you wan to apply  " << endl;
                    Set_Colour(11);
                    cout << "\t\t\t-------------Choose from below--------------" << endl;
                    cout << "\t\t\t____________________________________________" << endl;
                    cout << "\t\t\t|                                           |" << endl;
                    cout << "\t\t\t|        1-> HR Manager                     |" << endl;
                    cout << "\t\t\t|        2-> Marketing Manager              |" << endl;
                    cout << "\t\t\t|        3-> Sales Manager                  |" << endl;
                    cout << "\t\t\t|        4-> Team Leader                    |" << endl;
                    cout << "\t\t\t|___________________________________________|" << endl;
                    sub_choice = getch();

                    Set_Colour(15);
                    switch (sub_choice)
                    {
                    case '1':
                        if (Promotion_Approval())
                        {
                            Application_Accepted();

                            _manager_designation = "HR Manager";
                            _salary = 70000;
                            _manager_leaves = 6;
                        }
                        else
                        {
                            Application_Rejected();
                        }
                        break;

                    case '2':

                        if (Promotion_Approval())
                        {
                            Application_Accepted();
                            _manager_designation = "Marketing Head";
                            _salary = 100000;
                            _manager_leaves = 4;
                        }
                        else
                        {
                            Application_Rejected();
                        }

                        break;

                    case '3':
                        if (Promotion_Approval())
                        {
                            Application_Accepted();
                            _manager_designation = "Sales Head";
                            _salary = 90000;
                            _manager_leaves = 5;
                        }
                        else
                        {
                            Application_Rejected();
                        }

                        break;

                    case '4':
                        if (Promotion_Approval())
                        {
                            Application_Accepted();
                            _manager_designation = "Team Leader";
                            _salary = 100000;
                            _manager_leaves = 8;
                        }
                        else
                        {
                            Application_Rejected();
                        }

                        break;

                    default:
                        Set_Colour(12);
                        cout << " Invalid choice";
                        Set_Colour(15);
                        for (int i = 0; i < 4; i++)
                        {
                            cout << "!";
                            Sleep(1000);
                        }
                        goto f;
                        break;
                    }

                    break;

                default:
                    cout << "\n\t Invalid Input Please enter form the given choice " << endl;
                    system("CLS"); // To clear the screen
                    goto Menu;
                }

                found = true;
            }
            Set_Colour(15);

            file_1 << _id << "\n";
            file_1 << _name << "\n";
            file_1 << _age << "\n";
            file_1 << _experience << "\n";
            file_1 << _phone_number << "\n";
            file_1 << _manager_designation << "\n";
            file_1 << _salary << "\n";
            file_1 << _manager_leaves << "\n";
            file_1 << _address << "\n";

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age;
            file.ignore();
            getline(file, _experience);
            file >> _phone_number;
            file.ignore();
            getline(file, _manager_designation);
            file >> _salary >> _manager_leaves;
            file.ignore();
            getline(file, _address);
        }

        file.close();
        file_1.close();

        remove("ManagersData.txt");
        rename("promote.txt", "ManagersData.txt");

        // Show prompt that the data of the Manager is updated successfully
        if (found == true)
        {
            cout << "\t The manager is promoted to a new designation " << endl;
        }
        else
        {
            cout << "\tManager ID not found." << endl;
        }
    }
};
#endif