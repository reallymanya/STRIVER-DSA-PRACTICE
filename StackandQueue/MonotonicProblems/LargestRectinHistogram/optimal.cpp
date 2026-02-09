#include <iostream>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            int element = st.top();
            st.pop();

            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (heights[element] * (nse - pse - 1)));
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int nse = n;
        int element = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, (heights[element] * (nse - pse - 1)));
    }
    return maxArea;
}

int main()
{
    vector<int> histo = {2, 1, 5, 6, 2, 3, 1};

    cout << "The largest area in the histogram is " << largestRectangleArea(histo) << endl;
    return 0;
}