#include <bits/stdc++.h>
using namespace std;
// Structure to represent a binary tree node
struct TreeNode {
    int val;                // Value of the node
    TreeNode* left;         // Pointer to left child
    TreeNode* right;        // Pointer to right child
    // Constructor to initialize node with a given value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform zigzag (spiral) level order traversal of a binary tree
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Vector to store the final zigzag traversal result
        vector<vector<int>> result;
        // If the tree is empty, return an empty result
        if (!root) return result;

        // Queue to store nodes level by level (BFS)
        queue<TreeNode*> q;
        q.push(root);

        // Boolean flag to control traversal direction: true for left-to-right, false for right-to-left
        bool leftToRight = true;

        // Loop until all levels are processed
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int size = q.size();

            // Temporary vector to store the current level's values in correct zigzag order
            vector<int> level(size);

            // Process each node in the current level
            for (int i = 0; i < size; i++) {
                // Get the front node from the queue
                TreeNode* node = q.front();
                q.pop();

                // Determine index where this node's value should be placed based on traversal direction
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;

                // If left child exists, add it to the queue
                if (node->left) q.push(node->left);
                // If right child exists, add it to the queue
                if (node->right) q.push(node->right);
            }

            // After finishing this level, toggle the direction for the next level
            leftToRight = !leftToRight;

            // Add this level's data to the final result
            result.push_back(level);
        }

        // Return the zigzag traversal result
        return result;
    }
};

int main() {
    // Create binary tree:
    //        1
    //      /   \
    //     2     3
    //    / \     \
    //   4   5     6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Create Solution object
    Solution sol;

    // Get zigzag traversal result
    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    // Print result in desired format
    cout << "[";
    for (auto &level : ans) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i != level.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}

// Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.
// Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N). The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.