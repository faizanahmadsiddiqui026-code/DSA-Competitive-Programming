#include <bits/stdc++.h>
using namespace std;

// This structure defines a node in the binary tree
struct Node {
    // This stores the value of the node
    int data;
    // Pointer to the left child
    Node* left;
    // Pointer to the right child
    Node* right;

    // Constructor initializes node with value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// This class contains the solution logic
class Solution {
public:
    // Function to perform vertical order traversal
    vector<vector<int>> findVertical(Node* root) {
        // A map is used to store nodes grouped by vertical and level
        map<int, map<int, multiset<int>>> nodes;

        // A queue is used for BFS, storing node and its coordinates
        queue<pair<Node*, pair<int, int>>> todo;

        // Push the root node with vertical = 0 and level = 0
        todo.push({root, {0, 0}});

        // Perform BFS traversal
        while (!todo.empty()) {
            // Get the front element in queue
            auto p = todo.front();
            todo.pop();

            // Extract node
            Node* temp = p.first;
            // Extract vertical (x)
            int x = p.second.first;
            // Extract level (y)
            int y = p.second.second;

            // Insert the node into map by vertical and level
            nodes[x][y].insert(temp->data);

            // If left child exists, push with updated coordinates
            if (temp->left) {
                todo.push({temp->left, {x - 1, y + 1}});
            }

            // If right child exists, push with updated coordinates
            if (temp->right) {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        // Final answer vector
        vector<vector<int>> ans;

        // Iterate through verticals in map
        for (auto p : nodes) {
            vector<int> col;
            // Collect all nodes in order of levels
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());   //v.insert(position, first_iterator, last_iterator);
            }
            // Push the column into result
            ans.push_back(col);
        }

        // Return final vertical order traversal
        return ans;
    }
};

// Helper function to print result
void printResult(const vector<vector<int>>& result) {
    for (auto level : result) {
        for (auto node : level) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Driver code
int main() {
    // Create sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    // Create solution object
    Solution solution;

    // Call vertical order traversal
    vector<vector<int>> verticalTraversal = solution.findVertical(root);

    // Print result
    cout << "Vertical Traversal:" << endl;
    printResult(verticalTraversal);

    return 0;
}



// Time Complexity: O(N * log²N * log²N * log²N), where N represents the number of nodes in the Binary Tree. Postorder traversal is performed using BFS with a time complexity of O(N), since each node is visited exactly once. Multiset operations for inserting overlapping nodes at specific vertical and horizontal levels take O(log²N) time. Map operations involve insertion and retrieval of nodes using vertical and level as keys. Since there are two nested maps, the total complexity becomes O(log²N * log²N).
// Space Complexity: O(N + N/2), where N represents the number of nodes in the Binary Tree. The map storing nodes based on vertical and level information occupies O(N) space, as it stores all N nodes of the tree. The queue for BFS traversal occupies space proportional to the maximum number of nodes at any level, which can be O(N/2) in the worst case for a balanced tree.