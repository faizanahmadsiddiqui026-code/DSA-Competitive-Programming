// //brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//  int arr[]={2,2,3,3,1,2,2};
//  int n=7;
//  for(int i=0;i<n;i++){
//     int cnt=0;
//     for(int j=0;j<n;j++){
//        if(arr[j]==arr[i]){
//         cnt++;
//        }
//        if(cnt>(n/2)){
//         cout<<arr[i];
//         return 0;
//        }
//     }
//  }
//  cout<<-1; //if no majority element
//  return 0;
// }


// //better
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={2,2,3,3,1,2,2};
//     int n=7;
//     map<int,int>mpp;
//     for(int i=0;i<n;i++){
//         mpp[arr[i]]++;
//     }
//     for(auto it: mpp){
//         if(it.second>(n/2)){
//             cout<<it.first;
//             return 0;
//         }
//     }
//     cout<<-1;
//     return 0;
// }

//Optimal(Moore's Voting Algorithm)
#include<bits/stdc++.h>
using namespace std;
int main(){
   int arr[]={7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int n=16;
    int cnt=0;
    int ele;
    for(int i=0;i<n;i++){
        if (cnt==0){   //check for a new section
            ele=arr[i];
        }
        else if (arr[i]==ele){   //if count is not 0
            cnt++;
        }
        else{
            cnt--;
        }
    }
    //once we got element ele=5,then
    int cnt1=0;
    for(int i=0;i<n;i++){
      if(arr[i]==ele){
         cnt1++;
      }
    }
    if(cnt1>(n/2)){
        cout<<ele;
        return 0;
    }
    cout<<-1;
    return 0;

}