// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={1,1,2,2,3,3,4,5,5,6,6};
//     for(int i=0;i<arr.size();i++){
//         if(i==0){
//             if(arr[i]!=arr[i+1]){
//                 cout<<arr[0];
//             }
//         }
//         else if(i==arr.size()-1){
//             if(arr[i]!=arr[i-1]){
//                 cout<<arr[i];
//             }
//         }
//         else{
//             if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1]){
//                 cout<<arr[i];
//             }
//         }
//     }
//     return 0;
// }


//Better
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={1,1,2,2,3,3,4,5,5,6,6};
//     int ans=0;
//     for(int i=0;i<arr.size();i++){
//         ans=ans^arr[i];
//     }
//     cout<<ans;
//     return 0;
// }




//Optimal
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,1,2,2,3,3,4,5,5,6,6};
    int n=arr.size();

    if(n==1) {
        cout<<arr[0];
        return 0;
    }
    if(arr[0]!=arr[1]) {
        cout<<arr[0];
        return 0;
    }
    if(arr[n-1]!=arr[n-2]) {
        cout<<arr[n-1];
        return 0;
    }

    int low=1,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) {
            cout<<arr[mid];
            return 0;
        }
        
        if(mid%2==1 && arr[mid-1]==arr[mid] || mid%2==0 && arr[mid]==arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}