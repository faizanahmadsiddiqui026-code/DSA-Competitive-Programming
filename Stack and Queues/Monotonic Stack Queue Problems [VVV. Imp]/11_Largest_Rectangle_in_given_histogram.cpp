// //Brute force
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     vector<int> findPSE(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> pse(n);
//         stack<int> st;

//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }
//             pse[i] = st.empty() ? -1 : st.top();
//             st.push(i);
//         }

//         return pse;
//     }

//     vector<int> findNSE(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> nse(n);
//         stack<int> st;

//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }
//             nse[i] = st.empty() ? n : st.top();
//             st.push(i);
//         }

//         return nse;
//     }

//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();

//         vector<int> pse = findPSE(heights);
//         vector<int> nse = findNSE(heights);

//         int maxArea = 0;

//         for (int i = 0; i < n; i++) {
//             int height = heights[i];
//             int width = nse[i] - pse[i] - 1;
//             int area = height * width;
//             maxArea = max(maxArea, area);
//         }
//         return maxArea;
//     }
// };

// int main() {
//     vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
//     Solution obj;
//     cout << "Largest Rectangle Area: "<< obj.largestRectangleArea(heights) << endl;
//     return 0;
// }




// //Optimal
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//   public:
//     int largestRectangleArea(vector<int> &histo) {
//         stack<int> st; // Stack to store indices of the histogram bars
//         int maxA = 0;  // Variable to keep track of the maximum area
//         int n = histo.size();

//         // Loop through each bar including an imaginary bar at the end
//         for (int i = 0; i <= n; i++) {
//             // While current bar is smaller than the top of the stack or we reached the end
//             while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
//                 int height = histo[st.top()]; // Get the height of the bar at top of the stack
//                 st.pop(); // Remove that bar

//                 int width; 
//                 if (st.empty()) {
//                     width = i; // All bars before were higher
//                 } else {
//                     width = i - st.top() - 1; // Width between current index and index at top of stack
//                 }

//                 // Calculate area and update maximum area
//                 maxA = max(maxA, width * height);
//             }
//             // Push current index into stack
//             st.push(i);
//         }
//         return maxA;
//     }
// };

// int main() {
//     vector<int> histo = {3,2,10,11,5,10,6,3}; // Input histogram
//     Solution obj;
//     cout << "The largest area in the histogram is " << obj.largestRectangleArea(histo) << endl;
//     return 0;
// }





//Optimal(Copy)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        stack<int>st;
        int maxArea=0;
        int n=histo.size();
        for(int i=0;i<n;i++){ 
            while(!st.empty() && histo[st.top()]>histo[i]){  //met with smaller element
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty() ? -1 : st.top();
                maxArea=max(histo[ele]*(nse-pse-1),maxArea);
            }
            st.push(i);  //index based iteration and storing
        }
        while(!st.empty()){
            int ele=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty() ? -1 : st.top();
            maxArea=max(histo[ele]*(nse-pse-1),maxArea);
        }
        return maxArea;
    }
};

int main() {
    vector<int> histo = {3,2,10,11,5,10,6,3}; // Input histogram
    Solution obj;
    cout << "The largest area in the histogram is " << obj.largestRectangleArea(histo) << endl;
    return 0;
}




// //Optimal (Merged)
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& histo) {
//         stack<int> st;
//         int maxArea = 0;
//         int n = histo.size();

//         for (int i = 0; i <= n; i++) {   // merged trick (i = n handles remaining stack)
//             int curr = (i == n ? 0 : histo[i]);

//             while (!st.empty() && histo[st.top()] > curr) {
//                 int ele = st.top();
//                 st.pop();

//                 int nse = i;
//                 int pse = st.empty() ? -1 : st.top();

//                 maxArea = max(histo[ele] * (nse - pse - 1), maxArea);
//             }

//             st.push(i);
//         }

//         return maxArea;
//     }
// };

// int main() {
//     vector<int> histo = {3,2,10,11,5,10,6,3}; // Input histogram
//     Solution obj;
//     cout << "The largest area in the histogram is " 
//          << obj.largestRectangleArea(histo) << endl;
//     return 0;
// }