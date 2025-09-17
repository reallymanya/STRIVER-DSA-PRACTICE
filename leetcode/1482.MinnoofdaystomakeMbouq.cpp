#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;


  bool possible(vector<int>& arr, int day, int m, int k) {
        int n = arr.size();
        int cnt = 0;
        int noofB = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] <= day)
                cnt++;
            else {
                noofB += (cnt / k);
                cnt = 0;
            }
        }
        noofB += (cnt / k);
        return noofB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = 1LL * m * 1LL * k;
        int n = bloomDay.size();
        if (val > n)
            return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
    
int main(){
     vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = minDays(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}