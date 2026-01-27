#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <limits>

using namespace std;

const string FileData = "ClientsData.txt";

void ShowMainMenue();
void ShowTransactionsMenue();


struct sClients
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector<string> SplitString(string S1,string Delim){

    vector<string> Vstring;

    short pos = 0;
    string sword;
    
    while((pos = S1.find(Delim)) != std::string::npos){

        sword = S1.substr(0,pos);
        
        if(sword !=""){
            
            Vstring.push_back(sword);
        }
        
        S1.erase(0,pos + Delim.length());
    }
    
    if(S1 != ""){

        Vstring.push_back(S1);
    }

    return Vstring;
}


sClients ConvertLineToRecord (string Line, string Separator = "#//#"){

    vector<string>Vstring = SplitString(Line, Separator);

    sClients Client;

    Client.AccountNumber = Vstring[0];
    Client.PinCode = Vstring[1];
    Client.Name = Vstring[2];
    Client.Phone = Vstring[3];
    Client.AccountBalance = stod(Vstring[4]);

    return Client;
}


string ConvertRecordToLine(sClients Client, string Separator ="#//#"){

    string stClientData = "";

    stClientData += Client.AccountNumber + Separator;
    stClientData += Client.PinCode  + Separator;
    stClientData += Client.Name + Separator;
    stClientData += Client.Phone + Separator;
    stClientData += to_string(Client.AccountBalance);

    return stClientData;
}


bool ClientExistsByAccountNumber(string AccountNumber,string FileName){

    vector<sClients> vClients;
    
    fstream MyFile;
    
    MyFile.open(FileName, ios::in); //read mode

    if(MyFile.is_open()){

        string Line;
        sClients Client;

        while(getline(MyFile,Line)){

            Client = ConvertLineToRecord(Line);
            
            if(Client.AccountNumber == AccountNumber){

                MyFile.close();
                return true;
            }
            
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return false;
}


sClients ReadNewClient(){

    sClients Client;

    cout<<"\nEnter Account Number: ";
    
    getline(cin >> ws,Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber,FileData))
    {
        cout<<"\nClient With("<<Client.AccountNumber<<") already exists, Enter Another Account Number: ";
        getline(cin >> ws, Client.AccountNumber);

    }


    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
    
}


vector<sClients> LoadDataFromFile(string FileName){

    vector<sClients> vClientsData ;
    
    fstream Myfile;
    
    Myfile.open(FileName, ios::in); // Read Only;

    
    if(Myfile.is_open()){

        string Line;
        sClients Client;
        
        while(getline(Myfile,Line)){

            Client = ConvertLineToRecord(Line);
            
            vClientsData.push_back(Client);
        }

        Myfile.close();
    }
    
    return vClientsData;
}


void PrintClientRecordLine(sClients Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintClientRecordBalanceLine (sClients Client){

    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen(){

    vector<sClients> vClients = LoadDataFromFile(FileData);
    

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;


    if(vClients.size() == 0)

        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for(sClients Client: vClients){

        PrintClientRecordLine(Client);
        cout<<endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}


void ShowTotalBalances(){

    vector<sClients> vClients = LoadDataFromFile(FileData);

     cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalance = 0;

    if(vClients.size() == 0){

        cout << "\t\t\t\tNo Clients Available In the System!";

    }else{

        for(sClients C: vClients){

            PrintClientRecordBalanceLine(C);
            TotalBalance += C.AccountBalance;
            
            cout<<endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalance;
    }
}


void PrintClientCard(sClients Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}


bool FindClientByAccountNumber(string AccountNumber, vector <sClients> vClients, sClients& Client){

    
    for(sClients C: vClients){

        if(C.AccountNumber == AccountNumber){

            Client = C;
            return true;
        }
    }
    return false;
}


sClients ChangeClientRecord(string AccountNumber){

    sClients Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;


    return Client;
}


bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClients>& vClients){


    for(sClients& C: vClients){

        if(C.AccountNumber == AccountNumber){

            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}



vector <sClients> SaveCleintsDataToFile(string FileName, vector <sClients> vClients){

    fstream MyFile;

    MyFile.open(FileName, ios::out); //overwrite

    if(MyFile.is_open()){

        string Dataline;
        
        for(sClients C: vClients){

            if(C.MarkForDelete == false){
                
                Dataline = ConvertRecordToLine(C);
                
                MyFile<< Dataline <<endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}


void AddDataLineToFile(string FileName,string DataLine){

    fstream MyFile;
    
    MyFile.open(FileName, ios::out | ios::app);
    
    if(MyFile.is_open()){

        MyFile<< DataLine<<endl;

        MyFile.close();
    }
}


void AddNewClient(){

    sClients Client;
    
    Client = ReadNewClient();
    AddDataLineToFile(FileData,ConvertRecordToLine(Client));
}

void AddNewClients(){

    char Addmore = 'Y';

    do{

        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin>>Addmore;

    }while(toupper(Addmore)== 'Y');

}


bool DeleteClientByAccountNumber(string AccountNumber, vector <sClients>& vClients){

sClients Client;
char Answer = 'Y';

if(FindClientByAccountNumber(AccountNumber,vClients,Client)){

    PrintClientCard(Client);

    cout << "\n\nAre you sure you want delete this client? y/n ? ";
    cin>> Answer;

    if(Answer == 'Y' || Answer == 'y'){

        MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
        SaveCleintsDataToFile(FileData,vClients);

        vClients = LoadDataFromFile(FileData);
        
        cout << "\n\nClient Deleted Successfully.";
        return true;


    }
    
}else{
    cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";

}
    return false;
}


bool UpdateClientByAccountNumber(string AccountNumber,vector<sClients>&vClients){

    sClients Client;
    char Answer = 'Y';

    if(FindClientByAccountNumber(AccountNumber,vClients,Client)){

        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin>> Answer;

        if(Answer == 'Y'|| Answer == 'y'){

            
            for(sClients& C: vClients){

                if(C.AccountNumber == AccountNumber){
                    
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveCleintsDataToFile(FileData,vClients);

            cout << "\n\nClient Updated Successfully.";

            return true;
        }

    }else{

        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
    
    return false;
}


bool DepositBalanceToClientByAccountNumber(string AccountNumber,double Amount,vector<sClients>& vClients){


    char Answer = 'Y';

    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";

    cin>> Answer;

    if(Answer == 'Y' || Answer == 'y'){


        for(sClients& C : vClients){

            if(C.AccountNumber == AccountNumber){

                C.AccountBalance += Amount;
                SaveCleintsDataToFile(FileData,vClients);
                cout<<"\n\nDone Successfully. New balance is: "<< C.AccountBalance<<endl;
                
                return true;
            }
        }
    }
    return false;

}




string ReadClientAccountNumber(){

    string AccountNumber ="";

    cout<<"\nPlease Enter Account Number: ";
    cin>> AccountNumber;

    return AccountNumber;
}



void ShowDeleteClientScreen(){

    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector<sClients> vClients = LoadDataFromFile(FileData);
    
    string AccountNumber = ReadClientAccountNumber();

    DeleteClientByAccountNumber(AccountNumber,vClients);

}


void ShowUpdateClientScreen(){

    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";  
    
    vector<sClients> vClients = LoadDataFromFile(FileData);
    
    string AccountNumber = ReadClientAccountNumber();
    
    UpdateClientByAccountNumber(AccountNumber, vClients);

}


void ShowAddNewClientsScreen(){

    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";
    
    AddNewClients();
}


void ShowFindClientScreen(){

    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector<sClients> vClients = LoadDataFromFile(FileData);

    string AccountNumber = ReadClientAccountNumber();
    sClients Client;


    if(FindClientByAccountNumber(AccountNumber,vClients,Client)){

        PrintClientCard(Client);
    }else{

        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";

    }
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}


void ShowDepositScreen(){


    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

    sClients Client;

    vector<sClients> vClients = LoadDataFromFile(FileData);
    
    string AccountNumber = ReadClientAccountNumber();

    
    while (!FindClientByAccountNumber(AccountNumber,vClients,Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";

        AccountNumber = ReadClientAccountNumber();

    }


    PrintClientCard(Client);

    double Amount = 0;

    cout << "\nPlease enter deposit amount? ";
    cin>> Amount;

    DepositBalanceToClientByAccountNumber(AccountNumber,Amount,vClients);

    
}


void ShowWithDrawScreen(){

    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    sClients Client;

    vector<sClients> vClients = LoadDataFromFile(FileData);

    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber,vClients,Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter withdraw amount? ";
    cin >> Amount;

    while (Amount > Client.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }
    
    DepositBalanceToClientByAccountNumber(AccountNumber,Amount * -1,vClients);
    
}


void ShowTotalBalancesScreen(){

    ShowTotalBalances();
}



enum enTransactionsMenueOptions{

    eDeposit = 1 , eWithdraw = 2 , eShowTotalBalance = 3,
    eShowMainMenue = 4
};

enum enMainMenueOptions{

    eListClients = 1, eAddNewClient = 2,
    eDeleteClient = 3 , eUpdateClient = 4,
    eFindClient = 5 , eTransactions = 6,
    eExit = 7 
};


void GoBackToMainMenue(){

    cout << "\n\nPress any key to go back to Main Menue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    ShowMainMenue();

}

void GoBackToTransactionsMenue(){

    cout << "\n\nPress any key to go back to Transactions Menue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    ShowTransactionsMenue();
}

short ReadTransactionsMenueOption()
{
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}


void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption){

    switch (TransactionMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:
        system("clear");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;
    
    case enTransactionsMenueOptions::eWithdraw:
        system("clear");
        ShowWithDrawScreen();
        GoBackToTransactionsMenue();
        break;
    
    case enTransactionsMenueOptions::eShowTotalBalance:
        system("clear");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenue();
        break;
    
    case enTransactionsMenueOptions::eShowMainMenue:
        ShowMainMenue();
        
    
    }

}

void ShowTransactionsMenue(){

    system("clear");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "===========================================\n";
    PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}


short ReadMainMenueOption(){

    cout << "Choose what do you want to do? [1 to 7]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}


void PerfromMainMenueOption(enMainMenueOptions MainMenueOption){

    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
        
        system("clear");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;
    
    case enMainMenueOptions::eAddNewClient:
        system("clear");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        system("clear");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        system("clear");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;
    
    case enMainMenueOptions::eFindClient:
        system("clear");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;
        
    case enMainMenueOptions::eTransactions:
        system("clear");
        ShowTransactionsMenue();
        break;
    
    case enMainMenueOptions::eExit:
        system("clear");
        ShowEndScreen();
        break;
    }
}

void ShowMainMenue(){


    system("clear");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

int main(){

    ShowMainMenue();

    return 0;
}