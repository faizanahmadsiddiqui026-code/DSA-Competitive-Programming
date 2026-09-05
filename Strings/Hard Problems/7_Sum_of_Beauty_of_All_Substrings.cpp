//My Approach
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string str="aabcbaa";
//     int n=str.size();
//         int sum=0;
//         map<char,int>mpp;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 mpp[str[j]]++;
//                 int max_freq = 0;
//                 int min_freq = INT_MAX;
//                 for (auto it : mpp) {
//                     max_freq = max(max_freq, it.second);
//                     min_freq = min(min_freq, it.second);
//                 }
//                 sum += (max_freq - min_freq);
//             }
//             mpp.clear();
//         }
//     cout<<sum;
//     return 0;
// }


// //Optimal
// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int beautySum(string s) {
//         int n = s.size();
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             vector<int> freq(26, 0);
//             for (int j = i; j < n; j++) {
//                 freq[s[j] - 'a']++;
//                 int mx = 0, mn = INT_MAX;
//                 for (int k = 0; k < 26; k++) {
//                     if (freq[k] > 0) {
//                         mx = max(mx, freq[k]);
//                         mn = min(mn, freq[k]);
//                     }
//                 }
//                 ans += (mx - mn);
//             }
//         }
//         return ans;
//     }
// };


// Striver's Optimal
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        // Loop over all substrings
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                // Increase frequency of current character
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                // Find max and min frequency
                for (auto it : freq) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }

                // Add difference to sum
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;
    string s = "xyx";
    cout << "Beauty Sum: " << sol.beautySum(s) << endl;
    return 0;
}




// Time Complexity:
// Outer loop: O(n) (for each starting index)
// Inner loop: O(n) (for each ending index)
// Computing max and min for frequencies: O(26) in the worst case (since only lowercase letters), O(n^2 * 26) ≈ O(n^2) because 26 is constant.

// Space Complexity:
// Frequency map uses at most 26 characters → O(26) = O(1).
// No extra data structures apart from that.