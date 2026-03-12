#include <iostream>
using namespace std;

int longestKSubstr(string &s, int k)
{

    // edge case
    //  if(k == 0 || s.empty()) return 0;

    int l = 0, r = 0;

    int maxlen = -1;

    unordered_map<char, int> mpp;

    while (r < s.size())
    {
        mpp[s[r]]++;

        while (mpp.size() > k)
        {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0)
                mpp.erase(s[l]);
            l = l + 1;
        }

        if (mpp.size() == k)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

int main()
{

    string s = "eceba";
    int k = 2;
    cout << longestKSubstr(s, k) << endl;
    return 0;
}