
#include <cstring>
#include "postFixCalc.h"
#include <string>

#pragma warning(disable : 4996)

using namespace std;

void postFixCalc::setPostFixExp(string exp)
{
    pFexp = exp;
}

string postFixCalc::getPostFixExp()
{
    return pFexp;
}

void postFixCalc::evaluate()
{
    double num;
    char opr = '#';
    char* token;
    char delim[] = " ";
    expression = new char[pFexp.length() + 1];
    strcpy(expression, pFexp.c_str());
    token = strtok(expression, delim);
    do
    {
        if (isdigit(token[0]))
        {
            num = stof(token);
            resultStack.push(num);
        }
        else
        {
            opr = token[0];
            evaluateOpr(opr);
        }
        opr = '#';
    } while ((token = strtok(NULL, delim)) != NULL);
    delete expression;
}


void postFixCalc::evaluateOpr(char ch) throw (TooFewOperandsException, DivisionByZeroException, IllegalOperatorException)
{
    double op1, op2;

    if (resultStack.empty())
    {
        throw TooFewOperandsException();
    }
    else
    {
        op2 = resultStack.top();
        resultStack.pop();

        if (resultStack.empty())
        {
            throw TooFewOperandsException();
        }
        else
        {
            op1 = resultStack.top();
            resultStack.pop();

            switch (ch)
            {
            case '+':
                resultStack.push(op1 + op2);
                break;
            case '-':
                resultStack.push(op1 - op2);
                break;
            case '*':
                resultStack.push(op1 * op2);
                break;
            case '/':
                if (op2 != 0)
                    resultStack.push(op1 / op2);
                else
                {
                    while (!resultStack.empty())
                        resultStack.pop();
                    throw DivisionByZeroException();
                }
                break;
            default:
                while (!resultStack.empty())
                    resultStack.pop();
                throw IllegalOperatorException();
            }
        }
    }
}

double postFixCalc::getResult() throw (TooManyOperandsException, ErrorinExpressionException)
{
    double result;

    if (!resultStack.empty())
    {
        result = resultStack.top();
        resultStack.pop();

        if (resultStack.empty())
            return result;
        else
            while (!resultStack.empty())
                resultStack.pop();
        throw TooManyOperandsException();
    }
    else
    {
        while (!resultStack.empty())
            resultStack.pop();
        throw ErrorinExpressionException();
    }
}
