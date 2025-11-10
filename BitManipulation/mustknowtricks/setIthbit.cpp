#include <iostream>
using namespace std;


int setithBit(int n,int i) {
    return n | (1 << i);
}

int main() {

    int n = 10; // binary: 1010

    int result = setithBit(n,2);

    cout  << result << endl; // Output: 1110

    return 0;
}