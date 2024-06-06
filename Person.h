#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

class Person
{
protected:
    int _total_employees;
    string _name;
    string _address;
    string _id;
    int _salary;
    int _age;
    long long int _phone_number;

    Person()
    {
        // Default Constructor
    }

    void set_ID(string id)
    {
        _id = id;
    }

    string get_ID() const
    {
        return _id;
    }

    // Employee's

    void Set_Total_Employees()
    {
        int number;
        bool valid_input = false;

        while (!valid_input)
        {
            cout << "\n\n\t\tEnter the total employees you have in your company ";
            cin >> number;
            if (cin.fail())
            {
                cout << " Invalid Input. Please enter again " << endl;
                cin.clear(); // Ressets the error state
                cin.ignore(132 , '\n');
            }
            else
            {
                valid_input = true;
            }
        }

        _total_employees = number;
    }

    int Get_Total_Number_Of_Employee()
    {
        return _total_employees;
    }

    // Member functions realted to the Leave System

    int get_Leave_Days(const string &_type_of_leave)
    {
        int days;
        register bool valid_input = false;

        do
        {
            cout << "\n\nEnter the number of days of your" << _type_of_leave << " leave: ";
            cin >> days;

            if (cin.fail())
            {
                cout << " Invalid Input! Enter digits only " << endl;
                cin.clear();           // Clear the error flag
                cin.ignore(132, '\n'); // Discard the input buffer
            }
            else
            {
                valid_input = true; // Input is valid, exit the loop
            }
        } while (!valid_input);

        return days;
    }

    void Application_Rejected()
    {
        cout << "\t\t\t    ______________________________________ " << endl;
        cout << "\t\t\t   |                                      |" << endl;
        cout << "\t\t\t   |    YOUR APPLICATOIN WAS REJECTED     |" << endl;
        cout << "\t\t\t   |______________________________________|" << endl;
    }

    void Application_Accepted()
    {
        cout << "\t\t\t    ______________________________________ " << endl;
        cout << "\t\t\t   |                                      |" << endl;
        cout << "\t\t\t   |    YOUR APPLICATOIN WAS ACCEPTED     |" << endl;
        cout << "\t\t\t   |______________________________________|" << endl;
    }

    bool Application_Approval()
    {
        register bool match;
        string answer;

    a:
        cout << " Do you want to accept the leave application  (Yes or No)  ";
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

    // Sickness Leavve

    string get_Illness_Reason()
    {
        string _reason;

    a:
        cout << " Breifly state the reason of your illness: ";
        getline(cin, _reason);
        for (char i = 0; i < _reason.length(); i++)
        {
            if (isdigit(_reason[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto a;
            }
        }

        return _reason;
    }

    string get_Illness_Symptoms()
    {
        string _symptoms;

    a:
        cin.ignore();
        cout << " Enter the symptoms of the illness: ";
        getline(cin, _symptoms);
        for (char i = 0; i < _symptoms.length(); i++)
        {
            if (isdigit(_symptoms[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto a;
            }
        }

        return _symptoms;
    }

    void Sick_Leave_Application(const string &_illness_reason, const string &_symptoms, int _leave_days, const string &name, const string &_writing_to)
    {
        cout << "\n\n";

        cout << "\t\t\tDear" << _writing_to << ",\n\n";

        cout << "\t\tI hope this message finds you well. I am writing to formally request a period of sick leave due to\n";
        cout << "\t\t" << _illness_reason << "\n";
        cout << "\t\tI have been experiencing " << _symptoms << " which have\n";
        cout << "\t\tmade it difficult for me to perform my duties effectively.\n\n";

        cout << "\t\tI visited my healthcare provider and was advised to take " << _leave_days << "days to recover and\n";
        cout << "\t\tprevent the spread of any potential illness to my colleagues. Attached to this email is the medical\n";
        cout << "\t\tcertificate provided by my healthcare provider as evidence of my condition.\n\n";

        cout << "\t\tDuring my absence, I will ensure that all pending tasks are delegated appropriately and that\n";
        cout << "\t\tnecessary documentation is provided to ensure a smooth transition in my absence. If there are\n";
        cout << "\t\tany specific tasks or responsibilities you would like me to address before my leave begins, please\n";
        cout << "\t\tlet me know, and I will do my best to accommodate your requests.\n\n";

        cout << "\t\tI understand the importance of maintaining productivity within the team and will make every\n";
        cout << "\t\teffort to return to work as soon as I am medically able to do so. I will keep you updated on my\n";
        cout << "\t\tprogress and provide any additional documentation required upon my return.\n\n";

        cout << "\t\tThank you for your understanding and support during this time. Please do not hesitate to contact\n";
        cout << "\t\tme if you require any further information or assistance.\n\n";

        cout << "\t\tSincerely," << endl;
        cout << "\t\t" << name << endl;
    }

    // Personal Leave type

    string get_Personal_Reason()
    {
        string _reason;

    a:
        cout << " Breifly state the reason of your personal leave: ";
        getline(cin, _reason);
        for (char i = 0; i < _reason.length(); i++)
        {
            if (isdigit(_reason[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto a;
            }
        }

        return _reason;
    }

    void Personal_Leave_Application(const string &_personal_reason, int _leave_days, const string &name, const string &_writing_to)
    {
        cout << "\t\tDear" << _writing_to << ",\n\n";

        cout << "\t\tI hope this message finds you well. I am writing to formally request a period of unpaid leave due to\n";
        cout << "\t\t" << _personal_reason << "\n";
        cout << "\t\tDespite not being ill, I find it necessary to take time off for" << _leave_days << "days\n\n";

        cout << "\t\tI understand that this may inconvenience the team and I sincerely apologize for any disruption this may\n";
        cout << "\t\tcause. I am committed to ensuring a smooth transition and minimizing any impact on ongoing projects.\n\n";

        cout << "\t\tAttached to this email is a formal request outlining the duration of leave requested and any pertinent\n";
        cout << "\t\tdetails. I am open to discussing this matter further and providing any additional information as needed.\n\n";

        cout << "\t\tI assure you that upon my return, I will make every effort to catch up on any missed work and fulfill any\n";
        cout << "\t\tresponsibilities that may have arisen during my absence.\n\n";

        cout << "\t\tThank you for considering my request. Please let me know if there are any further steps I need to take\n";
        cout << "\t\tor if you require any additional information.\n\n";

        cout << "\t\tSincerely," << endl;
        cout << "\t\t" << name << endl;
    }

    // Study Leave

    string get_Study_Reason()
    {
        string _reason;

    a:
        cout << " Breifly state the reason of your study leave: ";
        getline(cin, _reason);
        for (char i = 0; i < _reason.length(); i++)
        {
            if (isdigit(_reason[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto a;
            }
        }

        return _reason;
    }

    string get_Study_Field()
    {
        string field;

    a:
        cin.ignore();
        cout << " Enter the field of the study ";
        getline(cin, field);
        for (char i = 0; i < field.length(); i++)
        {
            if (isdigit(field[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto a;
            }
        }

        return field;
    }

    void Study_Leave_Application(const string &_study_reason, const string &_field_of_study, int _leave_days, const string &name, const string &_writing_to)
    {
        cout << "\t\tDear" << _writing_to << ",\n\n";

        cout << "\t\tI hope this message finds you well. I am writing to formally request a period of study leave due to\n";
        cout << "\t\t" << _study_reason << ".\n\n";

        cout << "\t\tAs part of my professional growth and commitment to continuous learning, I have identified an opportunity\n";
        cout << "\t\tto engage in " << _field_of_study << " This endeavor is crucial for enhancing\n";
        cout << "\t\tmy skills and knowledge in the relevant field  for about " << _leave_days << "days.\n\n";

        cout << "\t\tI understand the importance of my role within the team and the potential impact of my absence. I am dedicated\n";
        cout << "\t\tto ensuring minimal disruption by proactively managing my workload and collaborating with colleagues to\n";
        cout << "\t\taddress any ongoing projects or tasks.\n\n";

        cout << "\t\tAttached to this email is a formal request detailing the duration and nature of the study leave I am seeking.\n";
        cout << "\t\tI am also prepared to discuss this matter further and provide any necessary documentation to support my request.\n\n";

        cout << "\t\tRest assured, I am fully committed to returning to work with renewed knowledge and skills that will benefit\n";
        cout << "\t\tboth our team and the organization as a whole. I will diligently apply myself to catch up on any missed work\n";
        cout << "\t\tand contribute effectively upon my return.\n\n";

        cout << "\t\tThank you for considering my request for study leave. Please let me know if there are any additional steps\n";
        cout << "\t\tI need to take or if you require any further information.\n\n";

        cout << "\t\tSincerely," << endl;
        cout << "\t\t" << name << endl;
    }

    // Annual Leave

    string get_Annual_Reason()
    {
        string _reason;

    a:
        cout << " GIve the reason for your annual leave ";
        getline(cin, _reason);
        for (char i = 0; i < _reason.length(); i++)
        {
            if (isdigit(_reason[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto a;
            }
        }

        return _reason;
    }

    void Annual_Leave_Application(const string _annual_reason, int _leave_days, const string &name, const string &_writing_to)
    {
        cout << "\t\tDear" << _writing_to << ",\n\n";

        cout << "\t\tI hope this message finds you well. I am writing to formally request a period of annual leave due to\n";
        cout << "\t\t" << _annual_reason << "\n";
        cout << "\t\t. As part of our company's policy, I am entitled to 10 days of annual leave per year, and\n";
        cout << "\t\t I would like to utilize " << _leave_days << " of these days at this time.\n\n";

        cout << "\t\tI understand the importance of maintaining productivity within the team, and I have made arrangements\n";
        cout << "\t\tto ensure that my workload is managed efficiently during my absence. I have discussed my plans with my\n";
        cout << "\t\tcolleagues and have taken necessary steps to delegate tasks and provide documentation for any ongoing\n";
        cout << "\t\tprojects.\n\n";

        cout << "\t\tAttached to this email is a formal request outlining the dates for my annual leave and any additional\n";
        cout << "\t\tinformation required. I am available to discuss this matter further and provide any necessary documentation.\n\n";

        cout << "\t\tI am committed to returning to work refreshed and rejuvenated after my annual leave, ready to contribute\n";
        cout << "\t\teffectively to our team's goals and objectives. Upon my return, I will ensure a smooth transition back\n";
        cout << "\t\tinto my responsibilities and catch up on any missed work.\n\n";

        cout << "\t\tThank you for considering my request for annual leave. Please let me know if there are any further steps\n";
        cout << "\t\tI need to take or if you require any additional information.\n\n";

        cout << "\t\tSincerely," << endl;
        cout << "\t\t" << name << endl;
    }

    // Maternity Leave

    string get_Maternity_Reason()
    {
        string _reason;

    a:
        cout << " Enter the reason for your maternnity leave ";
        getline(cin, _reason);
        for (char i = 0; i < _reason.length(); i++)
        {
            if (isdigit(_reason[i]))
            {
                cout << endl;

                cout << " Invalid input! Enter alphabets only. " << endl;
                goto a;
            }
        }

        return _reason;
    }

    void Materity_Leave_Application(const string &_maternity_reason, int _leave_days, const string &name, const string &_writing_to)
    {

        cout << "\t\tDear" << _writing_to << ",\n\n";

        cout << "\t\tI hope this message finds you well. I am writing to formally request a period of maternity leave due to\n";
        cout << "\t\t" << _maternity_reason << " As per our\n";
        cout << "\t\tcompany's policy and legal regulations, I am entitled to 5 weeks of maternity  leave, and \n";
        cout << "\t\tI would like to commence this leave for" << _leave_days << "days to accommodate the\n";
        cout << "\t\tneeds of my growing family.\n\n";

        cout << "\t\tI understand the significance of my role within the team and have taken proactive steps to ensure a smooth\n";
        cout << "\t\ttransition during my absence. I have communicated with my colleagues and have arranged for the delegation\n";
        cout << "\t\tof my tasks and responsibilities. Additionally, I am available to provide any necessary documentation or\n";
        cout << "\t\tsupport to facilitate this process.\n\n";

        cout << "\t\tAttached to this email is a formal request outlining the details of my maternity leave, including the start\n";
        cout << "\t\tand end dates. I am also prepared to discuss this matter further and address any concerns or inquiries\n";
        cout << "\t\tyou may have.\n\n";

        cout << "\t\tI am committed to returning to work after my maternity leave, fully rejuvenated and ready to contribute to\n";
        cout << "\t\tthe success of our team and organization. Upon my return, I will ensure a seamless transition back into\n";
        cout << "\t\tmy role and catch up on any missed work as efficiently as possible.\n\n";

        cout << "\t\tThank you for considering my request for maternity leave. Please let me know if there are any additional\n";
        cout << "\t\tsteps I need to take or if you require any further information.\n\n";

        cout << "\t\tSincerely," << endl;
        cout << "\t\t" << name << endl;
    }

    // Login
    bool Strong_Username(const string &_user_name)
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
};

#endif