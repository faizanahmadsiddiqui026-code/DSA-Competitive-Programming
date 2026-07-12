// //For unique elements
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={7,8,1,2,3,4,5,6};
//     int low=0, high=arr.size()-1, ans=INT_MAX;
//     int index=-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(arr[low]<=arr[high]){     
//             if(arr[low]<ans){
//                 index=low;
//                 ans=arr[low];
//             }
//             break;                   
//         }                            
//         if(arr[low]<=arr[mid]){
//             if(arr[low]<ans){
//                 index=low;
//                 ans=arr[low];
//             }
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//             if(arr[mid]<ans){
//                 index=mid;
//                 ans=arr[mid];
//             }
//         }
//     }
//     cout<<index;
//     return 0; 

// }



//For Duplicate elements
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={7,8,1,2,3,4,5,6};
    int low=0, high=arr.size()-1, ans=INT_MAX;
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;

        // If duplicates block decision
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            if(arr[mid]<ans){
                index=mid;
                ans=arr[mid];
            }
            if(arr[high]<ans){
                index=high;
                ans=arr[high];
            }
            low++;
            high--;
            continue;
        } 

        if(arr[low]<=arr[high]){     
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            break;                   
        }                            
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            low=mid+1;
        }
        else{
            high=mid-1;
            if(arr[mid]<ans){
                index=mid;
                ans=arr[mid];
            }
        }
    }
    cout<<index;
    return 0; 

}
