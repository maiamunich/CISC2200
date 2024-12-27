#include "Calculator.h"

int main() {
    // First calculation
    Calculator calculator;
    calculator.SetInfixExpression("1 + 2 * 3");
    calculator.DisplayInfixExpression();
    calculator.ConvertToPostfix();
    calculator.DisplayPostfixExpression();
    calculator.EvaluatePostfix();
    calculator.DisplayResult();

    // Second calculation - use the same calculator object
    calculator.SetInfixExpression("(1*3)+4(5/3)*6");
    calculator.DisplayInfixExpression();
    calculator.ConvertToPostfix();
    calculator.DisplayPostfixExpression();
    calculator.EvaluatePostfix();
    calculator.DisplayResult();
    return 0;
}