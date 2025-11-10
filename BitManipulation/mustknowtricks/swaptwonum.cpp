
#include <iostream>
using namespace std;

void swapnum(int &a, int &b) {  
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    int a = 5, b = 10;
    
    cout << "Before swapping:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    swapnum(a, b);
    
    cout << "After swapping:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    return 0;
}
