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

// Node* segregateEvenOdd(Node* head){
//     if(head==NULL || head->next==NULL) return head;
//     vector<int>arr;
//     Node* temp=head;
//     while(temp!=NULL && temp->next!=NULL){
//         arr.push_back(temp->data);
//         temp=temp->next->next;
//     }
//     if(temp!=NULL)  arr.push_back(temp->data);

//     temp=head->next;
//     while(temp!=NULL && temp->next!=NULL){
//         arr.push_back(temp->data);
//         temp=temp->next->next;
//     }
//     if(temp!=NULL)  arr.push_back(temp->data);

//     int i=0;
//     temp=head;
//     while(temp!=NULL){
//         temp->data=arr[i];
//         i++;
//         temp=temp->next;
//     }
//     return head;
// }


// int main(){
//     vector<int>arr={1,2,3,2,1};
//     Node* head=convertArr2LL(arr);
//     head=segregateEvenOdd(head);
//     Node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     freeList(head); // ✅ FIX: free memory
//     return 0;
// }





//Optimal(using link)
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

Node* segregateEvenOdd(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=head->next;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}


int main(){
    vector<int>arr={1,2,3,2,1};
    Node* head=convertArr2LL(arr);
    head=segregateEvenOdd(head);
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    freeList(head); // ✅ FIX: free memory
    return 0;
}
