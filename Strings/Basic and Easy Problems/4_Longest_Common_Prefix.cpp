//Sorted lexicographically” means arranged in the same order as words appear in a dictionary.
// For numbers (as strings):
// Lexicographic sorting treats them like text:
// "10", "2", "30" → sorted → "10", "2", "30"
// (because "1" comes before "2")
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string> str = {"interview", "internet", "internal", "interval"};
    if(str.empty()){
        cout<<"";
        return 0;
    }
    sort(str.begin(),str.end());
    string first=str[0];
    string last=str[str.size()-1];
    string ans="";
    int minLength=min(first.size(),last.size());
    for(int i=0;i<minLength;i++){
        if(first[i]!=last[i]){
            break;
        }
        ans+=first[i];
    }
    cout<<ans;
    return 0;
}



// Time Complexity: O(N * log N + M), where N is the number of strings and M is the minimum length of a string. The sorting operation takes O(N * log N) time, and the comparison of characters in the first and last strings takes O(M) time.

// Space Complexity: O(M), as the ans variable can store the length of the prefix which in the worst case will be O(M).




// How C++ sorts strings
// In C++, sort() uses lexicographical comparison for strings (dictionary order).
// That means it compares strings character by character, like this:
// Compare first letters of two words
// If same, compare second letters
// Continue until one is smaller (or one word ends)
// Example:
// "internal" vs "internet"
// compare 'i' == 'i'
// 'n' == 'n'
// 't' == 't'
// 'e' == 'e'
//  'r' == 'r'
// 'n' < 't' → so "internal" comes first
// 👉 So:
// Strings are compared using their letters
// But sorting is applied to entire words, not rearranging letters inside them