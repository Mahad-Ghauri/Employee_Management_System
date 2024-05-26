#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Parking.h"
#include "Person.h"

class Employee : virtual public Person, public Parking // The final keyword prevent further inheritance of the class
{
private:
    int _employee_number;
    int _employee_count;
    int _employee_leaves;
    string _employee_designation;
    char choice;

public:
    Employee() // Default Constructor
    {
        _employee_number = 0;
        _employee_count = 0;
    }

    int Get_Employee_Count()
    {
        return _employee_count;
    }

    int Get_Employee_Number()
    {
        return _employee_number;
    }

    // By overriding future error could be reduced

    void Set_ID(string id)
    {
        set_ID(id); // Called a member function of the base class
    }

    string Get_ID() const
    {
        return get_ID(); // Called a member function of the base class
    }

    void Add_Employee()
    {
        string id;
        ifstream file;
        file.open("EmployeesData.txt");
        if (!file.is_open())
        {
            cout << " Error opening the file " << endl;
            return;
        }

        cout << " \n ";

        cout << " Enter the following information of the employee " << endl;

        cout << endl;

    start:
        cout << " Enter the employee ID ";
        cin >> _id;

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
        cout << " Employee name: ";
        getline(cin, _name);
        for (char i = 0; i < _name.length(); i++)
        {
            if (isdigit(_name[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto a;
            }
        }

    b:
        cout << " Employee age: ";
        cin >> _age;
        if (cin.fail())
        {
            cout << endl;

            cout << " Invlaid input!. Enter integers only " << endl;
            goto b;
        }

        cin.ignore();

    c:
        cout << " Employee address: ";
        getline(cin, _address);
        for (char i = 0; i < _address.length(); i++)
        {
            if (isdigit(_address[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto c;
            }
        }

    d:
        cout << " Employee phone number ";
        cin >> _phone_number;
        if (cin.fail())
        {
            cout << endl;

            cout << " Invlaid input!. Enter integers only " << endl;
            goto d;
        }

        cin.ignore();

    e:

        cout << "\t\t\tDesignation of the employees: " << endl;
        cout << "\t\t\tWhat is the type of the employee " << endl;
        cout << "\t\t\t-------------Choose from below--------------" << endl;
        cout << "\t\t\t____________________________________________" << endl;
        cout << "\t\t\t|                                           |" << endl;
        cout << "\t\t\t|        1-> Office boy                     |" << endl;
        cout << "\t\t\t|        2-> Clerk                          |" << endl;
        cout << "\t\t\t|        3-> Accountant                     |" << endl;
        cout << "\t\t\t|        4-> IT specailist                  |" << endl;
        cout << "\t\t\t|        5-> Sales Representative           |" << endl;
        cout << "\t\t\t|        6-> Marketing person               |" << endl;
        cout << "\t\t\t|___________________________________________|" << endl;
        choice = getch();

        switch (choice)
        {
        case '1':
            _employee_designation = "Office Boy";
            _salary = 30000;
            _employee_leaves = 6;
            break;

        case '2':
            _employee_designation = "Clerk";
            _salary = 40000;
            _employee_leaves = 4;
            break;
        case '3':
            _employee_designation = "Accountant";
            _salary = 50000;
            _employee_leaves = 5;
            break;
        case '4':
            _employee_designation = "IT specailist";
            _salary = 100000;
            _employee_leaves = 8;
            break;
        case '5':
            _employee_designation = "Sales Representative";
            _salary = 70000;
            _employee_leaves = 6;
            break;
        case '6':
            _employee_designation = " Marketing person ";
            _salary = 80000;
            _employee_leaves = 5;
            break;

        default:
            cout << " Invalid choice!!! . Please enter again " << endl;
            goto e;
            break;
        }

        // Saving the data in the file
        ofstream file_write;
        file_write.open("EmployeesData.txt", ios::out | ios::app);
        if (!file_write.is_open())
        {
            cout << " Error opening the file " << endl;
            return;
        }
        file_write << _id << "\n";
        file_write << _name << "\n";
        file_write << _age << "\n";
        file_write << _phone_number << "\n";
        file_write << _employee_designation << "\n";
        file_write << _salary << "\n";
        file_write << _employee_leaves << "\n";
        file_write << _address << "\n";

        file_write.close();

        cout << " Employee added successfully! " << endl;
        _employee_count++;
        _employee_number++;
    }

    void Show_All_Employees_Data()
    {
        ifstream file;
        file.open("EmployeesData.txt");

        // Faliure in opening of the file
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age >> _phone_number;
        file.ignore();
        getline(file, _employee_designation);
        file >> _salary >> _employee_leaves;
        file.ignore();
        getline(file, _address);

        while (!file.eof()) // Check if the end of file is reached
        {
            cout << "\n";
            cout << "\n\t\t *************************************************************************" << endl;
            cout << "\t\t ||\t                    Data of Employee"
                 << "\t\t\t        || " << endl;
            cout << "\t\t ||_____________________________________________________________________||" << endl;
            cout << "\t\t ||                                                                     ||" << endl;
            cout << "\t\t || Employee ID                        : " << setw(25) << left << _id << "\t||" << endl;
            cout << "\t\t || Employee Name                      : " << setw(25) << left << _name << "\t||" << endl;
            cout << "\t\t || Employee Age                       : " << setw(25) << left << _age << "\t||" << endl;
            cout << "\t\t || Employee Phone Number              : " << setw(25) << left << _phone_number << "\t||" << endl;
            cout << "\t\t || Employee Designation               : " << setw(25) << left << _employee_designation << "\t||" << endl;
            cout << "\t\t || Employee Salary                    : " << setw(25) << left << _salary << "\t||" << endl;
            cout << "\t\t || Employee Leaves                    : " << setw(25) << left << _employee_leaves << "\t||" << endl;
            cout << "\t\t || Employee Address                   : " << setw(25) << left << _address << "\t||" << endl;
            cout << "\t\t ||                                                                     ||";
            cout << "\n\t\t *************************************************************************" << endl;
            cout << "\n";

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age >> _phone_number;
            file.ignore();
            getline(file, _employee_designation);
            file >> _salary >> _employee_leaves;
            file.ignore();
            getline(file, _address);
        }
        file.close();
    }

    void Search_Employee_Data()
    {

        string search_id;
        cout << "Search the data by entering the id : ";
        cin >> search_id;

        register int found = false; // A flag variable
        fstream file;
        file.open("EmployeesData.txt", ios::in);

        // Faliure in opening of the file
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age >> _phone_number;
        file.ignore();
        getline(file, _employee_designation);
        file >> _salary >> _employee_leaves;
        file.ignore();
        getline(file, _address);

        while (!file.eof())
        {
            if (search_id == _id)
            {

                cout << "\n";
                cout << "\n\t\t *************************************************************************" << endl;
                cout << "\t\t ||\t                    Data of Employee:    " << search_id
                     << "\t\t     ||" << endl;
                cout << "\t\t ||_____________________________________________________________________||" << endl;
                cout << "\t\t ||                                                                     ||" << endl;
                cout << "\t\t || Employee ID                        : " << setw(25) << left << _id << "\t||" << endl;
                cout << "\t\t || Employee Name                      : " << setw(25) << left << _name << "\t||" << endl;
                cout << "\t\t || Employee Age                       : " << setw(25) << left << _age << "\t||" << endl;
                cout << "\t\t || Employee Phone Number              : " << setw(25) << left << _phone_number << "\t||" << endl;
                cout << "\t\t || Employee Designation               : " << setw(25) << left << _employee_designation << "\t||" << endl;
                cout << "\t\t || Employee Salary                    : " << setw(25) << left << _salary << "\t||" << endl;
                cout << "\t\t || Employee Leaves                    : " << setw(25) << left << _employee_leaves << "\t||" << endl;
                cout << "\t\t || Employee Address                   : " << setw(25) << left << _address << "\t||" << endl;
                cout << "\t\t ||                                                                     ||";
                cout << "\n\t\t *************************************************************************" << endl;
                cout << "\n";
                found = true; // To check whether the id of the employee is found or not
                break;
            }

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age >> _phone_number;
            file.ignore();
            getline(file, _employee_designation);
            file >> _salary >> _employee_leaves;
            file.ignore();
            getline(file, _address);
        }

        file.close();

        if (found == false)
        {
            cout << "\tData of this id id not present";
        }
    }

    void Delete_Employee_Data()
    {
        string delete_id;
        register bool found = false; // A flag variblvariable
        cout << "\tEnter the ID of the employee you want to fire and delete the data: ";
        cin >> delete_id;

        fstream file, file_1;
        file.open("EmployeesData.txt", ios::in);
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            return;
        }

        file_1.open("temp.txt", ios::out | ios::app); // Created a file for storing all the data of the employee of the company that you donot want to delete
        if (!file_1.is_open())                        // and then this file is renamed
        {
            cout << "\tError opening file.";
            return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age >> _phone_number;
        file.ignore();
        getline(file, _employee_designation);
        file >> _salary >> _employee_leaves;
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
                file_1 << _phone_number << "\n";
                file_1 << _employee_designation << "\n";
                file_1 << _salary << "\n";
                file_1 << _employee_leaves << "\n";
                file_1 << _address << "\n";
            }
            if (delete_id == _id) // only to check wheter the id exsists or not
            {
                found = true;
            }

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age >> _phone_number;
            file.ignore();
            getline(file, _employee_designation);
            file >> _salary >> _employee_leaves;
            file.ignore();
            getline(file, _address);
        }

        file.close();
        file_1.close();

        remove("EmployeesData.txt");
        rename("temp.txt", "EmployeesData.txt"); // Renamed the file so donot get confusede in accessing the files containing the data of the employee
        if (found == false)
        {
            cout << "\tTheir is no data of any employee with this id " << endl;
        }
        else
        {
            _employee_count--;
            cout << "\tData Deleted Successfully." << endl;
        }
    }

    void Update_Employee_Data()
    {
        string promote_id;
        int choose;
        register bool found = false; // A flag variable

        cout << "\tEnter the employee ID to update data: ";
        cin >> promote_id;

        fstream file, file_1;
        file.open("EmployeesData.txt", ios::in);
        if (!file.is_open())
        {
            cout << " Employee file " << endl;
            cout << "\tError opening file.";
            return;
        }
        file_1.open("Promote.txt", ios::out);
        if (!file_1.is_open())
        {
            cout << " New file " << endl;
            cout << "\tError opening file.";
            return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age >> _phone_number;
        file.ignore();
        getline(file, _employee_designation);
        file >> _salary >> _employee_leaves;
        file.ignore();
        getline(file, _address);

        while (!file.eof())
        {
            if (promote_id == _id)
            {
                cout << "\n\t\t   Employee ID found. Update the information" << endl;
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
                    getline(cin, _employee_designation);
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
                    cin >> _employee_leaves;
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
            file_1 << _phone_number << "\n";
            file_1 << _employee_designation << "\n";
            file_1 << _salary << "\n";
            file_1 << _employee_leaves << "\n";
            file_1 << _address << "\n";

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age >> _phone_number;
            file.ignore();
            getline(file, _employee_designation);
            file >> _salary >> _employee_leaves;
            file.ignore();
            getline(file, _address);
        }

        file.close();
        file_1.close();

        remove("EmployeesData.txt");
        rename("Promote.txt", "EmployeesData.txt");

        // Show prompt that the data of the employee is updated successfully
        if (found == true)
        {
            cout << "\tData Updated Successfully." << endl;
        }
        else
        {
            cout << "\tEmployee ID not found." << endl;
        }
    }

    /*void Employee_Appliyng_for_Leave()
    {
        string id, _leave_type, emp_name;
        int _leave_days;
        char choose;
        register bool found = false; // A flag variable
        cout << " Enter your id ";
        cin >> id;
        fstream file, file_1;
        file.open("EmployeesData.txt", ios::in);
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
        // Reading from the file to take the id of the employee adn match whether an employee with this id exist or not
        // Also to update the employee leaves if their leave is expcepted
        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age >> _phone_number;
        file.ignore();
        getline(file, _employee_designation);
        file >> _salary >> _employee_leaves;
        file.ignore();
        getline(file, _address);
        emp_name = _name; // Storing the name for passing into the application
        while (!file.eof())
        {
            if (id == _id)
            {
                cout << "\n\t\t   Employee ID found. " << endl;
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
                Sleep(2000);
                system("CLS");
                const string TO = " Manager "; // Means writing the application to the Manager
                switch (choose)
                {
                case '1': // Sick Leave
                    _leave_type = " sick leave ";
                    _leave_days = get_Leave_Days(_leave_type);
                    Sick_Leave_Application(get_Illness_Reason(), get_Illness_Symptoms(), _leave_days, emp_name, TO);
                    // Application_Approval();
                    if (Application_Approval() == 1)
                    {
                        Application_Accepted();
                        _employee_leaves += _leave_days;
                        break;
                    }
                    else
                    {
                        Application_Rejected();
                        _employee_leaves = _employee_leaves;
                        break;
                    }
                case '2': // Unpaid Leave
                    _leave_type = " personal leave ";
                    _leave_days = get_Leave_Days(_leave_type);
                    Personal_Leave_Application(get_Personal_Reason(), _leave_days, emp_name, TO);
                    cout << "\n";
                    if (Application_Approval() == 1)
                    {
                        Application_Accepted();
                        _employee_leaves += _leave_days;
                        break;
                    }
                    else
                    {
                        Application_Rejected();
                        _employee_leaves = _employee_leaves;
                        break;
                    }
                case '3': // Study Leave
                    _leave_type = " study leave ";
                    _leave_days = get_Leave_Days(_leave_type);
                    Study_Leave_Application(get_Study_Reason(), get_Study_Field(), _leave_days, emp_name, TO);
                    cout << "\n";
                    if (Application_Approval() == 1)
                    {
                        Application_Accepted();
                        _employee_leaves += _leave_days;
                        break;
                    }
                    else
                    {
                        Application_Rejected();
                        _employee_leaves = _employee_leaves;
                        break;
                    }
                case '4': // Annual Leave
                    _leave_type = " annual leave ";
                    _leave_days = get_Leave_Days(_leave_type);
                    Annual_Leave_Application(get_Annual_Reason(), _leave_days, emp_name, TO);
                    cout << "\n";
                    if (Application_Approval() == 1)
                    {
                        Application_Accepted();
                        _employee_leaves += _leave_days;
                        break;
                    }
                    else
                    {
                        Application_Rejected();
                        _employee_leaves = _employee_leaves;
                        break;
                    }
                case '5': // Maternity Leave
                    _leave_type = " maternity leave ";
                    _leave_days = get_Leave_Days(_leave_type);
                    Materity_Leave_Application(get_Maternity_Reason(), _leave_days, emp_name, TO);
                    cout << "\n";
                    if (Application_Approval() == 1)
                    {
                        Application_Accepted();
                        _employee_leaves += _leave_days;
                        break;
                    }
                    else
                    {
                        Application_Rejected();
                        _employee_leaves = _employee_leaves;
                        break;
                    }
                default:
                    cout << "\n";
                    cout << "\n\t Invalid Input !!!." << endl;
                    system("CLS");
                    goto start;
                    break;
                }
                found = true;
            }
            file_1 << _id << "\n";
            file_1 << _name << "\n";
            file_1 << _age << "\n";
            file_1 << _phone_number << "\n";
            file_1 << _employee_designation << "\n";
            file_1 << _salary << "\n";
            file_1 << _employee_leaves << "\n";
            file_1 << _address << "\n";
            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age >> _phone_number;
            file.ignore();
            getline(file, _employee_designation);
            file >> _salary >> _employee_leaves;
            file.ignore();
            getline(file, _address);
        }
        file.close();
        file_1.close();
        remove("EmployeesData.txt");
        rename("promote.txt", "EmployeesData.txt");
        // Show prompt that the data of the employee is updated successfully
        if (found == true)
        {
            cout << "\tThanks for applying to the leave." << endl;
        }
        else
        {
            cout << "\tEmployee ID not found." << endl;
        }
    }*/

    void Employee_Applying_for_Leave()
    {
        string id, _leave_type, emp_name;
        int _leave_days;

        char choose;
        bool found = false; // A flag variable

        cout << "Enter your id: ";
        cin >> id;

        fstream file, file_1;
        file.open("EmployeesData.txt", ios::in);
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

        // Reading from the file to take the id of the employee and match whether an employee with this id exists or not
        // Also to update the employee leaves if their leave is accepted
        // The  'ws'     is used to skip any leading whitespace character in the input stream
        while (file >> _id >> ws && getline(file, _name) >> _age >> _phone_number >> ws && getline(file, _employee_designation) >> _salary >> _employee_leaves >> ws && getline(file, _address))
        {
            if (id == _id)
            {
                cout << "\n\t\t   Employee ID found. " << endl;
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

                const string TO = "Manager"; // Means writing the application to the Manager

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
                    _employee_leaves += _leave_days;
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
            file_1 << _phone_number << "\n";
            file_1 << _employee_designation << "\n";
            file_1 << _salary << "\n";
            file_1 << _employee_leaves << "\n";
            file_1 << _address << "\n";
        }

        file.close();
        file_1.close();

        remove("EmployeesData.txt");
        rename("promote.txt", "EmployeesData.txt");

        // Show prompt that the data of the employee is updated successfully
        if (found)
        {
            cout << "\tThanks for applying for the leave." << endl;
        }
        else
        {
            cout << "\tEmployee ID not found." << endl;
        }
    }

    void Mark_Employee_Attendance()
    {

        register string id;
        bool is_checking_in;
        cout << " Enter the id of the employee ";
        cin >> id;

        is_checking_in = Match_Employee_ID(id);

        if (is_checking_in == true)
        {
            Set_ID(id);
            // Increment attendance for the employee
            int count;
            count = Get_Employee_Attendance_Count(Get_ID()) + 1;

            fstream file;
            file.open("EmployeesAttendance.txt", ios::out | ios::app);
            if (!file.is_open())
            {
                cout << "Unable to open file.";
                return;
            }
            file << _id << " " << count << endl;
            file.close();

            cout << " Your Attendance has been marked! " << endl;
        }
        else
        {
            cout << " Such an ID donot exist in your system " << endl;
        }
    }

    int Get_Employee_Attendance_Count(const string &_emp_id)
    {
        ifstream file;
        file.open("EmployeesAttendance.txt");
        // if (!file.is_open())
        // {
        //     cout << "Unable to open file.";
        //     return 0;
        // }

        string id;
        int count;

        while (file >> id >> count)
        {
            if (id == _emp_id)
            {
                file.close();
                return count; // Return the count for the matching ID
            }
        }

        file.close();
        return 0; // Return 0 if the ID was not found
    }

    // This function checks whether the username entered is string or not
    bool Strong_Username(string _username) override
    {
        Strong_Username(_username);
    }

    void Employee_Sign_Up()
    {
        string _enter_id;
        register bool match;

        cout << " Enter your employee ID to sign-up ";
        cin >> _enter_id;

        match = Match_Employee_ID(_enter_id);

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
            file.open("EmpoloyeeUserPass.txt", ios::out | ios::app);
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
            // Employee_Login(_enter_id); // login function called.
        }
        else
        {
            cout << " Such an ID donot exist in your system " << endl;
        }
    }

    bool Employee_Login(string _user_id)
    {
        string id, check_id, name;
        bool found = false;
        Parking obj;

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
        file.open("EmpoloyeeUserPass.txt");

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
                cout << " \t \t \t \t Login Successful " << endl;
                cout << "\n";

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
            char choice;

        a:
            system("CLS");

            cout << "\t\t\t-------------Choose from below--------------" << endl;
            cout << "\t\t\t __________________________________________ " << endl;
            cout << "\t\t\t|                                          |" << endl;
            cout << "\t\t\t|       1--> To Mark Attendance            |" << endl;
            cout << "\t\t\t|       2--> To see your information       |" << endl;
            cout << "\t\t\t|       3--> To apply for leaves           |" << endl;
            cout << "\t\t\t|       4--> To update your information    |" << endl;
            cout << "\t\t\t|       5--> To See your attendance        |" << endl;
            cout << "\t\t\t|       6--> To Check-in and Ckeck-out     |" << endl;
            cout << "\t\t\t|       7--> To Go Back                    |" << endl;
            cout << "\t\t\t|       8--> To Exit the program           |" << endl;
            cout << "\t\t\t|__________________________________________|" << endl;
            choice = getch();

            switch (choice)
            {
            case '1':
                Mark_Employee_Attendance();
                goto a;
                break;

            case '2':
                Show_This_Employee_Information(Get_ID());
                goto a;
                break;

            case '3':
                Employee_Applying_for_Leave();
                goto a;
                break;

            case '4':
                Update_Employee_Data();
                goto a;

            case '5':
                cout << " Your Attendance is : " << Get_Employee_Attendance_Count(Get_ID()) << endl;
                goto a;
                break;

            case '6':
            a:
                cout << "Enter the id of the employee: " << endl;
                cin >> id;
                cin.ignore();
                found = Match_Employee_ID(id);
                if (found)
                {
                    cout << "Enter the name of the employee: " << endl;
                    getline(cin, name);
                    char option;

                start:
                    cout << "Do you want to check in or check out? " << endl;
                    cout << " __________________________________________ " << endl;
                    cout << "|                                          |" << endl;
                    cout << "|           1--> Check In                  |" << endl;
                    cout << "|           2--> Check Out                 |" << endl;
                    cout << "|__________________________________________|" << endl;
                    option = getch();

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
                            cout << " Employee is already parked." << endl;
                            goto a;
                        }
                        else
                        {
                            obj.Allot_Spots(name, id);
                            obj.Check_in();
                            goto a;
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
                            cout << "Employee not found." << endl;
                            goto a;
                        }
                        break;
                    }
                    default:
                    {
                        cout << "Select a valid option. " << endl;
                        goto start;
                        break;
                    }
                    }
                }
                else
                {
                    cout << " An employee with such ID donot exist in our system " << endl;
                    goto a;
                }

                break;

            case '7':
                return true;
                break;

            case '8':
                return false;
                break;

            default:
                cout << " Invlaid Choice ";
                for (int i = 0; i < 4; i++)
                {
                    cout << "!";
                    Sleep(1000);
                }
                goto a;
                break;
            }
        }
    }

    // This member function is used to chech whether an employee with this id is present in the system or not
    bool Match_Employee_ID(const string &_emp_id)
    {

        register int found = false; // A flag variable

        fstream file;
        file.open("EmployeesData.txt", ios::in);
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            // return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age >> _phone_number;
        file.ignore();
        getline(file, _employee_designation);
        file >> _salary >> _employee_leaves;
        file.ignore();
        getline(file, _address);

        while (!file.eof())
        {
            if (_emp_id == _id)
            {
                found = true; // To check whether the id of the employee is found or not
                return true;
                break;
            }

            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age >> _phone_number;
            file.ignore();
            getline(file, _employee_designation);
            file >> _salary >> _employee_leaves;
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

    // This function is used ot show the data o fthe employee which can be accessed by the employee itself
    void Show_This_Employee_Information(const string &_emp_id)
    {
        // register int found = false; // A flag variable
        fstream file;
        file.open("EmployeesData.txt", ios::in);
        if (!file.is_open())
        {
            cout << "\tError opening file.";
            return;
        }

        file >> _id;
        file.ignore();
        getline(file, _name);
        file >> _age >> _phone_number;
        file.ignore();
        getline(file, _employee_designation);
        file >> _salary >> _employee_leaves;
        file.ignore();
        getline(file, _address);

        while (!file.eof())
        {
            if (_emp_id == _id)
            {

                cout << "\n";
                cout << "\n\t\t *************************************************************************" << endl;
                cout << "\t\t ||\t                    Data of Employee:         " << _emp_id
                     << "\t\t ||" << endl;
                cout << "\t\t ||_____________________________________________________________________||" << endl;
                cout << "\t\t ||                                                                     ||" << endl;
                cout << "\t\t || Employee ID                        : " << setw(25) << left << _id << "\t||" << endl;
                cout << "\t\t || Employee Name                      : " << setw(25) << left << _name << "\t||" << endl;
                cout << "\t\t || Employee Age                       : " << setw(25) << left << _age << "\t||" << endl;
                cout << "\t\t || Employee Phone Number              : " << setw(25) << left << _phone_number << "\t||" << endl;
                cout << "\t\t || Employee Designation               : " << setw(25) << left << _employee_designation << "\t||" << endl;
                cout << "\t\t || Employee Salary                    : " << setw(25) << left << _salary << "\t||" << endl;
                cout << "\t\t || Employee Leaves                    : " << setw(25) << left << _employee_leaves << "\t||" << endl;
                cout << "\t\t || Employee Address                   : " << setw(25) << left << _address << "\t||" << endl;
                cout << "\t\t ||                                                                     ||";
                cout << "\n\t\t *************************************************************************" << endl;
                cout << "\n";
                // found = true; // To check whether the id of the employee is found or not
                break;
            }
            file >> _id;
            file.ignore();
            getline(file, _name);
            file >> _age >> _phone_number;
            file.ignore();
            getline(file, _employee_designation);
            file >> _salary >> _employee_leaves;
            file.ignore();
            getline(file, _address);
        }

        file.close();

        cout << " Your attendance count is " << Get_Employee_Attendance_Count(_emp_id);

        /*if (found == false)
        {
            cout << "\tData of this id id not present";
        }*/
    }
};
#endif