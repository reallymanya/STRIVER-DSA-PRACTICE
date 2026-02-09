#include <iostream>
#include <stack>
using namespace std;

string removeKdigits(string num, int k)
{

    stack<char> st;

    for (int i = 0; i < num.size(); i++)
    {
        char digit = num[i];

        while (!st.empty() && k > 0 && st.top() - '0' > digit - '0')
        {
            st.pop();
            k--;
        }

        st.push(digit);
    }

    while (!st.empty() && k > 0)
    {
        st.pop();
        k--;
    }

    if (st.empty())
        return "0";

    string res = "";
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    while (res.size() > 0 &&
           res.back() == '0')
    {

        res.pop_back();
    }

    reverse(res.begin(), res.end());

    if (res.empty())
        return "0";
    return res;
}

int main() {
    string nums = "541892";
    int k = 2;
    
    
    string ans = removeKdigits(nums, k);
    
    cout << "The smallest possible integer after removing k digits is: " << ans;
    
    return 0;
}
