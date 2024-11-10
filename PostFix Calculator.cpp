//***********************************************************
// Author: D.S. Malik and S.K. Schaffner
//
// Program: Postfix Calculator
// This program evaluates postfix expressions.
//***********************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include "postFixCalc.h"

using namespace std;

int main()
{
    ifstream infile;
    ofstream outfile;
    string expression;

    infile.open("RpnData.txt");
    if (!infile)
    {
        cout << "Cannot open the input file. "
            << "Program terminates!" << endl;
        return 1;
    }
    outfile.open("RpnOutput.txt");
    outfile << fixed << showpoint;
    outfile << setprecision(2);

    postFixCalc calculator;
    //double result;
    getline(infile, expression);

    while (infile)
    {
        calculator.setPostFixExp(expression);
        outfile << "--------------------------------------------\n";
        outfile << expression << " = ";
        try
        {
            calculator.evaluate();
        }
        catch (postFixCalc::TooFewOperandsException e)
        {
            outfile << e.what() << endl;
        }
        catch (postFixCalc::DivisionByZeroException e)
        {
            outfile << e.what() << endl;
        }
        catch (postFixCalc::IllegalOperatorException e)
        {
            outfile << e.what() << endl;
        }
        try
        {
            outfile << calculator.getResult() << endl;
        }
        catch (postFixCalc::TooManyOperandsException e)
        {
            outfile << e.what() << endl;
        }
        catch (postFixCalc::ErrorinExpressionException e)
        {
            outfile << e.what() << endl;
        }

        getline(infile, expression);
    }

    infile.close();
    outfile.close();
    return 0;
}

