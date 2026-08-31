#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "MCMXCIV";
    int integer=0; 
    unordered_map<char,int> roman={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    for(int i=0;i<s.size()-1;i++){
       if(roman[s[i]]<roman[s[i+1]]){
        integer-=roman[s[i]];
       }
       else{
        integer+=roman[s[i]];  
       }
    }
    cout<<integer + roman[s.back()];  //last left char got add up
    return 0;
}


// Time Complexity: O(n), where n is the length of the input string since we traverse the string once.
//Space Complexity: O(1), since we use a fixed-size map for Roman numerals.



//s.back() returns the last character of the string.
//So roman[s.back()] looks up the integer value of the last Roman numeral.
//Here s.back()=s[6] is 'V' so roman['V']=5