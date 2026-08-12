// //Brute force(data replacement)
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
//   Node* temp=head;
//   int cnt_0=0,cnt_1=0,cnt_2=0;
//     while(temp!=NULL){
//         if(temp->data==0) cnt_0++;
//         else if(temp->data==1) cnt_1++;
//         else cnt_2++;
//         temp=temp->next;
//     }
//     temp=head;
//     while(temp!=NULL){
//         if(cnt_0){
//             temp->data=0;
//             cnt_0--;
//         }
//         else if(cnt_1){
//             temp->data=1;
//             cnt_1--;
//         }
//         else{
//             temp->data=2;
//             cnt_2--;
//         }
//         temp=temp->next;
//     }
//     return head;
// }


// int main(){
//     vector<int>arr={1,0,1,2,0,2,1};
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

Node* sortLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* zeroHead=new Node(-1);
    Node* zero=zeroHead;

    Node* oneHead=new Node(-1);
    Node* one=oneHead;
    
    Node* twoHead=new Node(-1);
    Node* two=twoHead;
    
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=(oneHead->next)? oneHead->next : twoHead->next;
    one->next=twoHead->next;
    two->next=NULL;
    Node* newHead=zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return newHead;
}


int main(){
    vector<int>arr={1,0,1,2,0,2,1};
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