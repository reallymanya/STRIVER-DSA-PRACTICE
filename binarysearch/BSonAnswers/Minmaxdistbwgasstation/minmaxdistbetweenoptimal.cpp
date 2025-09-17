#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <iomanip>
using namespace std;


int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int gap = arr[i] - arr[i - 1];
        int numberInBetween = ceil((long double)gap / dist) - 1;
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    long double low = 0, high = 0;

   
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    
    long double diff = 1e-6; // precision
    while (high - low > diff) {
        long double mid = (low + high) / 2.0;
        int cnt = numberOfGasStationsRequired(mid, arr);

        if (cnt > k) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return high; 
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

   // cout << fixed << setprecision(6);
    cout << "Minimum possible maximum distance: "
         << minimiseMaxDistance(arr, k) << endl;

    return 0;
}
