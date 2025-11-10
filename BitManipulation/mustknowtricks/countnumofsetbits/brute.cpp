#include <iostream>
using namespace std;

    int countSetBits(int n) {
        int count = 0; 
        while (n > 0) {
            count += (n & 1); 
            n >>= 1;  
        }

        return count;
    }

int main() {
    int n = 29; 

    int result = countSetBits(n);

    cout << "The number of set bits is: " << result << endl;

    return 0;
}