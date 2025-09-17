#include <iostream>
using namespace std;

 int mySqrt(int x) {
       int low = 1, high = x;

       while(low <= high){
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;

        if(val <= (long long)x)
        low = mid + 1;

        else
        high = mid - 1;
       }
       return high;
    }
    
int main()
{
    int n = 28;
    int ans = mySqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}