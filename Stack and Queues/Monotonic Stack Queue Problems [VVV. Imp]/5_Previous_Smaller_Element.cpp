// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={4,5,2,10,8};
//     int n=sizeof(arr)/sizeof(int);
//     int pse[n];

//     for(int i=0;i<n;i++){
//         pse[i]=-1;
//         for(int j=i-1;j>=0;j--){
//             if(arr[j]<arr[i]){
//                 pse[i]=arr[j];
//                 break;
//             }
//         }
//     }        
//     for(int i=0;i<n;i++){
//         cout<<pse[i]<<" ";
//     }
//     return 0;
// }




//Optimal
#include <bits/stdc++.h>
using namespace std;

// Solution class to find previous smaller elements
class Solution {
public:
    // Function to find next greater elements
    vector<int> PreviousSmaller(vector<int>& nums) {
        // Stack to store elements
        stack<int> st;

        // Result array of same size
        int n = nums.size();
        vector<int> res(n);  //creating a nge array

        // Traverse from left to right
        for (int i = 0; i < n; i++) {

            // Pop all smaller or equal elements
            while (!st.empty() && st.top() >= nums[i]) {  //for previous smaller and equal element just remove the = from the inequality rest code is same
                st.pop();
            }

            // If stack is empty, no smaller element on left
            if (st.empty()) res[i] = -1;

            // Else top of stack is the answer at its correct position
            else res[i] = st.top();

            // Push current element
            st.push(nums[i]);
        }

        // Return the result
        return res;
    }
};

// Main function
int main() {
    vector<int> nums = {4,5,2,10,8};
    Solution sol;
    vector<int> ans = sol.PreviousSmaller(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
