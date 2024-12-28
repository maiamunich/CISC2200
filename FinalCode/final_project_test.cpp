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

    // Check result
    if (calculator.getResult() != (1+2*3)) 
    {
        std::cout << "Test failed: Expected result is " << (1+2*3) << ", but got " << calculator.getResult() << std::endl;
        return 1;
    }

    // Second calculation - use the same calculator object
    calculator.SetInfixExpression("(1*3)+4*(5/3)*6");
    calculator.DisplayInfixExpression();
    calculator.ConvertToPostfix();
    calculator.DisplayPostfixExpression();
    calculator.EvaluatePostfix();
    calculator.DisplayResult();

    // Check result
    if (calculator.getResult() != ((1.*3.)+4.*(5./3.)*6.)) 
    {
        std::cout << "Test failed: Expected result is " << ((1.*3.)+4.*(5./3.)*6.) << ", but got " << calculator.getResult() << std::endl;
        return 1;
    }
    return 0;
}