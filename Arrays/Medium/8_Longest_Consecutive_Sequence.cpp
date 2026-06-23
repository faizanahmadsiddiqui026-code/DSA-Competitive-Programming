// //brute force
// #include<bits/stdc++.h>
// using namespace std;
// bool linearSearch(vector<int>&a,int num){
//     int n=a.size();
//     for(int i=0;i<n;i++){
//         if(a[i]==num){
//             return true;
//         }
//     }
//     return false;
// }
// int main(){
//    vector<int>nums={1,1,1,2,2,2,3,3,4,100,100,101,101,102};
//    int n=nums.size();
//    int longest=1;
//    for(int i=0;i<n;i++){
//     int x=nums[i];
//     int cnt=1;
//     while(linearSearch(nums,x+1)==true){
//         x+=1;
//         cnt+=1;
//     }
//     longest=max(longest,cnt);
//    }
//    cout<<longest;
// }





// //better
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>nums={1,1,1,2,2,2,3,3,4,100,100,101,101,102};
//     if(nums.size()==0){
//         return 0;
//     }
//     sort(nums.begin(),nums.end()); 
//     int n=nums.size();
//     int lastSmaller=INT_MIN;
//     int cnt=0;
//     int longest=0;
//     for(int i=0;i<n;i++){
//         if(nums[i]-1==lastSmaller){
//             cnt+=1;
//             lastSmaller=nums[i];
//         }
//         else if(lastSmaller!=nums[i]){
//             cnt=1;
//             lastSmaller=nums[i];
//         }
//         longest=max(longest,cnt);
//     }
//     cout<<longest;
//     return 0;
// }



//optimal
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={102,4,100,100,101,3,2,1,1};
    int n=arr.size();
    if(n==0){
        return 0;
    }
    int longest=1;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for (auto it:st){
        if(st.find(it-1)==st.end()){  //(it -1) element is not in set but (it) is,we are going to start from this (it) element
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){  //we know that (it+1)element is in set,going to start loop
               x=x+1;
               cnt=cnt+1;
            }
            longest=max(longest,cnt);
        }
    }
    cout<<longest;
    return 0;
}