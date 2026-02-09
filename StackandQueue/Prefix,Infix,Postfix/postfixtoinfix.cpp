#include <iostream>
#include <algorithm>

using namespace std;

string postfixToInfix(string s){
    int i = 0;
    stack <string> st;
    int n = s.size();
    while( i < n){
        char c = s[i];

        if(isalnum(c)){
            st.push(string(1,c)); //creates a string of length 1 containing character c
        }
        else{
            string top1 = st.top(); st.pop();
            string top2 = st.top(); st.pop();
            st.push("(" + top2 + c + top1 + ")");
        }    
        i++;
    }

    return st.top();
}

int main() {
    string postfix = "AB*C+";
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}