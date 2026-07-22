// //Delete the head in a LL

// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
    
//     public:
//     Node (int data1){
//         data=data1;
//         next=nullptr;
//     }
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

// void print(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }

// Node* removeHead(Node* head){
//     if(head==NULL) return head;  //means LL is empty
//     Node* temp=head;
//     head=head->next;
//     delete temp;  // free(temp); can also be used
//     return head;
// }

// int main(){
//   vector<int>arr={12,5,8,7};
//   Node * head=convertArr2LL(arr);
//   head=removeHead(head);
//   print(head);
// }





// //Delete the tail in a LL

// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
    
//     public:
//     Node (int data1){
//         data=data1;
//         next=nullptr;
//     }
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

// void print(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }

// Node* removeTail(Node* head){
//     if(head==NULL || head->next==NULL) return NULL;  //means LL is empty or having 1 element and pointing to null
//     Node* temp=head;
//     while(temp->next->next!=NULL){
//         temp=temp->next;
//     }
//     delete temp->next;  // free(temp->next); can also be used
//     temp->next=nullptr;
//     return head;
// }

// int main(){
//   vector<int>arr={12,5,8,7};
//   Node * head=convertArr2LL(arr);
//   head=removeTail(head);
//   print(head);
// }




// //Delete Kth element of the LL

// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
    
//     public:
//     Node (int data1){
//         data=data1;
//         next=nullptr;
//     }
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

// void print(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }

// Node* removeK(Node* head,int k){
//   if(head==NULL) return head;
//   if(k==1){
//     Node* temp=head;
//     head=head->next;
//     delete temp;
//     return head;
//   }
//   int cnt=0;
//   Node* temp=head;
//   Node* prev=NULL;
//   while(temp!=NULL){
//     cnt++;
//     if(cnt==k){
//         prev->next=prev->next->next;
//         delete temp;
//         break;
//     }
//     prev=temp;
//     temp=temp->next;
//   }
//   return head;
// }

// int main(){
//   vector<int>arr={12,5,8,7};
//   Node * head=convertArr2LL(arr);
//   head=removeK(head,3);
//   print(head);
// }


// Key Rule (Very Important)
// Allocation  Deallocation
// new	       delete
// new[]	   delete[]
// malloc	   free

// 👉 Never mix them.






//Delete a element having value=val in the LL
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

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* removeEL(Node* head,int el){
  if(head==NULL) return head;
  if(head->data==el){
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
  }
  Node* temp=head;
  Node* prev=NULL;
  while(temp!=NULL){;
    if(temp->data==el){
        prev->next=prev->next->next;
        delete temp;
        break;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
}

int main(){
  vector<int>arr={12,5,8,7};
  Node * head=convertArr2LL(arr);
  head=removeEL(head,8);
  print(head);
}
