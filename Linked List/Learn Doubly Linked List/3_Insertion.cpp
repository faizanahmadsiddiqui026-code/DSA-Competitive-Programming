// //Insertion before head in the DLL

// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//    public:
//    int data;  //object
//    Node* next;  //object
//    Node* back;  //object

//    public:
//    Node(int data1,Node* next1,Node* back1){  //Constructor 1
//      data=data1;
//      next=next1;
//      back=back1;
//    }

//     Node(int data1){  //Constructor 2
//      data=data1;
//      next=nullptr;
//      back=nullptr;
//    }
// };

// Node* convertArr2DLL(vector<int> &arr){
//   Node* head=new Node(arr[0]);
//   Node* prev=head;
//   for(int i=1;i<arr.size();i++){
//     Node* temp=new Node(arr[i],nullptr,prev);  //prev-pointing to back node 
//     prev->next=temp;  //to connect back node to next node
//     prev=temp;   //or prev=prev->next //to move prev to next node
//   }
//   return head;
// }
// void print(Node* head){
//     while(head!=NULL){
//       cout<<head->data<<" ";
//       head=head->next;
//     }
// }

// Node* insertBeforeHead(Node* head,int val){
//     Node* newHead=new Node(val,head,nullptr);
//     head->back=newHead;    //Robust code-we must add condition if head is not null then only apply this condition
//     return newHead;
// }

// int main(){
//   vector<int>arr={12,5,8,7};
//   Node* head=convertArr2DLL(arr);
//   head=insertBeforeHead(head,10);
//   print(head);
//   return 0;
// }






//Insertion before tail in the DLL

// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//    public:
//    int data;  //object
//    Node* next;  //object
//    Node* back;  //object

//    public:
//    Node(int data1,Node* next1,Node* back1){  //Constructor 1
//      data=data1;
//      next=next1;
//      back=back1;
//    }

//     Node(int data1){  //Constructor 2
//      data=data1;
//      next=nullptr;
//      back=nullptr;
//    }
// };

// Node* convertArr2DLL(vector<int> &arr){
//   Node* head=new Node(arr[0]);
//   Node* prev=head;
//   for(int i=1;i<arr.size();i++){
//     Node* temp=new Node(arr[i],nullptr,prev);  //prev-pointing to back node 
//     prev->next=temp;  //to connect back node to next node
//     prev=temp;   //or prev=prev->next //to move prev to next node
//   }
//   return head;
// }
// void print(Node* head){
//     while(head!=NULL){
//       cout<<head->data<<" ";
//       head=head->next;
//     }
// }

// Node* insertBeforeHead(Node* head,int val){
//     Node* newHead=new Node(val,head,nullptr);
//     head->back=newHead;
//     return newHead;
// }

// Node* insertBeforeTail(Node* head,int val){
//     if(head->next==NULL) return insertBeforeHead(head,val);
//     Node* tail=head;
//     while(tail->next!=NULL){
//         tail=tail->next;
//     }
//     Node* prev=tail->back;
//     Node* newNode=new Node(val,tail,prev);
//     prev->next=newNode;
//     tail->back=newNode;
//     return head;
// }

// int main(){
//   vector<int>arr={12,5,8,7};
//   Node* head=convertArr2DLL(arr);
//   head=insertBeforeTail(head,10);
//   print(head);
//   return 0;
// }






//Insertion before the Kth element in the DLL

// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//    public:
//    int data;  //object
//    Node* next;  //object
//    Node* back;  //object

//    public:
//    Node(int data1,Node* next1,Node* back1){  //Constructor 1
//      data=data1;
//      next=next1;
//      back=back1;
//    }

//     Node(int data1){  //Constructor 2
//      data=data1;
//      next=nullptr;
//      back=nullptr;
//    }
// };

// Node* convertArr2DLL(vector<int> &arr){
//   Node* head=new Node(arr[0]);
//   Node* prev=head;
//   for(int i=1;i<arr.size();i++){
//     Node* temp=new Node(arr[i],nullptr,prev);  //prev-pointing to back node 
//     prev->next=temp;  //to connect back node to next node
//     prev=temp;   //or prev=prev->next //to move prev to next node
//   }
//   return head;
// }
// void print(Node* head){
//     while(head!=NULL){
//       cout<<head->data<<" ";
//       head=head->next;
//     }
// }

// Node* insertBeforeHead(Node* head,int val){
//     Node* newHead=new Node(val,head,nullptr);
//     head->back=newHead;
//     return newHead;
// }

// Node* insertBeforeTail(Node* head,int val){
//     if(head->next==NULL) return insertBeforeHead(head,val);
//     Node* tail=head;
//     while(tail->next!=NULL){
//         tail=tail->next;
//     }
//     Node* prev=tail->back;
//     Node* newNode=new Node(val,tail,prev);
//     prev->next=newNode;
//     tail->back=newNode;
//     return head;
// }

// Node* insertBeforeKthElement(Node* head,int k,int val){
//     if(k==1) return insertBeforeHead(head,val);
//     Node* temp=head;
//     int cnt=0;
//     while(temp!=NULL){
//         cnt++;
//         if(cnt==k) break;
//         temp=temp->next;
//     }
//     Node* prev=temp->back;
//     Node* newNode=new Node(val,temp,prev);
//     prev->next=newNode;
//     temp->back=newNode;
//     return head;
// }

// int main(){
//   vector<int>arr={12,5,8,7};
//   Node* head=convertArr2DLL(arr);
//   head=insertBeforeKthElement(head,3,10);
//   print(head);
//   return 0;
// }







//Insertion before the given node in the DLL

// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//    public:
//    int data;  //object
//    Node* next;  //object
//    Node* back;  //object

//    public:
//    Node(int data1,Node* next1,Node* back1){  //Constructor 1
//      data=data1;
//      next=next1;
//      back=back1;
//    }

//     Node(int data1){  //Constructor 2
//      data=data1;
//      next=nullptr;
//      back=nullptr;
//    }
// };

// Node* convertArr2DLL(vector<int> &arr){
//   Node* head=new Node(arr[0]);
//   Node* prev=head;
//   for(int i=1;i<arr.size();i++){
//     Node* temp=new Node(arr[i],nullptr,prev);  //prev-pointing to back node 
//     prev->next=temp;  //to connect back node to next node
//     prev=temp;   //or prev=prev->next //to move prev to next node
//   }
//   return head;
// }
// void print(Node* head){
//     while(head!=NULL){
//       cout<<head->data<<" ";
//       head=head->next;
//     }
// }

// void insertBeforeNode(Node* node,int val){
//     Node* prev=node->back;
//     Node* newNode=new Node(val,node,prev);
//     if(prev != NULL){
//         prev->next = newNode;
//     }
//     node->back=newNode;
// }


// int main(){
//   vector<int>arr={12,5,8,7};
//   Node* head=convertArr2DLL(arr);
//   insertBeforeNode(head->next,3);
//   print(head);
//   return 0;
// }





// //Insertion after head in the DLL

// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* back;

//     // Constructor with next and back
//     Node(int data1, Node* next1, Node* back1) {
//         data = data1;
//         next = next1;
//         back = back1;
//     }

//     // Constructor for single node
//     Node(int data1) {
//         data = data1;
//         next = nullptr;
//         back = nullptr;
//     }
// };

// // Convert array to DLL
// Node* convertArr2DLL(vector<int>& arr) {
//     if (arr.empty()) return nullptr;

//     Node* head = new Node(arr[0]);
//     Node* prev = head;

//     for (int i = 1; i < arr.size(); i++) {
//         Node* temp = new Node(arr[i], nullptr, prev);
//         prev->next = temp;
//         prev = temp;
//     }
//     return head;
// }

// // Print DLL
// void print(Node* head) {
//     while (head != nullptr) {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// // Insert node after head
// Node* insertAfterHead(Node* head, int val) {
//     if (head == nullptr) {
//         // If list is empty, new node becomes the head
//         return new Node(val);
//     }

//     Node* newNode = new Node(val, head->next, head); // next points to head's next, back points to head
//     if (head->next != nullptr) {
//         head->next->back = newNode;  // fix the back pointer of the old next node
//     }
//     head->next = newNode;  // link head to the new node

//     return head; // head remains the same
// }

// int main() {
//     vector<int> arr = {12, 5, 8, 7};
//     Node* head = convertArr2DLL(arr);

//     head = insertAfterHead(head, 100); // Insert 100 after the head (12)

//     print(head); // Output: 12 100 5 8 7

//     return 0;
// }






//Insertion after tail in the DLL

// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* back;

//     Node(int data1, Node* next1, Node* back1) {
//         data = data1;
//         next = next1;
//         back = back1;
//     }

//     Node(int data1) {
//         data = data1;
//         next = nullptr;
//         back = nullptr;
//     }
// };

// // Convert array to DLL
// Node* convertArr2DLL(vector<int>& arr) {
//     if (arr.empty()) return nullptr;

//     Node* head = new Node(arr[0]);
//     Node* prev = head;

//     for (int i = 1; i < arr.size(); i++) {
//         Node* temp = new Node(arr[i], nullptr, prev);
//         prev->next = temp;
//         prev = temp;
//     }
//     return head;
// }

// // Print DLL
// void print(Node* head) {
//     while (head != nullptr) {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// // Insert after tail
// Node* insertAfterTail(Node* head, int val) {
//     if (head == nullptr) {
//         // Empty list → new node is the head
//         return new Node(val);
//     }

//     // Move to tail
//     Node* tail = head;
//     while (tail->next != nullptr) {
//         tail = tail->next;
//     }

//     // Create new node
//     Node* newNode = new Node(val, nullptr, tail);
//     tail->next = newNode;  // tail points forward to new node

//     return head; // head stays the same
// }

// int main() {
//     vector<int> arr = {12, 5, 8, 7};
//     Node* head = convertArr2DLL(arr);

//     head = insertAfterTail(head, 100); // Insert 100 after tail (7)

//     print(head); // Output: 12 5 8 7 100

//     return 0;
// }





//Insertion after the Kth element in the DLL

// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* back;

//     Node(int data1, Node* next1, Node* back1) {
//         data = data1;
//         next = next1;
//         back = back1;
//     }

//     Node(int data1) {
//         data = data1;
//         next = nullptr;
//         back = nullptr;
//     }
// };

// // Convert array to DLL
// Node* convertArr2DLL(vector<int>& arr) {
//     if (arr.empty()) return nullptr;

//     Node* head = new Node(arr[0]);
//     Node* prev = head;
//     for (int i = 1; i < arr.size(); i++) {
//         Node* temp = new Node(arr[i], nullptr, prev);
//         prev->next = temp;
//         prev = temp;
//     }
//     return head;
// }

// // Print DLL
// void print(Node* head) {
//     while (head != nullptr) {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// // Insert after Kth element
// Node* insertAfterKthElement(Node* head, int k, int val) {
//     if (head == nullptr) return new Node(val);  // empty list

//     Node* temp = head;
//     int cnt = 1;

//     while (temp != nullptr && cnt < k) {
//         temp = temp->next;
//         cnt++;
//     }

//     if (temp == nullptr) {
//         cout << "Error: K is greater than the length of the list.\n";
//         return head;
//     }

//     Node* nextNode = temp->next;
//     Node* newNode = new Node(val, nextNode, temp);  // next = temp->next, back = temp
//     temp->next = newNode;                            // temp points forward to new node
//     if (nextNode != nullptr) {
//         nextNode->back = newNode;                    // fix back pointer of next node
//     }

//     return head;
// }

// int main() {
//     vector<int> arr = {12, 5, 8, 7};
//     Node* head = convertArr2DLL(arr);

//     head = insertAfterKthElement(head, 3, 10); // Insert 10 after 3rd element (8)

//     print(head); // Output: 12 5 8 10 7

//     return 0;
// }







//Insertion after the given node in the DLL

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Convert array to DLL
Node* convertArr2DLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Print DLL
void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Insert after a given node
void insertAfterNode(Node* node, int val) {
    if (node == nullptr) return;

    Node* nextNode = node->next;
    Node* newNode = new Node(val, nextNode, node);

    node->next = newNode;        // Link given node to new node
    if (nextNode != nullptr) {
        nextNode->back = newNode; // Fix back pointer of old next node
    }
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);

    insertAfterNode(head->next, 3); // Insert 3 after 2nd node (5)

    print(head); // Output: 12 5 3 8 7

    return 0;
}