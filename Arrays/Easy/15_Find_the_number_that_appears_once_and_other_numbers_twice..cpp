//Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={1,1,2,3,3,4,4};
//     int n=arr.size();
//     for(int i=0;i<n;i++){
//         int cnt=0;
//         int num=arr[i];
//         for(int j=0;j<n;j++){
//             if(arr[j]==num) cnt++;
//         }
//         if(cnt==1){
//             cout<<num;
//             return 0;
//         }
//     }
//     return 0;
// }



//Better(for +ve and small number)(Hashing)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={1,1,2,3,3,4,4};
//     int n=arr.size();
//     int maxi=arr[0];
//     for(int i=0;i<n;i++){
//         maxi=max(maxi,arr[i]);
//     }

//     vector<int>hash(maxi+1,0);    
//     for(int i=0;i<n;i++){
//         hash[arr[i]]++;
//     }

//     for(int i=0;i<n;i++){
//         if(hash[arr[i]]==1){
//             cout<<arr[i];
//             return 0;
//         } 
//     }
//     return 0;
// }



//Better(for -ve and large number)(Map)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={1,1,2,3,3,4,4};
//     int n=arr.size();

//     unordered_map<long long,int>mpp;
//     for(int i=0;i<n;i++){
//         mpp[arr[i]]++;
//     }
//     for(auto it : mpp){
//         if(it.second==1){
//             cout<<it.first;
//             return 0;
//         }
//     }
//     return 0;
// }



//Optimal(Xor operation)
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,1,2,3,3,4,4};
    int n=arr.size();
    int XORR=0;
    for(int i=0;i<n;i++){
        XORR^=arr[i];
    }
    cout<<XORR;
    return 0;
}