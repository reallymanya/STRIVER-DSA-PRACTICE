#include <iostream>
using namespace std;


int clearithBit(int n,int i) {
    return n & ~(1 << i);
}

int main() {

    int n = 10; // binary: 1010

    int result = clearithBit(n,2);

    cout  << result << endl; // Output: 1010

    return 0;
}