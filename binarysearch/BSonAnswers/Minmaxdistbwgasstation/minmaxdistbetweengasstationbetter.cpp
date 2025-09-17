#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <iomanip>
using namespace std;

double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<double, int>> pq;

   
    for (int i = 0; i < n - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }

 
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        auto tp = pq.top();
        pq.pop();
        int secondInd = tp.second;

        howMany[secondInd]++;

        double inidiff = arr[secondInd + 1] - arr[secondInd];
        double newSeclen = inidiff / (double)(howMany[secondInd] + 1);

        pq.push({newSeclen, secondInd});
    }

    return pq.top().first;
}

int main() {
    vector<int> arr = {1, 13, 17, 23};
    int k = 5;

    double ans = minimiseMaxDistance(arr, k);
    cout << fixed << setprecision(2);
    cout << "Minimum possible maximum distance = " << ans << endl;

    return 0;
}
