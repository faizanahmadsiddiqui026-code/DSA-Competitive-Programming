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

// Node* startingPoint(Node* head){
//     map<Node*,int>mpp;
//     Node* temp=head;
//     while(temp!=NULL){
//         if(mpp.find(temp)!=mpp.end()) return temp;
//         mpp[temp]++;
//         temp=temp->next;
//     }
//     return NULL;
// }

// int main(){
//     vector<int>arr={12,5,8,7};
//     Node* head=convertArr2LL(arr);
//     head->next->next->next->next = head->next; 
//     Node* startingNode=startingPoint(head);

//     if(startingNode != NULL){
//         cout<<startingNode->data;
//     }
//     else{
//         cout << "No cycle detected";
//     }
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

Node* startingNode(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}



int main(){
  vector<int>arr={12,5,8,7};
  Node* head=convertArr2LL(arr);

  // 🔁 Create a cycle manually
  head->next->next->next->next = head->next; 
  // 7 → points back to 5

  Node* startingPoint=startingNode(head);
  if(startingPoint)
        cout << startingPoint->data;
  else
        cout << "No cycle";
  return 0;
}

