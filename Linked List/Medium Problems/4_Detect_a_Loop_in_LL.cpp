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
 

// int main(){
//     vector<int>arr={12,5,8,7};
//     Node* head=convertArr2LL(arr);
//     head->next->next->next->next = head->next; 
//     map<Node*,int>mpp;
//     Node* temp=head;
//     while(temp!=NULL){
//         if(mpp.find(temp)!=mpp.end()){
//             cout<<"true";
//             return 0;
//         }
//         mpp[temp]++;
//         temp=temp->next;
//     }
//     cout<<"false";
//   return 0;
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

bool detectCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}



int main(){
  vector<int>arr={12,5,8,7};
  Node* head=convertArr2LL(arr);

  // 🔁 Create a cycle manually
  head->next->next->next->next = head->next; 
  // 7 → points back to 5

  bool loop=detectCycle(head);
  cout << (loop ? "true" : "false");  //cout << boolalpha << loop;
  return 0;
}

