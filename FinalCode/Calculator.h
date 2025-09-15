/*******************************************************************************
 * File: Calculator.h
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Header file for Calculator class - A comprehensive calculator
 *              that converts infix expressions to postfix notation and evaluates
 *              them with comprehensive error handling for both syntax and semantic
 *              errors. Supports basic arithmetic operations (+, -, *, /) with
 *              parentheses grouping and proper operator precedence.
 * 
 * Features:
 * - Infix to Postfix conversion using Shunting Yard algorithm
 * - Postfix expression evaluation with stack-based computation
 * - Syntax error detection (unmatched parentheses, invalid characters, etc.)
 * - Semantic error detection (division by zero, arithmetic overflow)
 * - Interactive user input mode
 * - Comprehensive test suite with various error cases
 *******************************************************************************/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <stack>
#include <string>
#include "Syntax.h"

class Calculator {
public:
    // Constructor and Destructor
    Calculator();                    // Initializes calculator with empty expressions
    ~Calculator();                   // Cleanup destructor

    // Display Methods
    void DisplayInfixExpression();  // Prints the current infix expression
    void DisplayPostfixExpression(); // Prints the converted postfix expression
    void DisplayResult();            // Prints the calculated result

    // Core Calculation Methods
    void CheckError();               // Validates expression and handles errors
    void ConvertToPostfix();         // Converts infix to postfix notation
    void EvaluatePostfix();          // Evaluates postfix expression
    double getResult();              // Returns the calculated result

    // Input Method
    void SetInfixExpression(std::string expression); // Sets new expression to evaluate

private:
    // Data Members
    double result;                   // Stores the final calculation result
    std::string infixExpression;    // Original infix expression from user
    std::string postfixExpression;  // Converted postfix expression
    std::stack<char> operatorStack;  // Stack for operators during conversion
    std::stack<double> operandStack; // Stack for operands during evaluation

    // Helper Methods
    int precedence(char op);         // Returns operator precedence (1 for +/-, 2 for */)
    double evaluate(double a, double b, char op); // Performs arithmetic operation with overflow checking
};

#endif