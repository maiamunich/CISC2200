#include "Calculator.h"
#include "Syntax.h"
#include "Semantic.h"
#include <iostream>
#include <cfloat>

Calculator::Calculator() 
{
    result = 0;
    infixExpression = "";
    postfixExpression = "";
}

Calculator::~Calculator() 
{
}

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

int Calculator::precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void Calculator::ConvertToPostfix() 
{
    if (infixExpression.empty()) 
    {
        throw SyntaxError(SyntaxErrorType::EMPTY_EXPRESSION, infixExpression);
    }

    postfixExpression = "";  
    bool lastWasOperator = true;
    bool lastWasNumber = false;
    int parenthesesCount = 0;
    std::string currentNumber = "";  // Buffer for building numbers
    
    for (char c : infixExpression) 
    {
        if (c >= '0' && c <= '9') 
        {
            currentNumber += c;  // Add digit to current number
            lastWasOperator = false;
            lastWasNumber = true;
        }
        else if (c == ' ') 
        {
            // If we were building a number, add it to postfix with a space
            if (!currentNumber.empty()) {
                postfixExpression += currentNumber + " ";
                currentNumber = "";
            }
        }
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
        else if (c == '+' || c == '-' || c == '*' || c == '/') 
        {
            // First add any pending number
            if (!currentNumber.empty()) {
                postfixExpression += currentNumber + " ";
                currentNumber = "";
            }
            if (!lastWasNumber && !lastWasOperator) {
                throw SyntaxError(SyntaxErrorType::MISSING_OPERAND, infixExpression);
            }
            if (lastWasOperator) {
                throw SyntaxError(SyntaxErrorType::ADJACENT_OPERATORS, infixExpression);
            }
            
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
        else 
        {
            throw SyntaxError(SyntaxErrorType::INVALID_CHARACTER, infixExpression);
        }
    }

    // Add final number if exists
    if (!currentNumber.empty()) {
        postfixExpression += currentNumber + " ";
    }

    if (parenthesesCount > 0) 
    {
        throw SyntaxError(SyntaxErrorType::UNMATCHED_PARENTHESES, infixExpression);
    }
    if(lastWasOperator)
    {
        throw SyntaxError(SyntaxErrorType::MISSING_OPERAND, infixExpression);
    }

    while (!operatorStack.empty()) {
        postfixExpression += operatorStack.top();
        postfixExpression += " ";  // Add space after operator
        operatorStack.pop();
    }
}

void Calculator::EvaluatePostfix() 
{
    std::string currentNumber = "";

    for (char c : postfixExpression) 
    {
        if (c >= '0' && c <= '9') 
        {
            currentNumber += c;  // Build multi-digit number
        }
        else if (c == ' ') 
        {
            // Convert complete number to double and push to stack
            if (!currentNumber.empty()) {
                operandStack.push(std::stod(currentNumber));
                currentNumber = "";
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') 
        {
            if (operandStack.size() < 2) 
            {
                throw SyntaxError(SyntaxErrorType::MISSING_OPERAND, postfixExpression);
            }

            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();

            // Check for division by zero
            if (c == '/' && operand2 == 0) 
            {
                throw SemanticError(SemanticErrorType::DIVISION_BY_ZERO, postfixExpression);
            }

            double tempResult = evaluate(operand1, operand2, c);
            
            // Check if result is too large
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

    if (operandStack.empty()) {
        throw SyntaxError(SyntaxErrorType::MISSING_OPERAND, postfixExpression);
    }

    result = operandStack.top();
}

void Calculator::SetInfixExpression(std::string expression) {
    infixExpression = expression;
}

double Calculator::evaluate(double a, double b, char op) {
    switch(op) {
        case '+': 
            if ((b > 0 && a > DBL_MAX - b) || (b < 0 && a < DBL_MIN - b))
                throw SemanticError(SemanticErrorType::ARITHMETIC_OVERFLOW, "");
            return a + b;
            
        case '-': 
            if ((b < 0 && a > DBL_MAX + b) || (b > 0 && a < DBL_MIN + b))
                throw SemanticError(SemanticErrorType::ARITHMETIC_OVERFLOW, "");
            return a - b;
            
        case '*': 
            if (a != 0 && (a * b) / a != b)
                throw SemanticError(SemanticErrorType::ARITHMETIC_OVERFLOW, "");
            return a * b;
            
        case '/': 
            if (b == 0)
                throw SemanticError(SemanticErrorType::DIVISION_BY_ZERO, "");
            return a / b;
            
        default: 
            throw SemanticError(SemanticErrorType::UNDEFINED_OPERATION, "");
    }
}

double Calculator::getResult() {
    return result;
}
