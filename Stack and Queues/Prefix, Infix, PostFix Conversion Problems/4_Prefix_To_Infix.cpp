#include <bits/stdc++.h>
using namespace std;

// Function to convert prefix to infix
string prefixToInfix(string prefix) {
    stack<string>st;
    int n = prefix.size();

    // Traverse the prefix expression from right to left
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

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

            // Form the new infix expression and push back to stack
            st.push("(" + op1 + c + op2 + ")");
        }
    }

    // The final element in the stack is the result
    return st.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
    return 0;
}
