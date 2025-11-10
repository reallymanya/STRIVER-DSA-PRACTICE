#include <iostream>
using namespace std;


int toggleithBit(int n,int i) {
    return n ^ (1 << i);
}

int main() {

    int n = 10; // binary: 1010

    int result = toggleithBit(n,2);

    cout  << result << endl; 

    return 0;
}