#include "Calculator.h"
#include "Semantic.h"
#include "Syntax.h"

int main() {
    // First calculation
    Calculator calculator;
    calculator.SetInfixExpression("1 + 2 * 3");
    calculator.DisplayInfixExpression();
    //calculator.ConvertToPostfix();
    calculator.CheckError();
    calculator.DisplayPostfixExpression();
    //calculator.EvaluatePostfix();
    calculator.DisplayResult();

    // Check result
    if (calculator.getResult() != (1+2*3)) 
    {
        std::cout << "Test failed: Expected result is " << (1+2*3) << ", but got " << calculator.getResult() << std::endl;
        return 1;
    }

    // Second calculation - use the same calculator object
    calculator.SetInfixExpression("(1*3)+4*(5/3)*6");
    calculator.DisplayInfixExpression();
    //calculator.ConvertToPostfix();
    calculator.CheckError();
    calculator.DisplayPostfixExpression();
    //calculator.EvaluatePostfix();
    calculator.DisplayResult();

    // Check result
    if (calculator.getResult() != ((1.*3.)+4.*(5./3.)*6.)) 
    {
        std::cout << "Test failed: Expected result is " << ((1.*3.)+4.*(5./3.)*6.) << ", but got " << calculator.getResult() << std::endl;
        return 1;
    }

    // Second calculation - use the same calculator object

    // Checking for errors 
    // Empty expression
    calculator.SetInfixExpression("");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    
    // Unmatched parentheses
    calculator.SetInfixExpression("(1+2))*3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Invalid character
    calculator.SetInfixExpression("1 @ 2 + 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Adjacent operators
    calculator.SetInfixExpression("1 ++ 2");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Missing Operator
    calculator.SetInfixExpression("1 2 + 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Missing Operand
    calculator.SetInfixExpression("1 + * 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Valid expression
    calculator.SetInfixExpression("(1 + 2) * 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    //calculator.ConvertToPostfix();
    calculator.DisplayPostfixExpression();
    //calculator.EvaluatePostfix();
    calculator.DisplayResult();


    //Checkng Semantic errors
    calculator.SetInfixExpression("5 / 0");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    calculator.SetInfixExpression("999999999 * 999999999");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    calculator.SetInfixExpression("5 +");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    
    calculator.SetInfixExpression("5 $ 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    calculator.SetInfixExpression("2 * 3 + 4");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    calculator.SetInfixExpression("(5 * 2) / (3 - 3)");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    return 0;
}