#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int totalElements(vector<int> &arr) {
                // code here
                int maxlen = 0;
                int lastElem = -1, seclastElem = -1;
                int currCnt = 0, lastElemStreak = 0;
                
                
                for(int i : arr){
                        if ( i == lastElem || i == seclastElem){
                                currCnt++;
                        }
                        else{
                                currCnt = lastElemStreak + 1;
                        }
                
                
                if(i == lastElem)
                lastElemStreak++;
                
                else{
                        lastElemStreak = 1;
                        seclastElem = lastElem;
                        lastElem = i;
                }
                
                maxlen = max(maxlen,currCnt);
                
                }
                return maxlen;
        }
};

int main() {
        Solution sol;
        vector<int> arr = {1, 2, 1, 2, 1, 2, 3};
        cout << "Length of longest subarray with at most 2 distinct elements: " 
                 << sol.totalElements(arr) << endl;
        return 0;
}