#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> matrix = {{ 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 }};
    vector<int> ans;
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    if(matrix.empty() || matrix[0].empty()) return 0; 
    while(top <= bottom && left <= right) {
        for(int i = left; i <= right; i++) {   //left and right will be check here
                ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++) {   //top and bottom will be check here
            ans.push_back(matrix[i][right]);
        }
        right--; 
        if(top <= bottom) {  //edge case
            for(int i = right; i >= left; i--) {   //right and left will be check here
                    ans.push_back(matrix[bottom][i]);
            }
            bottom--; 
        }
        if(left <= right) { //edge case
            for(int i = bottom; i >= top; i--) {  //bottom and top will be check here
                ans.push_back(matrix[i][left]);
            }
            left++; 
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;

}