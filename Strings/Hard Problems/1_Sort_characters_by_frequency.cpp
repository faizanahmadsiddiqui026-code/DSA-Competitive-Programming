//  Return the array of unique characters, sorted by highest to lowest occurring characters.
//If two or more characters have same frequency then arrange them in alphabetic order.

#include<bits/stdc++.h>
using namespace std;
static bool comparator(pair<int, char> p1, pair<int, char> p2) {
    if (p1.first > p2.first) return true;   // Higher frequency comes first
    if (p1.first < p2.first) return false;  // Lower frequency comes later
    return p1.second < p2.second;     // Same frequency → alphabetically
}

int main(){
   string s="tree";   
   pair<int, char> freq[26];
   for (int i = 0; i < 26; i++) { //T.C.->O(N)
            freq[i] = {0, i + 'a'};  
   }
   for (char ch : s) {
            freq[ch - 'a'].first++;
   }
   sort(freq, freq + 26, comparator);  //T.C.->O(k*log(k))
   vector<char> ans;
        for (int i = 0; i < 26; i++) {
            if (freq[i].first > 0) ans.push_back(freq[i].second);
        }

        // Return the result
        for(char ch : ans){
           cout<<ch<<" ";
        }
        return 0;
}



// Time Complexity: O(n + k log k), where n is the length of the string and k is the constant 26 for the alphabet.
// Space Complexity: O(k) , where k is the constant 26 for the frequency array.




// A comparator is a custom function that tells the sort() function how to compare two elements when sorting.
// By default, sort() arranges numbers or letters in ascending order.
// Example:
// vector<int> v = {3, 1, 4};
// sort(v.begin(), v.end());  // Default ascending sort
// // output -> v = {1, 3, 4}
// But sometimes, you want a different order (like descending or custom rules).
// That’s when you use a comparator function.


//This is a C++ string constructor
//string(int n,char c)
//It creates a string of length n, filled with character c.




