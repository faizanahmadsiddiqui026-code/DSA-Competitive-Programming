// //Insert the element at the head in the LL

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

// void print(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }

// Node* insertHead(Node* head,int el){
//    Node* temp=new Node(el,head);  //OR
//    return temp;                  //return new Node(el,head);
// }

// int main(){
//   vector<int>arr={12,5,8,7};
//   Node * head=convertArr2LL(arr);
//   head=insertHead(head,100);
//   print(head);
// }






// //Insert at the last in the LL

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

// void print(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }

// Node* insertTail(Node* head,int el){
//    if(head==NULL) return new Node(el);
//    Node* temp=head;
//    while(temp->next!=NULL){
//     temp=temp->next;
//    }
//    Node* newNode=new Node(el);
//    temp->next=newNode;  
//    return head;     
// }

// int main(){
//   vector<int>arr={12,5,8,7};
//   Node * head=convertArr2LL(arr);
//   head=insertTail(head,100);
//   print(head);
// }





// //Insert element at the Kth position in the LL

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

// void print(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }

// Node* insertPosition(Node* head,int el,int k){
//    if(head==NULL){
//     if(k==1){
//        return new Node(el);
//     }
//     else{
//        return head;
//     }
//    }

//    if(k==1){
//     Node* newHead=new Node(el,head);
//     return newHead;
//    }
//    int cnt=0;
//    Node* temp=head;
//    while(temp!=NULL){
//     cnt++;
//     if(cnt==(k-1)){
//         Node* x=new Node(el);
//         x->next=temp->next;  //first saves next address in x
//         temp->next=x; // then change the address to x
//         break;
//     }
//     temp=temp->next;
//    }
//    return head;     
// }

// int main(){
//   vector<int>arr={12,5,8,7};
//   Node * head=convertArr2LL(arr);
//   head=insertPosition(head,100,3);
//   print(head);
// }




//Insert element before the value x in the LL

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

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* insertBeforeValue(Node* head,int el,int val){
   if(head==NULL){
      return NULL;
   }

   if(head->data==val){
    Node* newHead=new Node(el,head);  //Or
    return newHead;                  //return new Node(el,head); 
   }
   int cnt=0;
   Node* temp=head;
   while(temp->next!=NULL){
    cnt++;
    if(temp->next->data==val){
        Node* x=new Node(el);  // Node* x=new Node(el,temp->next);
        x->next=temp->next;  //OR     //first saves next address in x
        temp->next=x; // then change the address to x
        break;
    }
    temp=temp->next;
   }
   return head;     
}

int main(){
  vector<int>arr={12,5,8,7};
  Node * head=convertArr2LL(arr);
  head=insertBeforeValue(head,100,12);
  print(head);
}