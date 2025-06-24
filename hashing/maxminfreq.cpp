#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
        m[a[i]]++;

    int max_freq = INT_MIN;
    int min_freq = INT_MAX;

    for (auto it : m) {
        max_freq = max(max_freq, it.second);
        min_freq = min(min_freq, it.second);
    }

    cout << "Max Frequency: " << max_freq << "\nElement(s): ";
    for (auto it : m) {
        if (it.second == max_freq)
            cout << it.first << " ";
    }

    cout << "\nMin Frequency: " << min_freq << "\nElement(s): ";
    for (auto it : m) {
        if (it.second == min_freq)
            cout << it.first << " ";
    }

    return 0;
}
