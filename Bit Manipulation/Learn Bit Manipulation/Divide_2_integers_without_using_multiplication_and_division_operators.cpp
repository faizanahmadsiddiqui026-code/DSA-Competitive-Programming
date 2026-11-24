// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    long long dividend=22;
//    long long divisor=3;
//    long long sum=0;
//    long long cnt=0;
//    if(dividend == divisor) return 1;
//    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
//    if(divisor == 1) return dividend;
//    while((sum+divisor)<=dividend){
//     cnt++;
//     sum+=divisor;
//    }
//    cout<<cnt;
//    return 0;
// }

// but give tle error for big numbers

//optimal
#include<bits/stdc++.h>
using namespace std;
int main(){
    int  dividend=22;
    int divisor=3;
    if (divisor == 0) {
        cout << "Error: Division by zero";
        return 0;
    }

    if(dividend==divisor) {
        cout<<1;
        return 0;
    }

    if (dividend == INT_MIN && divisor == -1) {
      cout << INT_MAX;
      return 0;
    }

    bool sign=true;
    //2 cases when sign gets negative
    if(dividend>=0 && divisor<0)  sign=false;
    else if(dividend<=0 && divisor>0) sign=false;

    long long n =llabs((long long)dividend);
    long long d =llabs((long long)divisor);
    long long quotient=0;
    while(n>=d){   //Keep subtracting divisor until dividend < divisor
        int cnt=0;
        while(cnt <62 && n>=(d<<(cnt+1))){ //d * (2^(cnt+1))
            cnt+=1;
        }
        quotient+=1LL<<cnt;  //(1 << cnt) represents 2^cnt
        n-=(d<<cnt);
    }
    if(quotient==(1LL<<31)&& sign){  //these checking can be remove if we don't remove the condition which is from line 38 to 40
        cout<<INT_MAX;
        return 0;
    }
    if(quotient==(1LL<<31)&& !sign){ //these checking can be remove if we don't remove the condition which is from line 38 to 40
        cout<<INT_MIN;
        return 0;
    }
    cout<<sign ? quotient : -quotient;
    return 0;
}