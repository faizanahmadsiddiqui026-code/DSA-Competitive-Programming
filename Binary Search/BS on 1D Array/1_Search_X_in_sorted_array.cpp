// //Iterative code
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int> arr={3,4,6,7,9,12,16,17};
//     int n=arr.size();
//     int low=0,high=n-1,target=6;
//     while(low<=high){
//         int mid=(low + high)/2;
//         if(arr[mid]==target){
//             cout<<"Found at position"<<" "<<mid;
//             return 1;
//         }
//         else if(target>arr[mid]){
//             low=mid+1;
//         }
//         else {
//             high=mid-1;
//         }
//     }
//     cout<<"Not found";
//     return -1;
// }


//Recursive code
#include<bits/stdc++.h>
using namespace std;
int bs(vector<int> &arr,int low,int high,int target){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(target>arr[mid]){
        return bs(arr,mid+1,high,target);
    }
    return bs(arr,low,mid-1,target);
}

int main(){
    vector<int> arr={3,4,6,7,9,12,16,17};
    int n=arr.size();
    int target=13;
    int result= bs(arr,0,n-1,target);
    if(result==-1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at index "<<result;
    }
    return 0;
} 