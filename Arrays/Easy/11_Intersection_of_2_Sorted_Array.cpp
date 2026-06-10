// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>a={1,2,2,3,3,4,5,6};
//     vector<int>b={2,3,3,5,6,6,7};
//     int n=a.size();
//     int m=b.size();

//     vector<int>ans;
//     vector<int>vis(m,0);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(a[i]==b[j] && vis[j]==0){
//                 ans.push_back(a[i]);
//                 vis[j]=1;
//                 break;
//             }
//             if(b[j] > a[i]) break;
//         }
//     }
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }
//     return 0;
// }


//Optimal(2 Pointer Approach)
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>a={1,2,2,3,3,4,5,6};
    vector<int>b={2,3,3,5,6,6,7};
    int n=a.size();
    int m=b.size();

    vector<int>ans;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        } 
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

