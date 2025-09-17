#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int findMax(vector<int>& v) {
        int maxi = INT_MIN;
        for (int x : v) {
            maxi = max(maxi, x);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int>& v, int hourly) {
        long long totalH = 0;
        for (int x : v) {
            totalH += (x + hourly - 1) / hourly; // integer ceil
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minEatingSpeed(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}

