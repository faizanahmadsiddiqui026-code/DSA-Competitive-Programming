//Recursive approach
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        int curr = root->data;
        // Both nodes are in the right subtree
        if(curr < p->data && curr < q->data) return lowestCommonAncestor(root->right,p,q);
        // Both nodes are in the left subtree
        if(curr > p->data && curr > q->data) return lowestCommonAncestor(root->left,p,q);
        // Split point found (or one node is the root)
        return root;
    }

};

int main() {
    /*
              6
            /   \
           2     8
          / \   / \
         0   4 7   9
            / \
           3   5
    */

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;   // Node 2
    TreeNode* q = root->right;  // Node 8

    Solution obj;
    TreeNode* lca = obj.lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "LCA of " << p->data << " and " << q->data
             << " is " << lca->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}



//Iterative approach
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->data < root->data && q->data < root->data)
                root = root->left;
            else if (p->data > root->data && q->data > root->data)
                root = root->right;
            else
                return root; // LCA found
        }
        return nullptr;
    }
};

int main() {
    /*
              6
            /   \
           2     8
          / \   / \
         0   4 7   9
            / \
           3   5
    */

    TreeNode* root = new TreeNode(6);

    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;   // Node 2
    TreeNode* q = root->right;  // Node 8

    Solution obj;
    TreeNode* lca = obj.lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "LCA of " << p->data << " and " << q->data
             << " is " << lca->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}