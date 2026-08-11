//Brute force
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

// Node* sortLL(Node* head){
//    vector<int>arr;
//    Node* temp=head;
//    while(temp!=NULL){
//         arr.emplace_back(temp->data);
//         temp=temp->next;
//    }
//    sort(arr.begin(),arr.end());

//    int i=0;
//    temp=head;
//    while(temp!=NULL){
//     temp->data=arr[i];
//     i++;
//     temp=temp->next;
//    }
//    return head;
// }


// int main(){
//     vector<int>arr={1,2,3,2,1};
//     Node* head=convertArr2LL(arr);
//     head=sortLL(head);
//     Node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
//     freeList(head); // ✅ FIX: free memory
//     return 0;
// }


//Optimal(using merge sort and modified version of tortoise and hare algorithm)
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

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* mergeTwoLists(Node* list1,Node* list2){
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(list1!=NULL && list2!=NULL){
        if(list1->data < list2->data){
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            temp=list2;
            list2=list2->next;
        }
    }
    if(list1) temp->next=list1;
    else temp->next=list2;

    return dummyNode->next;
}

Node* sortLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* middle=findMiddle(head);
    Node* right=middle->next;
    middle->next=NULL;
    Node* left=head;

    left=sortLL(left);
    right=sortLL(right);
    return mergeTwoLists(left,right);
}


int main(){
    vector<int>arr={1,2,3,2,1};
    Node* head=convertArr2LL(arr);
    head=sortLL(head);
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    freeList(head); // ✅ FIX: free memory
    return 0;
}

