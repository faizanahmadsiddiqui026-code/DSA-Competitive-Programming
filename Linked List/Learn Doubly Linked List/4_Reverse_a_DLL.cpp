// //Brute force
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


// Node* reverseDLL(Node* head){
//     stack<int>st;
//     Node* temp=head;
//     while(temp!=NULL){
//         st.push(temp->data);
//         temp=temp->next;
//     }
//     temp=head;
//     while(temp!=NULL){
//         temp->data=st.top();
//         st.pop();
//         temp=temp->next;
//     }
//     return head;
// }



// int main(){
//   vector<int>arr={12,5,8,6,7};
//   Node* head=convertArr2DLL(arr);
//   head=reverseDLL(head);
//   print(head);
//   return 0;
// }





//Optimal
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

Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* last=NULL;
    Node* current = head;
    while(current != nullptr){
        last = current->back;    // store previous
        current->back = current->next;  // swap
        current->next = last;    // swap

        current = current->back;      // move
    }
    return last->back;   //this is safer  return last ? last->back : head;
}

int main(){
  vector<int>arr={12,5,8,7};
  Node* head=convertArr2DLL(arr);
  head=reverseDLL(head);
  print(head);
  return 0;
}














