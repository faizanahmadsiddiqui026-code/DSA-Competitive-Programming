// //Getting the Head Node by Converting array to linked list

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
// Node* convertArr2LL(vector<int>&arr){
//    Node* head =new Node(arr[0]);
//    Node* mover=head;
//    for(int i=1;i<arr.size();i++){
//     Node* temp=new Node(arr[i]);
//     mover->next=temp;
//     mover=temp; //mover=mover_>next
//    } 
//    return head;
// }
// int main(){
//    vector<int>arr={12,5,8,7};
//     Node* head=convertArr2LL(arr);
//     cout<<head->data;
// }

//Time Complexity-O(N), where N is No of iteration,we traverse to every element and store it



// // //Traversal In LL

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
// Node* convertArr2LL(vector<int>&arr){
//    Node* head =new Node(arr[0]);
//    Node* mover=head;   //create mover pointer
//    for(int i=1;i<arr.size();i++){
//     Node* temp=new Node(arr[i]);   //new node created
//     mover->next=temp;      //Link nodes
//     mover=temp; //mover=mover_>next  //move mover and update it value using temp
//    } 
//    return head;
// }
// int main(){
//    vector<int>arr={12,5,8,7};
//     Node* head=convertArr2LL(arr);
//     Node* temp=head;
//     while(temp){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }



// //Length of a LL

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

// Node* convertArr2LL(vector<int>&arr){
//    Node* head =new Node(arr[0]);
//    Node* mover=head;
//    for(int i=1;i<arr.size();i++){
//     Node* temp=new Node(arr[i]);
//     mover->next=temp;
//     mover=temp; //mover=mover_>next
//    } 
//    return head;
// }

// int lengthOfLL(Node* head){
//     int cnt=0;
//     Node* temp=head;    // Initialize a temporary pointer to head
//     while(temp){   //OR //while (temp != nullptr) {
//         temp=temp->next;
//         cnt++;
//     }
//     return cnt;
// }

// int main(){
//    vector<int>arr={12,5,8,7};
//     Node* head=convertArr2LL(arr);
//     cout<<lengthOfLL(head);
// }


// Time Complexity: O(N), we traverse the entire linked list once to find the total number of nodes.
// Space Complexity: O(1) , we use fixed number of pointers and variables to find the length of linked list.




//    // Creating linked list: 10 -> 20 -> 30
//     Node* head = new Node(10);
//     head->next = new Node(20);
//     head->next->next = new Node(30);



//Search of an element

#include<bits/stdc++.h>
using namespace std;
class Node{
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

Node* convertArr2LL(vector<int>&arr){
   Node* head =new Node(arr[0]);
   Node* mover=head;
   for(int i=1;i<arr.size();i++){
    Node* temp=new Node(arr[i]);
    mover->next=temp;
    mover=temp; //mover=mover_>next
   } 
   return head;
}

int checkIfPresent(Node* head,int val){
    Node* temp=head;
    while(temp){
        if(temp->data==val) return 1;
        temp=temp->next;
    }
    return 0;
} 

int main(){
   vector<int>arr={12,5,8,7};
    Node* head=convertArr2LL(arr);
    cout<<checkIfPresent(head,5);
}

// Time Complexity-O(N)-worst case,we traverse the entire linked list once in worst case to search for the required value., O(1)-best case,if it is head  O(N/2)-avg case
// Space Complexity: O(1) , we use a constant amount of additional space, regardless of the linked list's length to search for an element.
