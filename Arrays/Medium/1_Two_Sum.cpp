// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={2,6,5,8,11};
//     int target=14;
//     int n=sizeof(arr)/sizeof(arr[0]);
//     for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){    //Little Optimization,Put j=i+1
//         if(i==j) continue;    

//         if(arr[i]+arr[j]==target){
//            cout<<i<<" "<<j;
//            return 0;
//         }
//        }
//     }
// return 0;
// }

// //Better(Hashing)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n =5,target=5;
//     vector<int>book;
//     book.emplace_back(4);
//     book.emplace_back(1);
//     book.emplace_back(2);
//     book.emplace_back(3);
//     book.emplace_back(1);
//     map<int,int>mpp;
//     for(int i=0;i<n;i++){
//         int a=book[i];
//         int moreNeeded=target-a;
//         if (mpp.find(moreNeeded)!=mpp.end()){ //mpp searches for num2 in map,if exist-returns iterator ,if not- returns mpp.end()
//             cout<<"Yes"; // return {mpp[moreNeeded],i};
//             return 0;
//         }
//         mpp[a]=i; // if the required number is not found in map,store current number and its index in the map
//     }
//      cout<<"No"; //return {-1,-1};
//      return 0;
// }

//Optimal(2 pointer approach)(Greedy approach)
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>book;
    book.emplace_back(4);
    book.emplace_back(1);
    book.emplace_back(2);
    book.emplace_back(3);
    book.emplace_back(1);
    int n =5,target=5;
    int left=0,right=n-1;
    sort(book.begin(),book.end());
    while(left<right){
      int sum=book[left]+book[right];
      if(sum==target){
        cout<<"yes";
        return 0;}
      else if(sum<target)
        left++;
      else 
        right--; 
    }
    cout<<"yes";
    return 0;
}    