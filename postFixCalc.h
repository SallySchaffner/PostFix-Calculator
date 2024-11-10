#ifndef PFCALC_H
#define PFCALC_H

//#include "myStack.h"
#include <string>
#include <stack>

using namespace std;

class postFixCalc
{
public:
    void setPostFixExp(string);
    // Precondition - postfix expression string is provided
    // Postcondition - String is stored in class
    string getPostFixExp();
    // Postcondition - Returns the expression string
    void evaluate();
    // Precondition - Assumes the expression has been stored in the class
    // Postcondition - The expression has been has been evaluated 
    // and the result is stored on the stack
    void evaluateOpr(char)
        /*throw (TooFewOperandsException,
            DivisionByZeroException,
            IllegalOperatorException)*/;
    // Precondition - The operator character is provided
    // Postcondition - the top two numbers on the stack are evaluated 
    // and the result is stored back on the stack, exceptions are thrown 
    // if the specified error conditions are detected
    double getResult(); //throw (TooManyOperandsException, ErrorinExpressionException);
    // Precondition - The expression has been evaluated and 
    // the result is the only item in the stack
    // Postcondition - the result is returned, exceptions are thrown if the
    // specified error conditions are detected

  // Exception classes
    class TooFewOperandsException
    {
    public:
        TooFewOperandsException() { message = "Not enough operands "; }
        string what() { return message; }
    private:
        string message;
    };

    class DivisionByZeroException
    {
    public:
        DivisionByZeroException() { message = "Division by 0"; }
        string what() { return message; }
    private:
        string message;
    };

    class IllegalOperatorException
    {
    public:
        IllegalOperatorException() { message = "Illegal operator"; }
        string what() { return message; }
    private:
        string message;
    };

    class TooManyOperandsException
    {
    public:
        TooManyOperandsException() { message = "Too many operands"; }
        string what() { return message; }
    private:
        string message;
    };

    class ErrorinExpressionException
    {
    public:
        ErrorinExpressionException() { message = "Error in expression"; }
        string what() { return message; }
    private:
        string message;
    };

private:
    string pFexp;
    stack<double> resultStack;
    char* expression;

};


#endif