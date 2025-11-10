#include <vector>
#include <iostream>
using namespace std;

int func1(int n){
    if(n % 4 == 1) return 1;
   else if(n%4 == 2) return n + 1;
    else if(n%4 == 3)return 0;
    else return n;
}

int findXOR(int L, int R){
    // Write your code here.
    return func1(L-1) ^ func1(R);
}

int main() {
    int l = 3, r = 5;

    int ans = findXOR(l, r);
    
    cout << "The XOR of numbers from " << l << " to " << r << " is: " << ans;
    
    return 0;
}