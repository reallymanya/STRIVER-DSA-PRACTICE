#include <bits/stdc++.h>
using namespace std;

// Function to set the rightmost unset bit (0 -> 1)
int setRightmostUnsetBit(int n) {
    return n | (n + 1);
}

int main() {
    int n = 10; // binary: 1010

    int result = setRightmostUnsetBit(n);

    cout << "Number after setting rightmost unset bit: " << result << endl; // Output: 11

    return 0;
}