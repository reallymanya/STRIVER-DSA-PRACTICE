#include <iostream>
#include <algorithm>

using namespace std;

int prec(char s)
{
    if (s == '^')
        return 3;
    else if (s == '/' || s == '*')
        return 2;
    else if (s == '+' || s == '-')
        return 1;
    else
        return -1;
}

void infixtoPostfix(string s)
{

    stack<char> st;
    string result;

    int i = 0;
    while (i < s.length())
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            result += s[i];

        else if (s[i] == '(')
            st.push('(');

        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
         i++;
    }
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        cout << "Prefix expression: " << result << endl;
    }


int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
 infixtoPostfix(exp);

  return 0;
}