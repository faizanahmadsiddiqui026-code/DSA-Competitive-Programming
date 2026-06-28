//Brute force
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>prices={7,1,5,3,6,4};
    int maxProfit = 0;
    for(int i = 0; i < prices.size(); i++){
        for(int j = i + 1; j < prices.size(); j++){
            int profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
        }
    }
    cout<<maxProfit;
    return 0;
}



//Optimal
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={7,1,5,3,6,4};
    int mini=arr[0];
    int profit=0;
    for(int i=1;i<arr.size();i++){
        profit=max(profit,arr[i]-mini);
        mini=min(mini,arr[i]);
    }
    cout<<profit;
    return 0;
}