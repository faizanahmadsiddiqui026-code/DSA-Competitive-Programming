//for even palindromic string check (i,i+1) for each element 
//for odd palindromic string check (i-1,i+1) for each element
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="babab";
    int n=s.size();
    int start=0;
    int maxLen=1;
    int left,right;
    if(n==1){
        cout<<s;
        return 0;
    }
    for(int i=1;i<n;i++){
        //even case 
        left=i-1;
        right=i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
        //odd case
        left=i-1;
        right=i+1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }
    cout<<s.substr(start, maxLen);
    return 0;
}