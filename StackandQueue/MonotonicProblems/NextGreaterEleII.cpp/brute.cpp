#include <iostream>
using namespace std;

vector<int> nextGreaterElements(vector<int> arr)
{

    int n = arr.size();

    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < i + n - 1; j++)
        {

            int ind = j % n;

            if (arr[ind] > arr[i])
            {

                ans[i] = arr[ind];

                break;
            }
        }
    }

    return ans;
}

int main()
{
    int n = 6;
    vector<int> arr = {5, 7, 1, 7, 6, 0};

    vector<int> ans = nextGreaterElements(arr);

    cout << "The next greater elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}