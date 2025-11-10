#include <iostream>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ nums[i];
    }
    return xorr;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 4, 3, 2};
    cout << singleNumber(a);
}