// // Brute force
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     /* Function to find the sum of the 
//     maximum value in each subarray */
//     int sumSubarrayMaxs(vector<int> &arr) {
//         int n = arr.size();
//         int mod = 1e9 + 7;
//         int sum = 0;

//         // Traverse all starting points
//         for(int i = 0; i < n; i++) {
//             int maxi = arr[i];
//             // Traverse all ending points
//             for(int j = i; j < n; j++) {
//                 // Update maximum in current subarray
//                 maxi = max(maxi, arr[j]);
//                 // Add to result
//                 sum = (sum + maxi) % mod;
//             }
//         }
//         return sum;
//     }
// };

// int main() {
//     vector<int> arr = {3, 1, 2, 4};
//     Solution sol;
//     int ans = sol.sumSubarrayMaxs(arr);

//     cout << "The sum of maximum value in each subarray is: " << ans;
//     return 0;
// }




//Optimal
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /* Function to find the indices of 
    next greater elements */
    vector<int> findNGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            // pop smaller or equal elements
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        return nge;
    }
    
    /* Function to find the indices of 
    previous greater or equal elements */
    vector<int> findPGEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> pgee(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            // pop strictly smaller elements
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pgee[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return pgee;
    }
    
public:
    /* Function to find the sum of the 
    maximum value in each subarray */
    int sumSubarrayMaxs(vector<int> &arr) {
        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);

        int n = arr.size();
        int mod = 1e9 + 7;
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;

            long long freq = left * right;
            long long val = (freq * arr[i]) % mod;
            sum = (sum + val) % mod;
        }
        return (int)sum;
    }
};

int main() {
    vector<int> arr = {3, 1, 2, 4};
    Solution sol;
    int ans = sol.sumSubarrayMaxs(arr);

    cout << "The sum of maximum value in each subarray is: " << ans;
    return 0;
}