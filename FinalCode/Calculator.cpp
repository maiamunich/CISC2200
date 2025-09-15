/*******************************************************************************
 * File: Calculator.cpp
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Implementation of Calculator class - A comprehensive calculator
 *              that converts infix expressions to postfix notation and evaluates
 *              them with comprehensive error handling for both syntax and semantic
 *              errors.
 * 
 * Algorithm Details:
 * - Uses Shunting Yard algorithm for infix to postfix conversion
 * - Implements stack-based postfix evaluation
 * - Comprehensive error checking for syntax and semantic errors
 * - Supports operator precedence and parentheses grouping
 *******************************************************************************/

#include "Calculator.h"
#include "Syntax.h"
#include "Semantic.h"
#include <iostream>
#include <cfloat>

// Constructor: Initializes calculator with default values
Calculator::Calculator() 
{
    result = 0;                    // Initialize result to 0
    infixExpression = "";          // Initialize empty infix expression
    postfixExpression = "";        // Initialize empty postfix expression
}

// Destructor: Cleanup (no dynamic memory to free)
Calculator::~Calculator() 
{
}

// Display Methods
void Calculator::DisplayInfixExpression() 
{
    std::cout << "Infix Expression: " << infixExpression << std::endl;
}

void Calculator::DisplayPostfixExpression() 
{
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;
}

void Calculator::DisplayResult() 
{
    std::cout << "Result: " << result << std::endl;
}

// Error Checking Method: Validates expression and handles all error types
// Pre: infixExpression has been set
// Post: Either result is calculated or appropriate error is thrown and handled
void Calculator::CheckError() 
{
    try 
    {
        ConvertToPostfix();  // This will throw SyntaxError for unmatched parentheses
        EvaluatePostfix();
    } 
    catch (const SyntaxError& e) 
    {
        std::cerr << "Syntax error: " << e.what() << std::endl;
        //throw;  // Re-throw the error so it can be caught in the test file
    }
    catch (const SemanticError& e) 
    {
        std::cerr << "Semantic error: " << e.what() << std::endl;
        //throw;  // Re-throw the error
    }
}

// Helper Method: Returns operator precedence for proper evaluation order
// Pre: op is a valid operator (+, -, *, /)
// Post: Returns precedence level (1 for +/-, 2 for */)
int Calculator::precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Core Method: Converts infix expression to postfix notation using Shunting Yard algorithm
// Pre: infixExpression contains a valid mathematical expression
// Post: postfixExpression contains the converted postfix notation
// Algorithm: 
// 1. Process each character in the infix expression
// 2. Numbers are added directly to postfix output
// 3. Operators are pushed to stack based on precedence
// 4. Parentheses control grouping and operator precedence
// 5. Comprehensive error checking for syntax violations
void Calculator::ConvertToPostfix() 
{
    if (infixExpression.empty()) 
    {
        throw SyntaxError(SyntaxErrorType::EMPTY_EXPRESSION, infixExpression);
    }

    postfixExpression = "";  
    bool lastWasOperator = true;    // Track operator/operand sequence
    bool lastWasNumber = false;     // Track if last token was a number
    int parenthesesCount = 0;       // Track balanced parentheses
    std::string currentNumber = ""; // Buffer for building multi-digit numbers
    
    // Process each character in the infix expression
    for (char c : infixExpression) 
    {
        // Handle digits: build multi-digit numbers
        if (c >= '0' && c <= '9') 
        {
            currentNumber += c;  // Add digit to current number
            lastWasOperator = false;
            lastWasNumber = true;
        }
        // Handle spaces: complete current number if building one
        else if (c == ' ') 
        {
            // If we were building a number, add it to postfix with a space
            if (!currentNumber.empty()) {
                postfixExpression += currentNumber + " ";
                currentNumber = "";
            }
        }
        // Handle opening parentheses: push to operator stack
        else if (c == '(') 
        {
            // First add any pending number
            if (!currentNumber.empty()) {
                postfixExpression += currentNumber + " ";
                currentNumber = "";
            }
            parenthesesCount++;
            operatorStack.push(c);
            lastWasOperator = false;
            lastWasNumber = false;
        }
        // Handle closing parentheses: pop operators until matching '('
        else if (c == ')') 
        {
            // First add any pending number
            if (!currentNumber.empty()) {
                postfixExpression += currentNumber + " ";
                currentNumber = "";
            }
            parenthesesCount--;
            if (parenthesesCount < 0) 
            {
                throw SyntaxError(SyntaxErrorType::UNMATCHED_PARENTHESES, infixExpression);
            }
            if (lastWasOperator) 
            {
                throw SyntaxError(SyntaxErrorType::MISSING_OPERAND, infixExpression);
            }
            // Pop operators until we find the matching opening parenthesis
            while (!operatorStack.empty() && operatorStack.top() != '(') 
            {
                postfixExpression += operatorStack.top();
                postfixExpression += " ";  // Add space after operator
                operatorStack.pop();
            }
            if (!operatorStack.empty()) 
            {
                operatorStack.pop(); // Remove '('
            }
            lastWasOperator = false;
            lastWasNumber = true;
        }
        // Handle arithmetic operators: manage precedence and stack operations
        else if (c == '+' || c == '-' || c == '*' || c == '/') 
        {
            // First add any pending number
            if (!currentNumber.empty()) {
                postfixExpression += currentNumber + " ";
                currentNumber = "";
            }
            // Validate operator placement
            if (!lastWasNumber && !lastWasOperator) {
                throw SyntaxError(SyntaxErrorType::MISSING_OPERAND, infixExpression);
            }
            if (lastWasOperator) {
                throw SyntaxError(SyntaxErrorType::ADJACENT_OPERATORS, infixExpression);
            }
            
            // Pop higher precedence operators from stack
            while (!operatorStack.empty() && operatorStack.top() != '(' && 
                   precedence(c) <= precedence(operatorStack.top())) 
            {
                postfixExpression += operatorStack.top();
                postfixExpression += " ";  // Add space after operator
                operatorStack.pop();
            }
            operatorStack.push(c);
            lastWasOperator = true;
            lastWasNumber = false;
        }
        // Handle invalid characters
        else 
        {
            throw SyntaxError(SyntaxErrorType::INVALID_CHARACTER, infixExpression);
        }
    }

    // Final cleanup: add any remaining number and validate expression
    if (!currentNumber.empty()) {
        postfixExpression += currentNumber + " ";
    }

    // Validate balanced parentheses and proper expression ending
    if (parenthesesCount > 0) 
    {
        throw SyntaxError(SyntaxErrorType::UNMATCHED_PARENTHESES, infixExpression);
    }
    if(lastWasOperator)
    {
        throw SyntaxError(SyntaxErrorType::MISSING_OPERAND, infixExpression);
    }

    // Pop any remaining operators from the stack
    while (!operatorStack.empty()) {
        postfixExpression += operatorStack.top();
        postfixExpression += " ";  // Add space after operator
        operatorStack.pop();
    }
}

// Core Method: Evaluates postfix expression using stack-based computation
// Pre: postfixExpression contains a valid postfix notation
// Post: result contains the calculated value
// Algorithm:
// 1. Process each token in postfix expression
// 2. Numbers are pushed onto operand stack
// 3. Operators pop two operands, compute result, push back
// 4. Comprehensive error checking for semantic violations
void Calculator::EvaluatePostfix() 
{
    std::string currentNumber = "";

    for (char c : postfixExpression) 
    {
        // Handle digits: build multi-digit numbers
        if (c >= '0' && c <= '9') 
        {
            currentNumber += c;  // Build multi-digit number
        }
        // Handle spaces: complete current number and push to stack
        else if (c == ' ') 
        {
            // Convert complete number to double and push to stack
            if (!currentNumber.empty()) {
                operandStack.push(std::stod(currentNumber));
                currentNumber = "";
            }
        }
        // Handle operators: perform arithmetic operations
        else if (c == '+' || c == '-' || c == '*' || c == '/') 
        {
            // Validate sufficient operands
            if (operandStack.size() < 2) 
            {
                throw SyntaxError(SyntaxErrorType::MISSING_OPERAND, postfixExpression);
            }

            // Pop two operands (note: order matters for subtraction and division)
            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();

            // Check for division by zero
            if (c == '/' && operand2 == 0) 
            {
                throw SemanticError(SemanticErrorType::DIVISION_BY_ZERO, postfixExpression);
            }

            // Perform operation with overflow checking
            double tempResult = evaluate(operand1, operand2, c);
            
            // Check if result is too large for integer representation
            if (tempResult > INT_MAX || tempResult < INT_MIN) 
            {
                throw SemanticError(SemanticErrorType::ARITHMETIC_OVERFLOW, postfixExpression);
            }

            operandStack.push(tempResult);
        }
    }

    // Handle any remaining number at the end
    if (!currentNumber.empty()) {
        operandStack.push(std::stod(currentNumber));
    }

    // Validate final result
    if (operandStack.empty()) {
        throw SyntaxError(SyntaxErrorType::MISSING_OPERAND, postfixExpression);
    }

    result = operandStack.top();
}

// Input Method: Sets new infix expression for calculation
// Pre: expression is a string containing mathematical expression
// Post: infixExpression is updated with new value
void Calculator::SetInfixExpression(std::string expression) {
    infixExpression = expression;
}

// Helper Method: Performs arithmetic operations with overflow checking
// Pre: a and b are valid numbers, op is a valid operator
// Post: Returns result of operation or throws SemanticError for overflow
// Note: Comprehensive overflow checking for each operation type
double Calculator::evaluate(double a, double b, char op) {
    switch(op) {
        case '+': 
            // Check for addition overflow
            if ((b > 0 && a > DBL_MAX - b) || (b < 0 && a < DBL_MIN - b))
                throw SemanticError(SemanticErrorType::ARITHMETIC_OVERFLOW, "");
            return a + b;
            
        case '-': 
            // Check for subtraction overflow
            if ((b < 0 && a > DBL_MAX + b) || (b > 0 && a < DBL_MIN + b))
                throw SemanticError(SemanticErrorType::ARITHMETIC_OVERFLOW, "");
            return a - b;
            
        case '*': 
            // Check for multiplication overflow
            if (a != 0 && (a * b) / a != b)
                throw SemanticError(SemanticErrorType::ARITHMETIC_OVERFLOW, "");
            return a * b;
            
        case '/': 
            // Division by zero already checked in EvaluatePostfix
            if (b == 0)
                throw SemanticError(SemanticErrorType::DIVISION_BY_ZERO, "");
            return a / b;
            
        default: 
            throw SemanticError(SemanticErrorType::UNDEFINED_OPERATION, "");
    }
}

// Accessor Method: Returns the calculated result
// Pre: EvaluatePostfix has been called successfully
// Post: Returns the final calculation result
double Calculator::getResult() {
    return result;
}
