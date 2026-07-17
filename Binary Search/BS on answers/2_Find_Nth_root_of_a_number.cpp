// //Brute force(for integer)
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     // Function to find Nth root of M
//     int nthRoot(int n, int m) {
//         // Loop from 1 to m
//         for (int i = 1; i <= m; i++) {
//             // Compute i^n
//             long long power = pow(i, n);
//             // If equal to m, return i
//             if (power == m) return i;
//             // If exceeds m, break
//             if (power > m) break;
//         }
//         // If not found, return -1
//         return -1;
//     }
// };

// int main() {
//     Solution sol;
//     int n = 3, m = 27;
//     // Find nth root
//     cout << "Nth Root: " << sol.nthRoot(n, m) << endl;
//     return 0;
// }


//Optimal(for integer)
// #include <bits/stdc++.h>
// using namespace std;   
// class Solution {
// public:
//     // Function to find N-th root of M using binary search
//     int nthRoot(int n, int m) {
//         // Set low and high for binary search
//         int low = 1, high = m;
//         // Start binary search
//         while (low <= high) {
//             // Calculate mid
//             int mid = (low + high) / 2;
//             // Store result of mid^n
//             long long ans = 1;
//             for (int i = 0; i < n; i++) { //Power
//                 ans *= mid;
//                 if (ans > m) break;
//             }
//             // If mid^n equals m
//             if (ans == m){
//                 cout<<mid;
//                 return 0;
//             } 
//             // If mid^n is less than m
//             if (ans < m) low = mid + 1;
//             // If mid^n is more than m
//             else high = mid - 1;
//         }
//         // Return -1 if not found
//         return -1;
//     }
// };
// // Main function
// int main() {
//     Solution obj;
//     int result = obj.nthRoot(3, 27);
//     return 0;
// }




//Optimal(for every type)
#include <bits/stdc++.h>
using namespace std;   
class Solution {
public:
    double multiply(double number,int n){
        double ans=1.0;
        for(int i=1;i<=n;i++){
            ans=ans*number;
        }
        return ans;
    }
    // Function to find N-th root of M using binary search
    double getNthRoot(int n, int m) {
        // Set low and high for binary search
        double low = 1, high = m;
        double eps=1e-6;
        // Start binary search
        while ((high-low)>eps){
            // Calculate mid
            double mid = (low + high) / 2.0;
            // Store result of mid^n
            if(multiply(mid,n)<m){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        return low;  //return high;
        //just to check with pow functon
        // cout<<pow(m,double(1.0/(double)n));
    }
};
// Main function
int main() {
    int n=3,m=27;
    Solution obj;
    double result = obj.getNthRoot(n,m);
    cout<<result<<endl;
    return 0;
}
