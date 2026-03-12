#include <iostream>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int l = 0, r = 0, zeroes = 0, maxlen = 0;

        while (r < nums.size())
        {
            if (nums[r] == 0)
                zeroes++;

            if (zeroes > 1)
            {
                if (nums[l] == 0)
                    zeroes--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 0, 1, 1, 0};

    cout << sol.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}