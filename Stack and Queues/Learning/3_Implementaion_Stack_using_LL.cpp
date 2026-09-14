// #include <bits/stdc++.h>
// using namespace std;

// // Node structure
// struct Node {
//     int val;
//     Node *next;
//     Node(int d) { //Constructor
//         val = d;
//         next = NULL;
//     }
// };

// // Structure to represent stack
// class LinkedListStack {
// private:
//     Node *head; // Top of Stack
//     int size; // Size

// public:
//     // Constructor
//     LinkedListStack() {
//         head = NULL;
//         size = 0;
//     }

//     // Method to push an element onto the stack
//     void push(int x) {
//         // Creating a node 
//         Node *element = new Node(x);
        
//         element->next = head; // Updating the pointers
//         head = element; // Updating the top
        
//         // Increment size by 1
//         size++;
//     }

//     // Method to pop an element from the stack
//     int pop() {
//         // If the stack is empty
//         if (head == NULL) {
//             return -1; // Pop operation cannot be performed
//         }
        
//         int value = head->val; // Get the top value
//         Node *temp = head; // Store the top temporarily
//         head = head->next; // Update top to next node
//         delete temp; // Delete old top node
//         size--; // Decrement size
        
//         return value; // Return data
//     }
    
//     // Method to get the top element of the stack
//     int top() {
//         // If the stack is empty
//         if (head == NULL) {
//             return -1; // Top element cannot be accessed
//         }
        
//         return head->val; // Return the top
//     }

//     // Method to check if the stack is empty
//     bool isEmpty() {
//         return (size == 0);
//     }
// };

// int main() {
//     // Creating a stack
//     LinkedListStack st;

//     // List of commands
//     vector<string> commands = {"LinkedListStack", "push", "push", 
//                                "pop", "top", "isEmpty"};
//     // List of inputs
//     vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

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
//         } else if (commands[i] == "LinkedListStack") {
//             cout << "null ";
//         }
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int d) {
        val = d;
        next = NULL;
    }
};

class LinkedListStack {
    Node* topNode;
    int sz;

public:
    LinkedListStack() {
        topNode = NULL;
        sz = 0;
    }
    
    ~LinkedListStack() {
        while (topNode != NULL) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // Push element
    void push(int x) {
        Node* temp = new Node(x);
        temp->next = topNode;
        topNode = temp;
        sz++;
    }

    // Returns top element
    int peek() {
        if (topNode == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->val;
    }

    // Removes and returns top element
    int pop() {
        if (topNode == NULL) {
            cout << "Stack underflow\n";
            return -1;
        }

        Node* temp = topNode;
        int value = temp->val;
        topNode = topNode->next;
        delete temp;
        sz--;

        return value;
    }

    int size() {
        return sz;
    }
};

// Main Function
int main() {
    LinkedListStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;

    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    cout << "Top element after popping: " << s.peek() << endl;
    cout << "Size after popping: " << s.size() << endl;

    cout << "Popped: " << s.pop() << endl;

    cout << "Popped: " << s.pop() << endl; // empty case

    cout << "Final size: " << s.size() << endl;

    return 0;
}