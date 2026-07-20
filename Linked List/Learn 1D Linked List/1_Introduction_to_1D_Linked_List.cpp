#include<bits/stdc++.h>
using namespace std;
struct Node{
   public:
   int data;  //object
   Node* next;  //object

   public:
   Node(int data1,Node* next1){  //Constructor 1
     data=data1;
     next=next1;
   }

    public:
    Node(int data1){  //Constructor 2
     data=data1;
     next=nullptr;
   }
};

int main(){
   vector<int>arr={2,5,8,7};
//    Using a pointer: Node* y

   Node* y=new Node(arr[0],nullptr);
   cout<<y<<endl; //It prints the address(memory location) of the Node object that y points to, not the address of y itself .❌ y does NOT store address of arr[0] ✅ y stores address of a new Node object ✅ That Node object contains a copy of value 2
// y is on the stack, but it contains the heap address of the Node.
// cout << y prints that heap address.

// if you wanted to print the address of the pointer y itself (on the stack), you would do:
// cout << &y << endl;
// &y gives the address of the variable y itself, which is on the stack

// new Node(...) allocates memory on the heap and returns a pointer to it and y stores the address of that node.
// y is a pointer to a Node.
// Access members using ->:
// cout<<y.data;//gives error
// cout<<y.next;//gives error
//Reason-Trying y.data or y.next fails because y is a pointer, not the object itself.
// to solve this
   cout<<y->data<<endl;
   cout<<y->next<<endl;
   
//    Using an object directly: Node x

// x is an actual object, stored on the stack.
   Node x=Node(arr[0],nullptr);//Creating an Object where these 2 things are there
// cout<<a; //throws a error because it's an Object
   //We can do this 
   cout<<x.data<<endl;
   cout<<x.next<<endl;
// You cannot use x->data here because x is not a pointer.

   Node* z=new Node(arr[0]);
// cout<<z.data;//gives error
// cout<<z.next;//gives error
// to solve this
   cout<<z->data<<endl;
   cout<<z->next<<endl;
}
//A Constructor is a special type of member function which is used to initialise the object of the class

// Difference between Node and Node*
// Aspect	 Node	                    Node*
// Storage  Object itself (stack)	    Pointer to object (heap or stack)
// Access	 Use . to access members	Use -> to access members
// Memory management	Automatically destroyed when out of scope	Must delete manually if created with new
// Example	            Node x(5, nullptr);	                        Node* y = new Node(5, nullptr);

// Node → actual node object.
// Node* → pointer to a node object

// If obj is an object: obj.data
// If ptr is a pointer: ptr->data or (*ptr).data


// Extra Tip
// When building a linked list, you almost always use new (heap allocation) because:
// You don’t know the size ahead of time.
// You want nodes to persist beyond function scope.
// Stack allocation (Node x) is only useful for temporary or small objects that don’t need dynamic linking.




//We can also use class in place of struct and it will work similar to struct 

// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//    public:
//    int data;  //object
//    Node* next;  //object

//    public:
//    Node(int data1,Node* next1){  //Constructor 1
//      data=data1;
//      next=next1;
//    }

//     public:
//     Node(int data1){  //Constructor 2
//      data=data1;
//      next=nullptr;
//    }
// };

// int main(){
//    vector<int>arr={2,5,8,7};
//    Node* y=new Node(arr[0],nullptr);
//    cout<<y<<endl; //gives pointer to this memory location
// // cout<<y.data;//gives error
// // cout<<y.next;//gives error
// // to solve this
//    cout<<y->data<<endl;
//    cout<<y->next<<endl;

//    Node x=Node(arr[0],nullptr);//Creating an Object where these 2 things are there
// // cout<<a; //throws a error because it's an Object
//    //We can do this 
//    cout<<x.data<<endl;
//    cout<<x.next<<endl;

//    Node* z=new Node(arr[0]);
// // cout<<z.data;//gives error
// // cout<<z.next;//gives error
// // to solve this
//    cout<<z->data<<endl;
//    cout<<z->next<<endl;
// }








// You do NOT need to write public multiple times. One public: is enough for everything that comes after it (until another access specifier appears).
// public: applies to everything below it until:
// another access specifier appears (private: / protected:), or
// the class ends.


// When do you use multiple public:?
// Only when you switch access levels, like:

// class Example {
// private:
//     int x;

// public:
//     void setX(int val) { x = val; }

// private:
//     int secret;

// public:
//     void show() { cout << x; }
// };

// Here multiple public: blocks are meaningful because you're switching between private and public.

// ✅ Best practice: use one public: block unless changing access levels