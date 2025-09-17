#include <bits/stdc++.h>
using namespace std;


long long func(int mid, int n, int m) {
    long long ans = 1;
    long long base = mid;

    while (n > 0) {
        if (n % 2 == 1) {  // odd exponent
            ans = ans * base;
            if (ans > m) return m + 1; // too large, stop early
            n--;
        } else {             // even exponent
            base = base * base;
            if (base > m) base = m + 1; // don’t return, just cap it
            n /= 2;
        }
    }
    return ans;
}

int NthRoot(int n, int m) {
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long val = func(mid, n, m);

        if (val == m) return mid;          // perfect nth root
        else if (val < m) low = mid + 1;   // try bigger
        else high = mid - 1;               // too large
    }
    return -1; // not a perfect nth root
}

int main() {
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;

    int root = NthRoot(n, m);
    if (root == -1) {
        cout << -1 ;
    } else {
        cout << "The " << n << "th root of " << m << " is " << root << "\n";
    }
    return 0;
}
