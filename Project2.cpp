#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
/*#include "windows.h"
#include "winioctl.h"
*/

using namespace std;


enum enQuestionsLevel {EasyLevel = 1,MedLevel = 2,HardLevel = 3, Mix = 4};
enum enOperationType {Add = 1,Sub = 2,Mult = 3,Div = 4,MixOp = 5};

string GetOpTypeSumbol(enOperationType OpType){


	switch(OpType){

    	case enOperationType::Add:
    	return "+";
    	break;

    	case enOperationType::Sub:
        	return "-";
    	break;

    	case enOperationType::Mult:
        	return "X";
    	break;

    	case enOperationType::Div:
        	return "/";
    	break;

    	default:
        	return "Mix";

	}
}


string GetQuestionLevelText(enQuestionsLevel QuestionLevel){

	string arr[4] = {"Easy","Med","Hard","Mix"};

	return arr[QuestionLevel - 1];
}

int RandomNumber(int From,int To){

	int RandNum = rand() % (To - From + 1) + From;
}

void SetScreenColor(bool Right){

	if(Right){

    	system("color 2F");
	}else{
    	system("color 4F");
    	cout<<"\a";
	}

}

short ReadHowManyQuestions(){

	short Questions = 0;

	do{

    	cout<<"How Many Questions Do You Want To Answer: ";
    	cin>> Questions;

	}while(Questions < 1 || Questions > 10);

	return Questions;
}

enQuestionsLevel ReadQuestionsLevel(){

	short Level = 0;

	do{

    	cout<<"Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix: ";
    	cin>> Level;

	}while(Level < 1 || Level > 4);

	return (enQuestionsLevel)Level;
}

enOperationType ReadOpType(){


	short OpType;

	do{

    	cout<<"Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix: ";
    	cin>> OpType;

	}while(OpType < 1 || OpType > 5);

	return (enOperationType)OpType;
}

struct stQuestion{

	int Number1 = 0;
	int Number2 = 0;
	enOperationType OperationType;
	enQuestionsLevel QuestionLevel;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;

};

struct stQuizz{

stQuestion QuestionList[100];
short NumberOfQuestions;
enQuestionsLevel QuestionsLevel;
enOperationType OpType;
short NumberOFWrongAnswers = 0;
short NumberOfRightAnswers = 0;
bool isPass= false;

};


int SimpleCalculator(int Number1, int Number2, enOperationType OpType){

	switch(OpType){

	case enOperationType::Add:
    	return Number1 + Number2;

	case enOperationType::Sub:
    	return Number1 - Number2;

	case enOperationType::Mult:
    	return Number1 * Number2;

	case enOperationType::Div:
    	return Number1 / Number2;

	default:
    	return Number1 + Number2;

	}
}

enOperationType GetRandomOperationType(){

	int Op = RandomNumber(1,4);

	return (enOperationType)Op;
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel,enOperationType OpType){

	stQuestion Question;

	if(QuestionLevel == enQuestionsLevel::Mix){

    	QuestionLevel = (enQuestionsLevel) RandomNumber(1,3);
	}

	if(OpType == enOperationType::MixOp){

    	OpType = GetRandomOperationType();
	}


	Question.OperationType = OpType;

	switch(QuestionLevel){

    	case enQuestionsLevel::EasyLevel:
        	Question.Number1 = RandomNumber(1,10);
        	Question.Number2 = RandomNumber(1,10);

        	Question.CorrectAnswer = SimpleCalculator(Question.Number1,Question.Number2,Question.OperationType);

        	Question.QuestionLevel = QuestionLevel;
        	return Question;

    	case enQuestionsLevel::MedLevel:
        	Question.Number1 = RandomNumber(10,50);
        	Question.Number2 = RandomNumber(10,50);

        	Question.CorrectAnswer = SimpleCalculator(Question.Number1,Question.Number2,Question.OperationType);

        	Question.QuestionLevel = QuestionLevel;

        	return Question;

    	case enQuestionsLevel::HardLevel:
        	Question.Number1 = RandomNumber(50,100);
        	Question.Number2 = RandomNumber(50,100);

        	Question.CorrectAnswer = SimpleCalculator(Question.Number1,Question.Number2,Question.OperationType);

        	Question.QuestionLevel = QuestionLevel;

	}

	return Question;

}

void GenerateQuizz(stQuizz& Quizz){

	for(short Question = 0; Question < Quizz.NumberOfQuestions; Question++){


    	Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel,Quizz.OpType);
	}

}

int ReadQuestionAnswer(){


	int Answer = 0;

	cin>> Answer;

	return  Answer;
}

void PrintTheQuestion(stQuizz& Quizz,short QuesionNumber){


	cout<<"\n";
	cout<<"Question ["<<QuesionNumber + 1<<" / "<< Quizz.NumberOfQuestions<<" ] \n\n";

	cout<<Quizz.QuestionList[QuesionNumber].Number1<<endl;

	cout<<Quizz.QuestionList[QuesionNumber].Number2<<" ";

	GetOpTypeSumbol(Quizz.QuestionList[QuesionNumber].OperationType);
	cout<<"\n______________"<<endl;

}


void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber){

	if(Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer){



    	Quizz.QuestionList[QuestionNumber].AnswerResult = false;
    	Quizz.NumberOFWrongAnswers++;

    	cout<<"Wrong Answer :-(\n";
    	cout<<"The Right Answer Is: ";
    	cout<<Quizz.QuestionList[QuestionNumber].CorrectAnswer;
    	cout<<"\n";

	}

	else {

    	Quizz.QuestionList[QuestionNumber].AnswerResult = true;
    	Quizz.NumberOfRightAnswers++;

    	cout<<"Right Answer :-) \n";
	}
	cout<<endl;

	SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);

}


void AskAndCorrectQuestionListAnswers(stQuizz& Quizz){


	for(short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++){


	PrintTheQuestion(Quizz,QuestionNumber);

	Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

	CorrectTheQuestionAnswer(Quizz,QuestionNumber);

	}

	Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOFWrongAnswers);
}


string GetFinalResultsText(bool Pass){

	if(Pass)
    	return "PASS :-)";
	else
    	return "Fail :-(";
}


void PrintQuizzResults(stQuizz Quizz){

	cout<<"\n";
	cout<<"____________________\n\n";

	cout<<" Final Results is: "<< GetFinalResultsText(Quizz.isPass);
	cout<<"\n_____________________________\n\n";

	cout<<"Number Of Questions: "<<Quizz.NumberOfQuestions<<endl;

	cout<<"Questions Level   	: "<<GetOpTypeSumbol(Quizz.OpType)<<endl;

	cout<<"Numeber Of Right Answers: "<<Quizz.NumberOfRightAnswers<<endl;

	cout<<"Numeber Of Wrong Answers: "<<Quizz.NumberOFWrongAnswers<<endl;

	cout<<"________________________________\n";

}


void PlayMathGame(){


stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionsLevel = ReadQuestionsLevel();
	Quizz.OpType = ReadOpType();


	GenerateQuizz(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizzResults(Quizz);

}



void ResetScreen(){

	system("cls");
	system("color 0F");
}

void StartGame(){

	char playAgain = 'Y';

	do{

    	ResetScreen();
    	PlayMathGame();

    	cout<<endl<<"Do you want to play again? Y/N: ";
    	cin>> playAgain;

	}while(playAgain == 'y' || playAgain == 'Y');
}

int main(){


srand((unsigned) time(NULL));

StartGame();


}