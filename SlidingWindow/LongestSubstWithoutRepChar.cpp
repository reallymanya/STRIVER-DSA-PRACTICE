#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int hash[256];

        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }

        int l = 0, r = 0, maxlen = 0;

        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            hash[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};

int main() {
    string s = "cadbzabcd"; 
    
    Solution sol;

    int result = sol.lengthOfLongestSubstring(s);

    // Output the maximum length
    cout << "The maximum length is:\n";
    cout << result << endl;

    return 0;
}
