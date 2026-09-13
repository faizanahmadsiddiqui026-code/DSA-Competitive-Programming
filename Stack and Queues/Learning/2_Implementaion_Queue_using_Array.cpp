// #include <bits/stdc++.h>
// using namespace std;

// // Class implementing Queue using Arrays
// class ArrayQueue {
//     // Array to store queue elements
//     int* arr;
//     // Indices for start and end of the queue
//     int start, end;
//     // Current size and maximum size of the queue
//     int currSize, maxSize;

// public:
//     // Constructor
//     ArrayQueue() {
//         arr = new int[10];
//         start = -1;
//         end = -1;
//         currSize = 0;
//         maxSize = 10;
//     }

//     // Method to push an element into the queue
//     void push(int x) {
//         // Check if the queue is full
//         if (currSize == maxSize) {
//             cout << "Queue is full\nExiting..." << endl;
//             exit(1);
//         }
        
//         // If the queue is empty, initialize start and end
//         if (end == -1) {
//             start = 0;
//             end = 0;
//         } 
//         else {
//             // Circular increment of end
//             end = (end + 1) % maxSize;
//         }
            
//         arr[end] = x;
//         currSize++;
//     }

//     // Method to pop an element from the queue
//     int pop() {
//         // Check if the queue is empty
//         if (start == -1) {
//             cout << "Queue Empty\nExiting..." << endl;
//             exit(1);
//         }
//         int popped = arr[start];
        
//         // If the queue has only one element, reset start and end
//         if (currSize == 1) {
//             start = -1;
//             end = -1;
//         }
//         else {
//             // Circular increment of start
//             start = (start + 1) % maxSize;
//         }
        
//         currSize--;
//         return popped;
//     }

//     // Method to get the front element of the queue
//     int peek() {
//         // Check if the queue is empty
//         if (start == -1) {
//             cout << "Queue is Empty" << endl;
//             exit(1);
//         }
//         return arr[start];
//     }

//     // Method to determine whether the queue is empty
//     bool isEmpty() {
//         return (currSize == 0);
//     }
// };

// int main() {
//     ArrayQueue queue;
//     vector<string> commands = {"ArrayQueue", "push", "push", 
//                                "peek", "pop", "isEmpty"};
//     vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

//     for (int i = 0; i < commands.size(); ++i) {
//         if (commands[i] == "push") {
//             queue.push(inputs[i][0]);
//             cout << "null ";
//         } else if (commands[i] == "pop") {
//             cout << queue.pop() << " ";
//         } else if (commands[i] == "peek") {
//             cout << queue.peek() << " ";
//         } else if (commands[i] == "isEmpty") {
//             cout << (queue.isEmpty() ? "true" : "false") << " ";
//         } else if (commands[i] == "ArrayQueue") {
//             cout << "null ";
//         }
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
class ArrayQueue {
    int size;
    int *q; //for making array
    int curr_size;
    int start;
    int end;


public:
    ArrayQueue() { //Constructor
        size=10;
        q= new int[size];
        curr_size=0;
        start=-1;
        end=-1;
    }

    // Destructor (important to avoid memory leak)
    ~ArrayQueue() {
        delete[] q;
    }

    // Pushes element x 
    void push(int x) {
        if (curr_size==size) {
            cout << "Queue overflow" << endl;
            return;
        }
        if(curr_size==0){
            start=0;
            end=0;
        }
        else{
            end=(end+1)%size;
        }
        q[end] = x;
        curr_size++;
    }

    // Removes and returns front element
    int pop() {
        if (curr_size==0){ 
            cout << "Queue is empty" << endl;
            return -1; 
        }
        int el=q[start];
        if(curr_size==1){
            start=-1;
            end=-1;
        }
        else{
            start=(start+1)%size;
        }
        curr_size--;
        return el;
    }

    // Returns front element
    int peek() {
        if (curr_size==0) {
            cout << "Queue is empty" << endl;
            return -1; 
        }
        return q[start];
    }

    int getSize(){
        return curr_size;
    }
};

// Main Function
int main() {
    ArrayQueue s;

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


//Renamed size() function → getSize() to avoid conflict with variable size
//Removed invalid int q[size]; (size wasn’t initialized yet)
// Used dynamic allocation int *q





// Queue vs Stack terminology
// Concept	         Queue	                     Stack
// Insert operation	 enqueue / push	             push
// Remove operation	 dequeue / pop	             pop
// Access element	 front / rear	             top
// Ends used	     front & rear	             top only
// Order	         FIFO (First In First Out)	 LIFO (Last In First Out)