#include <iostream>
using namespace std;

long long cntodd = (n + 1) / 2;
long long cnteven = n / 2;
long long cntodd1 = (m + 1) / 2;
long long cnteven1 = m / 2;
return cntodd * cnteven1 + cntodd1 * cnteven;


int main() {
    long long n, m;
    cout << "Enter two numbers n and m: ";
    cin >> n >> m;

    long long result = countPairs(n, m);
    cout << "Result: " << result << endl;

    return 0;
}