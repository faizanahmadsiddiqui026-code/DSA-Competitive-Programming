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

    cout<<last-first+1;
    return 0;
}
