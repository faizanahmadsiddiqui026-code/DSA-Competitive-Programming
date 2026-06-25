//brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
//     vector<vector<int>> ans(4,vector<int>(4,0)); //intialisation 2d vector
//     for(int i=0;i<matrix.size();i++){
//         for(int j=0;j<matrix[0].size();j++){
//             ans[j][4-1-i]=matrix[i][j];  // we didn't use emplace back ,reason it's a 2d vector not a vector of vector
//         }
//     }
//     //printing the original matrix
//     for(auto it:matrix){
//         for(auto vec:it){
//             cout<<vec<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
//     //printing the ans matrix
//     for(auto it:ans){
//         for(auto vec:it){
//             cout<<vec<<" ";
//         }
//         cout<<endl; 
//     }
//     return 0;
// }


//optimal
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}; 
    for(int i=0;i<=4-2;i++){
        for(int j=i+1;j<=4-1;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<=4-1;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    for(auto it:matrix){
       for(auto vec:it){
             cout<<vec<<" ";
        }
        cout<<endl; 
    }
}