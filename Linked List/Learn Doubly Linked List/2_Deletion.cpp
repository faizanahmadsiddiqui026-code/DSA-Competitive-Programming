// //Deletion of head node of DLL

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

// Node* deletionHead(Node* head){
//    if(head==NULL || head->next==NULL) return NULL;  //but this doesn't delete the single elemnet DLL so again accesing the head node any cause undefined behaviour
//    Node* prev=head;
//    head=head->next;  

//    head->back=nullptr;
//    prev->next=nullptr;

//    delete prev;
//    return head;
// }



// int main(){
//   vector<int>arr={12,5,8,7};
//   Node* head=convertArr2DLL(arr);
//   head=deletionHead(head);
//   print(head);
//   return 0;
// }


//Use this in edge case for Not getting error if again access the head
//   if(head == NULL) return NULL; // empty list

//   if(head->next == NULL) {      // single-element list
//        delete head;              // free memory
//        return NULL;              // list is now empty
//   }



// Deletion of tail of the DLL

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

// Node* deletionTail(Node* head){
//    if(head==NULL || head->next==NULL) return NULL;  //but this doesn't delete the single elemnet DLL so again accesing the head node any cause undefined behaviour
//    Node* tail=head;
//    while(tail->next!=NULL){
//     tail=tail->next;
//    }
//    Node* prev=tail->back;  //here prev means newTail
//    prev->next=nullptr;
//    tail->back=nullptr;

//    delete tail;
//    return head;
// }


// int main(){
//   vector<int>arr={12,5,8,7};
//   Node* head=convertArr2DLL(arr);
//   head=deletionTail(head);
//   print(head);
//   return 0;
// }




//Deletion of Kth element in the DLL

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

// Node* deletionHead(Node* head){
//    if(head==NULL || head->next==NULL) return NULL;  //but this doesn't delete the single elemnet DLL so again accesing the head node any cause undefined behaviour
//    Node* prev=head;
//    head=head->next;  

//    head->back=nullptr;
//    prev->next=nullptr;

//    delete prev;
//    return head;
// }

// Node* deletionTail(Node* head){
//    if(head==NULL || head->next==NULL) return NULL;  //but this doesn't delete the single elemnet DLL so again accesing the head node any cause undefined behaviour
//    Node* tail=head;
//    while(tail->next!=NULL){
//     tail=tail->next;
//    }
//    Node* prev=tail->back;  //here prev means newTail
//    prev->next=nullptr;
//    tail->back=nullptr;

//    delete tail;
//    return head;
// }

// Node* deleteKthElement(Node* head,int k){
//   if(head==NULL) return NULL;
//   int cnt=0;
//   Node* kNode=head;
//   while(kNode!=NULL){
//     cnt++;
//     if(cnt==k) break;
//     kNode=kNode->next;
//   }

//   Node* prev=kNode->back;
//   Node* front=kNode->next;
  
//   if(prev==NULL && front==NULL){
//     delete kNode; // free memory
//     return NULL; //list becomes empty
//   }
//   else if(prev==NULL){
//     return deletionHead(head);
//   }
//   else if(front==NULL){
//     return deletionTail(head);
//   }

//   prev->next=front;
//   front->back=prev;

//   kNode->next=nullptr;  //Using NULL in place of nullptr will not give an error, but using nullptr is considered better practice.
//   kNode->back=nullptr;

//   delete kNode;
//   return head;
// }

// int main(){
//   vector<int>arr={12,5,8,7};
//   Node* head=convertArr2DLL(arr);
//   head=deleteKthElement(head,2);
//   print(head);
//   return 0;
// }



//Deletion of given node in the DLL

#include<bits/stdc++.h>
using namespace std;
struct Node{
   public:
   int data;  //object
   Node* next;  //object
   Node* back;  //object

   public:
   Node(int data1,Node* next1,Node* back1){  //Constructor 1
     data=data1;
     next=next1;
     back=back1;
   }

    Node(int data1){  //Constructor 2
     data=data1;
     next=nullptr;
     back=nullptr;
   }
};

Node* convertArr2DLL(vector<int> &arr){
  Node* head=new Node(arr[0]);
  Node* prev=head;
  for(int i=1;i<arr.size();i++){
    Node* temp=new Node(arr[i],nullptr,prev);  //prev-pointing to back node 
    prev->next=temp;  //to connect back node to next node
    prev=temp;   //or prev=prev->next //to move prev to next node
  }
  return head;
}
void print(Node* head){
    while(head!=NULL){
      cout<<head->data<<" ";
      head=head->next;
    }
}

void deleteNode(Node* temp){
   Node* prev=temp->back;
   Node* front =temp->next;
   if(front==NULL){  //last element case
      prev->next=nullptr;
      temp->back=nullptr;
      delete temp;
      return;
   }
   prev->next=front;
   front->back=prev;

   temp->next=temp->back=nullptr;
   delete temp;
}

int main(){
  vector<int>arr={12,5,8,7};
  Node* head=convertArr2DLL(arr);
  deleteNode(head->next->next);
  print(head);
  return 0;
}