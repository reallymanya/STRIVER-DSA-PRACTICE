#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    string s;
    cin >> s;
  // transform(s.begin(), s.end(), s.begin(), ::tolower); to lowercase 

    //precompute
    int hash[256] = {0};
    for(int i = 0; i<s.size();i++){
        hash[s[i]] += 1; //autoconverts char to ASCII value

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;

        //fetch
        cout << hash[c] << endl;
    }
}