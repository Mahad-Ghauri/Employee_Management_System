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
    float _experience;
    int total_employees;

public:
    Manager() // Default Constructor
    {
        _manager_designation = " Manager ";
        _manager_count = 0;
        _manager_number = 0;
    }

    int Get_Total_Employees()
    {
        return total_employees;
    }

    void Set_Total_Number_Of_Employee()
    {
        total_employees = Get_Total_Number_Of_Employee();
    }

    void Set_Number_Of_Employees()
    {
    a:
        int number;
        cout << " Enter the number of employees you want to enter ";
        cin >> number;
        if (cin.fail())
        {
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

        cout << "\n";

        cout << " Enter the following information of the Manager " << endl;

        cout << endl;

    start:
        cout << " Enter the manager ID ";
        cin >> _id;

        // Checking whether an Manager with the eneterd id exits or not
        // Checking whether an employee with the eneterd id exits or not
        if (!file)
        {
            // If the file does not exist, we can skip this check
            file.clear();
        }
        else
        {
            while (file >> id)
            {
                file.ignore();

                if (id == _id)
                {
                    cout << " An employee with this id already exists " << endl;
                    file.close();
                    goto start;
                }
            }
            file.close();
        }
        cin.ignore();

    a:
        cout << " Manager name: ";
        getline(cin, _name);
        for (char i = 0; i < _name.length(); i++)
        {
            if (isdigit(_name[i])) // Built-in function to check whether the string has a digit entered or not
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto a;
            }
        }

    b:
        cout << " Manager age: ";
        cin >> _age;
        if (cin.fail())
        {
            cout << endl;

            cout << " Invlaid input!. Enter integers only " << endl;
            goto b;
        }

        cin.ignore();

    c:
        cout << " Manager Experience: ";
        cin >> _experience;
        if (cin.fail())
        {
            cout << " In valid Input! Enter numbers only " << endl;
            goto c;
        }

    d:
        cin.ignore();
        cout << " Manager address: ";
        getline(cin, _address);
        for (char i = 0; i < _address.length(); i++)
        {
            if (isdigit(_address[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto d;
            }
        }

    e:
        cout << " Manager phone number ";
        cin >> _phone_number;
        if (cin.fail())
        {
            cout << endl;

            cout << " Invlaid input!. Enter integers only " << endl;
            goto e;
        }

    f:
        cout << "\t\t\t Designation of the managers: " << endl;
        cout << "\t\t\tWhat is the type of the managers " << endl;
        cout << "\t\t\t-------------Choose from below--------------" << endl;
        cout << "\t\t\t____________________________________________" << endl;
        cout << "\t\t\t|                                           |" << endl;
        cout << "\t\t\t|        1-> HR Manager                     |" << endl;
        cout << "\t\t\t|        2-> Marketing Manager              |" << endl;
        cout << "\t\t\t|        3-> Sales Manager                  |" << endl;
        cout << "\t\t\t|        4-> Team Leader                    |" << endl;
        cout << "\t\t\t|___________________________________________|" << endl;
        choice = getch();

        switch (choice)
        {
        case '1':
            _manager_designation = "HR Manager";
            _salary = 70000;
            _manager_leaves = 6;
            break;

        case '2':
            _manager_designation = "Marketing Head";
            _salary = 100000;
            _manager_leaves = 4;
            break;

        case '3':
            _manager_designation = "Sales Head";
            _salary = 90000;
            _manager_leaves = 5;
            break;

        case '4':
            _manager_designation = "Team Leader";
            _salary = 100000;
            _manager_leaves = 8;
            break;

        default:
            cout << " Invalid choice!!! . Please enter again " << endl;
            goto f;
            break;
        }

        // Saving the data in the file
        ofstream file_write;
        file_write.open("ManagersData.txt", ios::out | ios::app);
        if (!file_write.is_open())
        {
            cout << " Error opening the file " << endl;
            return;
        }
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

        cout << " Manager added successfully! " << endl;
        _manager_count++;
        _manager_count++;
    }

    void Show_All_Managers_Data()
    {
        ifstream file;
        file.open("ManagersData.txt");

        // Faliure in opening of the file
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            return;
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

        while (!file.eof()) // Check if the end of file is reached
        {
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
            cout << "\tError opening file.";
            return;
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
            if (search_id == _id)
            {
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
        file >> _age >> _experience >> _phone_number;
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
            file >> _age >> _experience >> _phone_number;
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
        }
    }

    void Update_Manager_Data()
    {
        string promote_id;
        int choose;
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
        file >> _age >> _experience >> _phone_number;
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
                cout << "\n\t\t  What do you want to update ";
                cout << "\n\t\t\t   -------------Choose from below------------- " << endl;
                cout << "\n\t\t    __________________________________________ ";
                cout << "\n\t\t   |                                          |";
                cout << "\n\t\t   |  1--> Designation                        |"
                     << "\n\t\t   |  2--> Address                            |"
                     << "\n\t\t   |  3--> Phone Number                       |"
                     << "\n\t\t   |  4--> Salary                             |"
                     << "\n\t\t   |  5--> Total Leaves                       |";
                cout << "\n\t\t   |__________________________________________|" << endl;
                cin >> choose;
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
                } // Function called for input validation

                system("CLS");
                switch (choose)
                {
                case 1:
                    cout << "\tEnter the new designation: ";
                    cin.ignore();
                    getline(cin, _manager_designation);
                    break;

                case 2:
                    cout << "\n\tEnter the new address: ";
                    cin.ignore();
                    getline(cin, _address);
                    break;

                case 3:
                    cout << "\n\tEnter the new phone number: ";
                    cin >> _phone_number;
                    break;

                case 4:
                    cout << "\n\tEnter the new salary: ";
                    // cin >> salary;
                    break;

                case 5:
                    cout << "\n\tEnter the new total leaves: ";
                    cin >> _manager_leaves;
                    break;

                default:
                    cout << "\n\t Invalid Input .No such update of data available" << endl;
                    system("CLS"); // To clear the screen
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
            file >> _age >> _experience >> _phone_number;
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
            cout << "\tData Updated Successfully." << endl;
        }
        else
        {
            cout << "\tManager ID not found." << endl;
        }
    }

    /*void Manager_Applying_for_Leave()
    {
        string id, _leave_type, emp_name;
        int _leave_days;
        char choose;
        register bool found = false; // A flag variable
        cout << " Enter your id ";
        cin >> id;
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
        // Reading from the file to take the id of the Manager adn match whether an Manager with this id exist or not
        // Also to update the Manager leaves if their leave is expcepted
        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age >> _experience >> _phone_number;
        file.ignore();
        getline(file, _manager_designation);
        file >> _salary >> _manager_leaves;
        file.ignore();
        getline(file, _address);
        emp_name = _name; // Storing the name for passing into the application
        while (!file.eof())
        {
            if (id == _id)
            {
                cout << "\n\t\t   Manager ID found. " << endl;
                start:
                cout << "\n\t\t  Which type of leave you want to apply ? ";
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
                if (cin.fail())
                {
                    cout << " \n";
                    cout << " \t\t\t   Error! Please choose from the below " << endl;
                    cout << "\n\t\t  Which type of leave you want to apply ? ";
                    cout << "\n\t\t\t   -------------Choose from below------------- " << endl;
                    cout << "\n\t\t    __________________________________________ ";
                    cout << "\n\t\t   |                                          |";
                    cout << "\n\t\t   |  1--> Sick Leave                         |"
                         << "\n\t\t   |  2--> Personal Leave                     |"
                         << "\n\t\t   |  3--> Study Leave                        |"
                         << "\n\t\t   |  4--> Annual Leave                       |"
                         << "\n\t\t   |  5--> Maternity Leave                    |";
                    cout << "\n\t\t   |__________________________________________|" << endl;
                    // Built-in function   This function returns true when an input failure occurs. In this case it would be an input that is not an integer.
                    //  If the cin fails then the input buffer is kept in an error state.  Buffer is region of memory used to store data temporarily
                    cin.clear();

                    // Built-in function    This function to remove undesirable characters from the input buffer
                    cin.ignore(132, '\n');
                    choose = getch();
                }
                system("CLS");
                const string TO = " CEO "; // Means writing the application to the Manager
                switch (choose)
                {
                case 1: // Sick Leave
                    _leave_type = " sick leave ";
                    _leave_days = get_Leave_Days(_leave_type);
                    Sick_Leave_Application(get_Illness_Reason(), get_Illness_Symptoms(), _leave_days, emp_name, TO);
                    cout << "\n";
                    if (Application_Approval() == 1)
                    {
                        Application_Accepted();
                        _manager_leaves += _leave_days;
                        break;
                    }
                    else
                    {
                        Application_Rejected();
                        _manager_leaves = _manager_leaves;
                        break;
                    }
                case 2: // Unpaid Leave
                    _leave_type = " personal leave ";
                    _leave_days = get_Leave_Days(_leave_type);
                    Personal_Leave_Application(get_Personal_Reason(), _leave_days, emp_name, TO);
                    cout << "\n";
                    if (Application_Approval() == 1)
                    {
                        Application_Accepted();
                        _manager_leaves += _leave_days;
                        break;
                    }
                    else
                    {
                        Application_Rejected();
                        _manager_leaves = _manager_leaves;
                        break;
                    }
                case 3: // Study Leave
                    _leave_type = " study leave ";
                    _leave_days = get_Leave_Days(_leave_type);
                    Study_Leave_Application(get_Study_Reason(), get_Study_Field(), _leave_days, emp_name, TO);
                    cout << "\n";
                    if (Application_Approval() == 1)
                    {
                        Application_Accepted();
                        _manager_leaves += _leave_days;
                        break;
                    }
                    else
                    {
                        Application_Rejected();
                        _manager_leaves = _manager_leaves;
                        break;
                    }
                case 4: // Annual Leave
                    _leave_type = " annual leave ";
                    _leave_days = get_Leave_Days(_leave_type);
                    Annual_Leave_Application(get_Annual_Reason(), _leave_days, emp_name, TO);
                    cout << "\n";
                    if (Application_Approval() == 1)
                    {
                        Application_Accepted();
                        _manager_leaves += _leave_days;
                        break;
                    }
                    else
                    {
                        Application_Rejected();
                        _manager_leaves = _manager_leaves;
                        break;
                    }
                case 5: // Maternity Leave
                    _leave_type = " maternity leave ";
                    _leave_days = get_Leave_Days(_leave_type);
                    Materity_Leave_Application(get_Maternity_Reason(), _leave_days, emp_name, TO);
                    cout << "\n";
                   if (Application_Approval() == 1)
                    {
                        Application_Accepted();
                        _manager_leaves += _leave_days;
                        break;
                    }
                    else
                    {
                        Application_Rejected();
                        _manager_leaves = _manager_leaves;
                        break;
                    }
                default:
                    cout << "\n\t Invalid Input !!!." << endl;
                    system("CLS");
                    goto start;
                }
                found = true;
            }
            file_1 << _id << "\n";
            file_1 << _name << "\n";
            file_1 << _age << "\n";
            file_1 << _phone_number << "\n";
            file_1 << _manager_designation << "\n";
            file_1 << _salary << "\n";
            file_1 << _manager_leaves << "\n";
            file_1 << _address << "\n";
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
        file_1.close();
        remove("ManagersData.txt");
        rename("promote.txt", "ManagersData.txt");

        // Show prompt that the data of the Manager is updated successfully
        if (found == true)
        {
            cout << "\tThanks for applying to the leave." << endl;
        }
        else
        {
            cout << "\tManager ID not found." << endl;
        }
    }*/

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
        while (file >> _id >> ws && getline(file, _name) >> _age >> _experience >> _phone_number >> ws && getline(file, _manager_designation) >> _salary >> _manager_leaves >> ws && getline(file, _address))
        {
            if (id == _id)
            {
                cout << "\n\t\t   Manager ID found. " << endl;
            start:
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
                    cout << "\n\t Invalid Input !!!." << endl;
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

    bool Strong_Username(string _username) override
    {
        Strong_Username(_username);
    }

    void Manager_SignUp()
    {
        string _enter_id;
        register bool match;

        cout << " Enter your manager ID to sign-up ";
        cin >> _enter_id;

        match = Match_Manager_ID(_enter_id);

        if (match == true)
        {
        point: // point declared here will come here if username requirements not met
            system("CLS");
            string username, password;
            Set_ID(_enter_id);

            cout << "\n\n\t\tEmployee Managment System : " << endl;
            cout << "\n\n\t\tPlease SIGN UP by adding username and password " << endl;
            cout << "\n\n\t\tEnter Username :  ";
            getline(cin, username);
            if (username.length() <= 6 || !Strong_Username(username))
            {
                cout << "\tThe username must consist of more than six characters "
                     << "and consist of at-least one upper case one lowercase and one symbol. " << endl;
                cout << endl;
                Sleep(2000);
                goto point;
            }
            else if (username.length() >= 20 || !Strong_Username(username))
            {
                cout << "\tThe username must consist of less than twenty characters "
                     << "and consist of at-least one upper case one lowercase and one symbol. " << endl;
                cout << endl;
                Sleep(2000);
                goto point;
            }

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
                cout << " \t The password length should be more than 5  " << endl;
                Sleep(2000);
                goto point;
            }

            fstream file;
            file.open("ManagerUserPass.txt", ios::out | ios::app);
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
            // Manager_Login(_enter_id); // login function called.
        }
        else
        {
            cout << " Such an ID donot exist in your system " << endl;
        }
    }

    bool Manager_Login(string _user_id)
    {
    start: // start point will come here in case of logging out
        system("ClS");
        string username_1, pass_1, password, username;
        register bool match = false; // bool found used to check conditions

        cout << "\n\n\t\tEmployee Managment System : " << endl;
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
                cout << "\n";
                cout << " \t \t \t \t Login Successful " << endl
                     << endl;
                cout << "\t\t\t===============================================================" << endl;
                cout << "\t\t\t                         Welcome                               " << endl;
                cout << "\t\t\t===============================================================" << endl;
                cout << "\n";
                Sleep(3000);
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

            cout << "\t\t\t------------Choose from below----------- " << endl;
            cout << "\t\t\t _______________________________________ " << endl;
            cout << "\t\t\t|                                       |" << endl;
            cout << "\t\t\t|    1--> Manage employees              |" << endl;
            cout << "\t\t\t|    2--> Manage your own information   |" << endl;
            cout << "\t\t\t|    3--> Exit the program              |" << endl;
            cout << "\t\t\t|_______________________________________|" << endl;
            mainchoice = getch();

            switch (mainchoice)
            {
            case '1':
            point_a:
                system("CLS");

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

                switch (subchoice)
                {
                case '1':
                a:
                    Set_Number_Of_Employees();
                    if (Get_Total_Employees() >= Get_Number_Of_Employees())
                    {
                        goto point_a;
                    }
                    else
                    {
                        cout << " You have greater number of employees than ";
                        cout << "the total number of employees " << endl;
                        cout << " Total Number of Employees: " << Get_Total_Employees() << endl;
                        goto a;
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
                    goto point_a;
                    break;

                case '3':
                    Search_Employee_Data();
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
                    cout << " Invalid choice ";
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
                system("CLS");
                cout << "\t\t\t-------------Choose from below--------------" << endl;
                cout << "\t\t\t __________________________________________ " << endl;
                cout << "\t\t\t|                                          |" << endl;
                cout << "\t\t\t|       1--> To Mark Attendance            |" << endl;
                cout << "\t\t\t|       2--> To see your information       |" << endl;
                cout << "\t\t\t|       3--> To apply for leaves           |" << endl;
                cout << "\t\t\t|       4--> To update your information    |" << endl;
                cout << "\t\t\t|       5--> To See your attendance        |" << endl;
                cout << "\t\t\t|       6--> To Go Back                    |" << endl;
                cout << "\t\t\t|__________________________________________|" << endl;

                subchoice = getch();

                switch (subchoice)
                {
                case '1':
                    Mark_Manager_Attendance();
                    goto point_b;
                    break;

                case '2':
                    Show_This_Manager_Information(Get_ID());

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
                    goto Menu;
                    break;

                default:
                    cout << " Invlaid Choice ";
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
                cout << " Invalid choice ";
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

    // This member funciton is used to match whether a manager with this id ecits in your system or not
    bool Match_Manager_ID(const string &_manager_id)
    {

        register int found = false; // A flag variable

        fstream file;
        file.open("ManagersData.txt", ios::in);
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            // return;
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

        cout << " Your attendance count is " << Get_Manager_Attendance_Count(_manager_id);

        /*if (found == false)
        {
            cout << "\tData of this id id not present";
        }*/
    }
};
#endif