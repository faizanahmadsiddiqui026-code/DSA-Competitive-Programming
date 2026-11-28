// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){  
//    int l = 3, r = 5;
//    int ans = 0;
//    for(int i=l; i <= r; i++) {
// 		ans ^= i;
// 	}
//     cout<<ans;
//     return 0;
// }

//for 1 to N   put l=1 and r=n


//Optimal
#include<bits/stdc++.h>
using namespace std;

int func1(int n){
  if (n%4==1)   return 1;
  else if(n%4==2)  return n+1;
  else if(n%4==3) return 0;
  else return n;
}

int func(int L,int R){
    return func1(L-1) ^func1(R);
}

int main(){
  int l = 3, r = 5;
  int ans=func(l,r);
  cout<<ans;
  return 0;
}