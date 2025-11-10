#include <iostream>
using namespace std;


int removeithBit(int n) {
    return n & (n-1);
}

int main() {

    int n = 10; // binary: 1010

    int result = removeithBit(n);

    cout  << result << endl; 

    return 0;
}