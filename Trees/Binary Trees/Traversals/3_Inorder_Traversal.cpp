// //Recursive approach
// #include <bits/stdc++.h>
// using namespace std;
// // TreeNode structure for the binary tree
// struct TreeNode {
//     int data;
//     TreeNode* left;
//     TreeNode* right;
//     // Constructor to initialize
//     // the TreeNode with a value
//     // TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
//     TreeNode(int val) {
//         data=val;
//         left=nullptr;
//         right=nullptr;
//     }
// };

// class Solution{
//     private:
//     // Function to perform inorder traversal
//     // of the tree and store values in 'arr'
//     void recursiveInorder(TreeNode* root, vector<int> &arr){ //helper function
//         // If the current Tree is NULL
//         // (base case for recursion), return
//         if(root == nullptr){
//             return;
//         }
//         // Recursively traverse the left subtree
//         recursiveInorder(root->left, arr);
//         // Push the current TreeNode's
//         // value into the vector
//         arr.push_back(root->data);
//         // Recursively traverse 
//         // the right subtree
//         recursiveInorder(root->right, arr);
//     }
    
//     public:
//     // Function to initiate inorder traversal
//     // and return the resulting vector
//     vector<int> inorder(TreeNode* root){ //Public function
//         // Create an empty vector to
//         // store inorder traversal values
//         vector<int> arr;
//         // Call the inorder traversal function
//         recursiveInorder(root, arr);
//         // Return the resulting vector
//         // containing inorder traversal values
//         return arr;
//     }
// };

// // Main function
// int main()
// {
//     // Creating a sample binary tree
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
    
//     Solution sol = Solution();
//     // Getting inorder traversal
//     vector<int> result = sol.inorder(root);
//     // Displaying the inorder traversal result
//     cout << "Inorder Traversal: ";
//     // Output each value in the
//     // inorder traversal result
//     for(int val : result) {
//         cout << val << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Time Complexity: O(N), where N is the number of nodes in the binary tree. Each node is visited exactly once during the traversal.
// Space Complexity: O(N), where N is the number of nodes in the binary tree. The space is used for the recursion stack and the vector to store the inorder traversal result.






// Iterative approach
#include <bits/stdc++.h>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    // TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int val) {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class Solution {
public:
// Function to perform inorder traversal
// of a binary tree iteratively
vector<int> inorder(TreeNode* root){
    // Initialize a stack to track nodes
    stack<TreeNode*> st;
    // Start from the root node
    TreeNode* node = root;
    // Initialize a vector to store
    // inorder traversal result
    vector<int> inorder;

    // Start an infinite
    // loop for traversal
    while(true){
        // If the current node is not NULL
        if(node != NULL){
            // Push the current
            // node to the stack
            st.push(node);
            // Move to the left child
            // of the current node
            node = node->left;
        }
        else{
            // If the stack is empty,
            // break the loop
            if(st.empty()){
                break;
            }
            // Retrieve a node from the stack
            node = st.top();
            // Remove the node from the stack
            st.pop();
            // Add the node's value to
            // the inorder traversal list
            inorder.push_back(node->data);
            // Move to the right child
            // of the current node
            node = node->right;
        }
    }
    // Return the inorder
    // traversal result
    return inorder;
}

};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    Solution sol;
    // Getting the inorder traversal
    vector<int> result = sol.inorder(root);
    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

// Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited exactly once.
// Space Complexity: O(h), where h is the height of the binary tree. This is the space required for the stack to store the nodes during traversal.