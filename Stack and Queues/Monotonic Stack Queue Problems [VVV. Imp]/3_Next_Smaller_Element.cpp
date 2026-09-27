// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[5]={4, 8, 5, 2, 25};
//     int n=sizeof(arr)/sizeof(int);
//     int nse[n];
//     for(int i=0;i<n;i++){
//         nse[i]=-1;
//         for(int j=i+1;j<n;j++){
//             if(arr[j]<arr[i]){
//                 nse[i]=arr[j];
//                 break;
//             }
//         }
//     }
//     for(auto it : nse){
//         cout<<it<<" ";
//     }
//     return 0;
// }


// Time Complexity: O(N^2), since for each of the N elements, we might need to look at up to N-1 elements ahead.
// Space Complexity: O(N), since we are using an output array of size N.


// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:

//     /* Function to find the next smaller 
//     element for each element in the array */
//     vector<int> nextSmallerElement(vector<int>& arr) {
        
//         int n = arr.size(); // size of array
        
//         // To store the next smaller elements
//         vector<int> ans(n, -1);
        
//         for (int i = 0; i < n; ++i) {
            
//             // Get the current element
//             int currEle = arr[i];
            
//             /* Nested loop to get the 
//             next smaller element */
//             for (int j = i + 1; j < n; ++j) {
                
//                 // If the next smaller element is found
//                 if (arr[j] < currEle) {
                    
//                     // Store the next smaller element
//                     ans[i] = arr[j];
                    
//                     // Break from the loop
//                     break;
//                 }
//             }
//         }
        
//         // Return the answer
//         return ans;
//     }
// };

// int main() {
//     int n = 5;
//     vector<int> arr = {4, 8, 5, 2, 25};

//     /* Creating an instance of 
//     Solution class */
//     Solution sol;
    
//     /* Function call to find the next smaller element
//     for each element in the array */
//     vector<int> ans = sol.nextSmallerElement(arr);
    
//     cout << "The next smaller elements are: ";
//     for (int i = 0; i < n; ++i) {
//         cout << ans[i] << " ";
//     }
    
//     return 0;
// }




//Optimal(using Back traversal)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the next smaller 
    element for each element in the array */
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size(); // size of array
        // To store the next smaller elements  // Answer array initialized with -1
        vector<int> ans(n, -1);
        // Stack to store potential next smaller elements
        stack<int>st;
        // Traverse the array from right to left
        for (int i = n-1; i >= 0; i--) {
            // Pop elements from stack while they are >= current element
            while(!st.empty() && st.top()>=arr[i]) st.pop();
            // If stack is not empty, top is the next smaller element
            if(!st.empty()){
                ans[i]=st.top();
            }
            // Push current element to stack
            st.push(arr[i]);
        }
        
        // Return the answer
        return ans;
    }
};

int main() {
    int n = 5;
    vector<int> arr = {4, 8, 5, 2, 25};

    /* Creating an instance of 
    Solution class */
    Solution sol;
    
    /* Function call to find the next smaller element
    for each element in the array */
    vector<int> ans = sol.nextSmallerElement(arr);
    
    cout << "The next smaller elements are: ";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}


// Time Complexity: O(N), since each element is pushed and popped at most once.
// Space Complexity: O(N), since stack may hold up to N elements in the worst case.