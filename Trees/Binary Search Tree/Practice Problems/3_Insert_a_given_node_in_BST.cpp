#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

class Solution{
public:
    TreeNode* insertIntoBST(TreeNode* root,int val){
        if(root ==NULL) return new TreeNode(val);
        TreeNode* cur=root;
        while(true){
            if(cur->val<=val){
                if(cur->right != NULL) cur=cur->right;
                else{
                    cur->right=new TreeNode(val);
                    break;
                } 
            }
            else{
                if(cur->left!=NULL) cur=cur->left;
                else{
                    cur->left=new TreeNode(val);
                    break;
                }
            }     
        }
        return root;
    }

};

// Inorder traversal (prints BST in sorted order)
void inorder(TreeNode* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    Solution obj;

    TreeNode* root = NULL;

    vector<int> values = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(int x : values){
        root = obj.insertIntoBST(root, x);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    // Insert a new node
    root = obj.insertIntoBST(root, 5);

    cout << "After inserting 5: ";
    inorder(root);
    cout << endl;

    return 0;
}