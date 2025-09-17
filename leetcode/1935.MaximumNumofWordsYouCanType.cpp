#include <iostream>     
#include <string>        
#include <unordered_set> 
using namespace std;

int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> brokenKeys(brokenLetters.begin(),
                                       brokenLetters.end());

        int count = 0;
        bool canType = true;

        for (int i = 0; i <= text.size(); i++) {

            if (i == text.size() || text[i] == ' ') {
                if (canType)
                    count++;
                canType = true;
            }

            else if (brokenKeys.count(text[i])) {
                canType = false;
            }
        }
        return count;
    }

int main() {
    string text = "hello world";
    string brokenLetters = "ad";

    int result = canBeTypedWords(text, brokenLetters);
    cout << "Number of typable words: " << result << endl;

    return 0;
}