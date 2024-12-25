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

void Calculator::ConvertToPostfix() 
{

}

void Calculator::EvaluatePostfix() 
{

}

void Calculator::SetInfixExpression(std::string expression) {
    infixExpression = expression;
}