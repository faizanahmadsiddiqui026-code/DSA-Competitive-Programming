// //Recursive approach
// #include <bits/stdc++.h>
// using namespace std;
// // Definition for a binary tree node
// struct TreeNode {
//     int data;
//     TreeNode *left, *right;
//     // TreeNode(int val) : data(val), left(NULL), right(NULL) {}
//     TreeNode(int val) {
//         data=val;
//         left=nullptr;
//         right=nullptr;
//     }
// };

// // Solution class with postorder function
// class Solution {
// public:
//     void postorderTraversal(TreeNode* root, vector<int>& result) {
//         // Base case: if node is null
//         if (root==nullptr) return;

//         // Traverse left subtree
//         postorderTraversal(root->left, result);

//         // Traverse right subtree
//         postorderTraversal(root->right, result);

//         // Add current node value
//         result.push_back(root->data);
//     }
// };

// // Main function
// int main() {
//     // Build tree:    1
//     //              /   \
//     //             2     3
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);

//     // Object of solution
//     Solution sol;
//     vector<int> result;

//     // Call postorder traversal
//     sol.postorderTraversal(root, result);

//     // Print result
//     for (int val : result) cout << val << " ";

//     //Memory Deallocation
//     delete root->left;
//     delete root->right;
//     delete root;
//     return 0;
// }


// Time Complexity: O(N), we process each node once in traversal.
// Space Complexity: O(N), extra space used for storing post order traversal and recursion stack space.







// //Iterative approach (using 2 stacks)
// #include <bits/stdc++.h>
// using namespace std;

// // Node structure for the binary tree
// struct Node {
//     int data;   // Value of the node
//     Node* left; // Pointer to the left child
//     Node* right; // Pointer to the right child
    
//     // Constructor to initialize the node with a value
//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// // Function to return the postOrder traversal of a binary tree using two stacks
// vector<int> postOrder(Node* root) {
//     vector<int> postorder; // Vector to store the postorder traversal

//     // If the tree is empty, return an empty traversal
//     if(root == NULL){
//         return postorder;
//     }

//     // Two stacks for iterative traversal
//     stack<Node*> st1, st2;

//     // Push the root node onto the first stack
//     st1.push(root);

//     // Iterative traversal to populate st2 with nodes in postorder
//     while(!st1.empty()){
//         // Get the top node from st1
//         root = st1.top();
//         st1.pop();

//         // Push the node onto st2
//         st2.push(root);

//         // Push left child onto st1 if exists
//         if(root->left != NULL){
//             st1.push(root->left);
//         }

//         // Push right child onto st1 if exists
//         if(root->right != NULL){
//             st1.push(root->right);
//         }
//     }

//     // Populate the postorder traversal vector by popping st2
//     while(!st2.empty()){
//         postorder.push_back(st2.top()->data);
//         st2.pop();
//     }

//     // Return the postorder traversal
//     return postorder;
// }

// // Function to print the elements of a vector
// void printVector(const vector<int>& vec) {
//     // Iterate through the vector and print each element
//     for (int num : vec) {
//         cout << num << " ";
//     }
//     cout << endl;
// }

// // Main function
// int main()
// {
//     // Creating a sample binary tree
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);

//     // Getting postorder traversal
//     vector<int> result = postOrder(root);

//     // Printing the postorder traversal result
//     cout << "Postorder traversal: ";
//     printVector(result);

//     return 0;
// }


// Time Complexity: O(N), where N is the number of nodes in the binary tree. Each node is visited once during the traversal.
// Space Complexity: O(H), where H is the height of the binary tree. The space is used by the stack to store nodes during traversal.







// Iterative approach (using 1 stack)
#include <bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;   // Value of the node
    Node* left; // Pointer to the left child
    Node* right; // Pointer to the right child
    
    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to return the postOrder traversal of a binary tree using one stack
vector<int> postOrder(Node* root) {

    vector<int> postorder; // Vector to store the postorder traversal

    // If the tree is empty, return an empty traversal
    if(root == NULL){
        return postorder;
    }

    // Stack for iterative traversal
    stack<Node*> st;

    // Pointer for traversal
    Node* curr = root;

    // Iterative traversal
    while(curr != NULL || !st.empty()){

        // Push all left nodes into the stack
        if(curr != NULL){

            st.push(curr);
            curr = curr->left;
        }

        else{

            // Get the right child of the top node
            Node* temp = st.top()->right;

            // If right child does not exist
            if(temp == NULL){

                temp = st.top();
                st.pop();

                postorder.push_back(temp->data);

                // Process nodes whose right subtree is already visited
                while(!st.empty() && temp == st.top()->right){

                    temp = st.top();
                    st.pop();

                    postorder.push_back(temp->data);
                }
            }

            // Move to right subtree
            else{
                curr = temp;
            }
        }
    }

    // Return the postorder traversal
    return postorder;
}

// Function to print the elements of a vector
void printVector(const vector<int>& vec) {

    // Iterate through the vector and print each element
    for (int num : vec) {
        cout << num << " ";
    }

    cout << endl;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder traversal result
    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}




// Time Complexity: O(N)
// Space Complexity: O(H), where H= Worst case: O(N), Balanced tree: O(logN)
