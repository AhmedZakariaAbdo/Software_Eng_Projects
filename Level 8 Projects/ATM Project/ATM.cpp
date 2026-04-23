#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include<limits>

using namespace std;


struct sClients
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};


enum enMainMenueOptions{
    eQucikWithdraw = 1 , eNormalWithDraw = 2 , eDeposit = 3 , eCheckBalance = 4, eExit = 5
};

const string ClientsFileName = "ClientsData.txt";

sClients CurrentClient;

void ShowMainMenue();
void Login();
void ShowQuickWithdrawScreen();
void ShowNormalWithDrawScreen();
void ShowDepositScreen();


vector <string> SplitString(string S1, string Delim){

    vector <string> vString;
    short pos = 0;
    string sword;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sword = S1.substr(0 , pos);

        if (sword != "")
        {
            vString.push_back(sword);
        }

        S1.erase(0, pos + Delim.length());   
    }

    if(S1 != ""){

        vString.push_back(S1);
    }

    return vString;
}

sClients ConvertLinetoRecord(string Line, string Seperator ="#//#"){

    sClients Client;
    
    vector<string> vClientData = SplitString(Line,Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData [1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

string ConvertRecordToLine(sClients Client, string Seperator ="#//#"){

    string DataLine = "";

    DataLine += Client.AccountNumber + Seperator;
    DataLine += Client.PinCode + Seperator;
    DataLine += Client.Name + Seperator;
    DataLine += Client.Phone + Seperator;
    DataLine += to_string(Client.AccountBalance);

    return DataLine;
}

vector <sClients> LoadCleintsDataFromFile(string FileName){

    vector<sClients> vClients;

    fstream MyFile;
    
    MyFile.open(FileName, ios::in); 
    
    if(MyFile.is_open()){

        string Line;
        sClients Client;

        while(getline(MyFile,Line)){

            Client = ConvertLinetoRecord(Line);
            
            vClients.push_back(Client);
        }
        MyFile.close();
    }

    return vClients;
}


bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, sClients& Client){

    vector<sClients> vClients = LoadCleintsDataFromFile(ClientsFileName);
    
    for(sClients C: vClients){

        if(C.AccountNumber == AccountNumber && C.PinCode == PinCode){

            Client = C;
            return true;

        }
    }

    return false;
}

vector<sClients> SaveCleintsDataToFile(string FileName, vector<sClients> vClients){

    fstream MyFile;
    MyFile.open(FileName , ios::out);

    string DataLine;

    if(MyFile.is_open()){

        for(sClients C: vClients){

            if(C.MarkForDelete == false){

                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }

    return vClients;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClients>& vClients){

  char Answer = 'n';
  
  cout << "\n\nAre you sure you want perfrom this transaction? Y/N:";
  cin>> Answer;
  
  if(Answer == 'Y' || Answer == 'y'){

    for(sClients& C: vClients){

        if(C.AccountNumber == AccountNumber){

            C.AccountBalance +=  Amount;
            SaveCleintsDataToFile(ClientsFileName,vClients);
            cout << "\n\nDone Successfully. New balance is: "<< C.AccountBalance<<endl;

            return true;
        }
    }
  }
   return false;
}

short ReadQuickWithdrawOption(){

    short Choice = 0;

    while (Choice < 1 || Choice > 9)
    {
        cout<<"\nChoose What To Do From [1] To [9] : ";
        cin>> Choice;
    }
    return Choice;
}

short getQuickWithDrawAmount(short QuickWithDrawOption){

    switch (QuickWithDrawOption)
    {
    case 1:
        return 20;
    case 2:
        return 50;
    case 3:
        return 100;
    case 4:
        return 200;
    case 5:
        return 400;
    case 6:
        return 600;
    case 7:
        return 800;
    case 8:
        return 1000;

    
    default:
        
    return 0;

    }
}

void PerfromQuickWithdrawOption(short QuickWithDrawOption){

    if(QuickWithDrawOption == 9 ){
        return ;
    }

    short WithDrawBalance = getQuickWithDrawAmount(QuickWithDrawOption);

    if(WithDrawBalance > CurrentClient.AccountBalance){

        cout<<"\nThe Amount Exceeds Your Balance, Make Another Choice.\n";
        cout<<"Press Any Key To Continue...";
        ShowQuickWithdrawScreen();
        return ;

    }

    vector<sClients> vClients = LoadCleintsDataFromFile(ClientsFileName);

    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber,WithDrawBalance * -1, vClients);
    CurrentClient.AccountBalance -=WithDrawBalance;

}

double ReadDepositAmount(){

    double Amount ;

    cout<<"\nEnter A Positive Deposit Amount: ";
    cin>> Amount;

    while (Amount < 0)
    {
        cout<<"\nEnter Another Positive Deposit Amount: ";
        cin>> Amount;
    }
    return Amount;
    
}

void PerfromDepositOption() {

    double DepositAmount = ReadDepositAmount();

    vector<sClients> vClients = LoadCleintsDataFromFile(ClientsFileName);

    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber,DepositAmount, vClients);
    CurrentClient.AccountBalance += DepositAmount;
}

void ShowDepositScreen() {
system("clear");
cout << "===========================================\n";
cout << "\t\tDeposit Screen\n";
cout << "===========================================\n";
PerfromDepositOption();
}

void ShowCheckBalanceScreen()
{
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tCheck Balance Screen\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance << "\n";

}

int ReadWithDrawAmont(){

    int Amount;

    cout << "\nEnter an amount multiple of 5's ?: ";
    cin>> Amount;

    while (Amount % 5 != 0)
    {
        cout << "\nEnter an amount multiple of 5's ?: ";
        cin>> Amount;
    }
    return Amount;
}

void PerfromNormalWithdrawOption(){

    int WithDrawBalance =  ReadWithDrawAmont();

    if(WithDrawBalance > CurrentClient.AccountBalance){

        cout << "\nThe amount exceeds your balance, make another choice.\n";

        cout<<"Press Any Key To Continue...";
        ShowNormalWithDrawScreen();
        return ;
    }

    vector<sClients> vClients = LoadCleintsDataFromFile(ClientsFileName);

    DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber,WithDrawBalance * -1, vClients);
    CurrentClient.AccountBalance -= WithDrawBalance;
}

void ShowNormalWithDrawScreen()
{
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tNormal Withdraw Screen\n";
    cout << "===========================================\n";
    PerfromNormalWithdrawOption();
}

void ShowQuickWithdrawScreen()
{
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tQucik Withdraw\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance;
    PerfromQuickWithdrawOption(ReadQuickWithdrawOption());
}


void GoBackToMainMenue(){

    cout << "\n\nPress Any Key To Go Back To Main Menue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    ShowMainMenue();
}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 5]: ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption){


    switch (MainMenueOption)
    {
    case enMainMenueOptions::eQucikWithdraw:
    {
        system("clear");
        ShowQuickWithdrawScreen();
        GoBackToMainMenue();
        break;
    }

    case enMainMenueOptions::eNormalWithDraw:
    system("clear");
    ShowNormalWithDrawScreen();
    GoBackToMainMenue();
    break;

    case enMainMenueOptions::eDeposit:
    system("clear");
    ShowDepositScreen();
    GoBackToMainMenue();
    break;

    case enMainMenueOptions::eCheckBalance:
    system("clear");
    ShowCheckBalanceScreen();
    GoBackToMainMenue();
    break;

    case enMainMenueOptions::eExit:
        system("clear");
        Login();
        break;
    
    }

}

void ShowMainMenue()
{
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

bool LoadClientInfo(string AccountNumber, string PinCode){


    if(FindClientByAccountNumberAndPinCode(AccountNumber,PinCode,CurrentClient)){

        return true;
    }else{
        return false;

    }
}

void Login(){

    bool LoginFaild = false;

    string AccountNumber, PinCode;

    do
    {
        system("clear");
        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if(LoginFaild ){

            cout<<"Invalid AccountNumber/PinCode!\n";
        }
        cout<<"Enter Account Number: ";
        cin>> AccountNumber;

        cout<<"Enter PinCode: ";
        cin>> PinCode;

        LoginFaild = !LoadClientInfo(AccountNumber, PinCode);

    } while (LoginFaild);
    
    ShowMainMenue();
}

int main(){

    Login();

    return 0;
}