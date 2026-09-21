// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={6,0,8,1,3};
//     int n=sizeof(arr)/sizeof(int);
//     int nge[n];

//     for(int i=0;i<n;i++){
//         nge[i]=-1;
//         for(int j=i+1;j<n;j++){
//             if(arr[j]>arr[i]){
//                 nge[i]=arr[j];
//                 break;
//             }
//         }
//     }        
//     for(int i=0;i<n;i++){
//         cout<<nge[i]<<" ";
//     }
//     return 0;
// }



//Optimal
#include <bits/stdc++.h>
using namespace std;

// Solution class to find next greater elements
class Solution {
public:
    // Function to find next greater elements
    vector<int> nextGreater(vector<int>& nums) {
        // Stack to store elements
        stack<int> st;

        // Result array of same size
        int n = nums.size();
        vector<int> res(n);  //creating a nge array

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // If stack is empty, no greater element
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
    vector<int> nums = {4, 5, 2, 10};
    Solution sol;
    vector<int> ans = sol.nextGreater(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
