// User function Template for C++

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Function to check if a character is an operator
    bool isOperator(char ch) {
        return (ch == '-' || ch == '+' || ch == '^' || ch == '*' || ch == '/');
    }

    // Function to convert postfix expression to infix expression
    string postToInfix(string exp) {
        stack<string> st;

        for (char ch : exp) {
            if (isOperator(ch)) {
                string operand1 = st.top(); st.pop();
                string operand2 = st.top(); st.pop();

                // Form the new infix expression and push it onto the stack
                st.push("(" + operand2 + ch + operand1 + ")");
            } else {
                // Push operand onto the stack
                st.push(string(1, ch));
            }
        }

        // The result will be the only element remaining in the stack
        return st.top();
    }
};



