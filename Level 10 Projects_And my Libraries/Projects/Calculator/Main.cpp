#include <iostream>
using namespace std;

// Calculator class that performs basic arithmetic operations
class clsCalculator
{
private:

    // Stores the current result
    float _Result = 0;

    // Stores the last number used in an operation
    float _LastNumber = 0;

    // Stores the last operation performed
    string _LastOperation = "Clear";

    // Stores the previous result to support undo functionality
    float _PreviousResult = 0;

    // Helper method to check if a number is zero
    bool _IsZero(float Number)
    {
        return (Number == 0);
    }

public:

    // Adds a number to the current result
    void Add(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Adding";

        _Result += Number;
    }

    // Subtracts a number from the current result
    void Subtract(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Subtracting";

        _Result -= Number;
    }

    // Divides the current result by a number
    void Divide(float Number)
    {
        _LastNumber = Number;

        // Prevent division by zero
        if (_IsZero(Number))
            Number = 1;

        _PreviousResult = _Result;
        _LastOperation = "Dividing";

        _Result /= Number;
    }

    // Multiplies the current result by a number
    void Multiply(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Multiplying";

        _Result *= Number;
    }

    // Returns the current result
    float GetFinalResult()
    {
        return _Result;
    }

    // Resets the calculator to its initial state
    void Clear()
    {
        _Result = 0;
        _LastNumber = 0;
        _PreviousResult = 0;
        _LastOperation = "Clear";
    }

    // Reverts the calculator to the previous result
    void CancelLastOperation()
    {
        _Result = _PreviousResult;
        _LastNumber = 0;
        _LastOperation = "Cancelling Last Operation";
    }

    // Displays information about the latest operation
    void PrintResult()
    {
        cout << "Result after "
             << _LastOperation
             << " "
             << _LastNumber
             << " is: "
             << _Result
             << endl;
    }
};

int main()
{
    clsCalculator Calculator1;

    Calculator1.Clear();

    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Add(100);
    Calculator1.PrintResult();

    Calculator1.Subtract(20);
    Calculator1.PrintResult();

    Calculator1.Divide(0);
    Calculator1.PrintResult();

    Calculator1.Divide(2);
    Calculator1.PrintResult();

    Calculator1.Multiply(3);
    Calculator1.PrintResult();

    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();

    return 0;
}
