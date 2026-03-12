class Solution {
public:
    int countAtMost(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int sum=0, cnt = 0;

    if(k<0) return 0;

        while (r < nums.size()) {
            sum += nums[r] % 2;

            while(sum > k){
                sum = sum -  (nums[l] % 2);
                l++;
            }

            cnt+= r - l + 1;
            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};