/*******************************************************************************
 * File: Syntax.h
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Header file defining syntax error types and exception class
 *              for the Calculator project. Handles all syntax-related errors
 *              that occur during infix to postfix conversion.
 * 
 * Error Types Handled:
 * - UNMATCHED_PARENTHESES: Missing or extra parentheses
 * - INVALID_CHARACTER: Characters not allowed in mathematical expressions
 * - ADJACENT_OPERATORS: Two operators placed next to each other
 * - MISSING_OPERATOR: Missing operator between operands
 * - MISSING_OPERAND: Missing operand for an operator
 * - EMPTY_EXPRESSION: No expression provided
 * - INVALID_DECIMAL: Malformed decimal numbers
 *******************************************************************************/

#ifndef SYNTAX_H
#define SYNTAX_H

#include <iostream>
#include <exception>
#include <string>

// Enumeration of all possible syntax error types
enum class SyntaxErrorType {
    UNMATCHED_PARENTHESES,    // Missing or extra parentheses in expression
    INVALID_CHARACTER,        // Character not allowed in mathematical expression
    ADJACENT_OPERATORS,       // Two operators placed consecutively
    MISSING_OPERATOR,         // Missing operator between two operands
    MISSING_OPERAND,          // Missing operand for an operator
    EMPTY_EXPRESSION,         // No expression provided for evaluation
    INVALID_DECIMAL           // Malformed decimal number format
};

// Exception class for syntax errors in mathematical expressions
// Inherits from std::exception to provide standard error handling
class SyntaxError : public std::exception {
public:
    // Constructor: Creates syntax error with specific type and expression
    // Pre: type is valid SyntaxErrorType, expr is the problematic expression
    // Post: Error message is constructed based on error type
    SyntaxError(SyntaxErrorType type, const std::string& expr) {
        switch(type) {
            case SyntaxErrorType::UNMATCHED_PARENTHESES:
                message = "Unmatched parentheses in: " + expr;
                break;
            case SyntaxErrorType::INVALID_CHARACTER:
                message = "Invalid character in: " + expr;
                break;
            case SyntaxErrorType::ADJACENT_OPERATORS:
                message = "Adjacent operators in: " + expr;
                break;
            case SyntaxErrorType::MISSING_OPERATOR:
                message = "Missing operator in: " + expr;
                break;
            case SyntaxErrorType::MISSING_OPERAND:
                message = "Missing operand in: " + expr;
                break;
            case SyntaxErrorType::EMPTY_EXPRESSION:
                message = "Empty expression";
                break;
            case SyntaxErrorType::INVALID_DECIMAL:
                message = "Invalid decimal format in: " + expr;
                break;
        }
    }

    // Override what() method to return error message
    // Pre: SyntaxError object has been constructed
    // Post: Returns C-style string containing error message
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;  // Stores the formatted error message
};

#endif // SYNTAX_H  



