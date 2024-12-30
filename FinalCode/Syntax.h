#ifndef SYNTAX_H
#define SYNTAX_H

#include <iostream>
#include <exception>
#include <string>

enum class SyntaxErrorType {
    UNMATCHED_PARENTHESES,
    INVALID_CHARACTER,
    ADJACENT_OPERATORS,
    MISSING_OPERATOR,
    MISSING_OPERAND,
    EMPTY_EXPRESSION,
    INVALID_DECIMAL
};

class SyntaxError : public std::exception {
public:
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

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

#endif // SYNTAX_H  



