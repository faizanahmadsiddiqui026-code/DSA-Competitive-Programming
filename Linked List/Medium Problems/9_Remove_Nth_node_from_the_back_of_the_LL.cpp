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

// Node* removeNthNode(Node* head,int n){
//     if(head==NULL) return head;
//     int cnt=0;
//     Node* temp=head;
//     while(temp!=NULL){
//         cnt++;
//         temp=temp->next;
//     }
//     if(cnt==n){   // delete first node
//         Node* newHead=head->next;
//         delete head;
//         return newHead;
//     }
//     int res=cnt-n;
//     temp=head;
//     while(temp!=NULL){
//         res--;
//         if(res==0) break;
//         temp=temp->next;
//     }
//     Node* delNode=temp->next;
//     temp->next=temp->next->next;
//     delete delNode;
//     return head;
// }


// int main(){
//     vector<int>arr={1,2,3,2,1};
//     Node* head=convertArr2LL(arr);
//     int n=2;
//     head=removeNthNode(head,n);
//     Node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     freeList(head); // ✅ FIX: free memory
//     return 0;
// }





//Optimal(using 2 pointer)
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

Node* removeNthNode(Node* head,int n){
    Node* fast=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }

    // if fast is NULL → delete head
    if(fast == NULL){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    Node* slow=head;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node* delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
}


int main(){
    vector<int>arr={1,2,3,2,1};
    Node* head=convertArr2LL(arr);
    int n=2;
    head=removeNthNode(head,n);
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    freeList(head); // ✅ FIX: free memory
    return 0;
}

