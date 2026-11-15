#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the ceil of a key
    // in a Binary Search Tree (BST)
    int ceilInBST(TreeNode* root, int key){
        // Initialize the ceil variable
        int ceil = -1;
        
        // Traverse the BST until root becomes null
        while(root){
            // If key is equal to current node value
            // then it is the ceil
            if(root->val == key){
                ceil = root->val;
                return ceil;
            }
            
            // If key is greater than current node value
            // move right
            if(key < root->val){ 
                // If key is smaller, update the ceil and  move left
                ceil = root->val;
                root = root->left;
               
            }
            else{
               root = root->right;
            }
        }
        // Return the computed ceil value
        return ceil;
    }
};

// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Base case: if node is null
    if (root == nullptr) return;

    // Left subtree
    printInOrder(root->left);

    // Print current node
    cout << root->val << " ";

    // Right subtree
    printInOrder(root->right);
}

int main() {
    // Creating a BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree (Inorder): "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    
    // Key to find ceil
    int target = 8;
    int ceilVal = solution.ceilInBST(root, target);
    
    if(ceilVal != -1){
        cout << "Ceil of " << target << " is: " << ceilVal << endl;
    }
    else{
        cout << "No Ceil found!" << endl;
    }
    
    return 0;
}
