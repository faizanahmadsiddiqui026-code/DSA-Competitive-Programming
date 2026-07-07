// //brute force(linear search)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={2,4,6,8,8,8,11,13};
//     int first =-1,last=-1,x=8;
//     for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
//      if(arr[i]==x){
//         if(first==-1){
//             first=i;
//         }
//         last=i;
//      }
//     }
//     cout<<first<<endl;
//     cout<<last;
//     return 0;   
// }



// //Better(Lower bound and Upper bound)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={2,4,6,8,8,8,11,13};
//     int n=arr.size();
//     int x=8;
//     int low = 0, high = n - 1;
//     int ans1 = -1,ans2= -1;
//     //Lower bound
//     while (low <= high) {
//             int mid = low + ((high -low) / 2);
//             if (arr[mid] >= x) {
//                 ans1 = mid;     
//                 high = mid - 1;
//             } 
//             else {
//                low = mid + 1;     
//             }
//     }
//     int lb=ans1;
//     if(lb==n || arr[lb]!=x || lb==-1){
//         cout<<-1<<" "<<-1<<endl;
//         return 0;
//     }
//     cout<<lb<<endl;

//     low=0;
//     high=n-1;
//     //upper bound
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (arr[mid] > x) {
//             ans2= mid; 
//             high = mid - 1;
                
                  
//         }
//         else {
//            low = mid + 1;         
//         }
//     }
//     int ub=ans2;
//     cout<<ub-1;
//     return 0;
// }


//Optimal(Binary Search)
#include<bits/stdc++.h>
using namespace std;
int main(){
   vector<int>arr={2,4,6,8,8,8,11,13};
    int n=arr.size();
    int x=8;
    //first occurence
    int low=0,high=n-1;
    int first =-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid]==x){
            first=mid;
            high=mid-1;
        }
        else if(arr[mid]<x) {
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    cout<<first<<" ";

    if(first==-1){
        cout<<-1;
        return 0;
    }
    //last occurence
    low=0,high=n-1;
    int last =-1;
    while(low<=high){
        int mid =(low+high)/2;
        if(arr[mid]==x){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid]<x) {
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
     cout<<last;
}




