// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
    
// public:
//     Node (int data1){
//         data=data1;
//         next=nullptr;
//     }

//     Node (int data1, Node* next1){
//     data = data1;
//     next = next1;
// }
// };

// Node* convertArr2LL(vector<int> &arr){
//     Node* head=new Node(arr[0]);
//     Node* mover=head;
//     for(int i=1;i<arr.size();i++){
//       Node* temp=new Node(arr[i]);
//       mover->next=temp;
//       mover=temp;
//     }
//     return head;
// }
// void print(Node* head){
//     while(head!=NULL){
//       cout<<head->data<<" ";
//       head=head->next;
//     }
// }

// Node* reverseLL(Node* head){
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
//   vector<int>arr={12,5,8,7};
//   Node* head=convertArr2LL(arr);
//   head=reverseLL(head);
//   print(head);
//   return 0;
// }






//Optimal
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    
public:
    Node (int data1){
        data=data1;
        next=nullptr;
    }

    Node (int data1, Node* next1){
    data = data1;
    next = next1;
}
};

Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
      Node* temp=new Node(arr[i]);
      mover->next=temp;
      mover=temp;
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
      cout<<head->data<<" ";
      head=head->next;
    }
}

Node* reverseLL(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}



int main(){
  vector<int>arr={12,5,8,7};
  Node* head=convertArr2LL(arr);
  head=reverseLL(head);
  print(head);
  return 0;
}

