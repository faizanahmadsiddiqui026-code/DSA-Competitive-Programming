// #include <bits/stdc++.h>
// using namespace std;

// // Stack implementation using Queue
// class QueueStack {
//     // Queue
//     queue<int> q;

// public:
//     // Method to push element in the stack
//     void push(int x) {
//         // Get size 
//         int s = q.size(); 
//         // Add element
//         q.push(x); 

//         // Move elements before new element to back
//         for (int i = 0; i < s; i++) {
//             q.push(q.front()); 
//             q.pop(); 
//         }
//     }

//     // Method to pop element from stack
//     int pop() {
//         // Get front element 
//         int n = q.front(); 
//         // Remove front element
//         q.pop(); 
//         // Return removed element
//         return n; 
//     }

//     // Method to return the top of stack
//     int top() {
//         // Return front element
//         return q.front(); 
//     }

//     // Method to check if the stack is empty
//     bool isEmpty() {
//         return q.empty(); 
//     }
// };

// int main() {
//     QueueStack st;
    
//     // List of commands
//     vector<string> commands = {"QueueStack", "push", "push", 
//                                "pop", "top", "isEmpty"};
//     // List of inputs
//     vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

//     for (int i = 0; i < commands.size(); ++i) {
//         if (commands[i] == "push") {
//             st.push(inputs[i][0]);
//             cout << "null ";
//         } else if (commands[i] == "pop") {
//             cout << st.pop() << " ";
//         } else if (commands[i] == "top") {
//             cout << st.top() << " ";
//         } else if (commands[i] == "isEmpty") {
//             cout << (st.isEmpty() ? "true" : "false") << " ";
//         } else if (commands[i] == "QueueStack") {
//             cout << "null ";
//         }
//     }

//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

class QueueStack {
    queue<int> q;

public:
    void push(int x) {
        int s = q.size(); 
        q.push(x); 

        for (int i = 0; i < s; i++) {   //Eg-10 20
            q.push(q.front()); // Move the front element to the back  //Eg- 10 20 10
            q.pop();    // Remove the front element  //Eg- 20 10
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        } 
        int n = q.front(); 
        q.pop(); 
        return n; 
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front(); 
    }

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

};

// Main Function
int main() {
    QueueStack s;

   // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

   // Current front and size
    cout << "Front element: " << s.top() << endl;
    cout << "Size: " << s.getSize() << endl;

    // Pop elements
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    // Check again
    cout << "Front element after popping: " << s.top() << endl;
    cout << "Size after popping: " << s.getSize() << endl;

    // Pop remaining element
    cout << "Popped: " << s.pop() << endl;

    // Try popping from empty queue
    cout << "Popped: " << s.pop() << endl;

    // Final size check
    cout << "Final size: " << s.getSize() << endl;

    return 0;
}
