#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;


class clsString{

    private:
    string _Value;

    public:
    
    clsString(){

        _Value = "";
    }

    clsString (string Value){

        _Value = Value;
    }
    
    void SetValue(string Value){

        _Value = Value;
    }

    string GetValue(){

        return _Value;
    }

   // ==================== String Functions ====================

   static short CountWords(string S1){

    string delim = " ";
    short Counter = 0;
    size_t pos = 0;
    string sword;

    while((pos = S1.find(delim)) != std::string::npos){

        sword = S1.substr(0,pos);

        if(sword !=""){

            Counter ++;
        }

        S1.erase(0, pos + delim.length());
    }

    if(S1 !=""){

        Counter++;
    }
    return Counter;
   }

    short CountWords(){

        return CountWords(_Value);
}

   static string UpperFirstLetterOfEachWord(string Word)
    {
        bool IsFirstLetter = true;
        for (size_t i = 0; i < Word.length(); i++)
        {
            if (Word[i] != ' ' && IsFirstLetter)
                Word[i] = toupper(Word[i]);
            IsFirstLetter = (Word[i] == ' ' ? true : false);
        }
        return Word;
    }

    string UpperFirstLetterOfEachWord(){

        return UpperFirstLetterOfEachWord(_Value);
    }

    static string LowerFirstLetterOfEachWord(string Word)
    {
        bool IsFirstLetter = true;
        for (size_t i = 0; i < Word.length(); i++)
        {
            if (Word[i] != ' ' && IsFirstLetter)
                Word[i] = tolower(Word[i]);
            IsFirstLetter = (Word[i] == ' ' ? true : false);
        }
        return Word;
    }

    string LowerFirstLetterOfEachWord(){

        return LowerFirstLetterOfEachWord(_Value);
    }

    static string ConvertAllToUpper(string Word)
    {
        for (size_t i = 0; i < Word.length(); i++)
            Word[i] = toupper(Word[i]);
        return Word;
    }

    string ConvertAllToUpper(){

        return ConvertAllToUpper(_Value);
    }

    static string ConvertAllToLower(string Word)
    {
        for (size_t i = 0; i < Word.length(); i++)
            Word[i] = tolower(Word[i]);
        return Word;
    }

    string ConvertAllToLower(){

        return ConvertAllToLower(_Value);
    }

    static string InvertAllLettersCase(string Word)
    {
        for (size_t i = 0; i < Word.length(); i++)
        {
            if (islower(Word[i]))
                Word[i] = toupper(Word[i]);
            else
                Word[i] = tolower(Word[i]);
        }
        return Word;
    }

    string InvertAllLettersCase(){

        return InvertAllLettersCase(_Value);
    }

    static short GetLengthOfString(const string& Word)
    {
        return Word.length();
    }

    short GetLengthOfString(){

        return GetLengthOfString(_Value);
    }

    static short CountSmallLetters(const string& Word)
    {
        short count = 0;
        for (char c : Word)
            if (islower(c)) count++;
        return count;
    }
    
    short CountSmallLetters(){

        return CountSmallLetters(_Value);
    }

    static bool IsVowel(char C)
    {
        C = tolower(C);
        return (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u');
    }

    static short CountVowels(const string& Word)
    {
        short Count = 0;
        for (char c : Word)
            if (IsVowel(c)) Count++;
        return Count;
    }

    short CountVowels(){
        
        return CountVowels(_Value);
    }
    
    static void PrintVowels(const string& Word)
    {
        for (char c : Word)
            if (IsVowel(c)) cout << c << " ";
        cout << endl;
    }
    
     void PrintVowels(){

        return PrintVowels(_Value);
     }

     static vector<string> SplitString(const string& s1, const string& Delim = " ")
    {
        vector<string> Vstring;
        size_t pos = 0;
        string sWord;
        string temp = s1;

        while ((pos = temp.find(Delim)) != string::npos)
        {
            sWord = temp.substr(0, pos);
            if (sWord != "") Vstring.push_back(sWord);
            temp.erase(0, pos + Delim.length());
        }
        if (temp != "") Vstring.push_back(temp);

        return Vstring;
    }

    static string TrimLeft(string S1)
    {
        for (size_t i = 0; i < S1.length(); i++)
            if (S1[i] != ' ')
                return S1.substr(i);
        return "";
    }

    string TrimLeft(){

        return TrimLeft(_Value);
    }


    static string TrimRight(string S1)
    {
        for (short i = S1.length() - 1; i >= 0; i--)
            if (S1[i] != ' ')
                return S1.substr(0, i + 1);
        return "";
    }

    string TrimRight(){

        return TrimRight(_Value);
    }
    
    static string Trim(const string& S1)
    {
        return TrimLeft(TrimRight(S1));
    }

    string Trim(){

        return TrimLeft(TrimRight(_Value));
    }

    static string RemovePunctuations(const string& S1)
    {
        string S2 = "";
        for (char c : S1)
            if (!ispunct(c)) S2 += c;
        return S2;
    }

    string RemovePunctuations(){

        return RemovePunctuations(_Value);
    }

    static string ReplaceWord(const string& S1, const string& StringToReplace, const string& ReplaceTo)
    {
        string S = S1;
        size_t pos = 0;
        while ((pos = S.find(StringToReplace, pos)) != string::npos)
        {
            S.replace(pos, StringToReplace.length(), ReplaceTo);
            pos += ReplaceTo.length();
        }
        return S;
    }

    void Print(){

        cout<<_Value<<endl;
    }

};