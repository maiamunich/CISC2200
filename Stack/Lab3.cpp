/*******************************************************************************
 * File: Lab3.cpp
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Stack-based parentheses balancing checker using STL stack
 *              to validate mathematical expressions with proper bracket matching.
 * 
 * Algorithm:
 * - Uses stack to track opening brackets
 * - Validates matching pairs: (), {}, []
 * - Handles nested brackets correctly
 * - Detects unmatched brackets and mismatched types
 * 
 * Supported Brackets: (), {}, []
 * Time Complexity: O(n) where n is length of expression
 *******************************************************************************/

#include<iostream>
#include<stack> 
using namespace std;

// isBalanced: Checks if parentheses are properly balanced in expression
// Pre: cases contains a string with potential brackets
// Post: Returns true if all brackets are properly matched, false otherwise
// Algorithm: Stack-based validation of bracket pairs
bool isBalanced(const string& cases)
{
    stack<char> s;  // Stack to track opening brackets

    // Process each character in the expression
    for (char ch : cases )
    {
        // Handle opening brackets: push onto stack
        if(ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        // Handle closing brackets: check for matching opening bracket
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // If stack is empty, we have an unmatched closing bracket
            if(s.empty()) return false;

            char top = s.top();  // Get the most recent opening bracket

            // Check if closing bracket matches the opening bracket
            if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
            {
                s.pop();  // Remove the matching opening bracket
            }
            else 
            {
                return false;  // Mismatched bracket types
            }
        }
    }
    // Expression is balanced if stack is empty (all brackets matched)
    return s.empty();
}

// Main function: Interactive parentheses checker
int main ()
{
    string cases;
    cout << "Enter an expression to check if parentheses are balanced: ";
    getline(cin, cases );

    // Check and display result
    if( isBalanced(cases))
    {
        cout<< "The parentheses are balanced."<<endl;
    }
    else 
    {
        cout<< "The parentheses are not balanced."<<endl;
    }
    return 0;
}
   