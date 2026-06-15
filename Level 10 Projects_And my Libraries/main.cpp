#include <iostream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "clsEmployee.h"
#include "clsString.h"
#include "clsDate.h"

using namespace std;



int main() {

    clsDate Date1;
    
    Date1.Print();

    clsDate Date2("31/1/2022");
    Date2.Print();

    clsDate Date3(20,12,2022);
    Date3.Print();
    
    clsDate Date4(250,2022);
    Date4.Print();

    cout<<Date4.IsDateBeforeDate2(Date3)<<endl;


    return 0;
}