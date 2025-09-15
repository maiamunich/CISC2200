/*******************************************************************************
 * File: Semantic.h
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Header file defining semantic error types and exception class
 *              for the Calculator project. Handles all semantic-related errors
 *              that occur during expression evaluation.
 * 
 * Error Types Handled:
 * - DIVISION_BY_ZERO: Attempting to divide by zero
 * - INVALID_OPERAND: Invalid operand for an operation
 * - ARITHMETIC_OVERFLOW: Result exceeds maximum representable value
 * - UNDEFINED_OPERATION: Operation not supported or defined
 *******************************************************************************/

#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <iostream>
#include <exception>
#include <string>

// Enumeration of all possible semantic error types
enum class SemanticErrorType {
    DIVISION_BY_ZERO,        // Attempting to divide by zero
    INVALID_OPERAND,         // Invalid operand for an operation
    ARITHMETIC_OVERFLOW,     // Result exceeds maximum representable value
    UNDEFINED_OPERATION      // Operation not supported or defined
};

// Exception class for semantic errors in mathematical expressions
// Inherits from std::exception to provide standard error handling
class SemanticError : public std::exception {
public:
    // Constructor: Creates semantic error with specific type and expression
    // Pre: type is valid SemanticErrorType, expr is the problematic expression
    // Post: Error message is constructed based on error type
    SemanticError(SemanticErrorType type, const std::string& expr) {
        switch(type) {
            case SemanticErrorType::DIVISION_BY_ZERO:
                message = "Division by zero in expression: " + expr;
                break;
            case SemanticErrorType::INVALID_OPERAND:
                message = "Invalid operand in expression: " + expr;
                break;
            case SemanticErrorType::ARITHMETIC_OVERFLOW:
                message = "Arithmetic overflow in expression: " + expr;
                break;
            case SemanticErrorType::UNDEFINED_OPERATION:
                message = "Undefined operation in expression: " + expr;
                break;
        }
    }

    // Override what() method to return error message
    // Pre: SemanticError object has been constructed
    // Post: Returns C-style string containing error message
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;  // Stores the formatted error message
};

#endif // SEMANTIC_H



