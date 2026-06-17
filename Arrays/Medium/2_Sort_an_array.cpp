//brute force
//Any sorting technique 

// //Better
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//  int a[12]={0,1,2,0,1,2,1,2,0,0,0,1,};
//  int n=sizeof(a)/sizeof(a[0]);
//  int cnt_0=0, cnt_1=0, cnt_2=0;
//  for(int i=0;i<n;i++){
//    if (a[i]==0) cnt_0++;
//    else if (a[i]==1) cnt_1++;
//    else cnt_2++;
//  }
//  for(int i=0;i<cnt_0;i++){
//     a[i]=0;}
//  for(int i=cnt_0;i<(cnt_0+cnt_1);i++){
//     a[i]=1;}
//  for(int i=(cnt_0+cnt_1);i<n;i++){
//     a[i]=2;}

//  for(int i=0;i<n;i++){
//     cout<<a[i]<<" ";
//  }
// }

//Optimal(Dutch National Flag Algorithm)(3 pointers)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={0,1,1,0,1,2,1,2,0,0,0};
    int n =sizeof(arr)/sizeof(arr[0]);
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            //swap  if using vector or normally then, swap(arr[low],arr[mid]);
            swap(arr[low],arr[mid]);
            // int temp=arr[low];
            // arr[low]=arr[mid];
            // arr[mid]=temp;

            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else {
           //swap  if using vector or normally then, swap(arr[mid],arr[high]);
           swap(arr[mid],arr[high]);
        //   int temp=arr[mid];
        //   arr[mid]=arr[high];
        //   arr[high]=temp;

            high--;
        }
    }
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}
