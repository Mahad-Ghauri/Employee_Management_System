#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Parking.h"
#include "Person.h"

void Set_Colour(int value)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

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
        /*if (!file.is_open())    This condition will be automatically executed  cauz  opening the file for first time befor it is even created
        {
            cout << " Error opening the file " << endl;
           return;
        }*/

        cout << " \n ";
        cout << "\t    Enter the following information of the employee " << endl;
        cout << endl;

        bool valid_id = false;

        while (!valid_id)
        {
            cout << "\t Enter the employee ID: ";
            cin >> _id;

            // Checking whether an employee with the entered ID exists or not
            // If the file does not exist, we can skip this check
            if (!file)
            {
                file.clear();
                valid_id = true;
            }
            else
            {
                bool id_exists = false;
                while (file >> id)
                {
                    file.ignore();

                    if (id == _id)
                    {
                        cout << "\t An employee with this id already exists " << endl;
                        Sleep(1000);
                        file.close();

                        file.open("EmployeesData.txt");
                        id_exists = true;
                        break;
                    }
                }
                if (!id_exists)
                {
                    valid_id = true;
                }
                file.clear();
                /*The file.clear() function is used to clear the error state flags of the ifstream object.
                This is necessary because certain operations, like reading past the end of a file or encountering invalid input,
                can set error flags (such as eofbit, failbit, or badbit) on the stream.
                The most important the file.clear() donot clear the data of the file*/

                file.seekg(0, ios::beg); // Used to reset the reading position of the file  'beg' is for beigning
            }
        }
        file.close();

        cin.ignore();

        bool valid_name = false;
        while (!valid_name)
        {
            cout << "\t Employee name: ";
            getline(cin, _name);
            valid_name = true;
            for (char i = 0; i < _name.length(); i++)
            {
                if (isdigit(_name[i]))
                {
                    cout << endl;
                    cout << "\t Invalid input! Enter alphabets only. " << endl;
                    valid_name = false;
                    break;
                }
            }
        }

        bool valid_age = false;
        while (!valid_age)
        {
            cout << "\t Employee age: ";
            cin >> _age;
            if (cin.fail())
            {
                cout << endl;
                cout << "\t Invalid input! Enter integers only " << endl;
                cin.clear();
                cin.ignore(132, '\n');
            }
            else
            {
                valid_age = true;
            }

            if (_age < 0)
            {
                cout << " The age cannot be negative " << endl;
            }
        }

        cin.ignore();

        cout << "\t Employee address: ";
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

        bool valid_phone = false;
        while (!valid_phone)
        {
            cout << "\t Employee phone number: ";
            cin >> _phone_number;
            if (cin.fail() || _phone_number < 0)
            {
                cout << "\t Invalid Input !!! Enter integers only and phone number cannot be negative." << endl;
                cin.clear();
                cin.ignore(132, '\n');
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

        bool valid_choice = false;
        while (!valid_choice)
        {
            cout << "\t\t\tDesignation of the employees: " << endl;
            cout << "\t\t\tWhat is the type of the employee " << endl;

            Set_Colour(11);
            cout << "\t\t\t-------------Choose from below--------------" << endl;
            cout << "\t\t\t____________________________________________" << endl;
            cout << "\t\t\t|                                           |" << endl;
            cout << "\t\t\t|        1-> Office boy                     |" << endl;
            cout << "\t\t\t|        2-> Clerk                          |" << endl;
            cout << "\t\t\t|        3-> Accountant                     |" << endl;
            cout << "\t\t\t|        4-> IT specialist                  |" << endl;
            cout << "\t\t\t|        5-> Sales Representative           |" << endl;
            cout << "\t\t\t|        6-> Marketing person               |" << endl;
            cout << "\t\t\t|___________________________________________|" << endl;
            choice = getch();

            Set_Colour(15);
            switch (choice)
            {
            case '1':
                _employee_designation = "Office Boy";
                _salary = 30000;
                _employee_leaves = 6;
                valid_choice = true;
                break;
            case '2':
                _employee_designation = "Clerk";
                _salary = 40000;
                _employee_leaves = 4;
                valid_choice = true;
                break;
            case '3':
                _employee_designation = "Accountant";
                _salary = 50000;
                _employee_leaves = 5;
                valid_choice = true;
                break;
            case '4':
                _employee_designation = "IT specialist";
                _salary = 100000;
                _employee_leaves = 8;
                valid_choice = true;
                break;
            case '5':
                _employee_designation = "Sales Representative";
                _salary = 70000;
                _employee_leaves = 6;
                valid_choice = true;
                break;
            case '6':
                _employee_designation = "Marketing person";
                _salary = 80000;
                _employee_leaves = 5;
                valid_choice = true;
                break;
            default:
                cout << "\t Invalid choice!!! Please enter again " << endl;
                break;
            }
        }

        // Saving the data in the file
        ofstream file_write;
        file_write.open("EmployeesData.txt", ios::out | ios::app);
        if (!file_write.is_open())
        {
            cout << "\t Error opening the file " << endl;
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

        Sleep(2000);

        cout << "\t Employee added successfully! " << endl;
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

        while (!file.eof()) // The loop will itrate from the beigning  to the the end of the file
        {
            Set_Colour(14);
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

            Sleep(1000);

            Set_Colour(15);
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

        register bool found = false; // A flag variable
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

                Set_Colour(14);
                cout << "\n";
                cout << "\n\t\t *************************************************************************" << endl;
                cout << "\t\t ||\t                    Data of Employee:    " << search_id
                     << "\t\t         ||" << endl;
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
                Sleep(2000);
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

        Set_Colour(15);
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
            Sleep(2000);
        }
        else
        {
            _employee_count--;
            cout << "\tData Deleted Successfully." << endl;
            Sleep(2000);
        }
    }

    void Update_Employee_Data()
    {
        string promote_id;
        char choose;
        register bool found = false; // A flag variable

        cout << "\tEnter the employee ID to update data: ";
        cin >> promote_id;

        fstream file, file_1;
        file.open("EmployeesData.txt", ios::in);
        if (!file.is_open())
        {
            // cout << " Employee file " << endl; For debugging the filing error in the code
            cout << "\tError opening file.";
            return;
        }
        file_1.open("Promote.txt", ios::out);
        if (!file_1.is_open())
        {
            // cout << "New file " << endl;  wrote it for debugging process
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
                cout << "\t\t  What do you want to update " << endl;
                Set_Colour(11);
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

                // Sleep(1000);

                system("CLS");

                Set_Colour(15);
                switch (choose)
                {
                case '1':
                a:
                    cout << "\tEnter the new designation: ";
                    cin.ignore();
                    getline(cin, _employee_designation);
                    for (char i = 0; i < _employee_designation.length(); i++)
                    {
                        if (isdigit(_employee_designation[i]))
                        {
                            cout << endl;

                            Set_Colour(12);
                            cout << "\t\tInvalid input! Enter alphabets only. " << endl;
                            goto a;
                        }
                    }

                    break;

                    Set_Colour(15);
                case '2':
                    cout << "\n\tEnter the new address: ";
                    cin.ignore();
                    getline(cin, _address);

                    /* There is no validation for address because it can contain the house-number , street-number and
                    also the zip code of the city based upon the user input */

                    break;

                case '3':
                c:
                    cout << "\n\tEnter the new phone number: ";
                    cin >> _phone_number;
                    if (cin.fail())
                    {
                        Set_Colour(12);
                        cout << "\t\tInvalid input. Enter integers only " << endl;
                        goto c;
                    }
                    while (_phone_number < 0)
                    {
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
                d:
                    cout << "\n\tEnter the new salary: ";
                    cin >> _salary;
                    if (cin.fail())
                    {
                        Set_Colour(12);
                        cout << "\t\tInvlid Input!!!  Enter integers only " << endl;
                        goto d;
                    }

                    // Non negative and non zero salary vaidation
                    if (_salary <= 0)
                    {
                        cout << "\t\tThe salary must be non-negative and greater than zero " << endl;
                        goto d;
                    }

                    break;

                    Set_Colour(15);
                case '5':
                e:
                    cout << "\n\tEnter the new total leaves: ";
                    cin >> _employee_leaves;
                    if (cin.fail())
                    {
                        cout << "\t\tInvalid Input!!! . Enter integer only " << endl;
                        goto e;
                    }

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

            Set_Colour(15);
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
            Sleep(1000);
        }
        else
        {
            cout << "\tEmployee ID not found." << endl;
            Sleep(1000);
        }
    }

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
                Set_Colour(11);
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
                    cout << "\n\t Invalid Input";
                    Set_Colour(15);
                    for (int i = 0; i < 3; i++)
                    {
                        cout << "!";
                        Sleep(1000);
                    }

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

        Set_Colour(15);

        remove("EmployeesData.txt");
        rename("promote.txt", "EmployeesData.txt");

        // Show prompt that the data of the employee is updated successfully
        if (found)
        {
            cout << "\tThanks for applying for the leave." << endl;
            Sleep(2000);
        }
        else
        {
            cout << "\tEmployee ID not found." << endl;
            Sleep(2000);
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
            Sleep(2000);
        }
        else
        {
            cout << " Such an ID donot exist in your system " << endl;
            Sleep(2000);
        }
    }

    int Get_Employee_Attendance_Count(const string &_emp_id)
    {
        ifstream file;
        file.open("EmployeesAttendance.txt");
        // The validation will be automatically executed because the file has not been created and we are opening it for input u
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

    void Employee_Sign_Up()
    {
        string _enter_id;
        register bool match;

        cout << " Enter your employee ID to sign-up ";
        cin >> _enter_id;

        cin.ignore();

        match = Match_Employee_ID(_enter_id);

        if (match)
        {
        point: // point declared here will come here if username requirements not met
            system("CLS");
            string username, password;

            Set_ID(_enter_id); // Id of the employee is being set

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
            file.open("EmpoloyeeUserPass.txt", ios::out | ios::app);
            if (!file.is_open())
            {
                cout << "\tError opening file.";
            }

            file << username << "\n";
            file << password << "\n";
            file.close();

            Set_Colour(3);
            cout << "\n\n\t\tYour ID is being created.Please Wait ";
            Set_Colour(15);
            for (int i = 0; i < 4; i++)
            {
                cout << ".";
                Sleep(1000);
            }
            cout << "\n\n\t\tYour ID HAS BEEN CREATED ";
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
                Set_Colour(14);
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

        Set_Colour(15);
        if (match == true)
        {
            char choice;

        a:
            system("CLS");

            Set_Colour(11);
            cout << "\t\t\t-------------Choose from below--------------" << endl;
            cout << "\t\t\t __________________________________________ " << endl;
            cout << "\t\t\t|                                          |" << endl;
            cout << "\t\t\t|       1--> To Mark Attendance            |" << endl;
            cout << "\t\t\t|       2--> To see your information       |" << endl;
            cout << "\t\t\t|       3--> To apply for leaves           |" << endl;
            cout << "\t\t\t|       4--> To update your information    |" << endl;
            cout << "\t\t\t|       5--> To See your attendance        |" << endl;
            cout << "\t\t\t|       6--> To Check-in and Ckeck-out     |" << endl;
            cout << "\t\t\t|       7--> To Apply for promotion        |" << endl;
            cout << "\t\t\t|       8--> To Go Back                    |" << endl;
            cout << "\t\t\t|       9--> To Exit the program           |" << endl;
            cout << "\t\t\t|__________________________________________|" << endl;
            choice = getch();

            Set_Colour(15);
            switch (choice)
            {
            case '1':
                Mark_Employee_Attendance();
                goto a;
                break;

            case '2':
                Show_This_Employee_Information(Get_ID());
                cin.ignore(132, '\n');
                cin.get();
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
            point:
                cout << "Enter the id of the employee: " << endl;
                cin >> id;
                cin.ignore();
                found = Match_Employee_ID(id);
                if (found)
                {
                    cout << "Enter the name of the employee: " << endl;
                    getline(cin, name);
                    char option;

                point_b:
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
                            cout << " Employee is already parked." << endl;
                            Sleep(2000);
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
                            cout << "Employee not found." << endl;
                            Sleep(2000);
                            goto a;
                        }
                        break;
                    }
                    default:
                    {
                        cout << "Select a valid option. " << endl;
                        Sleep(2000);
                        goto point_b;
                        break;
                    }
                    }
                }
                else
                {
                    cout << " An employee with such ID donot exist in our system " << endl;
                    goto a;
                }

                goto a;
                break;

                Set_Colour(15);
            case '7':
                Employee_Applying_For_Promotion(Get_ID());
                goto a;
                break;

            case '8':
                return true;
                break;

            case '9':
                return false;
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
                goto a;
                break;
            }
        }
        Set_Colour(15);
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
            Sleep(2000);
            return false;
        }
    }

    // This function is used ot show the data of the employee which can be accessed by the employee itself
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

                Set_Colour(14);
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
                Sleep(2000);
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

        Set_Colour(15);
        cout << " Your attendance count is " << Get_Employee_Attendance_Count(_emp_id);

        /*if (found == false)
        {
            cout << "\tData of this id id not present";
        }*/
    }

    // last day added member functions ( might have some working issues )

    // Making the member function for promotion of the manager at new designation
    void Employee_Applying_For_Promotion(const string &_emp_id)
    {
        // string promote_id;

        char main_choice, sub_choice;
        register bool found = false; // A flag variable

        /*cout << "\tEnter the Manager ID for promotion: ";
        cin >> promote_id;*/

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
                e:

                    cout << "\t\t\tDesignation of the employees: " << endl;
                    cout << "\t\t\tWhat is the type of the employee " << endl;
                    Set_Colour(11);
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
                    sub_choice = getch();

                    Set_Colour(15);
                    switch (sub_choice)
                    {
                    case '1':
                        if (Promotion_Approval())
                        {
                            Application_Accepted();
                            _employee_designation = "Office Boy";
                            _salary = 30000;
                            _employee_leaves = 6;
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
                            _employee_designation = "Clerk";
                            _salary = 40000;
                            _employee_leaves = 4;
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
                            _employee_designation = "Accountant";
                            _salary = 50000;
                            _employee_leaves = 5;
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
                            _employee_designation = "IT specailist";
                            _salary = 100000;
                            _employee_leaves = 8;
                        }
                        else
                        {
                            Application_Rejected();
                        }

                        break;
                    case '5':
                        if (Promotion_Approval())
                        {
                            Application_Accepted();
                            _employee_designation = "Sales Representative";
                            _salary = 70000;
                            _employee_leaves = 6;
                        }
                        else
                        {
                            Application_Rejected();
                        }

                        break;
                    case '6':
                        if (Promotion_Approval())
                        {
                            Application_Accepted();
                            _employee_designation = " Marketing person ";
                            _salary = 80000;
                            _employee_leaves = 5;
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
                        for (int i = 0; i < 3; i++)
                        {
                            cout << "!";
                            Sleep(1000);
                        }

                        goto e;
                        break;
                    }

                    break;

                default:
                    cout << "\n\t Invalid Input Please enter form the given choice " << endl;
                    system("CLS"); // To clear the screen
                    goto e;
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

        Set_Colour(15);

        remove("EmployeesData.txt");
        rename("promote.txt", "EmployeesData.txt");

        // Show prompt that the data of the Manager is updated successfully
        if (found == true)
        {
            cout << "\t The employee is promoted to a new designation " << endl;
            Sleep(2000);
        }
        else
        {
            cout << "\tEmployee ID not found." << endl;
            Sleep(2000);
        }
    }

    bool Promotion_Approval()
    {
        register bool match;
        string answer;

    a:
        cout << " Do you want to accept the promotion  (Yes or No)  ";
        cin >> answer;

        for (char i = 0; i < answer.length(); i++)
        {
            if (isdigit(answer[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto a;
            }
        }

        if (answer == "Yes" || answer == "yes")
        {
            match = true;
            return match;
        }
        else
        {
            match = false;
            return match;
        }
    }
};
#endif