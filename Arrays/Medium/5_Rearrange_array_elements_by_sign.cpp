//1-Variety
// //brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={3,1,-2,-5,2,-4};
//     int n=6,j=0,k=0;
//     int pos[n/2],neg[n/2];
//     for (int i=0;i<n;i++){
//            if(arr[i]>0){
//             pos[j]=arr[i];
//             j++;
//            }
//            else{
//             neg[k]=arr[i];
//             k++;
//            }  
//     }
//     for (int i=0;i<n/2;i++){
//         arr[2*i]=pos[i];
//         arr[2*i+1]=neg[i];
//     }
//     for (int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

// //optimal
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//   vector<int>arr={3,1,-2,-5,2,-4};
//   int n=arr.size();
//   vector<int>ans(n,0);
//   int posIndex=0,negIndex=1;
//   for (int i=0;i<n;i++){
//     if(arr[i]<0){
//         ans[negIndex]=arr[i];
//         negIndex+=2;
//     }
//     else{
//        ans[posIndex]=arr[i];
//        posIndex+=2;
//     }
//   }
//   for (int i=0;i<n;i++){
//         cout<<ans[i]<<" ";
//   }
//   return 0;

// }


//2-Variety
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={-1,2,3,4,-3,1},pos,neg;
    int n=arr.size();
    for (int i=0;i<n;i++){
      if(arr[i]>0){
        pos.push_back(arr[i]);
      }
      else{
        neg.push_back(arr[i]);
      }
    }
    if (pos.size()>neg.size()){
        for (int i=0;i<neg.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for (int i=neg.size();i<pos.size();i++){
            arr[index]=pos[i];
            index++;
        }
    }
    else{
        for (int i=0;i<pos.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for (int i=pos.size();i<neg.size();i++){
            arr[index]=neg[i];
            index++;
        }
    }
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}






