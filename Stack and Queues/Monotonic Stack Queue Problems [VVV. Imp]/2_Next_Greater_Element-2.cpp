// //Brute force
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={2,10,12,1,11};
//     int n=sizeof(arr)/sizeof(int);
//     int nge[n];

//     for(int i=0;i<n;i++){
//         nge[i]=-1;
//         for(int j=i+1;j<=i+n-1;j++){
//             int index=j%n;
//             if(arr[index]>arr[i]){
//                 nge[i]=arr[index];
//                 break;
//             }
//         }
//     }        
//     for(int i=0;i<n;i++){
//         cout<<nge[i]<<" ";
//     }
//     return 0;
// }




//Optimal
#include <bits/stdc++.h>
using namespace std;

// Solution class to find next greater elements
class Solution {
public:
    // Function to find next greater elements
    vector<int> nextGreater(vector<int>& nums) {
        // Stack to store elements
        stack<int> st;

        // Result array of same size
        int n = nums.size();
        vector<int> res(n);  //creating a nge array

        // Start traversing from the back
        for (int i = 2*n - 1; i >= 0; i--) {

            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the greater element */
            while (!st.empty() && st.top() <= nums[i%n]) {
                st.pop();
            }

            //if (i<n) res[i]=st.empty() ? -1 : st.top();   
                   
                    //OR

            // Store the answer for the second half
            if(i < n) {
                
                /* If the greater element is not 
                found, stack will be empty */
                if(st.empty()) 
                    res[i] = -1;
                    
                // Else store the answer
                else 
                    res[i] = st.top();
            }


            /* Push the current element in the stack 
            maintaining the decreasing order */
            st.push(nums[i%n]);
        }

        // Return the result
        return res;
    }
};

// Main function
int main() {
    vector<int> nums = {2,10,12,1,11};
    Solution sol;
    vector<int> ans = sol.nextGreater(nums);
    
    cout << "The next greater elements are: ";
    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
