// //My Approach(Brute Force)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    string s="paper";
//    string t="title";
//    if(s.size()!=t.size()){
//     cout<<false;
//     return 0;
//    }
//    unordered_map<char,char> mpp1;
//    for(int i=0;i<s.size();i++){
//     if(mpp1.find(s[i])==mpp1.end()){
//        mpp1[s[i]]=t[i];
//     }
//     else{
//         if(mpp1[s[i]] != t[i]){  
//            cout << "false";
//            return 0;
//        }
//     }
//    }
//    unordered_map<char,char> mpp2;
//    for(int i=0;i<t.size();i++){
//     if(mpp2.find(t[i])==mpp2.end()){
//        mpp2[t[i]]=s[i];
//     }
//     else{
//         if(mpp2[t[i]] != s[i]){  
//            cout << "false";
//            return 0;
//        }
//     }
//    }
//    cout << "true";
//    return 0;
// }

//Time complexity = O(n) average, O(n²) worst-case
//Space Complexity = O(n)


//else condition meaning in plain english
// What it means in plain English
// “If this character of s was already mapped before, then it must map to the same character again.
// If it maps to something different now → ❌ invalid.”




//Optimal
#include<bits/stdc++.h>
using namespace std;
int main(){
   string s = "paper";
   string t = "title";
   int m1[256] = {0}, m2[256] = {0}; 
   int n = s.size(); 
   for (int i = 0; i < n; ++i) {
      // If previous positions of current characters differ, return false
      if (m1[s[i]] != m2[t[i]]) 
         return false;   
         // Update the position with current index + 1
         m1[s[i]] = i + 1;
         m2[t[i]] = i + 1;
      }      
   // If no mismatch is found, return true
   return true;
}


// Time Complexity: O(N) where N is the length of the input strings, due to the single loop iterating through each character.
// Space Complexity: O(1) since the space used by the arrays is constant (256 fixed size) regardless of input size



// How it Works Conceptually
// Imagine mapping s[i] → t[i].
// Keep track of the last time we saw each character.
// If at any point, the last seen indices of s[i] and t[i] don’t match, the mapping is inconsistent → not isomorphic.