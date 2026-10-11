// #include <bits/stdc++.h>
// using namespace std;

// // Function to check if a character is an operator
// bool isOperator(char c) {
//     return (!isalpha(c) && !isdigit(c));  // If the character is neither alphabetic nor numeric, it's an operator
// }

// // Function to return the precedence of operators
// int getPriority(char C) {
//     if (C == '-' || C == '+')  // Addition and subtraction have lowest precedence
//         return 1;
//     else if (C == '*' || C == '/')  // Multiplication and division have higher precedence
//         return 2;
//     else if (C == '^')  // Exponent operator has highest precedence
//         return 3;
//     return 0;
// }

// // Function to convert infix expression to postfix expression
// string infixToPostfix(string infix) {
//     infix = '(' + infix + ')';  // Add parentheses to handle edge cases
//     int l = infix.size();
//     stack<char> char_stack;  // Stack to store operators
//     string output;  // String to store the resulting postfix expression

//     for (int i = 0; i < l; i++) {

//         // If the scanned character is an operand, add it to output
//         if (isalpha(infix[i]) || isdigit(infix[i]))
//             output += infix[i];

//         // If the scanned character is ‘(’, push it to the stack
//         else if (infix[i] == '(')
//             char_stack.push('(');

//         // If the scanned character is ‘)’, pop and output from the stack until an ‘(‘ is encountered
//         else if (infix[i] == ')') {
//             while (char_stack.top() != '(') {
//                 output += char_stack.top();
//                 char_stack.pop();
//             }
//             char_stack.pop();  // Remove '(' from the stack
//         }

//         // If an operator is found
//         else {
//             if (isOperator(char_stack.top())) {
//                 if (infix[i] == '^') {
//                     while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
//                         output += char_stack.top();
//                         char_stack.pop();
//                     }
//                 } else {
//                     while (getPriority(infix[i]) < getPriority(char_stack.top())) {
//                         output += char_stack.top();
//                         char_stack.pop();
//                     }
//                 }
//                 // Push current operator on stack
//                 char_stack.push(infix[i]);
//             }
//         }
//     }
    
//     // Pop all remaining elements from the stack
//     while (!char_stack.empty()) {
//         output += char_stack.top();
//         char_stack.pop();
//     }
//     return output;  // Return the postfix expression
// }

// // Function to convert infix expression to prefix expression
// string infixToPrefix(string infix) {
//     int l = infix.size();

//     // Reverse the infix expression
//     reverse(infix.begin(), infix.end());

//     // Replace '(' with ')' and vice versa
//     for (int i = 0; i < l; i++) {
//         if (infix[i] == '(') {
//             infix[i] = ')';
//             i++;
//         } 
//         else if (infix[i] == ')') {
//             infix[i] = '(';
//             i++;
//         }
//     }

//     string prefix = infixToPostfix(infix);  // Convert the modified infix to postfix

//     // Reverse the postfix expression to get the prefix
//     reverse(prefix.begin(), prefix.end());

//     return prefix;  // Return the prefix expression
// }

// int main() {
//     string s = "(p+q)*(c-d)";  // Infix expression
//     cout << "Infix expression: " << s << endl;
//     cout << "Prefix Expression: " << infixToPrefix(s) << endl;  // Output the prefix expression
//     return 0;
// }





#include<bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix to prefix
void infixToPrefix(string s) {
    // Step 1: Reverse the string
    reverse(s.begin(), s.end());

    // Step 2: Replace ( with ) and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    stack<char> st;
    string result = "";

    // Step 3: Convert modified infix to postfix
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // Operand
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); //for removing (
        }

        else {
            if(c=='^'){
                while (!st.empty() && prec(c) < prec(st.top())) {
                    result += st.top();
                    st.pop();
                }
            }
            else{
                while (!st.empty() && prec(c) <= prec(st.top())) {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
    
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Step 4: Reverse postfix to get prefix
    reverse(result.begin(), result.end());

    cout << "Prefix expression: " << result << endl;
}

int main() {
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    infixToPrefix(exp);
    return 0;
}