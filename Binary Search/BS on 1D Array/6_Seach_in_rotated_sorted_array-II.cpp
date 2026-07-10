#include<bits/stdc++.h>
using namespace std;
int main(){
   vector<int>arr={3,1,2,3,3,3,3};
   int target=3;

   int low=0,high=arr.size()-1;
   while(low<=high){
    int mid=low+(high-low)/2;
    if(arr[mid]==target){
        cout<<mid;
        return 0;
    } 

    if(arr[low]==arr[mid]&& arr[mid]==arr[high]){
        low++;
        high--;
        continue; // skip this iteration and recalculate mid
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