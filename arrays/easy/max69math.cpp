#include <iostream>
using namespace std;

int maximum69Number(int num) {
    int divisor = 1000; 
    while (divisor > 0) {
        int digit = (num / divisor) % 10;
        if (digit == 6) {
            return num + 3 * divisor;
        }
        divisor /= 10;
    }
    return num;
}

int main(){
    int n = 9669;
    cout << maximum69Number(n);
}