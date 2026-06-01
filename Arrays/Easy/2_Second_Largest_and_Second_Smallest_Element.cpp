// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// void getElements(int arr[], int n){
//     if(n == 0 || n == 1){
//         cout << -1 << " " << -1 << endl;
//         return;
//     }  

//     sort(arr, arr + n);
//     int smallest = arr[0]; 
//     int largest = arr[n - 1]; 

//     int secondLargest=-1;
//     for(int i=n-2;i>=0;i--){
//         if(arr[i]!=largest){
//             secondLargest=arr[i];
//             break;
//         }
//     }

//     int secondSmallest=-1;
//     for(int i=1;i<n;i++){
//         if(arr[i]!=smallest){
//             secondSmallest=arr[i];
//             break;
//         }
//     }
//     cout << "Second smallest is " << secondSmallest << endl;
//     cout << "Second largest is " << secondLargest << endl;
// }

// int main(){
//     int arr[] = {1, 2, 4, 6, 7, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     getElements(arr, n);
//     return 0;
// }



// //Better
// #include<bits/stdc++.h>
// using namespace std;
// void getElements(int arr[], int n){
//     if(n == 0 || n == 1){
//         cout << -1 << " " << -1 << endl;
//         return;
//     }  

//     int smallest = arr[0];
//     for(int i=1;i<n;i++){
//         if(arr[i]<smallest) smallest=arr[i];
//     }

//     int secondSmallest=INT_MAX;
//     for(int i=0;i<n;i++){
//         if(arr[i]<secondSmallest && arr[i]!=smallest){
//             secondSmallest=arr[i];
//         }
//     }

//     int largest=arr[0];
//     for(int i=1;i<n;i++){
//         if(arr[i]>largest)  largest=arr[i];
//     }

//     int secondLargest=INT_MIN;
//     for(int i=0;i<n;i++){
//         if(arr[i]>secondLargest &&arr[i]!=largest){
//             secondLargest=arr[i];
//         }
//     }

//     if(secondSmallest == INT_MAX) secondSmallest = -1;

//     if(secondLargest == INT_MIN) secondLargest = -1;
    
//     cout << "Second smallest is " << secondSmallest << endl;
//     cout << "Second largest is " << secondLargest << endl;
// }

// int main(){
//     int arr[] = {1, 2, 4, 6, 7, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     getElements(arr, n);
//     return 0;
// }





//Optimal
#include<bits/stdc++.h>
using namespace std;
int secondLargest(vector<int>&a,int n){
    int largest=a[0];
    int slargest=INT_MIN;
    for(int i=1;i<n;i++){
        if(a[i]>largest){
            slargest=largest;
            largest=a[i];
        }
        else if(a[i]<largest && a[i]>slargest){
            slargest=a[i];
        }
    }

    if(slargest == INT_MIN) return -1;

    return slargest;
}
int secondSmallest(vector<int>&a,int n){
    int smallest=a[0];
    int ssmallest=INT_MAX;
    for(int i=1;i<n;i++){
        if(a[i]<smallest){
            ssmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]!=smallest && a[i]<ssmallest){
            ssmallest=a[i];
        }
    }

    if(ssmallest == INT_MAX) return -1;

    return ssmallest;
}

vector<int>getElements(vector<int>&a,int n){
    int slargest=secondLargest(a,n);
    int ssmallest=secondSmallest(a,n);
    return {slargest,ssmallest};
}

int main(){
    vector<int>arr = {1, 2, 4, 6, 7, 5};
    int n = arr.size();
    vector<int> ans = getElements(arr, n);
    cout << "Second Largest: " << ans[0] << endl;
    cout << "Second Smallest: " << ans[1] << endl;
    return 0;
}