#include<iostream>
#include<stack> 
using namespace std;

bool isBalanced(cosnt string& case)
{
    stack<char> s; 

    for (char ch : case)
    {
        //push onto stack
        if(ch == '()' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
         //checking stack
        else if (ch == ')' || ch == '}' || ch == ']')
        {
             // if stack empty means we have an unmatched pair of closing brackets 
       
            if(s.empty()) return false;

            char top = s.top();

            //this condition check if the top and bottom match each other
            if ((ch == ')' && top == '(') || (ch == '}' && top == '[') || (ch == ']' && top == '['))
            {
             //pop the matching opening bracket
                s.pop();
            }
            else 
            {
                return false; 
            //have mismatching brackets
            }
        }
    }
    return s.empty();
}

int main ()
{
    string case;
    cout << "Enter an expression to check if parentheses are balanced: ";
    getline(cin, case);

    if( isBalanced(case))
    {
        cout<< "The parenthese are balance."<<endl;
    }
    else 
    {
        cout<< "The parentheses are not balanced."<<endl;
    }
    return 0;
}
   