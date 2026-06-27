//Briute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={1,2,3,1,1,1,1,4,2,3};
//     int n = 10;
//     int target_sum=3;
//     int len=0;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum=0;
//             for(int k=i;k<=j;k++){  //subarray (i to j)
//                 sum+=arr[k];
//             }
//             if(sum==target_sum){
//                 len=max(len,j-i+1);
//             }
//         }
//    }
//    cout<<len;
//    return 0;
//} 

// Better
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={1,2,3,1,1,1,1,4,2,3};
//     int n = 10;
//     int target_sum=3;
//     int len=0;
//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum+=arr[j];
//             if(sum==target_sum){
//                 len=max(len,j-i+1);
//             }
//         }
//    }
//    cout<<len;
//    return 0;
// }


//Optimal(Prefix Sum)(using hashing)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,-3,1,1,1,4,2,-3};
    int k=3;
    unordered_map<int,int>mpp;
    mpp[0]=1;  //Because if a subarray from index 0 ,itself sums to k, we need to count it.
    int preSum=0;
    int cnt=0;
    for(int i=0;i<10;i++){
        preSum+=arr[i];  // update prefix sum    // 1. Add current element 
        int remove=preSum-k;  // value we need to find,(S-k) // 2. Check what prefix sum we need (preSum - k)
        cnt+=mpp[remove];    // add how many times it occurred   // 3. If that prefix sum existed before, it means a subarray with sum = k ends here
        mpp[preSum]+=1;     // store current prefix sum in map
    }
    cout<<cnt;
    return 0;

}




// cnt += mpp[remove];
// 🔹 What it means:
// remove = preSum - k;
// So you're checking:
// “How many times have I seen a prefix sum equal to (preSum - k) before?”

// 🔹 What mpp[remove] stores:
// mpp[x] = number of times prefix sum x has appeared so far.
// So:
// mpp[remove]
// tells you:
// 👉 “How many valid starting points exist for subarrays ending here with sum = k?”


// Simple intuition:
// Think of it like:
// “If I previously reached a sum of preSum - k, then from that point to now, the sum is exactly k.”
// And if that happened multiple times, you add all of them.



// What happens in
// cnt += mpp[remove];
// if remove has never appeared before?
// 🔹 Short answer:
// 👉 Then nothing gets added to cnt (i.e., it adds 0).

// If remove exists → returns its frequency
// If remove does NOT exist → it creates it with value 0


// Important side note ⚠️
// Even if it doesn't exist:
// mpp[remove]
// inserts remove into the map with value 0
//unnecessary keys get added in map 