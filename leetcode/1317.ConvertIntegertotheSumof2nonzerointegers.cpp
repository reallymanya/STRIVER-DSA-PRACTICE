
#include <iostream>
#include <vector>
using namespace std;

bool hasZero(int n) {
        if (n == 0)
            return true;
        while (n > 0) {
            if (n % 10 == 0)
                return true;
            n = n / 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (!(hasZero(i)) && !(hasZero(n - i))) {
                ans.push_back(i);
                ans.push_back(n - i);
                break;
            }
        }

        return ans;
    }

nt main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> result = getNoZeroIntegers(n);
    cout << "Two integers without zero that sum to " << n << " are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}