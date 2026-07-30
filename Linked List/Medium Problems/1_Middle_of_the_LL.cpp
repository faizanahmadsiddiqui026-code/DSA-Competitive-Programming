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

// Node* middleElement(Node* head){
//    Node* temp=head;
//    int cnt=0;
//    while(temp!=NULL){
//     cnt++;
//     temp=temp->next;
//    }
//    int midNode=(cnt/2)+1;
//    temp =head;
//    while(temp!=NULL){
//     midNode--;
//     if(midNode==0) break;
//     temp=temp->next;
//    }
//    return temp;
// }


// int main(){
//   vector<int>arr={12,5,8,7};
//   Node* head=convertArr2LL(arr);
//   Node* mid=middleElement(head);
//   cout<<mid->data;
//   return 0;
// }





//Optimal(Tortoise and hare algorithm)(Slow and Fast Pointer)
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

Node* middleElement(Node* head){
   Node* slow=head;
   Node* fast=head;
   while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
   }
   return slow;
}


int main(){
  vector<int>arr={12,5,4,8,7};
  Node* head=convertArr2LL(arr);
  Node* mid=middleElement(head);
  cout<<mid->data;
  return 0;
}

