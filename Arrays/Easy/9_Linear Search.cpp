#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,2,3,4,5};
    int num = 3;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==num){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1;
    return 0;  
}