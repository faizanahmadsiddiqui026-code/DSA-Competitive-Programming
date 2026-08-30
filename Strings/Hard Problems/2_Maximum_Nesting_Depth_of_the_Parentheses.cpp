#include<bits/stdc++.h>
using namespace std;
int main(){
    string  s = "(1+(2*3)+((8)/4))+1";
    int cnt=0;
    int maxi_cnt=0;
    for(char ch:s){
       if(ch=='('){
        cnt++;
        maxi_cnt=max(maxi_cnt,cnt);
       }
       if(ch==')'){
         cnt--;
       } 
    }
    cout<<maxi_cnt;
    return 0;

}

// Time complexity=O(n), where n is the length of the string.
// Space complexity=O(1) , as only constant extra space is used.