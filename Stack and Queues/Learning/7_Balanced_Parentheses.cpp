#include<bits/stdc++.h>
using namespace std;
int main(){
    string  s ="()[{}()]";
    stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' )  st.push(s[i]);

            else{
                if(st.empty()) {
                    cout<<"false";
                    return 0;
                }

                char ch=st.top();
                st.pop();
                if((s[i]==')' && ch=='(') || (s[i]==']' && ch=='[') || (s[i]=='}' && ch=='{') )  continue;

                else {
                    cout<<"false";
                    return 0;
                }
            }
        }
        cout<<(st.empty() ? "true" : "false");
        return 0;
}