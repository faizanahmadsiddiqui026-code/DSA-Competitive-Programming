// //My approach
// #include<bits/stdc++.h>
// using namespace  std;
// int main(){
//     string s = "rotation";
//     string goal = "tionrota";
//     if(s.size() != goal.size()) {
//         cout << "false" << endl;
//         return 0;
//     }
//     if(s==goal){
//         cout<<"true";
//         return 0;
//     }
//     for(int i=1;i<s.size();i++){
//       reverse(s.begin(),s.end());
//       reverse(s.begin(),s.begin()+i);
//       reverse(s.begin()+i,s.end());
//       if(s==goal){
//        cout<<"true";
//        return 0;
//       }
//     }
//     cout<<"false";
//     return 0;
      
// }

//Time Complexity: O(n²)
//Space Complexity: O(1)


// //Brute force
// #include<bits/stdc++.h>
// using namespace  std;
// int main(){
//     string s = "rotation";
//     string goal = "tionrota";
//     if(s.size() != goal.size()) {
//        cout << "false" << endl;
//        return 0;
//     }
//     for (int i = 0; i < s.length(); i++) {
//         string rotated = s.substr(i) + s.substr(0, i);  //s.substr(pos)  //s.substr(pos,len)
//         if (rotated == goal) {
//             cout<<"true";
//             return 0;
//         }
//     }
//     cout<<"false";
//     return 0;
// }

// Time Complexity: O(N^2) since generating N rotations and each comparison takes O(N) time.
//Space Complexity: O(N) for the space needed to store each rotated string.


//Optimal approach
#include<bits/stdc++.h>
using namespace  std;
int main(){
    string s = "rotation";
    string goal = "tionrota";

    if (s.size() != goal.size()) {
        cout << "false";
        return 0;
    }

    string Ds=s+s;
    cout<<(Ds.find(goal) != string::npos);
    return 0;
}


// Time Complexity: O(N), because checking for a substring in s + s is linear in time.
// Space Complexity: O(N) for the space needed to store the concatenated string s + s.




//if (Ds.find(goal) != string::npos) this condition can also work




//Ds.find(goal)
//find() is a function of string
//It searches for the substring goal inside Ds

//It returns:
//✅ Index (0, 1, 2, …) → if goal is found
//❌ string::npos → if goal is NOT found

//2. What is string::npos?
//It’s a special constant meaning “not found”
//Internally, it's a very large number (-1 as unsigned)



// The comparison
// Ds.find(goal) != string::npos
// This checks:
// 👉 “Is goal present inside Ds?”
// ✅ Outcomes
// Case 1: Found
// Ds = "rotationrotation"
// goal = "tionrota"
// Ds.find(goal) → 4
// 4 != string::npos → true
// ✔ Result: true

// Case 2: Not Found
// goal = "abcdef"
// Ds.find(goal) → string::npos
// string::npos != string::npos → false
// ✔ Result: false