#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="54376";
    int ind =-1;
    int i;
    for (i = s.length() - 1; i >= 0; i--) {
        if ((s[i] - '0') % 2 == 1) {
            ind = i;
             break;
        }
    }
    //Skip leading zeros
    i=0;
    while(i<=ind && s[i]=='0') {
        i++;
    }   
    //Extract substring
    string sub=s.substr(i,ind-i+1);
    cout<<sub;
    return 0;
}


// Time Complexity: O(N), since the loop runs once through the string of length N.
// Space Complexity: O(1), as we are using only a constant amount of extra space.



// What does the program do?
// It extracts the largest prefix of the string (ignoring leading zeros) that ends at the last odd digit.



// s[i] - '0'
// This is the most important part.
// Characters like '0', '1', '2'… are stored using ASCII values.
// For example:
// '0' → 48
// '1' → 49
// '5' → 53

// When you do: s[i] - '0'
// you convert the character digit → integer digit
// Example:
// '5' - '0' = 53 - 48 = 5
// '7' - '0' = 55 - 48 = 7
// So this converts '5' → 5, '7' → 7.



// 🧠 Shortcut Insight
// This is a very common trick in C++:
// 👉 "character digit" → number using:
// digit = ch - '0';