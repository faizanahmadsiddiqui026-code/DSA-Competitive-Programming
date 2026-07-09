#include<bits/stdc++.h>
using namespace std;
int main(){
   vector<int>arr={4,5,6,7,0,1,2};
   int target=0;

   int low=0,high=arr.size()-1;
   while(low<=high){
    int mid=low+(high-low)/2;

    if(arr[mid]==target){
        cout<<mid;
        return 0;
    }  
    //left sorted
    if(arr[low]<=arr[mid]){
        if(target>=arr[low] && target<=arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    //right sorted
    else{
        if(target>=arr[mid] && target<=arr[high]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

   }

   cout<<-1;
   return 0;
}