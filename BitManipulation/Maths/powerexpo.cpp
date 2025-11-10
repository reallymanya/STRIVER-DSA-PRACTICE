#include <iostream>
using namespace std;

 double myPow(double x, int n) {
        double ans = 1;
        long long power = n;

        if (power < 0) {
            x = 1.0 / x;
            power = -power;
        }

        while(power > 0){
            if( power % 2 == 1){
                ans = ans * x;
                power = power -1;
            }
            else{
               power = power/2;
                x = x*x;
            }
        }
        return ans;
    }

int main() {
    double x;
    int n;
    
    cout << myPow(x, n) << endl;
    return 0;
}