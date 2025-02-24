#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

struct sEmployee{

    int ID;
    string Name ;
    double salary;
    string Job_Title;
};

sEmployee FillEmployeeData(){

    sEmployee EData;

    cout<<"\nEnter Employee ID: ";
    cin>> EData.ID;
    
    cout<<"\nEnter Employee Name: ";
    cin.ignore();
    getline(cin,EData.Name);
    
    cout<<"\nEnter Salary: ";
    cin>> EData.salary;
    
    cout<<"\nEnter Job Title: ";
    cin.ignore();
    getline(cin,EData.Job_Title);

    return EData;
}

void PrintEmployeeData(sEmployee Data){

    cout<<"\n\n**************Employees Data**************\n";
    cout<<"ID: "<<Data.ID<<endl;
    cout<<"Name: "<<Data.Name<<endl;
    cout<<"Salary: "<<Data.salary<<endl;
    cout<<"Job Title: "<<Data.Job_Title<<endl;
}

void FillEmployees(sEmployee Arr[100], short Num){

    cout<<"\nEntering Employees Data:\n";
    
    for(int i = 0; i < Num; i ++){

        cout<<"\nEntering data for Employee "<< i + 1<<endl;
        Arr[i] = FillEmployeeData();
    }
}

void PrintAllEmployees(sEmployee Arr[100], short Num){

    for(int i = 0; i < Num; i ++){
        
        PrintEmployeeData(Arr[i]);
        
    }
}

void RunProgram(){

    short Num = 0;
    sEmployee Arr[100];
    cout<<"\nHow Many Employees You Want To Enter: ";
    cin>> Num;

    FillEmployees(Arr, Num);
    PrintAllEmployees(Arr, Num);   
}


int main(){
    
    RunProgram();
    return 0;
}