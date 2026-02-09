#include <iostream>
#include <stack>
using namespace std;

int sumSubarrayMins(vector<int> &arr)
{

    int n = arr.size();

    int mod = 1e9 + 7;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {

        int mini = arr[i];

        for (int j = i; j < n; j++)
        {

            mini = min(mini, arr[j]);

            sum = (sum + mini) % mod;
        }
    }

    return sum;
}

int main()
{
    vector<int> arr = {3, 1, 2, 5};

    int ans = sumSubarrayMins(arr);

    cout << "The sum of minimum value in each subarray is: " << ans;

    return 0;
}