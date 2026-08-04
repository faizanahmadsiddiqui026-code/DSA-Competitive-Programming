// //Brute force(using Hashing)
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

// int lengthOfLoop(Node* head){
//     map<Node*,int>mpp;
//     Node* temp=head;
//     int timer=1;
//     while(temp!=NULL){
//         if(mpp.find(temp)!=mpp.end()){
//             int value=mpp[temp];
//             return (timer-value);
//         }
//         mpp[temp]=timer;
//         timer++;
//         temp=temp->next;
//     }
//     return 0;
// }

// int main(){
//     vector<int>arr={12,5,8,7};
//     Node* head=convertArr2LL(arr);
//     head->next->next->next->next = head->next; 
//     int length=lengthOfLoop(head);
//     cout<<length;
//     return 0;
// }




//Optimal(Tortoise & Hare Algorithm)
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

int findLength(Node* slow,Node* fast){
    int cnt=1;
    fast=fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}

int lengthOfLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return findLength(slow,fast);
        }
    }
    return 0;
}


int main(){
  vector<int>arr={12,5,8,7};
  Node* head=convertArr2LL(arr);

  // 🔁 Create a cycle manually
  head->next->next->next->next = head->next; 
  // 7 → points back to 5

  int length=lengthOfLoop(head);
  cout<<length;
  return 0;
}

