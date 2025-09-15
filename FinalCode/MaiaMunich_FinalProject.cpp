/*******************************************************************************
 * File: MaiaMunich_FinalProject.cpp
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Comprehensive test suite and interactive calculator application
 *              demonstrating the Calculator class functionality. Tests both
 *              valid calculations and various error conditions including
 *              syntax and semantic errors.
 * 
 * Test Categories:
 * 1. Basic arithmetic operations with proper precedence
 * 2. Complex expressions with parentheses grouping
 * 3. Syntax error testing (unmatched parentheses, invalid characters, etc.)
 * 4. Semantic error testing (division by zero, arithmetic overflow)
 * 5. Interactive user input mode for real-time calculations
 * 
 * Usage: Compile and run to see comprehensive testing of calculator functionality
 *******************************************************************************/

#include "Calculator.h"
#include "Semantic.h"
#include "Syntax.h"
#include <limits>
using namespace std;

int main() {
    // Initialize calculator object for testing
    Calculator calculator;

    // ============================================================================
    // SECTION 1: BASIC ARITHMETIC OPERATIONS TESTING
    // ============================================================================
    
    // Test 1: Basic precedence (multiplication before addition)
    std::cout << "First calculation --------------------------------" << std::endl;
    calculator.SetInfixExpression("1 + 2 * 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    calculator.DisplayPostfixExpression();
    calculator.DisplayResult();

    // Verify result matches expected calculation
    if (calculator.getResult() != (1+2*3)) 
    {
        std::cout << "Test failed: Expected result is " << (1+2*3) << ", but got " << calculator.getResult() << std::endl;
        return 1;
    }

    // Test 2: Another basic precedence test
    std::cout << "First-half calculation --------------------------------" << std::endl;
    calculator.SetInfixExpression("10 + 2 * 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    calculator.DisplayPostfixExpression();
    calculator.DisplayResult();

    // Verify result
    if (calculator.getResult() != (10+2*3)) 
    {
        std::cout << "Test failed: Expected result is " << (10+2*3) << ", but got " << calculator.getResult() << std::endl;
        return 1;
    }

    // ============================================================================
    // SECTION 2: COMPLEX EXPRESSIONS WITH PARENTHESES
    // ============================================================================
    
    // Test 3: Complex expression with multiple operations and parentheses
    std::cout << std::endl << "Second calculation --------------------------------" << std::endl;
    calculator.SetInfixExpression("(1*3)+4*(5/3)*6");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    calculator.DisplayPostfixExpression();
    calculator.DisplayResult();

    // Verify complex calculation
    if (calculator.getResult() != ((1.*3.)+4.*(5./3.)*6.)) 
    {
        std::cout << "Test failed: Expected result is " << ((1.*3.)+4.*(5./3.)*6.) << ", but got " << calculator.getResult() << std::endl;
        return 1;
    }

    // Test 4: Another complex expression
    std::cout << std::endl << "Third calculation --------------------------------" << std::endl;
    calculator.SetInfixExpression("(6 + 13) * 2 - (5 + 1) / 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    calculator.DisplayPostfixExpression();
    calculator.DisplayResult();

    // Verify result
    if (calculator.getResult() != ((6+13)*2-(5+1)/3)) 
    {
        std::cout << "Test failed: Expected result is " << ((6+13)*2-(5+1)/3) << ", but got " << calculator.getResult() << std::endl;
        return 1;
    }

    // ============================================================================
    // SECTION 3: SYNTAX ERROR TESTING
    // ============================================================================
    
    std::cout << std::endl << "Checking for errors --------------------------------" << std::endl;

    // Test 5: Empty expression
    std::cout << std::endl << "Empty expression --------------------------------" << std::endl;
    calculator.SetInfixExpression("");
    calculator.DisplayInfixExpression();
    calculator.CheckError();
    
    // Test 6: Unmatched parentheses
    std::cout << std::endl << "Unmatched parentheses --------------------------------" << std::endl;
    calculator.SetInfixExpression("(1+2))*3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 7: Invalid character
    std::cout << std::endl << "Invalid character --------------------------------" << std::endl;
    calculator.SetInfixExpression("1 @ 2 + 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 8: Adjacent operators
    std::cout << std::endl << "Adjacent operators --------------------------------" << std::endl;
    calculator.SetInfixExpression("1 ++ 2");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 9: Missing operator
    std::cout << std::endl << "Missing Operator --------------------------------" << std::endl;
    calculator.SetInfixExpression("1 2 + 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 10: Missing operand
    std::cout << std::endl << "Missing Operand --------------------------------" << std::endl;
    calculator.SetInfixExpression("1 + * 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 11: Invalid operator
    std::cout << std::endl << "Invalid operator --------------------------------" << std::endl;
    calculator.SetInfixExpression("2 * 3 % 4");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 12: Invalid character with braces
    std::cout << std::endl << "Invalid character --------------------------------" << std::endl;
    calculator.SetInfixExpression("{(2 * 3) / 4}");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // ============================================================================
    // SECTION 4: SEMANTIC ERROR TESTING
    // ============================================================================

    // Test 13: Division by zero
    std::cout << std::endl << "Division by zero --------------------------------" << std::endl;
    calculator.SetInfixExpression("5 / 0");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 14: Arithmetic overflow
    std::cout << std::endl << "Arithmetic overflow --------------------------------" << std::endl;
    calculator.SetInfixExpression("999999999 * 999999999");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 15: Undefined operation
    std::cout << std::endl << "Undefined operation --------------------------------" << std::endl;
    calculator.SetInfixExpression("5 +");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 16: Invalid operand
    std::cout << std::endl << "Invalid operand --------------------------------" << std::endl;
    calculator.SetInfixExpression("5 $ 3");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 17: Missing operand
    std::cout << std::endl << "Missing operand --------------------------------" << std::endl;
    calculator.SetInfixExpression("2 * x + 4");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // Test 18: Division by zero in complex expression
    std::cout << std::endl << "Division by zero --------------------------------" << std::endl;
    calculator.SetInfixExpression("(5 * 2) / (3 - 3)");
    calculator.DisplayInfixExpression();
    calculator.CheckError();

    // ============================================================================
    // SECTION 5: INTERACTIVE USER INPUT MODE
    // ============================================================================
    
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
        
        // Check for exit commands
        if (userInput == "exit" || userInput == "quit") {
            break;
        }

        // Process user input
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