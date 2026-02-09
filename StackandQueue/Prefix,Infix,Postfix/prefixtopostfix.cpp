#include <iostream>
#include <algorithm>

using namespace std;

string prefixTopostfix(string s){
    
    stack <string> st;
    int n = s.size();
    for(int i = n-1 ; i>=0;i--){
        char c = s[i];

        if(isalnum(c)){
            st.push(string(1,c));
        }
        else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            st.push(t1 + t2 + c);
        }
    }
    return st.top();
}

int main() {
    string postfix = "/-AB*+DEF";
    cout << "Prefix Expression: " << prefixTopostfix(postfix) << endl;
    return 0;
}