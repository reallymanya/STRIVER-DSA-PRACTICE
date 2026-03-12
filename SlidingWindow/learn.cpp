
#include <iostream>
#include <algorithm>
using namespace std;

int maxLengthSubarray(int arr[], int n, int k)
{
    int l = 0, r = 0, sum = 0, maxlen = 0, start = 0;

    while (r < n)
    {
        sum = sum + arr[r];

      while (sum > k)
        {
            sum = sum - arr[l];
            l++;
        }
       
            maxlen = max(maxlen,r - l + 1);
        
        r++;
    }

    return maxlen;
}

int main()
{
    int arr[] = {2, 5, 1, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 14;

    int ans = maxLengthSubarray(arr, n, k);
    cout << ans;
    cout << endl;

    return 0;
}