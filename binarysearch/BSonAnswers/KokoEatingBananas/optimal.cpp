#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

//find the maximum:
int maxele(vector<int> &a){
    int n = a.size();
    int maxi = INT_MIN;
    for(int i = 0; i<n;i++){
       maxi = max(maxi,a[i]);
    }
    return maxi;
}

 //find total hours:
long long totalHours(vector<int> &a, int hourly){
    long long total = 0;
    for(int i = 0; i<a.size();i++){
        total += ceil((double)a[i] / (double)hourly);
       
    }
    return total;
}

int minimumRateToEatBananas(vector<int> v, int h) {

    int low = 1, high = maxele(v);

    while(low <= high){
        int mid = low + (high - low)/2;
        long long totalH = totalHours(v,mid);
        if(totalH <= h)
        high = mid - 1;
        else
        low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}