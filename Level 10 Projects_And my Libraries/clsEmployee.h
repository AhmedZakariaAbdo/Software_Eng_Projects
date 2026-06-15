#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"

using namespace std;

class clsEmployee : public clsPerson
{
private:
    string _Title;
    string _Department;
    float _Salary;

public:
    clsEmployee(int id, const string& firstname, const string& lastname,
                const string& fullname, const string& email, const string& phone,
                const string& title, const string& department, float salary)
        : clsPerson(id, firstname, lastname, fullname, email, phone),
          _Title(title),
          _Department(department),
          _Salary(salary)
    {
    }

    // Setters
    void SetTitle(const string& title)
    {
        _Title = title;
    }

    void SetDepartment(const string& department)
    {
        _Department = department;
    }

    void SetSalary(float salary)
    {
        _Salary = salary;
    }

    // Getters
    string GetTitle() const
    {
        return _Title;
    }

    string GetDepartment() const
    {
        return _Department;
    }

    float GetSalary() const
    {
        return _Salary;
    }

    void Print()
    {
        cout << "Info:\n";
        cout << "___________________________________________" << endl;
        cout << "ID         : " << GetID() << endl;
        cout << "FirstName  : " << GetFirstName() << endl;
        cout << "LastName   : " << GetLastName() << endl;
        cout << "FullName   : " << GetFullName() << endl;
        cout << "Email      : " << GetEmail() << endl;
        cout << "Phone      : " << GetPhone() << endl;
        cout << "Title      : " << _Title << endl;
        cout << "Department : " << _Department << endl;
        cout << "Salary     : " << _Salary << endl;
        cout << "___________________________________________" << endl;
    }
};