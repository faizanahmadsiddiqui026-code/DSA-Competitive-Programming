// //Brute force
// #include <iostream>
// using namespace std;

// int main() {
//     int start = 10, goal = 7;
//     int xor_val = start ^ goal;
//     int count = 0;

//     for (int i = 0; i < 32; i++) {
//         if (xor_val & (1 << i)) {
//             count++;
//         }
//     }

//     cout << count << endl;
//     return 0;
// }





//Little better(not unnecessary iteration)
#include <iostream>
using namespace std;

int minBitFlips(int start, int goal) {
    int xor_val = start ^ goal;  // XOR to find differing bits
    int count = 0;

    // Only loop until xor_val becomes 0
    for (int i = 0; xor_val != 0; i++) {
        if (xor_val & 1) {  // check the least significant bit
            count++;
        }
        xor_val >>= 1;  // shift right to check the next bit
    }

    return count;
}

int main() {
    int start = 10, goal = 7;
    cout << minBitFlips(start, goal) << endl; // Output: 3

    start = 3; goal = 4;
    cout << minBitFlips(start, goal) << endl; // Output: 3
}