#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
    int top;
    int st[10];

public:
    ArrayStack() { //constructor
        top = -1;
    }

    // Pushes element x 
    void push(int x) {
        if (top >= 9) {
            cout << "Stack overflow" << endl;
            return;
        }
        st[++top] = x;
    }

    // Returns top element
    int peek() {
        if (top == -1){ 
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return st[top];
    }

    // Removes and returns top element
    int pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return st[top--];
    }

    int size(){
        return top + 1;
    }
};

// Main Function
int main() {
    ArrayStack s;

   // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // Current top and size
    cout << "Top element: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;

    // Pop elements
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    // Check again
    cout << "Top element after popping: " << s.peek() << endl;
    cout << "Size after popping: " << s.size() << endl;

    // Pop remaining element
    cout << "Popped: " << s.pop() << endl;

    // Try popping from empty stack
    cout << "Popped: " << s.pop() << endl;

    // Final size check
    cout << "Final size: " << s.size() << endl;

    return 0;
}





// //Vector Version
// #include <bits/stdc++.h>
// using namespace std;

// class VectorStack {
//     vector<int> st;

// public:
//     // Push element
//     void push(int x) {
//         st.push_back(x);
//     }

//     // Returns top element
//     int peek() {
//         if (st.empty()) {
//             cout << "Stack is empty" << endl;
//             return -1;
//         }
//         return st.back();
//     }

//     // Removes and returns top element
//     int pop() {
//         if (st.empty()) {
//             cout << "Stack is empty" << endl;
//             return -1;
//         }
//         int val = st.back();
//         st.pop_back();
//         return val;
//     }

//     // Returns size
//     int size() {
//         return st.size();
//     }

//     // Check if empty
//     bool isEmpty() {
//         return st.empty();
//     }
// };

// // Main Function
// int main() {
//     VectorStack s;

//     // Push elements
//     s.push(10);
//     s.push(20);
//     s.push(30);

//     // Current top and size
//     cout << "Top element: " << s.peek() << endl;
//     cout << "Size: " << s.size() << endl;

//     // Pop elements
//     cout << "Popped: " << s.pop() << endl;
//     cout << "Popped: " << s.pop() << endl;

//     // Check again
//     cout << "Top element after popping: " << s.peek() << endl;
//     cout << "Size after popping: " << s.size() << endl;

//     // Pop remaining element
//     cout << "Popped: " << s.pop() << endl;

//     // Try popping from empty stack
//     cout << "Popped: " << s.pop() << endl;

//     // Final size check
//     cout << "Final size: " << s.size() << endl;

//     return 0;
// }


// ⚠️ Important difference from your custom stack:
// pop() does NOT return the value, so you must call top() first, then pop().




// #include <bits/stdc++.h>
// using namespace std;

// class ArrayStack {
// private:
//     // Array to hold elements
//     int* stackArray;
//     // Maximum capacity
//     int capacity; 
//      // Index of top element  
//     int topIndex;   

// public:
//     // Constructor
//     ArrayStack(int size = 1000) {
//         capacity = size;
//         stackArray = new int[capacity];
//         // Initialize stack as empty
//         topIndex = -1; 
//     }

//     // Destructor
//     ~ArrayStack() {
//         delete[] stackArray;
//     }

//     // Pushes element x 
//     void push(int x) {
//         if (topIndex >= capacity - 1) {
//             cout << "Stack overflow" << endl;
//             return;
//         }
//         stackArray[++topIndex] = x;
//     }

//     // Removes and returns top element
//     int pop() {
//         if (isEmpty()) {
//             cout << "Stack is empty" << endl;
//             // Return invalid value
//             return -1; 
//         }
//         return stackArray[topIndex--];
//     }

//     // Returns top element
//     int top() {
//         if (isEmpty()) {
//             cout << "Stack is empty" << endl;
//             return -1; 
//         }
//         return stackArray[topIndex];
//     }

//    /* Returns true if the 
//    stack is empty, false otherwise*/
//     bool isEmpty() {
//         return topIndex == -1;
//     }
// };

// // Main Function
// int main() {
//     ArrayStack stack;
//     vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
//     vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

//     for (size_t i = 0; i < commands.size(); ++i) {
//         if (commands[i] == "push") {
//             stack.push(inputs[i][0]);
//             cout << "null ";
//         } else if (commands[i] == "pop") {
//             cout << stack.pop() << " ";
//         } else if (commands[i] == "top") {
//             cout << stack.top() << " ";
//         } else if (commands[i] == "isEmpty") {
//             cout << (stack.isEmpty() ? "true" : "false") << " ";
//         } else if (commands[i] == "ArrayStack") {
//             cout << "null ";
//         }
//     }

//     return 0;
// }





