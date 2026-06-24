// //brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    vector<vector<int>>matrix={{1,1,1,1},{1,0,1,1},{1,1,0,1},{1,0,0,1}};
//         // Get number of rows
//         int m = matrix.size();
//         // Get number of columns
//         int n = matrix[0].size();

//         // Traverse each cell of the matrix
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 // If current cell is zero
//                 if (matrix[i][j] == 0) {
//                     // Mark all elements in this row as -1 (except existing zeros)
//                     for (int col = 0; col < n; col++) {
//                         if (matrix[i][col] != 0)
//                             matrix[i][col] = -1;
//                     }
//                     // Mark all elements in this column as -1 (except existing zeros)
//                     for (int row = 0; row < m; row++) {
//                         if (matrix[row][j] != 0)
//                             matrix[row][j] = -1;
//                     }
//                 }
//             }
//         }
//          // Second pass: replace all -1 markers with 0
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == -1)
//                     matrix[i][j] = 0;
//             }
//         }
//          // Print final matrix
//         for (auto row : matrix) {
//          for (auto val : row) {
//             cout << val << " ";
//          }
//          cout << endl;
//         }
//         return 0;
// }



// //Better
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    vector<vector<int>>matrix={{1,1,1,1},{1,0,1,1},{1,1,0,1},{1,0,0,1}};
//    int n=4,m=4;
//    int col[m]={0}, row[n]={0};
//    for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         if(matrix[i][j]==0){
//             row[i]=1;
//             col[j]=1;
//         }
//     }
//    }
//    for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         if(row[i] || col[j]){
//             matrix[i][j]=0;
//         }
//     }
//    }
//    //print the matrix
//    for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//       cout<<matrix[i][j]<<" ";
//    }
//    cout<<endl;
//   }
//   return 0;
// }


//Optimal
#include <bits/stdc++.h>
using namespace std;
int main(){
   vector<vector<int>> matrix = {{1,1,1,1},{1,0,1,1},{1,1,0,1},{0,1,1,1}};
    int n = matrix.size();
    int m = matrix[0].size();
    int col0=1;  //This variable keeps track if first column needs to be zero.
    //matrix[i][0]  -> row marker
    //matrix[0][j]  -> column marker
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0){  //here j=0 means col first
                    matrix[0][j]=0;
                }
                else{         //matrix[3][0] = 0
                    col0=0;   //matrix[i][0] = 0 // Already 0
                              //j == 0   //So we cannot use matrix[0][0] to mark column.
                              //Instead  col0 = 0  //first column must become zero later
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
           if(matrix[i][j]!=0){
             if(matrix[0][j]==0 || matrix[i][0]==0){
                matrix[i][j]=0;
             }
           }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
    for(auto it :matrix){
        for(auto vec:it){
            cout<<vec<<" ";
        }
        cout<<endl;
    }
    return 0;

}