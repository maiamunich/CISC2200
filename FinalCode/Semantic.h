#ifndef SEMANTIC_H
#define SEMANTIC_H


#include <iostream>
#include <exception>
#include <string>

enum class SemanticErrorType {
    DIVISION_BY_ZERO,
    INVALID_OPERAND,
    ARITHMETIC_OVERFLOW,
    UNDEFINED_OPERATION
};

class SemanticError : public std::exception {
public:
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

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

#endif // SEMANTIC_H



