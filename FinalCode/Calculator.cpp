#include "Calculator.h"

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
    postfixExpression = "";  // Clear previous postfix expression
    
    for (char c : infixExpression) 
    {
        if (c == '(') {
            operatorStack.push(c);
        }
        else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') 
            {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty()) 
            {
                operatorStack.pop(); // Remove '('
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') 
        {
            while (!operatorStack.empty() && operatorStack.top() != '(' && precedence(c) <= precedence(operatorStack.top())) 
            {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
        else if (c >= '0' && c <= '9') 
        {
            postfixExpression += c;
            std::cout << " "<< std::endl;
        }
        else if (c == ' ') 
        {
            continue;
        }
        else 
        {
            std::cout << "Invalid character: " << c << std::endl;
        }
    }

    // Empty remaining operators
    while (!operatorStack.empty()) {
        postfixExpression += operatorStack.top();
        operatorStack.pop();
    }
}

void Calculator::EvaluatePostfix() 
{
    for (char c : postfixExpression) 
    {
        if (c >= '0' && c <= '9') 
        {
            operandStack.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') 
        {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int tempResult = evaluate(operand1, operand2, c);
            operandStack.push(tempResult);
        }
    }
    result = operandStack.top();
}

void Calculator::SetInfixExpression(std::string expression) {
    infixExpression = expression;
}

int Calculator::evaluate(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
        default: return 0;
    }
}