#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;


long long sumbyD(vector<int> &arr, int div){
    int n = arr.size();
    long long sum = 0;
    for(int i = 0; i<n;i++){
        sum += ceil((double)arr[i]/(double)div);
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n > threshold) return -1;
        int low = 1, high = *max_element(nums.begin(),nums.end());

        while(low <= high){
            int mid = (low + high)/2;
            if(sumbyD(nums,mid) <= threshold)
            high = mid -1;
            else
            low = mid + 1;
        }
        return low;
    }
    
int main()
{
    vector<int> arr = {1, 2, 5,9};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}