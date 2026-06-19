//brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={-2,-3,4,-1,-2,1,5,-3};
//     int n=8;
//     int maximum=INT_MIN;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             int sum=0;
//             for(int k=i;k<j;k++){
//                 sum+=arr[k];
//                 maximum=max(sum,maximum);
//             }
//         }
//     }
//     cout<<maximum;
//     return 0;
// }


// //Better
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    int arr[]={-2,-3,4,-1,-2,1,5,-3};
//     int n=sizeof(arr) / sizeof(arr[0]);
//     int maximum=INT_MIN;
//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum+=arr[j];
//             maximum=max(sum,maximum);     
//         }
//     }
//     cout<<maximum;
//     return 0;
// }

//Optimal(Kadane's Algorithm)
//How to find maximum subarrays' sum and and subarray with maximum sum  
#include<bits/stdc++.h>
using namespace std;
int main(){
 int arr[]={-2,-3,4,-1,-2,1,5,-3};
 int n=8,start=0,ansStart=-1,ansEnd=-1;
 long long sum=0,maxi=LONG_MIN;
 for(int i=0;i<n;i++){
    if(sum==0){  //for printing subarray with max sum
       start=i; //for printing subarray with max sum
    } 
    sum+=arr[i];
     
    if(sum>maxi){
        maxi=sum;
        ansStart=start;  //for printing subarray with max sum
        ansEnd=i;     //for printing subarray with max sum
    }

    if(sum<0){
        sum=0;
    }
 }
 if(maxi<0){
    cout<<"{}";
    return 0;
 }
 cout<<maxi<<endl;  //Printing Maximum subarray sum
 for(int i=ansStart;i<=ansEnd;i++){
    cout<<arr[i]<<" ";   //Printing subarray with maximum sum
 }
 return 0;
}