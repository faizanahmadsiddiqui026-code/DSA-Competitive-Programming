//Recursive approach
#include <bits/stdc++.h>
using namespace std;
// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    // Function to find the
    // maximum depth of a binary tree
    int maxDepth(Node* root){
        // If the root is NULL
        // (empty tree), depth is 0
        if(root == NULL){
            return 0;
        }
        
        // Recursive call to find the
        // maximum depth of the left subtree
        int lh = maxDepth(root->left);
        
        // Recursive call to find the
        // maximum depth of the right subtree
        int rh = maxDepth(root->right);
        
        // Return the maximum depth of the
        // tree, adding 1 for the current node
        return 1 + max(lh, rh);
    }
};

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    
    Solution solution;
    int depth = solution.maxDepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;
    return 0;
}
    


// //Level Order Traversal Approach
// #include <bits/stdc++.h>
// using namespace std;

// // Node structure for the binary tree
// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     // Function to find maximum depth using Level Order Traversal
//     int maxDepth(Node* root) {
//         if (root == nullptr)
//             return 0;

//         queue<Node*> q;
//         q.push(root);

//         int depth = 0;

//         while (!q.empty()) {
//             int size = q.size(); // Number of nodes at current level

//             for (int i = 0; i < size; i++) {
//                 Node* curr = q.front();
//                 q.pop();

//                 if (curr->left)
//                     q.push(curr->left);

//                 if (curr->right)
//                     q.push(curr->right);
//             }

//             depth++; // Completed one level
//         }

//         return depth;
//     }
// };

// // Main function
// int main() {
//     // Creating a sample binary tree
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->left->right->right = new Node(6);
//     root->left->right->right->right = new Node(7);

//     Solution solution;
//     int depth = solution.maxDepth(root);

//     cout << "Maximum depth of the binary tree: " << depth << endl;

//     return 0;
// }






    //       1
    //     /   \
    //    2     3
    //   / \
    //  4   5
    //       \
    //        6
    //         \
    //          7