#pragma once
#include <iostream>
#include <limits> // include this for numeric_limits
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>   // for toupper, tolower, isupper
#include <iomanip>  // for setw
#include <fstream>  // for files
using namespace std;


namespace MyLib{


struct sDate {
    short day;
    short month;
    short year;
};

struct stPeriod {
    sDate StartDate;
    sDate EndDate;
};


struct sClients{
    string AccountNumber;
    string PinCode;
    string AccountName;
    string Name;
    string Phone;
    string Email;
    double AccountBalance;
    bool MarkForDelet = false;
    bool MarkForUpdate = false;
};

const string FileData = "ClientsData.txt";

bool IsLastDayInMonth(sDate Date);
bool IsWeekEnd(sDate Date);
bool IsBusinessDay(sDate Date);
string ConvertRecordToline(sClients Client , string Sperator = "#//#");




    int ReadPositiveNumber(string Message){

	int Number = 0;
		
		do{

			cout<<Message<<": ";
			cin>> Number;

		}while(Number <= 0);

		return Number;
	}
    
    int SumOfDigits(int Number){

        int Sum = 0 , Remainder = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number /= 10;
            Sum += Remainder;
        }
        return Sum;
    }

    
    int MaxNumberInArray(int arr[100], int arrlength){


        int Max = 0;

        for(int i = 0; i < arrlength ; i++){

            if(arr[i] > Max){

                Max = arr[i];
            }
        }
        
        return Max;
    }

    int MinNumberInArray(int arr[100], int arrlength){

        int Min = 0;
        Min = arr[0];

        for(int i = 0; i < arrlength; i ++){

            if(arr[i] < Min){
                Min = arr[i];
            }
        }
        return Min;
    }


    int SumArray(int arr[100], int arrlength){

        int Sum = 0;

        for(int i = 0; i < arrlength; i ++){

            Sum += arr[i];
        }

         return Sum;
    }

    float ArrayAverage(int arr[100], int arrlength){


        return (float)SumArray(arr,arrlength) / arrlength;
    }

    short FindNumberPositionInArray(int Number, int arr[100],int arrlength){


        for(int i = 0; i < arrlength; i ++){

            if(arr[i] == Number)
                return i + 1;

        }
        return -1;
    }


    bool IsNumberInArray(int Number, int arr[100], int arrlength){

        return FindNumberPositionInArray(Number,arr,arrlength) != -1;

    }



int ReadNumberValidation(){


    /*When you decide to use this function don't forget to include the library of limits
    #include <limits> // include this header for numeric_limits

    */

	int Number = 0;
	
	cout<<"Please Enter Number: ";
	cin>> Number;

	while(cin.fail()){

	// user didn't input a number
	cin.clear(); // this line is responsible to delete the user input

	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	
	cout<<"Invalid Number,Enter a Valid one: "<<endl;

	cout<<"Enter A Number: ";
	cin>>Number;

	}// End Of While

	return Number;
}


int MyPower(int base, int power){
 // Based on recursive function

	if(power == 0){

		return 1;
	}else{

		return(base * MyPower(base, power - 1));
	}

}


int MaxOfTwoNumbers(int N1, int N2){

	if(N1 > N2)
		return N1;
	else
		return N2;
}


int MaxOfThreeNumbers(int N1, int N2,int N3){

	if(N1 > N2 && N1 > N3)
		return N1;
	
	else if(N2 > N1 && N2 > N3)
		return N2;
	else
		return N3;
}


float CalculateRectangleArea(float A , float B){

	return A * B;
}


float CalculateRectangleAreaBySideDiagonal(float A , float D){

	float Area = A * sqrt( pow(D,2) - pow(A,2));
	
	return Area;

}


float TriangleArea(float A , float H){

	float Area = (A/2) * H;
	
	return Area;

}


int CountDigitFrequency (short DigitTocheck, int Number){

	int FreqCount = 0, Remainder = 0;

	while(Number > 0){

		Remainder = Number % 10;
		Number /= 10;

		if(DigitTocheck == Remainder){
			FreqCount ++;
		}
	}

	return FreqCount;
}

float ReadRadius(){

	float R = 0;

	cout<<"\nEnter Radius: ";
	cin>> R;

	return R;
}

float CircleArea(float R){

	const float PI = 3.141592653589793238;

	float Area = pow(R,2) * PI;
	return Area;
}


 float ReadDiameter(){

	float D = 0;

	cout<<"\nEnter Diameter: ";
	cin>> D;

	return D;
}

float CircleAreaByDiamter(float D){

	const float PI = 3.141592653589793238;

	float Area = (pow(D,2) * PI) / 4;
	return Area;
}


bool IsPerfectNumber(int Number){

	int sum = 0;
	
	for(int i = 1; i < Number; i ++){

		if(Number % i == 0)
			sum += i;
	}
	
	return Number == sum;
}


string ReadString(){

        string Word;

        cout<<"Please Enter Your String: ";
        getline(cin,Word);

        return Word;
    }



int ReversedNumber(int Number){

	int REv = 0, Rem = 0, Number2 = 0;
	
	while(Number > 0){
		
		Rem = Number % 10;
		Number2 = Number2 * 10 + Rem;
		Number /= 10;
	}
	return Number2;
}


bool IsPalindrom(int Number){

	return Number == ReversedNumber(Number);
}



bool GuessPassword(string originalPassword) {
    string word = "";
    int counter = 0;

    for (int i = 65; i <= 90; i++) { // Loop for the first letter (A-Z)
        for (int j = 65; j <= 90; j++) { // Loop for the second letter (A-Z)
            for (int k = 65; k <= 90; k++) { // Loop for the third letter (A-Z)
                counter++;
                word = ""; // Reset `word` for each new trial
                word += char(i);
                word += char(j);
                word += char(k);

                cout << "Trial [" << counter << "]: " << word << endl;

                if (word == originalPassword) {
                    cout << "\nPassword is: " << word << endl;
                    cout << "Found After " << counter << " Trial(s)\n";
                    return true;
                }
            }
        }
    }

    cout << "\nPassword not found!\n";
    return false;
}



int RandomNumber(int from, int to){

    int RandNum = rand() % (to - from + 1) + from;


    return RandNum;
}



int TimesRepeated(int Number, int Arr[100], int Length){

    int count = 0;
    
    for(int i = 0; i < Length; i ++){

        if(Number == Arr[i])
            count ++;
    }
    return count;
}



   int SumMatrixElements(int Matrix1[3][3] , int Rows, int Cols){

        int Sum = 0;

        for(short i = 0; i < Cols; i ++){

            for(short j = 0; j < Rows; j ++){

                Sum += Matrix1[i][j];
            }
        }
        
        return Sum;
    }


bool CheckIdentityMatrix(int Matrix1[3][3], int Rows, int Cols){
    
    for(short i = 0; i < Rows; i++){

        for(short j = 0; j < Cols; j++){

            // If the element is on the main diagonal, it must be 1

            if(i == j && Matrix1[i][j] != 1){
                return false;
            }
            // If the element is NOT on the main diagonal, it must be 0
            else if(i != j && Matrix1[i][j] != 0){
                return false;
            }
        }
    }
    // If all conditions are satisfied => Matrix is Identity
    return true;
}


bool IsScalarMatrix(int Matrix1[3][3], int Rows, int Cols){
    
    int FirstElement = Matrix1[0][0];


    for(short i = 0; i < Rows; i++){

        for(short j = 0; j < Cols; j++){

            // If the element is on the main diagonal, it must be 1

            if(i == j && Matrix1[i][j] != FirstElement){
                return false;
            }
            // If the element is NOT on the main diagonal, it must be 0
            else if(i != j && Matrix1[i][j] != 0){
                return false;
            }
        }
    }
    // If all conditions are satisfied => Matrix is Identity
    return true;
}


    short CountNumberInMatrix(int Matrix1[3][3],int NumberFreq ,int Rows, int Cols){
        
        short NumberFreqs = 0;

        for(short i = 0 ; i < Cols; i ++){

            for(short j = 0; j < Rows; j++){

                if(Matrix1[i][j] == NumberFreq){
                    
                    NumberFreqs ++;
                }
            }
        }

        return NumberFreqs;
    }



 bool IsSParse(int Matrix[3][3],int Rows,int Cols){

        short zerocount = 0;
        short nonzero = 0;

        for(short i = 0; i < Cols; i ++){

            for(short j = 0; j < Rows; j++){

                if (Matrix[i][j] == 0){
                    
                    zerocount ++;
                }else {

                    nonzero++;
                }
            }
        }

        return zerocount > nonzero;
    }
    

    bool FindNumberInMatrix(int Matrix[3][3], int Number, int Rows, int Cols){

        for(short i = 0; i < Cols; i ++){

            for(short j = 0; j < Rows; j++){

                if(Matrix[i][j] == Number)
                    return true;
            }
        }
        return false;
    }


    int MinNumberInMatrix(int Matrix1[3][3], int Rows, int Cols){

        int Min = Matrix1[0][0];
        
        for(short i = 0; i < Cols; i ++){

            for(short j = 0; j < Rows; j++){

                if(Matrix1[i][j] < Min){
                    
                    Min = Matrix1[i][j];
                }
            }
        }
        return Min;
    }

    int MaxNumberInMatrix(int Matrix1[3][3], int Rows, int Cols){

        int Max = Matrix1[0][0];
        
        for(short i = 0; i < Cols; i ++){

            for(short j = 0; j < Rows; j++){

                if(Matrix1[i][j] > Max){
                    
                    Max = Matrix1[i][j];
                }
            }
        }
        return Max;
    }




    int IsPalindromMatrix(int matrix1[3][3], int Rows, int Cols){

        
        for(short i = 0; i < Rows; i ++){

            for(short j = 0; j < Cols / 2; j++){

                if(matrix1[i][j] != matrix1[i][Cols - 1 - j]){
                    return false;
                }
            }
        }
        return true;
    }


    string UpperFirstLetterOfEachword(string Word){

        bool IsFirstLetter = true;

        for(short i = 0; i < Word.length(); i++){

            if(Word[i] != ' ' && IsFirstLetter){

                Word[i] = toupper(Word[i]);
            }

            IsFirstLetter = (Word[i] == ' ' ? true : false);
        }

        return Word;
    }


    string LowerFirstLetterOfEachword(string Word){

        bool IsFirstLetter = true;

        for(short i = 0; i < Word.length(); i ++){

            if(Word[i] != ' ' && IsFirstLetter){

                Word[i] = tolower(Word[i]);
            }
            
            IsFirstLetter = (Word[i] == ' ' ? true : false);

        }

        return Word;

    }


     string ConvertAllstringToUpper(string Word){

        
        for(short i = 0; i < Word.length(); i ++){
            
            Word[i] = toupper(Word[i]);
        }

        return Word;

    }

    string ConvertAllstringToLower(string Word){

        for(short i = 0; i < Word.length(); i ++){

            Word[i] = tolower(Word[i]);
        }

        return Word;
    }



    char ReadCharacter(){

        char C;

        cout<<"Please Enter Character: ";
        cin>> C;

        return C;
    }


   char InvertCharacterCase(char C){

        return isupper(C) ? tolower(C) : toupper(C);
    }


    string InvertAllLettersCase(string  Word){

        for(short i = 0; i < Word.length(); i++){

            if(islower(Word[i])){
                
                Word[i] = InvertCharacterCase(Word[i]);
            }
        }

        return Word;

    }



    int GetLengthOfString(string Word){

        int count = 0;

        for(short i = 0; i < Word.length(); i ++){

            if(Word[i] != ' '){
                
                count++;
            }
        }
        
        return count;
    }

    int CountSmallLettersInString(string Word){

        int count = 0;

        for(short i = 0; i < Word.length(); i ++){

            if(islower(Word[i])){
                count++;
            }
        }
        
        return count;
    }

    int CountCapitallLettersInString(string Word){

        int count = 0;
        
        for(short i = 0; i < Word.length(); i ++){
            
            if(isupper(Word[i])){
                
                count++;
            }
        }

        return count;
    }


    int CountSpecificLetterInString(string Word,char C){

        short count = 0;

        for (short i = 0; i < Word.length(); i ++){

            if (Word[i] == C){
                count ++;
            }
        }

        return count;
    }



    int CountSpecificLetterInString(string Word,char C, bool MatchCase = true){

        short count = 0;

        for (short i = 0; i < Word.length(); i ++){

            if(MatchCase){
                
                if(Word[i] == C)
                count ++;

            }else{
                
                if(tolower(Word[i]) == tolower(C))
                    count++;
            }
        }

        return count;
    }


    bool IsVowels(char C){

        C  = tolower(C);

        return ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'o')|| (C == 'u'));

    }


    int CountVowelsLettersInString(string Word){

        short Count = 0;

        for(short i = 0; i < Word.length(); i ++){

            if(IsVowels(Word[i])){
                
                Count++;
            }
        }

        return Count;
    }

    void PrintAllVowelsLettersInString(string Word){

        for(short i = 0; i < Word.length(); i ++){

            if(IsVowels(Word[i])){
                
                cout<<Word[i]<<" ";
            }
        }
        cout<<endl;
    }



    short CountEachWordInString(string Word){

        string delim = " ";
        short Pos = 0;
        short count = 0;
        string sWord; 

        while((Pos = Word.find(delim)) != std::string::npos){

            sWord = Word.substr(0,Pos);

            if(sWord != ""){

                count++;
            }

            Word.erase(0,Pos + delim.length());
        }

        if(Word != ""){

            count ++;

        }
        return count;
    }


    vector<string> SplitString(string s1, string Delim){

        vector<string> Vstring;

        short pos = 0;
        string sWord;

        while((pos = s1.find(Delim)) != std::string::npos){

            sWord = s1.substr(0,pos);

            if(sWord != ""){

                Vstring.push_back(sWord);
            }

            s1.erase(0,pos + Delim.length());

        }

        if(s1 != ""){
            
            Vstring.push_back(s1);
        }

        return Vstring;
    }



    string TrimLeft(string S1){

        
        for(short i = 0; i < S1.length(); i ++){

            if(S1[i] != ' '){

            return S1.substr(1,S1.length() - i);

            }
        }
        return "";
    }

    string TrimRight(string S1){

        for(short i = S1.length()-1; i >= 0; i--){

            if(S1[i] != ' '){

                return S1.substr(0, i+1);

            }
        }
        return"";
    }

    string Trim(string S1){

        return (TrimLeft(TrimRight(S1)));
    }



    string JoinString(vector<string>vString, string Delim){


        string s1;

        for(string& s: vString){

            s1 = s1 + s + Delim;
        }

        return s1.substr(0,s1.length() - Delim.length());
    }

        
    string JoinString(string arrString[], short length, string Delim){


        string s1 = "";

        for(short i = 0; i < length; i ++){

            s1 = s1 + arrString[i] + Delim;
        }

        return s1.substr(0,s1.length() - Delim.length());
    }




    string RemovePunctuationsFromString(string s1){

        string s2 = "";

        for(short i = 0; i < s1.length(); i ++){

            if(!ispunct(s1[i])){

                s2 += s1[i];
            }
        }

        return s2;
    }

  


sClients ReadNewClient(){

    sClients Client;
    cout<<"\t\tPlease Enter Client Data\n\n";
    
    cout<<"\nEnter Account Number: ";
    getline(cin,Client.AccountNumber);
    
    cout<<"\nEnter PinCode: ";
    getline(cin,Client.PinCode);
    
    cout<<"\nEnter Name: ";
    getline(cin,Client.Name);
    
    cout<<"\nEnter Phone: ";
    getline(cin,Client.Phone);
    
    cout<<"\nEnter Account Balance: ";
    cin>>Client.AccountBalance;
    

    return Client;
}

string ConvertRecordToline(sClients Client , string Sperator = "#//#"){

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Sperator;
    stClientRecord += Client.PinCode + Sperator;
    stClientRecord += Client.Name + Sperator;
    stClientRecord += Client.Phone + Sperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}



string ReplaceWordInStringUsingBuiltInFunction(string s1, string StringToReplace, string ReplaceTo){


    short pos = s1.find(StringToReplace);

    while(pos != std::string::npos){

        s1 = s1.replace(pos,StringToReplace.length(), ReplaceTo);
        pos = s1.find(StringToReplace); // Next Word
    }

    return s1;
}


string ReplaceWordsInStringUsingBuiltinFunc(string S1, string sReplace, string ReplaceTo){


    short pos = S1.find(sReplace);

    while(pos != std::string::npos){

        S1 = S1.replace(pos,sReplace.length(),ReplaceTo);
        pos = S1.find(sReplace);
    }

    return S1;
}



bool FindClientByAccountNumber(string AccountNumber, vector<sClients>& vClients, sClients& Client)
{
    for(sClients C: vClients){
        if(C.AccountNumber == AccountNumber){
            Client = C;
            return true;
        }
    }
    return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClients>& vClients)
{
    for(sClients& C : vClients){
        if(C.AccountNumber == AccountNumber){
            C.MarkForDelet = true;
            return true;
        }
    }
    return false;
}


sClients ConvertLineToRecord(string Line,string Separator = "#//#"){

    vector<string> Vstring = SplitString(Line, Separator);

    sClients Client;
    
    Client.AccountNumber = Vstring[0];
    Client.PinCode = Vstring[1];
    Client.AccountName = Vstring[2];
    Client.Phone = Vstring[3];
    Client.Email = Vstring[4];
    Client.AccountBalance = stod(Vstring[5]); // cast string to double

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



vector<sClients> SaveCleintsDataToFile(string FileName,vector<sClients> vClients){

    fstream Myfile;
    
    Myfile.open(FileName, ios::out); // overwrite
    
    string DataLine;

    if(Myfile.is_open()){

        
        for(sClients C: vClients){

           if(C.MarkForDelet == false){
            
            DataLine = ConvertRecordToline(C);
            
            Myfile << DataLine << endl;

           }
        }

        Myfile.close();
        
    }

    return vClients;
}


bool DeleteClientByAccountNumber(string AccountNumber,vector<sClients>& vClients){

    char Answer = 'Y';
    sClients Client;

    if(FindClientByAccountNumber(AccountNumber, vClients, Client)){

        PrintClientCard(Client);
        
        cout<<"\nAre you sure you want delete this client: Y/N: ";
        cin>> Answer;

        if(Answer == 'Y' || Answer == 'y'){
            
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            
            SaveCleintsDataToFile(FileData,vClients);

            vClients = LoadDataFromFile(FileData);

            cout<<"\nClient Deleted Successfully.\n";

            return true;

        }

    }else{
            
        cout<<"\nClient With Account Number ("<<AccountNumber<<") Is Not Found!"<<endl;
            
        return false;
    
    }
}


bool MarkClientForUpdateByAccountNumber(string AccountNumber,vector<sClients>& vClients){

    for(sClients& C: vClients){

        if(C.AccountNumber == AccountNumber){

            C.MarkForUpdate = true;
            
            return true;
        }
    }
    return false;
}


string NumberToText(int Number){

    if(Number == 0){

        return "";
    }

    if(Number >= 1 && Number <= 19){

        string arr[] = {"","one","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen",};

        return arr[Number] + " ";
    }

    if(Number >= 20 && Number <= 99){

        string arr[]{"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }


    if(Number >= 100 && Number <= 199){

        return "One Hundred " + NumberToText(Number % 100);

    }


    if(Number >= 200 && Number <= 999){

        return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        
    }

    if(Number >= 2000 && Number <= 999999){

        return NumberToText(Number / 1000) + "Thousands " +  NumberToText(Number % 1000);
        
    }

    if(Number >= 1000000 && Number <= 1999999){

        return "One Million " +  NumberToText(Number % 1000000);
        
    }

    if(Number >= 2000000 && Number <= 999999999){

        return NumberToText(Number / 1000000) + "Millions "+ NumberToText(Number % 1000000);
        
    }

    if(Number >= 1000000000 && Number <= 1999999999){

        return "One Billion " + NumberToText(Number % 1000000000);
        
    }else{

        return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number %1000000000);

    }

}


bool ChechYearLeapOrNot(int year){

   return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

short NumberOfDaysInAYear(short Year)
{
    return ChechYearLeapOrNot(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year){

    return NumberOfDaysInAYear(Year) * 24;
}

int NumberOfMinutesInAYear(short Year){

    return NumberOfHoursInAYear(Year) * 60;
}

int NumberOfSecondsInAYear(short Year){
    
    return NumberOfMinutesInAYear(Year) * 60;
}



short NumberOfDaysInAMonth(short Month,short Year){

    if(Month < 1 || Month > 12)
        return 0;
    
    if(Month == 2){

        return ChechYearLeapOrNot(Year) ? 29: 28;
    }

    short Arr31Days[7] = {1,3,5,7,8,10,12};

    for(short i = 1; i <= 7; i ++){

        if(Arr31Days[i - 1] == Month){
            
            return 31;
        }
    }
    
    return 30;
}


short NumberOfHoursInMonth(short month,short year){

    return  NumberOfDaysInAMonth(month,year) * 24;

}

int NumberOfMinutesInMonth(short month,short year){

    return NumberOfHoursInMonth(month,year) * 60;
}

int NumberOfSecondsInMonth(short month,short year){

    return NumberOfMinutesInMonth(month,year) * 60;
}


string MonthShortName(short MonthNumber)
{
    string months[12] = {"Jan", "Feb", "Mar",
                         "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep",
                         "Oct", "Nov", "Dec"};

    return months[MonthNumber - 1];
}

short NumberOfDaysInMonth(short month, short year)
{
    if (month < 1 || month > 12)
        return 0;  // invalid month

    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // If February, check leap year
    return (month == 2) ? (ChechYearLeapOrNot(year) ? 29 : 28)
                        : days[month - 1];
}


short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    // Adjust months so that March = 1 ... February = 12
    a = (14 - Month) / 12;

    y = Year - a;
    m = Month + (12 * a) - 2;

    // Zeller's formula
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}


short NumberOfDaysFromTheBeginingOfTheYear(short Day,short Month,short Year){

  short TotalDays = 0;


  for(short i = 1; i <= Month - 1; i++){

    TotalDays += NumberOfDaysInMonth(i,Year);
  }

  TotalDays += Day;

  return  TotalDays;
}





sDate GetDateFromDayOrderInYear(short TotalDays,short year){

  sDate Date;
  short remmainingdays = TotalDays;
  short monthDays = 0;

  Date.year = year;
  Date.month = 1;

  while (true)
  {
    monthDays = NumberOfDaysInMonth(Date.month , year);
    
    if(remmainingdays > monthDays){
      
      remmainingdays -= monthDays;
      Date.month++;
      
    }else{

      Date.day = remmainingdays;
      break;
    }
  }
  
  return Date;
}



bool IsDate1EqualToDate2(sDate Date1, sDate Date2){

  return (Date1.year == Date2.year) ?
   (Date1.month == Date2.month) ?
    (Date1.day == Date2.day)? true : false : false : false ;
        
}


bool IsDate1BeforeDate2(sDate Date1, sDate Date2){
  // Compare year - if Date1.year < Date2.year, return true
  return (Date1.year < Date2.year) ? true :
         // If Date1.year > Date2.year, return false
         (Date1.year > Date2.year) ? false:
         
         // Years are equal - compare months
         (Date1.month < Date2.month) ? true :
         // If Date1.month > Date2.month, return false
         (Date1.month > Date2.month) ? false:
         
         // Years and months are equal - compare days
         (Date1.day < Date2.day) ? true : false;
}

bool IsLastMonthInYear(short year){

  return(year == 12);
}



bool IsLastDayInMonth(sDate Date){
    return Date.day == 30 || Date.day == 31;
}

sDate IncreaseDateByOneDay(sDate Date){


    if(IsLastDayInMonth(Date)){

      if(IsLastMonthInYear(Date.month)){

        Date.day = 1;
        Date.month = 1;
        Date.year++;
      } else{

        Date.day = 1;
        Date.month++;
      }
      
    }else{
      
      Date.day++;
    }

    return Date;

}



sDate GetSystemDate(){
  sDate Date;

  time_t t = time(0);
  
  tm* now = localtime(&t);  // استخدم localtime بدلاً من locale

  Date.year = now->tm_year + 1900;
  Date.month = now->tm_mon + 1;
  Date.day = now->tm_mday;

  return Date;
}



bool IsDate1BeforeDate2(sDate Date1, sDate Date2){
  // Compare year - if Date1.year < Date2.year, return true
  return (Date1.year < Date2.year) ? true :
         // If Date1.year > Date2.year, return false
         (Date1.year > Date2.year) ? false:
         
         // Years are equal - compare months
         (Date1.month < Date2.month) ? true :
         // If Date1.month > Date2.month, return false
         (Date1.month > Date2.month) ? false:
         
         // Years and months are equal - compare days
         (Date1.day < Date2.day) ? true : false;
}


int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false){


  int Days = 0;
  short SwapFlag = 1;


  if(!IsDate1BeforeDate2(Date1,Date2)){

    SwapDates(Date1 , Date2);
    
    SwapFlag = -1;
  }


  while(IsDate1BeforeDate2(Date1,Date2)){

    Days++;
    
    Date1 = IncreaseDateByOneDay(Date1);

  }

  return IncludeEndDay ? ++Days * SwapFlag : Days * SwapFlag;
}



//Dates Functions


sDate IncreaseDateByOneDay(sDate Date){


    if(IsLastDayInMonth(Date)){

      if(IsLastMonthInYear(Date.month)){

        Date.day = 1;
        Date.month = 1;
        Date.year++;
      } else{

        Date.day = 1;
        Date.month++;
      }
      
    }else{
      
      Date.day++;
    }

    return Date;

}


sDate IncreaseDateByXDays(short Days, sDate Date){


  for(short i = 1; i <= Days; i++){
    
    Date = IncreaseDateByOneDay(Date);
  }
  
  return Date;
}


sDate IncreaseDateByOneWeek(sDate Date){

  for(int i = 1; i <= 7; i ++){

    Date = IncreaseDateByOneDay(Date);
  }


  return Date;
}


sDate IncreaseDateByXWeeks(short NumberOfWeeks, sDate Date){

  for(int i = 1; i <= NumberOfWeeks; i++){

    Date = IncreaseDateByOneWeek(Date);
  }

  return Date;
}


sDate IncreaseDateByOneMonth(sDate Date){

  if(Date.month == 12){

    Date.month = 1;
    Date.year ++;
  
  }else{
    
    Date.month++;
  }

  short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.month,Date.year);

  if(Date.day > NumberOfDaysInCurrentMonth){

    Date.day = NumberOfDaysInCurrentMonth;
  }

  return Date;
}


sDate IncreaseDateByXMonth(short NumberOfMonths, sDate Date){
  for(int i = 1; i <= NumberOfMonths; i++){
    Date = IncreaseDateByOneMonth(Date);
  }
  return Date;
}


sDate IncreaseDateByOneYear(sDate Date){

  Date.year++;
  
  return Date;
}


sDate IncreaseDateByXYear(short NumberOfYears, sDate Date){

  for(int i = 1; i <= NumberOfYears; i ++){

    Date = IncreaseDateByOneYear(Date);
  }

  return Date;
}


sDate IncreaseDateByXYearFaster(short NumberofYears, sDate Date){

  Date.year += NumberofYears;

  return Date;
}


sDate IncreaseDateByOneDecade(sDate Date){

  Date.year += 10;
  
  return Date;
}

sDate IncreaseDateByXDecades(short NumberOfDecades,sDate Date){

  for(int i = 1; i <= NumberOfDecades * 10; i ++){

    Date = IncreaseDateByOneYear(Date);
  }

  return Date;
}


sDate IncreaseDateByXDecadesFaster(short NumberOfDecades, sDate Date){

  Date.year += NumberOfDecades * 10;
  
  return Date;
}


sDate IncreaseDateByOneCentury(sDate Date){

  Date.year += 100;

  return Date;
}


bool IsWeekEnd(sDate Date){
    return false; // placeholder
}

bool IsBusinessDay(sDate Date){
    return true; // placeholder
}

sDate IncreaseDateByOneMillennium(sDate Date){

  Date.year += 1000;

  return Date;
}






sDate DecreaseDateByOneDay(sDate Date){

  if(Date.day == 1){

    if(Date.month == 1){
      
      Date.month = 12;
      Date.day = 31;
      Date.year--;
    
    }else{
      
      Date.month --;
      Date.day = NumberOfDaysInMonth(Date.month,Date.year);
    }
  
  }else{

    Date.day--;
  }
  
  return Date;

}


sDate DecreaseDateByXDays(short Days, sDate Date){


  for(short i = 1; i <= Days; i++){
    
    Date = DecreaseDateByOneDay(Date);
  }
  
  return Date;
}


sDate DecreaseDateByOneWeek(sDate Date){

  for(int i = 1; i <= 7; i ++){

    Date = DecreaseDateByOneDay(Date);
  }


  return Date;
}


sDate DecreaseDateByXWeeks(short NumberOfWeeks, sDate Date){

  for(int i = 1; i <= NumberOfWeeks; i++){

    Date = DecreaseDateByOneWeek(Date);
  }

  return Date;
}


sDate DecreaseDateByOneMonth(sDate Date){

  if(Date.month == 1){

    Date.month = 12;
    Date.year --;
  
  }else{
    
    Date.month--;
  }

  short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.month,Date.year);

  if(Date.day > NumberOfDaysInCurrentMonth){

    Date.day = NumberOfDaysInCurrentMonth;
  }

  return Date;
}


sDate DecreaseDateByXMonth(short NumberOfMonths, sDate Date){

  for(short i = 1; i <= NumberOfMonths; i++){

    Date = DecreaseDateByOneMonth(Date);
  
  }

  return Date;

}


sDate DecreaseDateByOneYear(sDate Date){

  Date.year--;
  
  return Date;
}


sDate DecreaseDateByXYear(short NumberOfYears, sDate Date){

  for(int i = 1; i <= NumberOfYears; i ++){

    Date = DecreaseDateByOneYear(Date);
  }

  return Date;
}


sDate DecreaseDateByXYearFaster(short NumberofYears, sDate Date){

  Date.year -= NumberofYears;

  return Date;
}


sDate DecreaseDateByOneDecade(sDate Date){

  Date.year -= 10;
  
  return Date;
}

sDate DecreaseDateByXDecades(short NumberOfDecades,sDate Date){

  for(int i = 1; i <= NumberOfDecades * 10; i ++){

    Date = DecreaseDateByOneYear(Date);
  }

  return Date;
}


sDate DecreaseDateByXDecadesFaster(short NumberOfDecades, sDate Date){

  Date.year -= NumberOfDecades * 10;
  
  return Date;
}


sDate DecreaseDateByOneCentury(sDate Date){

  Date.year -= 100;

  return Date;
}


sDate DecreaseDateByOneMillennium(sDate Date){

  Date.year -= 1000;

  return Date;
}




short DaysUntilTheEndOfWeek(sDate Date){

  return 6 - DayOfWeekOrder(Date.day, Date.month, Date.year);
}

short DaysUntilTheEndOfMonth(sDate Date){

  sDate EndOfMonth;

  EndOfMonth.day = NumberOfDaysInMonth(Date.month, Date.year);
  EndOfMonth.month = Date.month;
  EndOfMonth.year = Date.year;

  return GetDifferenceInDays(Date,EndOfMonth, true);
}


short DaysUntilTheEndOfYear(sDate Date){

  sDate EndOfYear;
  EndOfYear.day = 31;
  EndOfYear.month = 12;
  EndOfYear.year = Date.year;

  return GetDifferenceInDays(Date, EndOfYear, true);
}




short CalculateVacationDays(sDate DateFrom,sDate DateTo){

  short DaysCount = 0;

  while (IsDate1BeforeDate2(DateFrom, DateTo))
  {
      if(IsBusinessDay(DateFrom))
        DaysCount++;
      
      DateFrom = IncreaseDateByOneDay(DateFrom);
  }

  return DaysCount;
  
}

short ReadVacationDays(){

  short Days = 0;
  
  cout<<"\nPlease Enter Vacation Days: ";
  cin>> Days;

  return Days;
}


sDate CalculateVacationReturnDate(sDate DateFrom,short VacationDays){

  short WeekEndCounter = 0;

  while (IsWeekEnd(DateFrom))
  {
    DateFrom = IncreaseDateByOneDay(DateFrom);

  }

  for(short i = 1; i <= VacationDays + WeekEndCounter; i++){


      if(IsWeekEnd(DateFrom))
        WeekEndCounter++;
      
      DateFrom = IncreaseDateByOneDay(DateFrom);
  }

  while (IsWeekEnd(DateFrom))
  {
    DateFrom = IncreaseDateByOneDay(DateFrom);
  }
  
  return DateFrom;
  
}




enum enDateCompare {Before = -1, Equal = 0, After = 1};

enDateCompare CompareDates(sDate Date1, sDate Date2){

  if(IsDate1BeforeDate2(Date1 , Date2))
    return enDateCompare::Before;

  if(IsDate1EqualToDate2(Date1 , Date2))
    return enDateCompare::Equal;

  return enDateCompare::After;

}



bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2){

  if(CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before ||
  CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After
  )
  return false;

  else
    return true;
}




int PeriodLengthInDays(stPeriod Period, bool includeEndDate = false){

  return GetDifferenceInDays(Period.StartDate,Period.EndDate, includeEndDate);

}



/*
    ***************THE PROCEDURES FUNCTIONS***********************
*/


void StartGame(){


    char PlayAgain = 'y';

    do{

       // ResetScreen();
       // PlayMathGame();

        cout<<"Do You Want Play Again Y/N : ";
        cin>> PlayAgain;

    }while(PlayAgain == 'Y'|| PlayAgain == 'y');
}


void AllPerfectNumbersFrom1ToN(int Number){

	cout<<"\nAll Perfect Numbers From 1 To "<<Number<<endl;

	for(int i = 1; i <= Number; i ++){

		if(IsPerfectNumber(i)){
			
			cout<<i<<" ";
		}
	}
	cout<<endl;
}


    void PrintArray(int arr[100],int arrlength){

        for(int i = 0; i < arrlength; i++){

            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


    void ReadArray(int arr[100], int& length){


        cout<<"\nEnter Number Of Elements: ";
        cin>> length;

        cout<<"\nEnter Array Elements: \n";
        
        for(int i = 0; i < length; i ++){

            cout<<"Elements ["<<i + 1<<"]: ";
            cin>> arr[i];
        }
        cout<<endl;
    }

void PrintNumbersFromToN(int m, int n){
    // Based on recursive function

	if(m >= n){

		cout<< m << endl;
		PrintNumbersFromToN(m - 1, n);
	}
}

void PrintNumberInReversed(int Number){

	cout<<"\nThe Number "<<Number<<" In Reversed Order: "<<endl;
	while(Number > 0){

		int Digits = Number % 10;
		cout<<Digits<<endl;
		Number /= 10;
	}
}

void HelloWorld(){
    
    cout<<"\nHello World"<<endl;
}


void LoadDataFromFileTovector(string FileName, vector<string>& vFileContent){

    fstream Myfile;

    Myfile.open(FileName, ios::in | ios::out); // write and read mode;

    if(Myfile.is_open()){

        string line;

        while (getline(Myfile, line))
        {
            vFileContent.push_back(line);
        }
        
        Myfile.close();
    }
}



void SaveVectorToFile(string FileName, vector <string> vFileContent){


    ofstream Myfile;

    Myfile.open(FileName, ios:: out); // write and read mode
    
    if(Myfile.is_open()){

        
        for (string &line : vFileContent)
        {
            if( !line.empty()){
                
                Myfile << line <<endl;
            }
        }

        Myfile.close();
        
    }
}


void DeleteRecordFromFile(string FileName, string Record){

    vector <string> vFileContent;

    LoadDataFromFileTovector(FileName, vFileContent);

    for(string &line : vFileContent){

        if(line == Record){

            line = "";
        }
    }

    SaveVectorToFile(FileName,vFileContent);
}



void PrintFileConent(string FileName){

    fstream Myfile;

    Myfile.open(FileName, ios::out| ios::in); // write and read mode
    
    if(Myfile.is_open()){

        string line;

        while(getline(Myfile, line)){

            cout<<line<<endl;
        }

        Myfile.close();
    }
}


void ReadNumbers(vector <int> &vNumbers){

    char Y = 'y';
    int Number = 0;

    do{

        cout<<"Please Enter Number: ";
        cin>> Number;
        
        vNumbers.push_back(Number);

        cout<<"Do you Want To Add More Press y/n: ";
        cin>> Y;

    }while(Y == 'Y'|| Y == 'y');
}



void PrintVectorNumbers(vector <int> &vNumbers){

    for (int &Number : vNumbers){

        cout<<Number<<endl;
    }
}


    void PrintMatrix(int arr[3][3],int Rows, int cols){

        for(short i = 0; i < cols; i++){

            for(short j = 0; j < Rows; j++){

                printf(" %0*d   ",2,arr[i][j]);
               // cout<<setw(3)<< arr[i][j]<<"    ";
            }
            cout<<endl;
        }
    }


    void FillMatrixWithRandomNumbers(int Arr[3][3], int Rows, int Cols){

        for(short i = 0; i < Cols; i ++){

            for(short j = 0; j < Rows; j++){

                Arr[i][j] = RandomNumber(0,1);
            }
        }
        
    }


    void PrintIntersectedNumbers(int Matrix1[3][3],int Matrix2[3][3], int Rows, int Cols){

        int Number = 0;

        for(short i = 0; i < Cols; i ++){

            for(short j = 0; j < Rows; j++){

            Number = Matrix1[i][j];

            if(FindNumberInMatrix(Matrix2,Number,Rows,Cols)){
                
                cout<<setw(3)<< Number<<"    ";
            }
        }
        }
    }


    void PrintFibonacciusingLoop(short Number){

        int FebNumber = 0;
        int Prev2 = 0 , Prev1 = 1;
        cout<<"1  ";

        for(short i = 2; i <= Number; i++){

            FebNumber = Prev1 + Prev2;
            cout<<FebNumber <<"   ";
            Prev2 = Prev1;
            Prev1 = FebNumber;
        }
    }



    void PrintFibonacciusingRecursion(short Number, int Prev1, int Prev2){

        int FebNumber = 0;

        if (Number > 0){

            FebNumber = Prev1 + Prev2;
            Prev2 = Prev1;
            Prev1 = FebNumber;
            cout<<FebNumber<<"    ";

            PrintFibonacciusingRecursion(Number -1, Prev1 , Prev2);
        }
    }


     void PrintEachLetterofEeachWord(string Word){


        bool IsfirstLetter = true;

        for(short i = 0; i < Word.length(); i++){

            
            if(Word[i] != ' ' && IsfirstLetter){

                cout<<Word[i]<<endl;
            }

            IsfirstLetter = (Word[i] == ' ' ? true : false);
        }
    }


    void PrintEachWordInString(string Word){

        
        string delim = " ";
        cout<<"\nYour String Words Are: "<<endl;

        short Pos = 0;
        string sWord;

        while((Pos = Word.find(delim)) != std::string::npos){

            sWord = Word.substr(0,Pos);

            if(sWord != ""){
                
                cout<<sWord<<endl;
            }

            Word.erase(0,Pos + delim.length());
        }

        if(Word != ""){
            cout<<Word<<endl;
        }
    }


void PrintClientRecord(sClients Client){


    cout<<"\n\nThe Following is The extracted client record: \n";
    cout<<"\nAccount Number: "<< Client.AccountNumber<<endl;
    cout<<"\nAccount PinCode: "<< Client.PinCode<<endl;
    cout<<"\nAccount Name: "<< Client.Name<<endl;
    cout<<"\nAccount Phone: "<< Client.Phone<<endl;
    cout<<"\nAccount Balance: "<< Client.AccountBalance<<endl;
    
}



void PrintAllClientsData(vector<sClients> vClientsData){

    cout<<"\n\n\t\t\t Client List ("<<vClientsData.size()<<") Client(s)"<<endl;
    cout<<"_______________________________________________________________________________________________________________\n";
    cout<<"| "<<left<<setw(16)<<"Account Number ";
    cout<<"| "<<left<<setw(10)<<"Pin Code ";
    cout<<"| "<<left<<setw(30)<<"Account Name ";
    cout<<"| "<<left<<setw(16)<<"Phone ";
    cout<<"| "<<left<<setw(15)<<"Email ";
    cout<<"| "<<left<<setw(10)<<"Account Balance ";
    
    cout<<"\n_______________________________________________________________________________________________________________\n";
    
    for(sClients Client: vClientsData){

        PrintClientRecord(Client);
        cout<<endl;
    }
}



void PrintClientCard(sClients Client){

    cout<<"\nThe Following Are The Client Detailes: ";
    
    cout<<"\nAccount Number : "<< Client.AccountNumber;
    cout<<"\nPin Code : "<<Client.PinCode;
    cout<<"\nName : "<<Client.AccountName;
    cout<<"\nPhone : "<<Client.Phone;
    cout<<"\nEmail : "<<Client.Email;
    cout<<"\nAccount Balance: "<<Client.AccountBalance;
}



void PrintMonthCalendar(short month, short year)
{
    short current = DayOfWeekOrder(1, month, year);   // first weekday
    short NumberofDays = NumberOfDaysInMonth(month, year);

    cout << "\n\n";
    cout << "-----------------------------\n";
    cout << "        " << MonthShortName(month) << " " << year << "\n";
    cout << "-----------------------------\n";
    cout << " Sun Mon Tue Wed Thu Fri Sat\n";

    short i;

    // Print leading spaces before day 1
    for (i = 0; i < current; i++)
        cout << setw(4) << " ";

    // Print days of the month
    for (int day = 1; day <= NumberofDays; day++)
    {
        cout << setw(4) << day;

        // Move to next line after Saturday
        if (++i == 7)
        {
            i = 0;
            cout << "\n";
        }
    }

    cout << "\n-----------------------------\n";
}


void SwapDates(sDate& Date1, sDate& Date2){

  sDate TempDate;

  TempDate.day = Date1.day;
  TempDate.month = Date1.month;
  TempDate.year = Date1.year;

  Date1.day = Date2.day;
  Date1.month = Date2.month;
  Date1.year = Date2.year;

  Date2.day = TempDate.day;
  Date2.month = TempDate.month;
  Date2.year = TempDate.year;
}



}