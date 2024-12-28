#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <stack>

class Calculator {
public:
    Calculator();
    ~Calculator();

    void DisplayInfixExpression();
    void DisplayPostfixExpression();
    void DisplayResult();
    void CheckError();
    void ConvertToPostfix();
    void EvaluatePostfix();
    double getResult();

    void SetInfixExpression(std::string expression);
    

private:
    int result;
    std::string infixExpression;
    std::string postfixExpression;
    std::stack<char> operatorStack;
    std::stack<double> operandStack;
    int precedence(char op);
    double evaluate(double a, double b, char op);
    
};

#endif