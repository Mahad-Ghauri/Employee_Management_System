#ifndef PARKING_H
#define PARKING_H

#include "Person.h"
using namespace std;

class Parking
{
private:
    static const int max_space = 10;
    string name[max_space];
    string employee_id[max_space];
    time_t parking_Time[max_space];
    int spots;

public:
    Parking() { spots = 0; }

    bool Allot_Spots(string n, string i)
    {
        if (spots < max_space)
        {
            name[spots] = n;
            employee_id[spots] = i;
            parking_Time[spots] = time(0);
            spots++;
            return true;
        }
        return false;
    }

    bool Dismiss_Spots(string i)
    {
        for (int index = 0; index < spots; index++)
        {
            if (employee_id[index] == i)
            {
                for (int j = index; j < spots - 1; j++)
                {
                    name[j] = name[j + 1];
                    employee_id[j] = employee_id[j + 1];
                    parking_Time[j] = parking_Time[j + 1];
                }
                spots--;
                return true;
            }
        }
        return false;
    }

    void Check_in()
    {
        ofstream checking_in("checkIn_info.txt", ios::app);
        if (!checking_in.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        cout << "\nNumber of parked employees: " << spots << endl;
        for (int i = 0; i < spots; i++)
        {
            cout << " _____________________________________________________" << endl;
            cout << "|                                                     |" << endl;
            cout << "| Employee with id:  " << setw(20) << left << employee_id[i] << "             |" << endl;
            cout << "| Name            :  " << setw(20) << left << name[i] << "             |" << endl;
            cout << "| Checked in at   :  " << setw(24) << left << ctime(&parking_Time[i]) << "|" << endl;
            cout << "|_____________________________________________________|" << endl;
            checking_in << employee_id[i] << endl
                        << name[i] << endl;
        }
        checking_in.close();
    }

    void Check_out()
    {
        cout << "\nNumber of parked employees: " << spots << endl;
        for (int i = 0; i < spots; i++)
        {
            cout << " _____________________________________________________" << endl;
            cout << "|                                                     |" << endl;
            cout << "| Employee with id:  " << setw(20) << left << employee_id[i] << "                |" << endl;
            cout << "| Name            :  " << setw(20) << left << name[i] << "                |" << endl;
            cout << "| Checked out at  :  " << setw(24) << left << ctime(&parking_Time[i]) << "      |" << endl;
            cout << "|_____________________________________________________|" << endl;
        }

        ofstream update_file("checkIn_info.txt");
        if (!update_file.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }
        for (int i = 0; i < spots; i++)
        {
            update_file << employee_id[i] << endl
                        << name[i] << endl;
        }
        update_file.close();
    }
};

int main()
{
    string id, check_id , name;
    bool found = false;
    Parking obj;

a:
    cout << "Enter the id of the employee: " << endl;
    cin >> id;
    cin.ignore();
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

#endif