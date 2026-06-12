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


// //Little better
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


//Better(using Hashing) for subarray containing only positives but optimal for subarray containing both positives and negatives
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={1,2,3,1,1,1,1,4,2,3};
//     long long k=3;
//     map<long long,int>preSumMap;
//     long long sum=0;
//     int maxLen=0;
//     for (int i=0;i<arr.size();i++){
//        sum+=arr[i];
//        if (sum==k){
//         maxLen=max(maxLen,i+1);
//        }
//        long long rem=sum-k;
//        if(preSumMap.find(rem)!=preSumMap.end()){  //if rem exist in map
//           int len=i-preSumMap[rem];  //current index minus the index where rem was first found
//           maxLen=max(maxLen,len);
//        }
//        if(preSumMap.find(sum)==preSumMap.end()){   //if not in map then store preix sum
//        preSumMap[sum]=i;
//        }
//     }
//     cout<<maxLen;
//     return 0;

// }


//Sliding window in DSA is about using two pointers (or indices) to maintain a “window” over the array/string and moving it efficiently to solve problems involving contiguous elements.
//optimal(2 pointer and sliding window approach)
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,2,3,1,1,1,1,3,3};
    long long k=6;
    long long sum=arr[0];
    int left =0,right =0;
    int maxLen=0;
    int n =arr.size();
    while(right<n){
        while(left<=right && sum > k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    cout<<maxLen;
    return 0;
}
