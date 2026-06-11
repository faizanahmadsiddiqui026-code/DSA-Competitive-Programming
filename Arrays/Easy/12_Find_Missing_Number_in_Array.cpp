// //Brute force
// #include <iostream>
// #include <vector>
// using namespace std;
// int missingNum(vector<int>& arr) {
//     int n = arr.size() + 1;
//     // Iterate from 1 to n and check
//     // if the current number is present
//     for (int i = 1; i <= n; i++) {
//         bool found = false;
//         for (int j = 0; j < n - 1; j++) {
//             if (arr[j] == i) {
//                 found = true;
//                 break;
//             }
//         }

//         // If the current number is not present
//         if (!found)
//             return i;
//     }
//     return -1;
// }

// int main() {
//     vector<int> arr = {8, 2, 4, 5, 3, 7, 1}; 
//     cout << missingNum(arr) << endl; 
//     return 0;
// }



//Better(Hashing)
// #include <iostream>
// #include <vector>
// using namespace std;
// int missingNum(vector<int> &arr) {
//     int n = arr.size() + 1;
//     // Create hash array of size n+1
//     vector<int> hash(n + 1, 0);
//     // Store frequencies of elements
//     for (int i = 0; i < n - 1; i++) {
//         hash[arr[i]]++;
//     }

//     // Find the missing number
//     for (int i = 1; i <= n; i++) {
//         if (hash[i] == 0) {
//             return i;
//         }
//     }
//     return -1;
// }

// int main() {
//     vector<int> arr = {8, 2, 4, 5, 3, 7, 1};
//     int res = missingNum(arr);
//     cout << res << endl;
//     return 0;
// }




// //Optimal(Sum of n terms formula)
// #include <iostream>
// #include <vector>
// using namespace std;

// int missingNum(vector<int> &arr) {
//     int n = arr.size() + 1;
  
//     // Calculate the sum of array elements
//     int sum = 0;
//     for (int i = 0; i < n - 1; i++) {
//         sum += arr[i];
//     }

//     // Calculate the expected sum
//     long long expSum = (n *1LL* (n + 1)) / 2;  

//     // Return the missing number
//     return expSum - sum;
// }

// int main() {
//     vector<int> arr = {8, 2, 4, 5, 3, 7, 1};  
//     cout << missingNum(arr);  
//     return 0;
// }




//Optimal(XOR operation)
#include <iostream>
#include <vector>
using namespace std;
int missingNum(vector<int>& arr) {
    int n = arr.size()+1;
    int xor1 = 0, xor2 = 0;

    // XOR all array elements
    for (int i = 0; i < n-1 ; i++) {
        xor2 ^= arr[i];
        xor1 ^= (i+1);
    }

    xor1 ^= n;
    
    // Missing number is the XOR of xor1 and xor2
    return xor1 ^ xor2;
}

int main() {
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1}; 
    int res = missingNum(arr);  
    cout << res << endl;  
    return 0;
}


