//Brute force
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,1,2,2,2,3,3};
    int n=arr.size();
    set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int index=0;
    for(auto it:st){
        arr[index]=it;
        index++;
    }
    return 0;
}


//Optimal(2 Pointer Approach)
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,1,2,2,2,3,3};
    int n=arr.size();
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    cout<<i+1<<endl;
    return 0;
}