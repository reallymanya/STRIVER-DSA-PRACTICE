
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> maxLengthSubarray(int arr[], int n, int k)
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
        if (r-l+1>maxlen)
        {
            maxlen = r - l + 1;
            start = l;
         
        }
           r = r + 1;
    }

    vector<int> result;
    for (int i = start; i < start + maxlen; i++)
    {
        result.push_back(arr[i]);
    }

    return result;
}

int main()
{
    int arr[] = {2, 5, 1, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 14;

    vector<int> result = maxLengthSubarray(arr, n, k);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
} explain tc