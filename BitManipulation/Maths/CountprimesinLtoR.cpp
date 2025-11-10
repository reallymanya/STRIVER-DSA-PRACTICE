#include <iostream>
using namespace std;

vector<int> getSeive(int n){
     vector<int> isPrime(n+1, 1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    return isPrime;
  }
    int countPrimes(int L, int R) {
        // code here
        int n  = 1e6;
        vector<int> prime = getSeive(n);
        
        int count = 0;
        
        for(int i = 2; i<=n; i++){
            count += prime[i];
            prime[i] = count;
        }
        
        if(L < 2) L = 2;
        
        int ans = prime[R] - prime[L - 1];
        return ans;
        
    }