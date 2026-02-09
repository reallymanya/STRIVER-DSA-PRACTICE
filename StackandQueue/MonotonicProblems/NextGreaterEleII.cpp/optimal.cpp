#include <iostream>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);

    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {

        int ind = i % n;
        int currEle = arr[ind];

        while (!st.empty() && st.top() <= currEle)
        {
            st.pop();
        }

        if (i < n)
        {
            ans[i] = st.empty() ? -1 : st.top();
        }

        st.push(currEle);
    }

    return ans;
}

int main()
{
    int n = 6;
    vector<int> arr = {5, 7, 1, 7, 6, 0};

    vector<int> ans = nextGreaterElement(arr);

    cout << "The next greater elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}