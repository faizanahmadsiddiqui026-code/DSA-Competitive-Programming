//Brute force(Approach-1 Map)
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     // Function to find union of two arrays
//     vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
//         // Create a map to store frequency of each element
//         map<int, int> freq;
//         // Create a vector to store the union result
//         vector<int> Union;
//         // Loop through first array and store frequency
//         for (int i = 0; i < n; i++)
//             freq[arr1[i]]++;
//         // Loop through second array and store frequency
//         for (int i = 0; i < m; i++)
//             freq[arr2[i]]++;
//         // Traverse the map to get unique sorted elements
//         for (auto &it : freq)
//             Union.push_back(it.first);
//         // Return the union vector
//         return Union;
//     }
// };

// int main() {
//     int n = 10;
//     // Define size of second array
//     int m = 7;
//     // Initialize first array
//     int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     // Initialize second array
//     int arr2[] = {2, 3, 4, 4, 5, 11, 12};
//     // Create object of Solution class
//     Solution obj;
//     // Call FindUnion function
//     vector<int> Union = obj.FindUnion(arr1, arr2, n, m);
//     // Print output message
//     cout << "Union of arr1 and arr2 is " << endl;
//     // Print all elements of union
//     for (auto &val : Union)
//         cout << val << " ";
//     // Return success
//     return 0;
// }




// //Brute force(Approach-1 Set)
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     // Function to find the union of two arrays using set
//     vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
//         // Create a set to store unique elements
//         set<int> st;

//         // Insert elements from first array
//         for (int i = 0; i < n; i++) {
//             st.insert(arr1[i]);
//         }

//         // Insert elements from second array
//         for (int i = 0; i < m; i++) {
//             st.insert(arr2[i]);
//         }

//         // Convert set to vector
//         // vector<int> unionArr(st.begin(), st.end());
//         vector<int>unionArr;
//         for(auto it : st){
//             unionArr.push_back(it);
//         }
//         return unionArr;
//     }
// };

// int main() {
//     int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int arr2[] = {2, 3, 4, 4, 5, 11, 12};
//     int n = 10, m = 7;

//     Solution obj;
//     vector<int> result = obj.findUnion(arr1, arr2, n, m);
//     cout << "Union of arr1 and arr2 is: ";
//     for (int val : result) {
//         cout << val << " ";
//     }
//     return 0;
// }




//Optimal(2 pointer approach)
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>a= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int>b= {2, 3, 4, 4, 5, 11, 12};
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    vector<int>unionArr;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(unionArr.size()==0 || unionArr.back()!=a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back()!=b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(unionArr.size()==0 || unionArr.back()!=(b[j])){
            unionArr.push_back(b[j]);
        }
        j++;
    }
    while(i<n1){
        if(unionArr.size()==0 || unionArr.back()!=a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
    for(auto it : unionArr){
        cout<<it<<" ";
    }
    return 0;
}
 