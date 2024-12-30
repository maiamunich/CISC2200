#include "Calculator.h"
#include "Semantic.h"
#include "Syntax.h"
using namespace std;

int main() {
    // Creating a calculator object
    Calculator calculator;

   // First calculation
    std::cout << "First calculation" << std::endl;
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
    std::cout << "Second calculation" << std::endl;
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

    // Third calculation
    std::cout << "Third calculation" << std::endl;
    calculator.SetInfixExpression("(6 + 13) * 2 - (5 + 1) / 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    //calculator.ConvertToPostfix();
    calculator.DisplayPostfixExpression();
    //calculator.EvaluatePostfix();
    calculator.DisplayResult();

    // Checking for errors --------------------------------

    // Syntax errors --------------------------------

    // Empty expression
    std::cout << "Empty expression" << std::endl;
    calculator.SetInfixExpression("");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    
    // Unmatched parentheses
    std::cout << "Unmatched parentheses" << std::endl;
    calculator.SetInfixExpression("(1+2))*3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Invalid character
    std::cout << "Invalid character" << std::endl;
    calculator.SetInfixExpression("1 @ 2 + 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Adjacent operators
    std::cout << "Adjacent operators" << std::endl;
    calculator.SetInfixExpression("1 ++ 2");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Missing Operator
    std::cout << "Missing Operator" << std::endl;
    calculator.SetInfixExpression("1 2 + 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Missing Operand
    std::cout << "Missing Operand" << std::endl;
    calculator.SetInfixExpression("1 + * 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Invalid operator
    std::cout << "Invalid operator" << std::endl;
    calculator.SetInfixExpression("2 * 3 % 4");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Invalid character
    std::cout << "Invalid character" << std::endl;
    calculator.SetInfixExpression("{(2 * 3) / 4}");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    //Checkng Semantic errors --------------------------------

    // Division by zero
    std::cout << "Division by zero" << std::endl;
    calculator.SetInfixExpression("5 / 0");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Arithmetic overflow
    std::cout << "Arithmetic overflow" << std::endl;
    calculator.SetInfixExpression("999999999 * 999999999");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Undefined operation
    std::cout << "Undefined operation" << std::endl;
    calculator.SetInfixExpression("5 +");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Invalid operand
    std::cout << "Invalid operand" << std::endl;
    calculator.SetInfixExpression("5 $ 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Missing operand
    std::cout << "Missing operand" << std::endl;
    calculator.SetInfixExpression("2 * x + 4");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Division by zero
    std::cout << "Division by zero" << std::endl;
    calculator.SetInfixExpression("(5 * 2) / (3 - 3)");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    return 0;
}