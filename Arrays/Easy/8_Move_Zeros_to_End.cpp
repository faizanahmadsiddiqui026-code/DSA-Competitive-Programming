// //Brute force
// #include <bits/stdc++.h>
// using namespace std;
// // Solution class
// class Solution {
// public:
//     vector<int> moveZeroes(vector<int>& arr) {
//         vector<int> temp(arr.size(), 0);
//         int index = 0;
//         for (int i = 0; i < arr.size(); i++) {
//             if (arr[i] != 0) {
//                 temp[index] = arr[i];
//                 index++;
//             }
//         }
//         for (int i = 0; i < arr.size(); i++) {
//             arr[i] = temp[i];
//         }
//         return arr;
//     }
// };

// int main() {
//     vector<int> arr = {0, 1, 0, 3, 12};
//     Solution sol;
//     vector<int> result = sol.moveZeroes(arr);
//     cout << "Array after moving zeroes: ";
//     for (int num : result) {
//         cout << num << " ";
//     }
//     cout << endl;
//     return 0;
// }





//Optimal(using 2 pointer approach)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        if (j == -1) return;

        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);

    // Print the result
    for (int num : nums) cout << num << " ";
    cout << endl;
    return 0;
}

