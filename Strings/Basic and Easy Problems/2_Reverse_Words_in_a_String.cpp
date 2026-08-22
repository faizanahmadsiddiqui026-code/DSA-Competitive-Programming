// //Brute Force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   string  s = "welcome to the jungle";
//   vector<string>words;

//   string word="";
//   for(int i=0;i<s.size();i++){  //Traverse the string character by character
//     if(s[i]!=' '){    //will throw error if used s[i]!=" "   (this is a string, not a char)
//         word+=s[i];   //Concatenate
//     }
//     else if(!word.empty()){
//         words.push_back(word);
//         word="";   //resetting for the next word
//     }
//   }

//   if (!word.empty()) {   //for last word  //Important because the last word does not end with a space
//         words.push_back(word);
//   }

//   reverse(words.begin(), words.end());

//   string result="";
//   for(int i=0;i<words.size();i++){
//     result+=words[i]; //Concatenate
//     if(i<words.size()-1){    //checking condition for last word
//         result+=" ";    //then give space b/w words except after the last word
//     }
//   }
//   cout<<result;
//   return 0;
// }


//Time Complexity-O(N), We traverse the string once to collect words (O(N)) and once more to reverse and join them (O(N)). Hence total time is O(N).
//Space Complexity-O(N), requires extra space to store all the words


//Optimal(Pointer)
#include<bits/stdc++.h>
using namespace std;
int main(){
  string  s = "welcome to the jungle";
  string result="";
  int i=s.size()-1;  //Pointer starts from last character
  while(i>=0){
    while(i>=0 && s[i]==' '){   //Ignore spaces
        i--;  
    }
    if(i<0){   //If pointer goes out of bounds → stop the loop
        break;
    }
    int end=i;   //Marks the last index of the current word
    while (i >= 0 && s[i] != ' ') {   //Move left until a space is found
        i--;     //i is at space before the word This implies that  Word starts at i + 1
    }
    string word = s.substr(i + 1, end - i);     //s.substr(position,length)
    if (!result.empty()) {
            result += " ";    //Adds space only between words ,Prevents:Leading space ❌ Extra trailing space ❌
    }
    result += word;
  }
  cout<<result;
  return 0;
}


//Time Complexity-O(N), , We traverse the string once from right to left and construct the result directly without extra passes.
//Space Complexity-O(1), Ignoring the output string, no additional data structures proportional to input size are used.








// A character is one single element, whereas a string is a collection of characters.
// In memory, a string is essentially an array of characters ending with a special null character \0 in languages like C.


// Main Difference for Coding Purposes

// Memory & Storage:
// A character usually takes 1 byte (in ASCII).
// A string takes multiple bytes (1 per character) + 1 extra byte for the null terminator (\0 in C).

// Operations:
// Characters: Can be compared, incremented/decremented, or used in arithmetic (like 'A' + 1 = 'B').
// Strings: Need string functions (strlen, strcpy, concat) for most operations; cannot do arithmetic directly.

// Use Case:
// Character: Ideal for storing single symbols or iterating over a string.
// String: Ideal for storing text, words, sentences, or sequences of data.