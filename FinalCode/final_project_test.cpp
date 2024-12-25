#include "Calculator.h"

int main() {
    Calculator calculator;
    calculator.SetInfixExpression("1 + 2 * 3");
    calculator.DisplayInfixExpression();
    calculator.ConvertToPostfix();
    calculator.DisplayPostfixExpression();
    calculator.EvaluatePostfix();
    calculator.DisplayResult();
    return 0;
}