#include <bits/stdc++.h>   // includes all standard libraries
using namespace std;

vector<int> findAllPeakElements(vector<int> &arr) {
    int n = arr.size();
    vector<int> peaks;

    for (int i = 0; i < n; i++) {
        if ((i == 0 || arr[i - 1] < arr[i]) &&
            (i == n - 1 || arr[i] > arr[i + 1])) {
            peaks.push_back(i); 
        }
    }
    return peaks;  // return all peak indices
}

int main() {
    vector<int> arr = {1, 3, 2, 4, 1};   
    vector<int> peaks = findAllPeakElements(arr);

    cout << "Peak indices: ";
    for (int idx : peaks) {
        cout << idx << " ";
    }
    cout << endl;

    cout << "Peak values: ";
    for (int idx : peaks) {
        cout << arr[idx] << " ";
    }
    cout << endl;

    return 0;
}
