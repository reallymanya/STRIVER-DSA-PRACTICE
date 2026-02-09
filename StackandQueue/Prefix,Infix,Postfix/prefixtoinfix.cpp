#include <iostream>
#include <algorithm>

using namespace std;

string prefixToInfix(string s)
{

    stack<string> st;
    int n = s.size();
    int i = n - 1;
    while (i >= 0)
    {
        char c = s[i];

        if (isalnum(c))
        {
            st.push(string(1, c)); // creates a string of length 1 containing character c
        }
        else
        {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            st.push("(" + top1 + c + top2 + ")");
        }
        i--;
    }

    return st.top();
}

int main()
{
    string prefix = "*+PQ-MN";
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
    return 0;
}