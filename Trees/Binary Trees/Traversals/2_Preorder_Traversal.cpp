// //Recursive approach
// #include <bits/stdc++.h>
// using namespace std;

// // Node structure for
// // the binary tree
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     // Constructor to initialize
//     // the node with a value
//     // Node(int val) : data(val), left(nullptr), right(nullptr) {}
//     Node(int val) {
//         data=val;
//         left=nullptr;
//         right=nullptr;
//     }
// };

// // Solution class containing traversal functions
// class Solution {
// public:
//     // Function to perform preorder traversal
//     // of the tree and store values in 'arr'
//     void preorder(Node* root, vector<int> &arr){  //helper function
//         // If the current node is NULL
//         // (base case for recursion), return
//         if(root == nullptr){
//             return;
//         }
//         // Push the current node's
//         // value into the vector
//         arr.push_back(root->data);
//         // Recursively traverse
//         // the left subtree
//         preorder(root->left, arr);
//         // Recursively traverse 
//         // the right subtree
//         preorder(root->right, arr);
//     }

//     // Function to initiate preorder traversal
//     // and return the resulting vector
//     vector<int> preOrder(Node* root){  //Public function
//         // Create an empty vector to
//         // store preorder traversal values
//         vector<int> arr;
//         // Call the preorder traversal function
//         preorder(root, arr);
//         // Return the resulting vector
//         // containing preorder traversal values
//         return arr;
//     }
// };

// // Main function
// int main()
// {
//     // Creating a sample binary tree
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);

//     // Create object of Solution class
//     Solution sol;

//     // Getting preorder traversal
//     vector<int> result = sol.preOrder(root);

//     // Displaying the preorder traversal result
//     cout << "Preorder Traversal: ";
//     // Output each value in the
//     // preorder traversal result
//     for(int val : result) {
//         cout << val << " ";
//     }
//     cout << endl;

//     // Free memory
//     delete root->left->left;
//     delete root->left->right;
//     delete root->left;
//     delete root->right;
//     delete root;
    
//     return 0;
// }





//Iterative approach
#include <bits/stdc++.h>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;  // Value of the node
    TreeNode* left;  // Pointer to the left child
    TreeNode* right;  // Pointer to the right child
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor to initialize a node
};

class Solution {
public:
    // Function to perform preorder traversal of a binary tree iteratively
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;  // Vector to store the preorder traversal result
        
        // If the root is null, return an empty traversal result
        if(root == nullptr) {
            return preorder;
        }
        
        stack<TreeNode*> st;  // Stack to store nodes during traversal
        st.push(root);  // Push the root node onto the stack
        
        // Perform iterative preorder traversal
        while(!st.empty()) {
            root = st.top();  // Get the current node from the top of the stack
            st.pop();  // Remove the node from the stack
            
            preorder.push_back(root->val);  // Add the node's value to the preorder result
            
            // Push the right child onto the stack if exists
            if(root->right != nullptr) {
                st.push(root->right);
            }
            
            // Push the left child onto the stack if exists
            if(root->left != nullptr) {
                st.push(root->left);
            }
        }
        
        // Return the preorder traversal result
        return preorder;
    }
};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solu tion class
    Solution sol;

    // Getting the preorder traversal
    vector<int> result = sol.preorderTraversal(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}




// Time Complexity: O(N), where N is the number of nodes in the binary tree. Each node is visited once during the traversal.
// Space Complexity: O(H), where H is the height of the binary tree. The space is used by the stack to store nodes during traversal.