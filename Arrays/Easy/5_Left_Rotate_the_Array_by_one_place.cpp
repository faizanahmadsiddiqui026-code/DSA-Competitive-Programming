#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,1,2,2,2,3,3};
    int n=arr.size();
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}