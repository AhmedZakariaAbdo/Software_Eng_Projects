#pragma once
#include <iostream>
#include <limits> // include this for numeric_limits
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


namespace MyLib{

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

    int RandNum = rand() % (to - from + 1) + to;

    return RandNum;
}



int TimesRepeated(int Number, int Arr[100], int Length){

    int count = 0;
    
    for(int i = 0; i <= Length; i ++){

        if(Number == Arr[i])
            count ++;
    }
    return count;
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




}