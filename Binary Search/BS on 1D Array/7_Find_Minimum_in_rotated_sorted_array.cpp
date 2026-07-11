//For unique element
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={7,8,1,2,3,4,5,6};
    int low=0, high=arr.size()-1, ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){     //
            ans=min(ans,arr[low]);    // for optimization,if already sorted
            break;                   //
        }                            //
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else{
            high=mid-1;
            ans=min(ans,arr[mid]);
        }
    }
    cout<<ans;
    return 0; 

}

//For duplicate elements
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {2,2,2,0,1,2};  // try duplicates also
    int low = 0, high = arr.size()-1, ans = INT_MAX;

    while(low <= high){
        int mid = (low + high) / 2;

        // If duplicates block decision
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            ans = min(ans, arr[mid]);
            low++;
            high--;
            continue;
        }

        // If already sorted
        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }

        // Left part sorted
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        //right part sorted
        else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    cout << ans;
    return 0;
}