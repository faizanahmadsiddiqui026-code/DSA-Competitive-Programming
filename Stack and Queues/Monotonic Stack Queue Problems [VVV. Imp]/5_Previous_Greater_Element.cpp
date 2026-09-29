// //Brute force
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int arr[] = {4, 5, 2, 10, 8};
//     int n = sizeof(arr) / sizeof(int);
//     int pge[n];

//     for(int i = 0; i < n; i++){
//         pge[i] = -1;
//         for(int j = i - 1; j >= 0; j--){
//             if(arr[j] > arr[i]){   // changed condition
//                 pge[i] = arr[j];
//                 break;
//             }
//         }
//     }

//     for(int i = 0; i < n; i++){
//         cout << pge[i] << " ";
//     }

//     return 0;
// }



//Optimal
#include <bits/stdc++.h>
using namespace std;

// Solution class to find previous greater elements
class Solution {
public:
    // Function to find previous greater elements
    vector<int> PreviousGreater(vector<int>& nums) {
        // Stack to store elements
        stack<int> st;

        // Result array of same size
        int n = nums.size();
        vector<int> res(n);  //creating a pge array

        // Traverse from left to right
        for (int i = 0; i < n; i++) {

            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= nums[i]) {  //for previous greater and equal element just remove the = from the inequality rest code is same
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
    vector<int> ans = sol.PreviousGreater(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
