#include <iostream>
#include <algorithm>

using namespace std;

string postfixToprefix(string s){
    
    stack <string> st;
    int n = s.size();
    for(int i = 0 ; i<n;i++){
        char c = s[i];

        if(isalnum(c)){
            st.push(string(1,c));
        }
        else{
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            st.push(c + op1 + op2);
        }
    }
    return st.top();
}

int main() {
    string postfix = "ABC/-AK/L-*";
    cout << "Prefix Expression: " << postfixToprefix(postfix) << endl;
    return 0;
}