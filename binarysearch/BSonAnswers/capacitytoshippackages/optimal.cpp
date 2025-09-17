#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
using namespace std;

int numofdays(vector<int>& a, int cap) {
        int day = 1, load = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] + load > cap) {
                day = day + 1;
                load = a[i];
            } else
                load += a[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int noOfday = numofdays(weights, mid);
            if (noOfday <= days)
                high = mid - 1;

            else
                low = mid + 1;
        }
        return low;
    }
    
int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = shipWithinDays(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
