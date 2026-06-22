// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    vector<int>arr={10,22,12,3,0,6};
//    vector<int>ans;
//    int n=arr.size();
//    for(int i=0;i<n;i++){
//      bool leader=true;
//      for(int j=i+1;j<n;j++){
//        if(arr[j]>arr[i]){
//         leader=false;
//         break;
//        }
//        }
//        if(leader==true){
//          ans.emplace_back(arr[i]);
//        }

//    }
//    for(int i=0;i<ans.size();i++){
//      cout<<ans[i]<<" ";
//    }
// }


//Optimal(Back Traversal)
#include<bits/stdc++.h>
using namespace std;
int main(){
   vector<int>arr={10,22,12,3,0,6};
   vector<int>ans;
   int n=arr.size();
   int maxi=INT_MIN;
   for(int i=n-1;i>=0;i--){
    if(arr[i]>maxi){
        ans.push_back(arr[i]);
    }
    maxi=max(maxi,arr[i]); //keep track of right max
   }
   
//    reverse(ans.begin(),ans.end()); //only if, we want in original order
//    for(int i=0;i<ans.size();i++){
//       cout<<ans[i]<<" ";
//    } 
//   OR WE CAN USE THIS
   for(int it : ans){
       cout <<it<< " ";
   }
   return 0;
}   