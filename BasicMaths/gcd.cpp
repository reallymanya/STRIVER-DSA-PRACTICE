#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int findgcd(int n, int n2){
    for(int i = min(n,n2); i>0; i--){
        if(n%i == 0 && n2%i == 0){
            return i;
        }
    }
    return 1;
}

int main() {
    int n1 = 20, n2 = 15;
    
   
    int gcd = findgcd(n1, n2);

    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

    return 0;
}

//Time Complexity: O(min(N1, N2))
//Space Complexity: O(1)