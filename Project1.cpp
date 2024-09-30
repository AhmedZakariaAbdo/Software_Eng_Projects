#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include "windows.h"
#include "winioctl.h"

using namespace std;


enum enGameChoice {Stone = 1, Paper = 2, Scissors = 3};
enum enWinner {Player1 = 1, Computer = 2, Draw = 3};


struct stRoundInfo{

	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults{

	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

int RandomNumber(int From, int To){

	int RandNum = rand() % (To - From + 1)+ From;
	return RandNum;
}


string WinnerName (enWinner Winner){

	string arrWinnerName[3] = {"Player1","Computer","No Winner"};

	return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo){

	if(RoundInfo.Player1Choice == RoundInfo.ComputerChoice){

    	return enWinner::Draw;
	}

	switch(RoundInfo.Player1Choice){

    	case enGameChoice::Stone:
    	if(RoundInfo.ComputerChoice == enGameChoice::Paper){

        	return enWinner::Computer;
    	}
    	break;

    	case enGameChoice::Paper:
    	if(RoundInfo.ComputerChoice == enGameChoice::Scissors){

        	return enWinner::Computer;
    	}
    	break;

    	case enGameChoice::Scissors:
    	if(RoundInfo.ComputerChoice == enGameChoice::Stone){
        	return enWinner::Computer;
    	}
    	break;
	}

	return enWinner::Player1;
}


string ChoiceName(enGameChoice Choice){

	string arrGameChoices[3] = {"Stone","Paper","Scissors"};

	return arrGameChoices[Choice - 1];
}



void SetWinnerScreenColor(enWinner Winner){


switch(Winner){

	case enWinner::Player1:
	system("color 2F"); // turn screen to Green
	break;

	case enWinner::Computer:
	system("color 4F"); // turn Screen To red
	cout<<"\a";
	break;

	case enWinner::Draw:
	system("color 6F"); // turn Screen To Yellow
	break;
} // end the switch

} // end the SetWinnerScreenColor function



void PrintRoundResults(stRoundInfo RoundInfo){

	cout<<"\n______________Round ["<<RoundInfo.RoundNumber<<"]__________\n\n";

	cout<<"Player1 Choice: "<<ChoiceName(RoundInfo.Player1Choice) <<endl;
	cout<<"Computer Choice: "<<ChoiceName(RoundInfo.ComputerChoice) <<endl;
	cout<<"Round Winner   :["<<RoundInfo.WinnerName<< "] \n";
	cout<<"\n_________________________________________\n"<<endl;

	SetWinnerScreenColor(RoundInfo.Winner);

} // End PrintRoundResults function


enWinner WhoWonTheGame(short Player1WinTimes,short ComputerWinTimes){

	if(Player1WinTimes > ComputerWinTimes)
    	return enWinner::Player1;

	else if(ComputerWinTimes > Player1WinTimes)
    	return enWinner::Computer;

	else
    	return enWinner::Draw;

}// End WhoWonTheGame Function


stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes){

	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.Computer2WinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes,ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);


	return GameResults;


}// End The FillGameResults Function;


enGameChoice ReadPlayer1Choice(){

	short Choice = 1;

	do{

    	cout<<"\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
    	cin >> Choice;

	}while(Choice < 1 || Choice > 3);

	return (enGameChoice)Choice;

} // End  ReadPlayer1Choice function


enGameChoice GetComputerChoice(){

	return (enGameChoice)RandomNumber(1,3);
}// End GetComputerChoice function




stGameResults PlayGame(short HowManyRounds){

	stRoundInfo RoundInfo;

	short Player1WinTimes = 0 , ComputerWinTimes = 0, DrawTimes = 0;

	for(short GameRound = 1 ; GameRound <= HowManyRounds; GameRound ++){


    	cout<<"\nRound ["<<GameRound<<"] begins:\n";
    	RoundInfo.RoundNumber = GameRound;
    	RoundInfo.Player1Choice = ReadPlayer1Choice();
    	RoundInfo.ComputerChoice = GetComputerChoice();
    	RoundInfo.Winner = WhoWonTheRound(RoundInfo);
    	RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);


    	// increase win/draw counters

    	if(RoundInfo.Winner == enWinner::Player1)
        	Player1WinTimes++;
    	else if(RoundInfo.Winner == enWinner::Computer)
         	ComputerWinTimes++;
    	else
        	DrawTimes++;

    	PrintRoundResults(RoundInfo);
	}

	return FillGameResults(HowManyRounds,Player1WinTimes,ComputerWinTimes,DrawTimes);

} // End PlayGame Function


string Tabs(short NumberOfTabs){

	string t = "";

	for (int i = 1; i <NumberOfTabs; i ++){

    	t = t + "\t";
    	cout<< t;
	}

	return t;
} // End Tabs Function


void ShowGameOverScreen(){

	cout<<Tabs(2)<<"________________________________\n\n";
	cout<<Tabs(2)<<"                	+++Game Over +++\n";
	cout<<Tabs(2)<<"________________________________\n\n";

} // end ShowGameOverScreen Function


void ShowFinalGameResults(stGameResults GameResults){

	cout<<Tabs(2)<<"____________[Game Results______________]\n\n";
	cout<<Tabs(2)<<"Game Rounds         	: "<<GameResults.GameRounds<<endl;
	cout<<Tabs(2)<<"Player1 Won Times   	: "<<GameResults.Player1WinTimes<<endl;
	cout<<Tabs(2)<<"Computer Won Times  	: "<<GameResults.Computer2WinTimes<<endl;
	cout<<Tabs(2)<<"Draw Times          	: "<<GameResults.DrawTimes<<endl;
	cout<<Tabs(2)<<"Final Winner        	: "<<GameResults.WinnerName<<endl;
	cout<<Tabs(2)<<"________________________________________\n";
	SetWinnerScreenColor(GameResults.GameWinner);


}// End ShowFinalGameResults Function


short ReadHowManyRounds(){

	short GameRounds = 1;

	do{

    	cout<<"How Many Rounds 1 To 10 ? \n";
    	cin>>GameRounds;

	}while(GameRounds < 1 || GameRounds > 10);

	return GameRounds;
}// End ReadHowManyRounds Function


void ResetScreen(){

	system("cls");
	system("color 0f");
} // ResetScreen Function


void StartGame(){

	char PlayAgain = 'Y';

	do{

    	ResetScreen();
    	stGameResults GameResults = PlayGame(ReadHowManyRounds());
    	ShowGameOverScreen();
    	ShowFinalGameResults(GameResults);

    	cout<<endl <<Tabs(3)<<"Do you want to play again? Y/N: ";
    	cin>>PlayAgain;

	}while(PlayAgain == 'Y' || PlayAgain == 'y');

}//end StartGame Function

int main(){

srand((unsigned) time(NULL));

StartGame();

	return 0;
}