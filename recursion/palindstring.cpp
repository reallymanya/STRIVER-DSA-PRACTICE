#include <iostream>
using namespace std;

//recursive
bool palinndrome(int i, string &s){
    if (i >= s.length() / 2){
        return true;
    }
    if(s[i] != s[s.length() - i -1]){
        return false;
    }
    return palinndrome(i + 1, s);
}
//iterative

int main(){
string s = "madam";
cout << palinndrome(0,s);
}