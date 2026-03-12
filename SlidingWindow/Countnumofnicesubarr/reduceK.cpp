class Solution {
public:
    int countAtMost(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int cnt = 0;

        while (r < nums.size()) {
            if (nums[r] % 2 != 0)
                k--;

            while (k < 0) {
                if (nums[l] % 2 != 0)
                    k++;
                l++;
            }

            cnt += (r - l + 1);
            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};