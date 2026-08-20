//Primitive valid parentheses is 
//Non Empty and 
//cannot be split into smaller valid parts

#include<bits/stdc++.h>
using namespace std;
int main(){
    string  s = "()(()())(())";
    string result="";
    int level=0;  //Track depth of parentheses
    for(auto ch : s){  //process each character one by one.
        if(ch=='('){
            level++;
            if(level>1){   //When level == 1, it's the outermost opening bracket
                result+=ch;
            }
        }

        else if(ch==')'){
            level--;
            if(level>0){  //When level == 0, it's the outermost closing bracket
                result+=ch;
            }
        }
    }
    cout<<result;
    return 0;
}


//Time Complexity-> O(N),since we are only doing traversing of the string
//Space Complexity-> O(1), we are using a few variables to track the current state.



//String concatenation
//1. Using + Operator
// string a = "Hello";
// string b = "World";
// string c = a + " " + b;

//Output:Hello World

//2. Using += Operator (what you used)
// string result = "";
// result += 'a';
// result += "bc";

//Output:abc

//3. Using append() Function
// string s = "Hello";
// s.append(" World");

//Output:Hello World