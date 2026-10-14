#include <bits/stdc++.h>
using namespace std;

// Function to convert postfix to prefix
string postfixToPrefix(string postfix) {
    stack<string>st;
    int n = postfix.size();

    // Traverse the postfix expression from left to right
    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(c)) {
            st.push(string(1, c));
        } 
        else {
            // Pop two operands from the stack
            string op1 = st.top(); 
            st.pop();
            string op2 = st.top(); 
            st.pop();

            // Form the new prefix expression and push back to stack
            st.push(c + op2 + op1);
        }
    }

    // The final element in the stack is the result
    return st.top();
}

int main() {
    string postfix = "ABC/-AK/L-*";
    cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;
    return 0;
}
