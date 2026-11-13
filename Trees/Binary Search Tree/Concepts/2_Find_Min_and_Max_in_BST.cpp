// //Iterative approach
// #include <bits/stdc++.h>
// using namespace std;
// // Definition of TreeNode
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int data) {
//         val = data;
//         left = right = nullptr;
//     }
// };

// class Solution {
// public:
//   TreeNode* findMin(TreeNode* root){
//     if(root==NULL) return NULL;
//     while(root->left!=NULL){
//         root=root->left;
//     }
//     return root;
//   }

//     TreeNode* findMax(TreeNode* root){
//     if(root==NULL) return NULL;
//     while(root->right!=NULL){
//         root=root->right;
//     }
//     return root;
//   }
// };

// // Driver code
// int main() {
//     TreeNode* root = new TreeNode(4);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(7);
//     root->left->left = new TreeNode(1);
//     root->left->right = new TreeNode(3);

//     Solution obj;
//     TreeNode* minElement = obj.findMin(root);
//     TreeNode* maxElement = obj.findMax(root);
//     if(minElement!=NULL && maxElement!=NULL){
//         cout<<"Min element: "<<minElement->val<<endl;
//         cout<<"Max element: "<<maxElement->val<<endl;
//     }
//     else{
//         cout<<"NULL"<<endl;
//     }
//     return 0;
// }







//Recursive approach
#include <bits/stdc++.h>
using namespace std;
// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = nullptr;
    }
};

class Solution {
public:
  TreeNode* findMin(TreeNode* root){
    if(root==NULL) return NULL;

    if(root->left==NULL){
        return root;
    }
    return findMin(root->left);
  }

    TreeNode* findMax(TreeNode* root){
    if(root==NULL) return NULL;

    if(root->right==NULL){
        return root;
    }
    return findMax(root->right);
  }
};

// Driver code
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    TreeNode* minElement = obj.findMin(root);
    TreeNode* maxElement = obj.findMax(root);
    if(minElement!=NULL && maxElement!=NULL){
        cout<<"Min element: "<<minElement->val<<endl;
        cout<<"Max element: "<<maxElement->val<<endl;
    }
    else{
        cout<<"NULL"<<endl;
    }
    return 0;
}





