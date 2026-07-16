// //Brute force(Linear Search)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n=25;
//     int ans=1;
//     for(int i=0;i<=n;i++){
//         if(i*i<=n) ans=i;  //if (i <= n / i) better for overflow
//         else break;
//     }
//     cout<<ans;
//     return 0;
// }


//Optimal
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=36;
    int ans=1;
    int low=1 ,high=n;
    while(low<=high){
        long long mid=(low+high)/2;
        if(mid*mid<=n){  //if(mid <= n / mid)
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans;     //cout<<high;
    return 0;
}