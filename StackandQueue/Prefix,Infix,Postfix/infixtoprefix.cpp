#include <iostream>
#include <algorithm>

using namespace std;

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) {
    if (C == '-' || C == '+')  
        return 1;
    else if (C == '*' || C == '/')  
        return 2;
    else if (C == '^')  
        return 3;
    return 0;
}

string infixToPostfix(string s){
    s = '(' + s + ')';  // Add parentheses to handle edge cases
    int l = s.size();
    stack<char> st;
    string result;  

     int i = 0;
    while (i < s.length())
    {
        if (isalpha(s[i]) || isdigit(s[i]))
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
            if(isOperator(st.top())){
                if(s[i] == '^'){
                    while(getPriority(s[i]) <= getPriority(st.top())){
                        result += st.top();
                        st.pop();
                    }
                }else{
                    while (getPriority(s[i]) < getPriority(st.top())) {
                        result += st.top();
                        st.pop();
                    }
                }
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

        return result;
}

string infixToPrefix(string s){
    int l = s.size();

    reverse(s.begin(), s.end());

    for(int i = 0; i<l;i++){
        if(s[i] == '('){
            s[i] = ')';
            i++;
        }
        else if(s[i] == ')'){
            s[i] = '(';
            i++;
        }
    }

    string prefix = infixToPostfix(s);

    reverse(prefix.begin(),prefix.end());

    return prefix;
}

int main() {
    string s = "(p+q)*(c-d)";  
    cout << "Infix expression: " << s << endl;
    cout << "Prefix Expression: " << infixToPrefix(s) << endl;  
    return 0;
}