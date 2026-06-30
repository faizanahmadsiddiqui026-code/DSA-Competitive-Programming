// //1st Problem (given row r and column c tell the element at that place)

//Extreme Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    int row=5;
//    int col=3;

//    int n=row-1;
//    int r=col-1;

//    if(col > row || col < 1) {   //1 ≤ col ≤ row must be true everytime
//     cout << "Invalid input";
//     return 0;
//    }

//    long long res=1;
//    for(int i=0;i<r;i++){
//     res *=(n-i);
//     res/=(i+1);
//    }
//    cout<<res;
//    return 0;
// }





//2nd Problem(Print any Nth row of pascal triangle)

// //Extreme Brute force
// #include<bits/stdc++.h>
// using namespace std;

// int nCr(int n,int r){
//    long long res=1;
//    for(int i=0;i<r;i++){
//     res *=(n-i);
//     res/=(i+1);
//    }
//    return res;
// }

// int main(){
//     int row=6;
//     for(int col=1;col<=row;col++){
//        cout<<nCr(row-1,col-1)<<" ";
//     }
//     return 0;
// }






// //Optimal
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   int row=6;  
//   int ans=1;
//   cout<<ans<<" ";
//   for(int i=1;i<row;i++){
//     ans*=(row-i);
//     ans/=i;
//     cout<<ans<<" ";
//   }
//   return 0;
// }






//3rd Problem given N row print the entire pascal triangle

//Extreme Brute Force
// #include<bits/stdc++.h>
// using namespace std;

// int nCr(int n,int r){
//    long long res=1;
//    for(int i=0;i<r;i++){
//     res *=(n-i);
//     res/=(i+1);
//    }
//    return res;
// }

// int main(){
//     int n=6;
//    vector<vector<int>>ans;
//    for(int row=1;row<=n;row++){
//      vector<int>temp;
//      for(int col=1;col<=row;col++){
//         temp.push_back(nCr(row-1,col-1));
//      }
//      ans.push_back(temp);
//    }

//    //for printing
//    for(auto it:ans){
//     for(auto el:it){
//         cout<<el<<" ";
//     }
//     cout<<endl;
//    }
//    return 0;
// }





//Optimal
#include<bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row){
    long long ans=1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

int main(){
    int N=6;
    vector<vector<int>>ans;
    for(int i=1;i<=N;i++){
        ans.push_back(generateRow(i));
    }

    for(auto row:ans){
    for(auto val:row){
        cout<<val<<" ";
    }
    cout<<endl;
   }
   return 0;
}