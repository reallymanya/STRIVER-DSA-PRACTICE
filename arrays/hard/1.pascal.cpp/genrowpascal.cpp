#include <iostream>
#include <vector>
using namespace std;

//tc = O(n)
//sc = O(1)
/* BRUTE IS using ncr for each row which will reuslt in o(N*R)*/

void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; 

    
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}