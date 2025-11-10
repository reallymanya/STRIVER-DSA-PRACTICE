#include <iostream>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int bitindex = 0; bitindex < 32; bitindex++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & (1 << bitindex))
                cnt++;
        }
        if (cnt % 3 == 1)
            ans = ans | (1 << bitindex);
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 2, 3, 3, 4, 4, 3, 4, 2};
    cout << singleNumber(a);
}

//bucket method
// Once XOR num is checking if there is already something in ones, 
//then we AND with NOT twos to check it’s not in twos.
// In twos, XOR num checks if it’s already present in twos, 
//and we AND with NOT ones to ensure it’s not in ones.
// When it’s the third time, both ones and twos become 0.