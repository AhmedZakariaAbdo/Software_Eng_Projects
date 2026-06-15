#pragma once
#include <iostream>
#include <string>
using namespace std;


class clsPerson{

    private:
    short _ID;// read only
    string _First_Name;
    string _Last_Name;
    string _Full_Name;
    string _Email;
    string _Phone;


    public:
    
    clsPerson(int Id, string FirstName,string LastName,
        string FullName,string Email,string Phone){

        _ID = Id;
        _First_Name = FirstName;
        _Last_Name = LastName;
        _Full_Name = FullName;
        _Email = Email;
        _Phone = Phone;
    }

    void SetFirstName(string FirstName){

        _First_Name = FirstName;
    }

    string GetFirstName(){

        return _First_Name;
    }
    
    void SetLastName(string LastName){

        _Last_Name = LastName;
    }

    string GetLastName(){

        return _Last_Name;
    }
    
    void SetFullName(string FullName){

        _Full_Name = FullName;
    }
    
    string GetFullName(){

        return _Full_Name;
    }

    void SetEmail(string Email){
        
        _Email = Email;
    }
    
    string GetEmail(){

        return _Email;
    }
    
    void SetPhone(string phone){

        _Phone = phone;
    }
    
    string GetPhone(){

        return _Phone;
    }

    void SendEmail(string subj,string Cont){

        cout<<"\nThe Following Message Sent Successfully to Email: "<<_Email<<endl;
        cout<<"Subject: "<<subj<<endl;
        cout<<"Body: "<< Cont<<endl;
    }
    
    void SendSMS(string cont){

        cout<<"\nThe Following SMS Sent Successfully To Phone: "<<_Phone<<endl;
        cout<<cont<<endl;
    }

    int GetID(){

        return _ID;
    }

    void Print(){

        cout<<"Info:\n";
        cout<<"____________________"<<endl;
        cout<<"ID           : "<<_ID<<endl;
        cout<<"FirstName    : "<<_First_Name<<endl;
        cout<<"LastName     : "<<_Last_Name<<endl;
        cout<<"FullName     : "<<_Full_Name<<endl;
        cout<<"Email        : "<<_Email<<endl;
        cout<<"Phone        : "<<_Phone<<endl;
        cout<<"____________________"<<endl;
    }
};
