#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isvalidbst(root,LLONG_MIN,LLONG_MAX);
    }

    bool isvalidbst(TreeNode* root,long long minVal,long long maxVal){
        if(root==NULL) return true;
        if(root->data >= maxVal || root->data <=minVal) return false;
        return isvalidbst(root->left, minVal, root->data) && isvalidbst(root->right ,root->data, maxVal);
    }
};

int main(){
TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution obj;

    if (obj.isValidBST(root))
        cout << "Valid BST\n";
    else
        cout << "Not a BST\n";

    return 0;
}