#include <iostream>
using namespace std;
 
 
 bool isOdd(int n) {
        return (n % 2 != 0); 
    }


int main() {
    int num = 7;

    if (isOdd(num)) {
        cout << num << " is odd." << endl;
    } else {
        cout << num << " is not odd." << endl;
    }

    return 0;
}