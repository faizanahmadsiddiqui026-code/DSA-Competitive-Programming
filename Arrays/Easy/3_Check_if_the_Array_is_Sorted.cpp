#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,2,1,3,4,3};
    int n=arr.size();
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            cout<<"False";
            return 0;
        }
    }
    cout<<"True";
    return 0;
}