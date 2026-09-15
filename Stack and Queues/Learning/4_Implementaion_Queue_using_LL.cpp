// #include <bits/stdc++.h>
// using namespace std;

// // Node structure
// struct Node {
//     int val;
//     Node *next;
//     Node(int d) {
//         val = d;
//         next = NULL;
//     }
// };

// // Structure to represent stack
// class LinkedListQueue {
// private:
//     Node *start; // Start of the queue
//     Node *end; // End of the queue
//     int size; // Size of the queue

// public:
//     // Constructor
//     LinkedListQueue() {
//         start = end = NULL;
//         size = 0;
//     }

//     // Method to push an element in the queue
//     void push(int x) {
//         // Creating a node 
//         Node *element = new Node(x);
        
//         // If it is the first element being pushed
//         if(start == NULL) {
//             // Initialise the pointers
//             start = end = element;
//         }
//         else {
//             end->next = element; // Updating the pointers
//             end = element; // Updating the end
//         }
        
//         // Increment size by 1
//         size++;
//     }

//     // Method to pop an element from the queue
//     int pop() {
//         // If the queue is empty
//         if (start == NULL) {
//             return -1; // Pop operation cannot be performed
//         }
        
//         int value = start->val; // Get the front value
//         Node *temp = start; // Store the front temporarily
//         start = start->next; // Update front to next node
//         delete temp; // Delete old front node
//         size--; // Decrement size
        
//         return value; // Return data
//     }
    
//     // Method to get the front element in the queue
//     int peek() {
//         // If the stack is empty
//         if (start == NULL) {
//             return -1; // Top element cannot be accessed
//         }
        
//         return start->val; // Return the top
//     }

//     // Method to check if the queue is empty
//     bool isEmpty() {
//         return (size == 0);
//     }
// };

// int main() {
//     // Creating a queue
//     LinkedListQueue q;

//     // List of commands
//     vector<string> commands = {"LinkedListQueue", "push", "push", 
//                                "peek", "pop", "isEmpty"};
//     // List of inputs
//     vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

//     for (int i = 0; i < commands.size(); ++i) {
//         if (commands[i] == "push") {
//             q.push(inputs[i][0]);
//             cout << "null ";
//         } else if (commands[i] == "pop") {
//             cout << q.pop() << " ";
//         } else if (commands[i] == "peek") {
//             cout << q.peek() << " ";
//         } else if (commands[i] == "isEmpty") {
//             cout << (q.isEmpty() ? "true" : "false") << " ";
//         } else if (commands[i] == "LinkedListQueue") {
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
    Node(int d) { //Constructor
        val = d;
        next = NULL;
    }
};

class LinkedListQueue {
    Node* start;
    Node* end;
    int sz;

public:
    LinkedListQueue() {
        start=end=NULL;
        sz = 0;
    }
    ~LinkedListQueue() {
        while (start != NULL) {
            Node* temp = start;
            start = start->next;
            delete temp;
        }
    }
    
    // Pushes element x 
    void push(int x) {
        Node* temp=new Node(x);
        if(start==NULL){ //no elements
            start=end=temp;
        }
        else{
            end->next=temp;
            end=temp;
        }
        sz++;
    }

    // Removes and returns front element
    int pop() {
        if (start==NULL){ 
            cout << "Queue is empty" << endl;
            return -1; 
        }
        Node* temp=start;
        int val=temp->val;
        start = start->next;
        if (start==NULL) { //for 1 element
            end = NULL;
        }
        delete temp;
        sz--;
        return val; 
    }

    // Returns front element
    int peek() {
        if (start==NULL) { 
            cout << "Queue is empty" << endl;
            return -1; 
        }
        return start->val;
    }

    int getSize(){
        return sz;
    }
};

// Main Function
int main() {
    LinkedListQueue s;

   // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

   // Current front and size
    cout << "Front element: " << s.peek() << endl;
    cout << "Size: " << s.getSize() << endl;

    // Pop elements
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    // Check again
    cout << "Front element after popping: " << s.peek() << endl;
    cout << "Size after popping: " << s.getSize() << endl;

    // Pop remaining element
    cout << "Popped: " << s.pop() << endl;

    // Try popping from empty queue
    cout << "Popped: " << s.pop() << endl;

    // Final size check
    cout << "Final size: " << s.getSize() << endl;

    return 0;
}

