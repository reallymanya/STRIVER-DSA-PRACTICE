#include <iostream>
#include <vector>
using namespace std;

int largestRect(vector<int> &histo)
{
    stack<int> st;
    int maxArea = 0;
    int n = histo.size();

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && histo[st.top()] > histo[i])
        {
            int ele = st.top();
            st.pop();

            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (histo[ele] * (nse - pse - 1)));
        }

        st.push(i);
    }
    while (!st.empty())
    {
        int nse = n;
        int element = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, (histo[element] * (nse - pse - 1)));
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;
    int n = matrix.size();
    int m = matrix[0].size();

    int maxArea = 0;
    vector<vector<int>> prefixSum(n, vector<int>(m));

    for (int j = 0; j < m; j++)
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] == '1')
                sum += 1;

            else
                sum = 0;

            prefixSum[i][j] = sum;
        }
    }
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, largestRect(prefixSum[i]));
    }
    return maxArea;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    int ans =
        maximalRectangle(matrix);

    cout << "The largest rectangle area containing all 1s is: " << ans;
    return 0;
}