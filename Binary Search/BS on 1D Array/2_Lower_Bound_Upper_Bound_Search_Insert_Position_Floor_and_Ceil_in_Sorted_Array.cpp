// //Lower Bound
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={1,2,3,3,5,8,8,10,10,11};
//     int n=arr.size();
//     int x=9;
//     int low=0,high=n-1;
//     int ans=n;
//     while(low<=high){      
//         int mid=(low+high)/2;     // we can use this shortcut in place of whole while {}, int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();  and then cout<<lb;
//         if(arr[mid]>=x){
//             ans=mid;   //ans get updated 
//             high=mid-1; //look for more small index at left
//         }
//         else{
//             low=mid+1;   //look for right
//         }
//     }  
//     cout<<ans;
//     return 0;
// }




// // //Upper Bound
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={1,2,3,3,5,8,8,10,10,11};
//     int n=arr.size();
//     int x=9;
//     int low=0,high=n-1;
//     int ans=n;
//     while(low<=high){      
//         int mid=(low+high)/2;     // we can use this shortcut in place of whole while {}, int lb=upper_bound(arr.begin(),arr.end(),x)-arr.begin();  and then cout<<lb;
//         if(arr[mid]>x){
//             ans=mid;   //ans get updated 
//             high=mid-1;  //look for more small index at left
//         }
//         else{
//             low=mid+1;   //look for right
//         }
//     }  
//     cout<<ans;
//     return 0;
// }




// //Search Insert Position
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={1,2,3,3,5,8,8,10,10,11};
//     int n=arr.size();
//     int x=9;
//     int low=0,high=n-1;
//     int ans=n;
//     while(low<=high){      
//         int mid=(low+high)/2;     // we can use this shortcut in place of whole while {}, int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();  and then cout<<lb;
//         if(arr[mid]>=x){
//             ans=mid;   //ans get updated 
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }  
//     cout<<ans;
//     return 0;
// }


//Floor and Ceil
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={10,20,30,40,50};
    int n=arr.size();
    int x=25;
    int low = 0, high = n - 1;
    int ans1 = -1,ans2= -1;
    // Function to find the floor of x
    while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                ans1 = arr[mid];     // Potential floor
                low = mid + 1;      // Search right side
            } 
            else {
                high = mid - 1;     // Search left side
            }
    }
    cout<<ans1<<endl;
    // Function to find the ceiling of x
    low=0;
    high=n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
                ans2= arr[mid];     // Potential ceil
                high = mid - 1;     // Search left side
        }
        else {
                low = mid + 1;      // Search right side
        }
    }
    cout<<ans2;
    return 0;

}
