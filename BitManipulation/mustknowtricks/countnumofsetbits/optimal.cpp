#include <iostream>
using namespace std;

int countSetBits(int n) {
        int count = 0; 

        while (n) {
            n &= (n - 1); 
            count++;  
        }

        return count;
    }

int main() {
    int n = 29;  

    Solution sol;
    int result = sol.countSetBits(n);

    cout << "The number of set bits is: " << result << endl;

    return 0;
}
