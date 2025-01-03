#include "Calculator.h"
#include "Semantic.h"
#include "Syntax.h"
#include <limits>
using namespace std;

int main() {
    // Creating a calculator object
    Calculator calculator;

   // First calculation
    std::cout << "First calculation --------------------------------" << std::endl;
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

   // First calculation
    std::cout << "First-half calculation --------------------------------" << std::endl;
    calculator.SetInfixExpression("10 + 2 * 3");
    calculator.DisplayInfixExpression();
    //calculator.ConvertToPostfix();
    calculator.CheckError();
    calculator.DisplayPostfixExpression();
    //calculator.EvaluatePostfix();
    calculator.DisplayResult();

    // Check result
    if (calculator.getResult() != (10+2*3)) 
    {
        std::cout << "Test failed: Expected result is " << (10+2*3) << ", but got " << calculator.getResult() << std::endl;
        return 1;
    }

    // Second calculation - use the same calculator object
    std::cout << std::endl << "Second calculation --------------------------------" << std::endl;
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
    std::cout << std::endl << "Third calculation --------------------------------" << std::endl;
    calculator.SetInfixExpression("(6 + 13) * 2 - (5 + 1) / 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    //calculator.ConvertToPostfix();
    calculator.DisplayPostfixExpression();
    //calculator.EvaluatePostfix();
    calculator.DisplayResult();

    // Check result
    if (calculator.getResult() != ((6+13)*2-(5+1)/3)) 
    {
        std::cout << "Test failed: Expected result is " << ((6+13)*2-(5+1)/3) << ", but got " << calculator.getResult() << std::endl;
        return 1;
    }
    // Checking for errors --------------------------------

    // Syntax errors --------------------------------

    // Empty expression
    std::cout << std::endl << "Empty expression --------------------------------" << std::endl;
    calculator.SetInfixExpression("");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    
    // Unmatched parentheses
    std::cout << std::endl << "Unmatched parentheses --------------------------------" << std::endl;
    calculator.SetInfixExpression("(1+2))*3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Invalid character
    std::cout << std::endl << "Invalid character --------------------------------" << std::endl;
    calculator.SetInfixExpression("1 @ 2 + 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Adjacent operators
    std::cout << std::endl << "Adjacent operators --------------------------------" << std::endl;
    calculator.SetInfixExpression("1 ++ 2");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Missing Operator
    std::cout << std::endl << "Missing Operator --------------------------------" << std::endl;
    calculator.SetInfixExpression("1 2 + 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Missing Operand
    std::cout << std::endl << "Missing Operand --------------------------------" << std::endl;
    calculator.SetInfixExpression("1 + * 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Invalid operator
    std::cout << std::endl << "Invalid operator --------------------------------" << std::endl;
    calculator.SetInfixExpression("2 * 3 % 4");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Invalid character
    std::cout << std::endl << "Invalid character --------------------------------" << std::endl;
    calculator.SetInfixExpression("{(2 * 3) / 4}");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    //Checkng Semantic errors --------------------------------

    // Division by zero
    std::cout << std::endl << "Division by zero --------------------------------" << std::endl;
    calculator.SetInfixExpression("5 / 0");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Arithmetic overflow
    std::cout << std::endl << "Arithmetic overflow --------------------------------" << std::endl;
    calculator.SetInfixExpression("999999999 * 999999999");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Undefined operation
    std::cout << std::endl << "Undefined operation --------------------------------" << std::endl;
    calculator.SetInfixExpression("5 +");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Invalid operand
    std::cout << std::endl << "Invalid operand --------------------------------" << std::endl;
    calculator.SetInfixExpression("5 $ 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Missing operand
    std::cout << std::endl << "Missing operand --------------------------------" << std::endl;
    calculator.SetInfixExpression("2 * x + 4");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Division by zero
    std::cout << std::endl << "Division by zero --------------------------------" << std::endl;
    calculator.SetInfixExpression("(5 * 2) / (3 - 3)");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // User Input Section
    std::cout << std::endl << "User Input Calculator --------------------------------" << std::endl;
    std::cout << "Enter expressions to calculate (type 'exit' to quit)" << std::endl;
    std::cout << "Example: 1 + 2 * 3" << std::endl;
    
    std::string userInput;
    while (true) 
    {
        std::cout << "\nEnter expression: ";
        std::cout.flush();  // Flush the output buffer
        
        std::getline(std::cin, userInput);
        if (std::cin.fail()) {
            std::cin.clear();  // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
            continue;
        }
        
        if (userInput == "exit" || userInput == "quit") {
            break;
        }

        try {
            calculator.SetInfixExpression(userInput);
            calculator.DisplayInfixExpression();
            calculator.CheckError();
            calculator.DisplayPostfixExpression();
            calculator.DisplayResult();
            std::cout.flush();  // Flush after displaying results
        }
        catch (...) {
            // Errors are already displayed by CheckError()
            continue;
        }
    }

    return 0;
}