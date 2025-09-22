#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mpp;
    mpp.reserve(n);

    for (int i = 0; i < n; i++) {
        mpp[nums[i]]++;
    }

    int maxfreq = 0;
    int count = 0;

    for (auto it : mpp) {
        if (it.second > maxfreq) {
            maxfreq = it.second;
            count = it.second;
        } else if (it.second == maxfreq) {
            count += it.second;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 1, 1};
    cout << maxFrequencyElements(nums) << endl;
    return 0;
}