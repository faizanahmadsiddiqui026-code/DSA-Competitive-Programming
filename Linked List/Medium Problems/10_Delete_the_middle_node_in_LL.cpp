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
//     if(arr.empty()) return NULL;
//     Node* head=new Node(arr[0]);
//     Node* mover=head;
//     for(int i=1;i<arr.size();i++){
//       Node* temp=new Node(arr[i]);
//       mover->next=temp;
//       mover=temp;
//     }
//     return head;
// }

// void freeList(Node* head){
//     while(head != NULL){
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//     }
// }

// Node* deleteTheMiddleNode(Node* head){
//     if(head==NULL || head->next==NULL) return NULL;

//     Node* temp=head;
//     int n=0;

//     while(temp!=NULL){
//         n++;
//         temp=temp->next;
//     }

//     int res=n/2;
//     temp=head;
//     while(temp!=NULL){
//         res--;
//         if(res==0){
//             Node* middle=temp->next;
//             temp->next=temp->next->next;
//             delete middle;
//             break;
//         }
//         temp=temp->next;
//     }
//     return head;

// }


// int main(){
//     vector<int>arr={1,2,3,2,1};
//     Node* head=convertArr2LL(arr);
//     head=deleteTheMiddleNode(head);
//     Node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     freeList(head); // ✅ FIX: free memory
//     return 0;
// }



//Optimal(Modified Tortoise & Hare Algorithm)
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
    if(arr.empty()) return NULL;
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
      Node* temp=new Node(arr[i]);
      mover->next=temp;
      mover=temp;
    }
    return head;
}

void freeList(Node* head){
    while(head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* deleteTheMiddleNode(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* middle=slow->next;
    slow->next=slow->next->next;
    delete middle;
    return head;
}


int main(){
    vector<int>arr={1,2,3,2,1};
    Node* head=convertArr2LL(arr);
    head=deleteTheMiddleNode(head);
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    freeList(head); // ✅ FIX: free memory
    return 0;
}
