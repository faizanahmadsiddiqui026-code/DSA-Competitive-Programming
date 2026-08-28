//✔ Anagrams are strings that have the same characters with the same frequency (order doesn’t matter)   ❌ Not all permutations need to be generated
//Anagram of the string are all the possible permutation of the string


//My Approach
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    string s1="ACT";
//    string s2="CAT";
//    if(s1.size() != s2.size()){
//     cout << "false";
//     return 0;
//    }

//    unordered_map<char,int>mpp1;
//    for(int i=0;i<s1.size();i++){
//     mpp1[s1[i]]++;
//    }

//    unordered_map<char,int>mpp2;
//    for(int i=0;i<s2.size();i++){
//     mpp2[s2[i]]++;
//    }

//    if(mpp1==mpp2){
//     cout<<"true";
//     return 0;
//    }
//    cout<<"false";
//    return 0;
// }

//Time Complexity->O(n)
//Space Complexity->O(n)



//Brute force
#include<bits/stdc++.h>
using namespace std;
int main(){
   string s1="ACT";
   string s2="CAT";
   if(s1.size() != s2.size()){
    cout << "false";
    return 0;
   }
   sort(s1.begin(),s1.end());
   sort(s2.begin(),s2.end());
    
   if(s1 == s2) {
    cout << "true";
    return 0;
   }
   cout << "false";
   return 0;
}


//Time Complexity: O(N log N), where N is the length of the strings. This is due to the sorting step performed on both strings.
//Space Complexity: O(1), as the sorting is done in-place and no extra space proportional to input size is used (excluding the input strings themselves).

//Optimal approach
#include<bits/stdc++.h>
using namespace std;
int main(){
   string s1="ACT";
   string s2="CAT";
   if(s1.size() != s2.size()){
    cout << "false";
    return 0;
   }
   int freq[26]={0};

   for(int i=0;i<s1.size();i++){
     freq[s1[i] - 'A']++; // Increment frequency for each character in str1
   }

   for (int i = 0; i < s2.length(); i++) {
        freq[s2[i] - 'A']--;  // Decrement frequency for each character in str2
   }

   // Check if all frequencies are zero, meaning both strings have the same characters
   for (int i = 0; i < 26; i++) {
        if (freq[i] != 0){
            cout<<"false";
            return 0;
        }
   }
   cout<<"true";
   return 0;
}



//Time Complexity: O(N), where N is the length of the strings. Each string is traversed once, and the frequency array is checked in constant time (26 iterations).
//Space Complexity: O(1), as a fixed-size array of 26 elements is used regardless of the input size.


// Edge Case Improvement
// If input can be:
// lowercase letters → use 'a'
// mixed case → normalize first
// full ASCII → use size 256
// Example (lowercase safe version):
// freq[s1[i] - 'a']++;
// freq[s2[i] - 'a']--;


//Better way of writing
// for(char c : s1) freq[c - 'a']++;
// for(char c : s2) freq[c - 'a']--;
