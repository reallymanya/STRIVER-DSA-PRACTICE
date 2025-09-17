#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int maxFreqSum(string s) {

        int maxVowel = 0, maxConsonant = 0;
        unordered_map<char,int> mpp;

        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            mpp[c]++;
            maxVowel = max(maxVowel, mpp[c]);
            }
            else{
                mpp[c]++;
                maxConsonant = max(maxConsonant, mpp[c]);

            }
        }
        return maxVowel + maxConsonant;
    }


int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = maxFreqSum(s);
    cout << "Max frequency sum = " << result << endl;

    return 0;
}