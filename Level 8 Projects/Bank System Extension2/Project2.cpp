#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include<limits>

using namespace std;

struct stUsers
{
    /*
    Admins Info
    */
    string Username;
    string Password;
    int Permissions;
    bool MarkForDelete = false;
};

enum enTransactionsMenueOptions {eDeposit = 1 , eWithDraw = 2, eShowTotalBalance = 3,
eShowMainMenue = 4};

enum enManageUsersMenueOptions{eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
eUpdateUser = 4, eFindUser = 5, eMainMenue = 6};

enum enMainMenueOptions {
eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
eManageUsers = 7, eExit = 8
};


enum enMainMenuePermissions {
eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
pUpdateClients = 8, pFindClient = 16, pTranactions = 32,
pManageUsers = 64
};


const string ClientsFileName = "ClientsDate.txt";
const string UsersFileName = "Users.txt";

stUsers CurrentUser;

void ShowMainMenue();
void ShowTransactionsMenue();
void ShowManageUsersMenue();
bool CheckAccessPermission(enMainMenuePermissions Permission);
void Login();

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector<string> SplitString(string S1,string Delim){

    vector<string> vString;

    short pos = 0;
    string sword;

    while((pos = S1.find(Delim)) != std::string::npos){

        sword = S1.substr(0, pos);

        if(sword != ""){
            
            vString.push_back(sword);
        }

        S1.erase(0, pos + Delim.length());
    }
    if(S1 != ""){
        
        vString.push_back(S1);
    }

    return vString;
}


stUsers ConvertUserLinetoRecord(string Line,string Seperator = "#//#"){


    stUsers User;
    vector<string> vUserData = SplitString(Line, Seperator);

    User.Username = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi(vUserData[2]);

    return User;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#"){


    sClient Client;

    vector<string> vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData [3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

stUsers ConvertUserLinetoRecord2(string Line, string Seperator = "#//#"){

    stUsers UserData;

    vector <string> vUserData = SplitString(Line, Seperator);

    UserData.Username = vUserData[0];
    UserData.Password = vUserData [1];
    UserData.Permissions = stoi(vUserData[2]);
    
    return UserData;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#"){

    
    string DataLine = "";

    DataLine += Client.AccountNumber + Seperator ;
    DataLine += Client.PinCode + Seperator;
    DataLine += Client.Name + Seperator;
    DataLine += Client.Phone + Seperator;
    DataLine += to_string(Client.AccountBalance);

    return DataLine;
}


string ConvertUserRecordToLine (stUsers User, string Seperator = "#//#"){

    
    string DataLine = "";

    DataLine += User.Username + Seperator;
    DataLine += User.Password + Seperator;
    DataLine += to_string(User.Permissions);

    return DataLine;
}


bool ClientExistsByAccountNumber(string AccountNumber, string FileName){

    
    vector<sClient> vClients;
    
    fstream MyFile;

    MyFile.open(FileName, ios::in); // read mode;

    if(MyFile.is_open()){

        string Line;
        sClient Client;

        while (getline(MyFile,Line))
        {
            Client = ConvertLinetoRecord(Line);
            
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

bool UserExistsByUsername(string Username, string FileName){


    fstream MyFile;

    MyFile.open(FileName, ios::in); // read mode;
    
    if(MyFile.is_open()){

        string Line;
        stUsers User;

        while (getline(MyFile,Line))
        {
            User = ConvertUserLinetoRecord(Line);
            
            if(User.Username == Username){
                
                MyFile.close();
                return true;

            }
        }
        
        MyFile.close();
    }
    return false;   
}


sClient ReadNewClient(){

    sClient Client;

    cout<<"Enter Account Number: ";
    getline(cin >> ws, Client.AccountNumber);


    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout<<"\nClient With ["<<Client.AccountNumber<<"] Already Exists, Enter another Account Number: ";
        getline(cin>> ws, Client.AccountNumber);

    }

    cout<<"Enter PinCode: ";
    getline(cin, Client.PinCode);

    cout<<"Enter Name: ";
    getline(cin, Client.Name);

    cout<<"Enter Phone: ";
    getline(cin, Client.Phone);

    cout<<"Enter Account Balance: ";
    cin>> Client.AccountBalance;

    return Client;
}

int ReadPermissionsToSet(){

    int Permissions = 0;
    char Answer = 'n';

    cout<<"\nDo You Want To Give Full Access Y/N: ";
    cin>> Answer;

    if(Answer == 'y' || Answer == 'Y'){

        return -1;
    }

    cout<<"\nDo You Want To Give Access To : \n";

    cout<<"\nShow Client List Y/N: ";
    cin>> Answer;

    if(Answer == 'y' || Answer == 'Y'){

        Permissions += enMainMenuePermissions::pListClients;
    }

    cout<<"\nAdd New Clients Y/N: ";
    cin>> Answer;

    if(Answer == 'y' || Answer == 'Y'){

        Permissions += enMainMenuePermissions::pAddNewClient;
    }

    cout<<"\nDelete Client Y/N: ";
    cin>> Answer;

    if(Answer == 'y' || Answer == 'Y'){

        Permissions += enMainMenuePermissions::pDeleteClient;
    }

    cout<<"\nUpdate Client Y/N: ";
    cin>> Answer;

    if(Answer == 'y' || Answer == 'Y'){
        
        Permissions += enMainMenuePermissions::pUpdateClients;
    }

    cout<<"\nFind Client Y/N: ";
    cin>> Answer;

    if(Answer == 'y'|| Answer == 'Y'){

        Permissions += enMainMenuePermissions::pFindClient;
    }

    cout<<"\nTransactions Y/N: ";
    cin>> Answer;
    
    if(Answer == 'y' || Answer == 'Y'){

        Permissions += enMainMenuePermissions::pTranactions;
    }

    cout<<"\nManage Users Y/N: ";
    cin>> Answer;

    if(Answer == 'y'|| Answer == 'Y'){

     Permissions += enMainMenuePermissions::pManageUsers;
    }


    return Permissions;
}

stUsers ReadNewUser(){

    stUsers User;

    cout<<"Enter Username: ";
    getline(cin>> ws, User.Username);


    while (UserExistsByUsername(User.Username, UsersFileName))
    {
        cout<<"\nUser With ["<<User.Username<<"] Already Exists, Enter Another Username: ";
        getline(cin >> ws, User.Username);
    }

    cout<<"Enter Password: ";
    getline(cin,User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;
}


vector<stUsers> LoadUsersDataFromFile(string FileName){

    vector <stUsers> vUsers;
    
    fstream Myfile;

    Myfile.open(FileName, ios:: in); // Read Mode
    
    if(Myfile.is_open()){

        string Line;
        stUsers User;

        while (getline(Myfile,Line))
        {
            User = ConvertUserLinetoRecord(Line);
            
            vUsers.push_back(User);
        }

        Myfile.close();
    }

    return vUsers;
}

vector <sClient> LoadCleintsDataFromFile(string FileName){

    vector <sClient> vClients;
    
    fstream MyFile;

    MyFile.open(FileName, ios:: in); // read mode
    
    if(MyFile.is_open()){

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            
            vClients.push_back(Client);
        }

        MyFile.close();   
    }

    return vClients;
}


void PrintClientRecordLine(sClient Client){

    cout<<"| "<<setw(15) << left <<Client.AccountNumber;
    cout<<"| "<<setw(10) << left <<Client.PinCode;
    cout<<"| "<<setw(40) << left << Client.Name;
    cout<<"| "<<setw(12) << left <<Client.Phone;
    cout<<"| "<<setw(12) << left << Client.AccountBalance;
}

void PrintUserRecordLine(stUsers User){

    cout<<"| "<< setw(15) << left << User.Username;
    cout<<"| "<< setw(10) << left << User.Password;
    cout<<"| "<< setw(40) << left << User.Permissions;
}

void PrintClientRecordBalanceLine(sClient Client){

    cout<<"| "<< setw(15) << left << Client.AccountNumber;
    cout<<"| "<< setw(40) << left << Client.Name;
    cout<<"| "<< setw(12) << left << Client.AccountBalance;
    
}

void ShowAccessDeniedMessage(){

    cout<<"\n-------------------------------\n";
    cout<<"Access Denied, \nYou Don't Have Permission To Do This,\nPlease Contact You're Admin.";
    cout<<"\n-------------------------------\n";
}


void ShowAllClientsScreen(){

    if(!CheckAccessPermission(enMainMenuePermissions::pListClients)){

        ShowAccessDeniedMessage();

        return;
    }

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout<<"\n\t\t\t\t\tClient List("<< vClients.size()<<") Client(s).";
    
    cout<<"\n________________________________________________________________________________________________";
    cout<<"\n________________________________________________________________________________________________\n";
    cout<<"| "<< left<< setw(15) << "Account Number";
    cout<<"| "<< left<< setw(10) << "Pin Code";
    cout<<"| "<< left<< setw(40) << "Client Name";
    cout<<"| "<< left<< setw(12) << "Phone";
    cout<<"| "<< left<< setw(12) << "Balance";
    
    cout<<"\n_______________________________________________________";
    cout<<"_________________________________________\n"<<endl;
    
    if(vClients.size() == 0){
        cout<<"\t\t\tNo Client's Available In The System!";
    }else{

        for(sClient Client: vClients){

            PrintClientRecordLine(Client);
            cout<<endl;
        }
    }

    cout<<"\n_______________________________________________________";
    cout<<"_________________________________________\n"<<endl;
    
}


void ShowAllUsersScreen(){

    vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);

    cout<<"\n\t\t\t\tUsers List ("<<vUsers.size()<<") User(s).";

    cout<<"\n_______________________________________________________\n";
  //  cout<<"_________________________________________\n" <<endl;

    cout<<"| "<< left << setw(15) << "User Name";
    cout<<"| "<< left << setw(10) << "Password";
    cout<<"| "<< left << setw(40) << "Permissions";

    cout<<"\n_______________________________________________________\n";
   // cout<<"_________________________________________\n"<<endl;

    if(vUsers.size() == 0)
        cout<<"\t\t\t\tNo Users Available In The System!";

    else

    for(stUsers User: vUsers){

            PrintUserRecordLine(User);
            cout<<endl;
        }

    cout<<"\n_______________________________________________________";
    cout<<"_________________________________________\n"<<endl;

}

void ShowTotalBalances(){

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout<<"\n\t\t\t\t\tBalance List ("<< vClients.size()<<") Client(s).";

    cout<<"\n_______________________________________________________";
    cout<<"_________________________________________\n";

    cout<<"| "<< left << setw(15) << "Account Number";
    cout<<"| "<< left << setw(40) << "Client Name";
    cout<<"| "<< left << setw(12) << "Balance";

    cout<<"\n_______________________________________________________";
    cout<<"_________________________________________\n"<<endl;

    double TotalBalances = 0;

    if(vClients.size() == 0)
        cout<<"\t\t\t\tNo Clients Available In The System!";
    else

        for(sClient Client: vClients){

            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.AccountBalance;
            cout<<endl;
        }

    cout<<"\n_______________________________________________________";
    cout<<"_________________________________________\n"<<endl;
    cout<<"\t\t\t\t\t   Total Balances = "<< TotalBalances;

}


void PrintClientCard(sClient Client){

    cout<<"\nThe Following Are The Client Details:\n";
    cout<<"-----------------------------------";
    cout<<"\nAccount Number  : "<<Client.AccountNumber;
    cout<<"\nPin Code        : "<<Client.PinCode;
    cout<<"\nName            : "<<Client.Name;
    cout<<"\nPhone           : "<< Client.Phone;
    cout<<"\nAccount Balance : "<<Client.AccountBalance;
    cout<<"\n-----------------------------------\n";

}


void PrintUserCard(stUsers User){

    cout<<"\nThe Following Are The User Details:\n";
    cout<<"-----------------------------------";
    cout<<"\nUserName     : "<<User.Username;
    cout<<"\nPassword     : "<<User.Password;
    cout<<"\nPermissions  : "<<User.Permissions;
    cout<<"\n-----------------------------------\n";
}


bool FindClientByAccountNumber(string AccountNumber, vector<sClient>vClients,sClient& Client){

    for(sClient C: vClients){

        if(C.AccountNumber == AccountNumber){
            
            Client = C;
            return true;
        }
    }

    return false;
}



bool FindUserByUsername(string UserName,vector<stUsers> vUsers,stUsers& User){


    for(stUsers U: vUsers){

        if(U.Username == UserName){

            User = U;
            return true;
        }
    }
    return false;

}

bool FindUserByUsernameAndPassword(string Username,string Password,stUsers& User){


    vector <stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);

    for(stUsers U: vUsers){

        if(U.Username == Username && U.Password == Password){
            
            User = U;
            return true;
        }
    }
    
    return false;
}


sClient ChangeClientRecord(string AccountNumber){

    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout<<"\n\nEnter PinCode: ";
    getline(cin >>ws, Client.PinCode);

    cout<<"Enter Name: ";
    getline(cin, Client.Name);

    cout<<"Enter Phone: ";
    getline(cin, Client.Phone);

    cout<<"Enter AccountBalance: ";
    cin>> Client.AccountBalance;

    return Client;
}

stUsers ChangeUserRecord(string Username){

    stUsers User;

    User.Username = Username;

    cout<<"\n\nEnter Password: ";
    getline(cin>> ws, User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;
}


bool MarkClientForDeleteByAccountNumber(string AccountNumber,vector<sClient>& vClients){

    for(sClient& C: vClients){

        if(C.AccountNumber == AccountNumber){
            
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;

}

bool MarkUserForDeleteByUsernam(string Username,vector<stUsers>& vUsers){

    
    for(stUsers& U: vUsers){

        if(U.Username == Username){

            U.MarkForDelete = true;
            return true;
        }
    }

    return false;
}


vector <sClient> SaveCleintsDataToFile(string FileName,vector<sClient> vClients){

    fstream MyFile;
    
    MyFile.open(FileName, ios::out); // overwrite

    string DataLine;
    
    if(MyFile.is_open()){


        for(sClient C: vClients){
            
            if(C.MarkForDelete == false){
                
                DataLine = ConvertRecordToLine(C);
                
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }
    
    return vClients;
}

vector <stUsers> SaveUsersDataToFile(string FileName,vector<stUsers> vUsers){

    fstream MyFile;
    
    MyFile.open(FileName, ios::out); // overwrite
    
    string Dataline;

    if(MyFile.is_open()){

        
        for(stUsers U: vUsers){

            if(U.MarkForDelete == false){

                Dataline = ConvertUserRecordToLine(U);
                
                MyFile << Dataline << endl;
            }
        }

        MyFile.close();
    }
    
    return vUsers;
}


void AddDataLineToFile (string FileName, string DataLine){


    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app); 

    if (MyFile.is_open())
    {
        MyFile<< DataLine <<endl;
        MyFile.close();
    }
}

void AddNewClient (){

    sClient Client;

    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName,ConvertRecordToLine(Client));

}


void AddNewUser(){

    stUsers User;
    
    User = ReadNewUser();
    AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(User));
}


void AddNewClients(){

    char Answer = 'Y';

    do{

        cout<<"Adding New Client:\n\n";

        AddNewClient();
        
        cout<<"\nClient Added Successfully, Do You Want To Add More Clients: Y/N";
        cin>> Answer;

    }while(toupper(Answer) == 'Y');
}

void AddNewUsers(){

    char Answer = 'Y';
    
    do
    {
        cout<<"Adding New User:\n\n";

        AddNewUser();

        cout<<"\nUser Added Successfully, Do You Want Add More Users: Y/N";
        cin>> Answer;

    } while (toupper(Answer) == 'Y');
    
}

bool DeleteClientByAccountNumber(string AccountNumber,vector<sClient>& vClients){

    sClient Client;
    char Answer = 'n';

    if(FindClientByAccountNumber(AccountNumber,vClients, Client)){

        PrintClientCard(Client);
        cout<<"\n\nAre You Sure You Want To Delete This Client: Y/N: ";
        cin>> Answer;

        if(Answer == 'y'|| Answer == 'Y'){

            MarkClientForDeleteByAccountNumber(AccountNumber,vClients);
            
            SaveCleintsDataToFile(ClientsFileName, vClients);

            //Referesh Clients
            vClients = LoadCleintsDataFromFile(ClientsFileName);

            cout<<"\n\nClient Deleted Successfully.";
            return true;

        }
    }

    else{
        cout<<"\nClient With Account Number ("<< AccountNumber<<") Is Not Found!";

    }
    return false;
}

bool DeleteUserByUsername(string UserName, vector<stUsers>& vUsers){

    if(UserName =="Admin"){
        
        cout<<"\n\nYou Cannot Delete This User.";
        return false;
    }

    stUsers User;
    char Answer = 'n';

    if(FindUserByUsername(UserName,vUsers,User)){

        PrintUserCard(User);
        
        cout<<"\n\nAre You Sure You Want To Delete This User? Y/N: ";
        cin>> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            MarkUserForDeleteByUsernam(UserName,vUsers);
            SaveUsersDataToFile(UsersFileName,vUsers);

            //Referesh
            vUsers = LoadUsersDataFromFile(UsersFileName);

            cout<<"\n\nUser Deleted Successfully.";
            return true;

        }
        
    }else{

        cout<<"\nUser With Username ("<<UserName<<") Is Not Found!";
    }
    return false;
}


bool UpdateClientByAccountNumber(string AccountNumber,vector<sClient>& vClients){

    sClient Client;
    char Answer = 'n';

    if(FindClientByAccountNumber(AccountNumber,vClients,Client)){

        PrintClientCard(Client);

        cout<<"\n\nAre You Sure You Want Update This Client Y/N: ";
        cin>> Answer;

        if(Answer == 'y'|| Answer == 'Y'){

            for(sClient& C: vClients){

                if(C.AccountNumber == AccountNumber){
                    
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            
            SaveCleintsDataToFile(ClientsFileName,vClients);
            cout<<"\n\nClient Updated Successfully.";
            return true;

        }
    }else{

        cout<<"\nClient With Account Number ("<<AccountNumber<<") Is Not Found!";
    }
    return false;
}


bool UpdateUserByUsername(string Username,vector<stUsers>& vUsers){

    stUsers User;
    char Answer = 'n';

    if(FindUserByUsername(Username,vUsers,User)){

        PrintUserCard(User);

        cout<<"\n\nAre You Sure You Want Update This User Y/N: ";
        cin>> Answer;

        if(Answer == 'Y'|| Answer == 'y'){

            for(stUsers& U: vUsers){

                if(U.Username == Username){

                    U = ChangeUserRecord(Username);
                    break;
                }
            }

            SaveUsersDataToFile(UsersFileName,vUsers);
            cout<<"\n\nUser Updated Successfully.";
            return true;
        }
    }else{

        cout<<"\nUser With Account Number ("<<Username<<") Is Not Found!";
    }
    return false;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber,double Amount,vector<sClient>& vClients){

  char Answer = 'n';

  cout<<"\n\nAre You Sure You Want Perform This Transaction Y/n: ";
  cin>> Answer;


  if (Answer == 'Y'|| Answer == 'y'){

    for(sClient& C: vClients){

        if(C.AccountNumber == AccountNumber){

            C.AccountBalance += Amount;
            SaveCleintsDataToFile(ClientsFileName,vClients);
            cout<<"\n\nDone Successfully. New Balance Is: "<<C.AccountBalance;

            return true;
        }
    }

  }
   return false;
}

string ReadClientAccountNumber(){

    string AccountNumber = "";

    cout<<"\nPlease Enter AccountNumber: ";
    cin >> AccountNumber;

    return AccountNumber;   
}

string ReadUserName(){

    string Username = "";

    cout<<"\nPlease Enter Username: ";
    cin>> Username;
    return Username;
}

void ShowListUsersScreen(){

    ShowAllUsersScreen();
}

void ShowAddNewUserScreen(){

    cout<<"\n-----------------------------------\n";
    cout<<"\tAdd New User Screen";
    cout<<"\n-----------------------------------\n";

    AddNewUser();    
}

void ShowDeleteUserScreen(){

    cout<<"\n-----------------------------------\n";
    cout<<"\tDelete Users Screen";
    cout<<"\n-----------------------------------\n";

    vector<stUsers>vUsers = LoadUsersDataFromFile(UsersFileName);

    string Username = ReadUserName();
    DeleteUserByUsername(Username,vUsers);
}

void ShowUpdateUserScreen(){


    cout<<"\n-----------------------------------\n";
    cout<<"\tUpdate Users Screen";
    cout<<"\n-----------------------------------\n";

    vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);

    string Username = ReadUserName();

    UpdateUserByUsername(Username,vUsers);
}


void ShowDeleteClientScreen(){

    if(!CheckAccessPermission(enMainMenuePermissions::pDeleteClient)){

        ShowAccessDeniedMessage();
        return ;
    }

    
    cout<<"\n-----------------------------------\n";
    cout<<"\tDelete Client Screen";
    cout<<"\n-----------------------------------\n";
    
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen(){

    
    if(!CheckAccessPermission(enMainMenuePermissions::pUpdateClients)){

        ShowAccessDeniedMessage();
        return ;
    }

    cout<<"\n-----------------------------------\n";
    cout<<"\tUpdate Client Info Screen";
    cout<<"\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(AccountNumber,vClients);
}

void ShowAddNewClientsScreen(){

    if(!CheckAccessPermission(enMainMenuePermissions::pAddNewClient)){

        ShowAccessDeniedMessage();

        return ;
    }

    cout<<"\n-----------------------------------\n";
    cout<<"\tAdd New Clients Screen";
    cout<<"\n-----------------------------------\n";
    
    AddNewClients();
}

void ShowFindClientScreen(){

    if(!CheckAccessPermission(enMainMenuePermissions::pFindClient)){

        ShowAccessDeniedMessage();

        return ;
    }

    cout<<"\n-----------------------------------\n";
    cout<<"\tFind Client Screen";
    cout<<"\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    sClient Client;

    string AccountNumber = ReadClientAccountNumber();

    if(FindClientByAccountNumber(AccountNumber,vClients,Client)){

        PrintClientCard(Client);
    }else{

        cout<<"\nClient With AccountNumber ("<< AccountNumber<<") Is Not Found!";

    }
}

void ShowFindUserScreen(){

    cout<<"\n-----------------------------------\n";
    cout<<"\tFind Client Screen";
    cout<<"\n-----------------------------------\n";
    
    vector<stUsers> vUsers = LoadUsersDataFromFile(UsersFileName);

    stUsers User;

    string Username = ReadUserName();

    if(FindUserByUsername(Username,vUsers,User)){

        PrintUserCard(User);

    }else{

        cout<<"\nUser With Username("<<Username<<") Is Not Found!";

    }
}

void ShowEndScreen(){

    cout<<"\n-----------------------------------\n";
    cout<<"\tProgram Ends :-)";
    cout<<"\n-----------------------------------\n";
}

void ShowDepositScreen(){

    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;
    
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    while(!FindClientByAccountNumber(AccountNumber,vClients,Client)){

        cout<<"\nClient With ["<< AccountNumber <<"] Does Not Exists. \n";

        AccountNumber = ReadClientAccountNumber();
        
    }

    PrintClientCard(Client);

    double Amount = 0;

    cout<<"\nPlease Enter Deposit Amount: ";
    cin>> Amount;

    DepositBalanceToClientByAccountNumber(AccountNumber,Amount,vClients);
}

void ShowWithDrawScreen(){

    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber,vClients,Client))
    {
        cout<<"\nClient With ["<<AccountNumber<<"] Does Not Exists. \n";

        AccountNumber = ReadClientAccountNumber();

    }

    PrintClientCard(Client);

    double Amount;

    cout<<"\nPlease Enter WithDraw Amount: ";
    cin>> Amount;

    while (Amount > Client.AccountBalance)
    {
        cout<<"\nAmount Exceeds The Balance, You Can WithDraw Up To: "<<Client.AccountBalance<<endl;
        cout<<"Please Enter Another Amount: ";
        cin>> Amount;
    }
    
    DepositBalanceToClientByAccountNumber(AccountNumber,Amount * -1 ,vClients);
    
}


void ShowTotalBalancesScreen(){

    ShowTotalBalances();
}


bool CheckAccessPermission(enMainMenuePermissions Permissions){

    if((CurrentUser.Permissions == enMainMenuePermissions::eAll))
        return true;
    
    if((Permissions & CurrentUser.Permissions)== Permissions)
        return true;
    
    else
        return false;

}

void GoBackToMainMenue(){

    cout << "\n\nPress Any Key To Go Back To Main Menue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    ShowMainMenue();
}

void GoBackToTransactionsMenue(){

    cout<<"\n\nPress Any Key To Go Back To Transactions Menue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    ShowTransactionsMenue();
}

void GoBackToManageUsersMenue(){

    cout<<"\n\nPress Any Key To Go Back To Transactions Menue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    ShowManageUsersMenue();
}

short ReadTransactionsMenueOption(){

    short choice = 0;

    cout<<"Choose What Do You Want To Do [1 To 4]: ";
    cin>> choice;

    return choice;
}

void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption){

    switch (TransactionMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:{
        system("clear");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eWithDraw:{
    
        system("clear");
        ShowWithDrawScreen();
        GoBackToTransactionsMenue();
        break;
    }
    case enTransactionsMenueOptions::eShowTotalBalance:{
        system("clear");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenue();
        break;
    }
    case enTransactionsMenueOptions::eShowMainMenue:{
        ShowMainMenue();
    
        }
    }
}

void ShowTransactionsMenue(){

    if(!CheckAccessPermission(enMainMenuePermissions::pTranactions)){

        ShowAccessDeniedMessage();
        GoBackToMainMenue();
        
        return ;
    }

    system("clear");

    cout << "===========================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "===========================================\n";

    PerfromTranactionsMenueOption((enTransactionsMenueOptions) ReadTransactionsMenueOption());   
}

short ReadMainMenueOption(){

    cout<<"Choose What Do You Want To Do: [1 To 8]: ";
    short choice = 0;
    cin>>choice;

    return choice;
}

void PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption){



    switch(ManageUsersMenueOption){

        case enManageUsersMenueOptions::eListUsers:{

            system("clear");
            ShowListUsersScreen();
            GoBackToManageUsersMenue();
            break;

        }
    
        case enManageUsersMenueOptions::eAddNewUser:{


            system("clear");
            ShowAddNewUserScreen();
            GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:{

            system("clear");
            ShowDeleteUserScreen();
            GoBackToManageUsersMenue();

            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:{

            system("clear");
            ShowUpdateUserScreen();
            GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:{

            system("clear");
            ShowFindUserScreen();
            GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:{
            
            ShowMainMenue();
        }

    }
}

short ReadManageUsersMenueOption(){

    cout<<"Choose What Do You Want To Do [1 To 6]: ";
    short choice = 0;
    cin>> choice;

    return choice;
}


void ShowManageUsersMenue(){

    if(!CheckAccessPermission(enMainMenuePermissions::pManageUsers)){

        ShowAccessDeniedMessage();
        GoBackToMainMenue();
        return ;

    }
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tManage Users Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "===========================================\n";

    PerfromManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());

}


void PerfromMainMenueOption(enMainMenueOptions MainMenueOption){

    switch(MainMenueOption){

        case enMainMenueOptions::eListClients:{

            system("clear");
            ShowAllClientsScreen();
            GoBackToMainMenue();
            break;
        }

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

        case enMainMenueOptions::eShowTransactionsMenue:
        system("clear");
        ShowTransactionsMenue();
        break;

        case enMainMenueOptions::eManageUsers:
        system("clear");
        ShowManageUsersMenue();
        break;

        case enMainMenueOptions::eExit:
        system("clear");

        Login();
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
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.\n";
    cout << "===========================================\n";

    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());

}

bool LoadUserInfo(string Username, string Password){

    if(FindUserByUsernameAndPassword(Username,Password,CurrentUser))
        return true;
    
    else
        return false;
}


void Login(){

    bool LoginFaild = false;

    string Username,Password;

    do{

        system("clear");
        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if(LoginFaild){

            cout<<"Invalid Username/Password!\n";
        }
        
        cout<<"Enter Username: ";
        cin>> Username;

        cout<<"Enter Password: ";
        cin>> Password;


        LoginFaild = !LoadUserInfo(Username,Password);

    }while(LoginFaild);

    ShowMainMenue();
}


int main(){

    Login();
    
    return 0;
}