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
// bool checkPalindrome(Node* head){
//     stack<int>st;
//     Node* temp=head;
//     while(temp!=NULL){
//         st.push(temp->data);
//         temp=temp->next;
//     }
//     temp=head;
//     while(temp!=NULL){
//         if(temp->data!=st.top()) return false;
//         temp=temp->next;
//         st.pop();
//     }
//     return true;
// }


// int main(){
//     vector<int>arr={1,2,3,2,1};
//     Node* head=convertArr2LL(arr);
//     bool palindrome=checkPalindrome(head);
//     cout<<boolalpha<<palindrome;
//     return 0;
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

void freeList(Node* head){
    while(head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* reverseLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* newHead=reverseLL(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

bool checkPalindrome(Node* head){
    if(head==NULL || head->next==NULL) return true;

    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* newHead=reverseLL(slow->next);
    Node* first=head;
    Node* second=newHead;
    while(second!=NULL){
        if(first->data!=second->data){
            slow->next=reverseLL(newHead); //reattach the reversed part
            return false;
        }
        first=first->next;
        second=second->next;
    }
    slow->next=reverseLL(newHead); //reattach the reversed part
    return true;
}


int main(){
    vector<int>arr={1,2,3,2,1};
    Node* head=convertArr2LL(arr);
    bool palindrome=checkPalindrome(head);
    cout<<boolalpha<<palindrome;
    freeList(head); // ✅ FIX: free memory
    return 0;
}


//using std::lst-> easiest thing
// Why this is great
// No new
// No delete
// No memory leak possible
// Fully handled by STL
// 👉 Best for production code unless you're practicing DSA.

//Using SmartPointers(unique_ptr)
// unique_ptr automatically deletes memory when it goes out of scope
// No freeList() needed at all