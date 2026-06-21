// //better
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   vector<int>arr={2,1,5,4,3,0,0};
//   int n=arr.size();
//   next_permutation(arr.begin(),arr.end());
//   for(int i=0;i<n;i++){
//     cout<<arr[i]<<',';
//   }
// }


//optimal
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={2,1,5,4,3,0,0};
    int n=arr.size();
    int ind=-1;
    for (int i=n-2;i>=0;i--){
      if(arr[i]<arr[i+1]){
        ind=i;
        break;
      }
    }
    if(ind==-1){  //edge case
        reverse(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
        cout<<arr[i]<<',';
        }
        return 0;
    }

    for(int i=n-1;i>ind;i--){
        if(arr[ind]<arr[i]){
            swap(arr[ind],arr[i]);
            break;
        }
    }

    reverse(arr.begin()+ind+1,arr.end());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<',';
    }
    return 0;

}




