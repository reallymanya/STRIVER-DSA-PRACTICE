#include <iostream>
using namespace std;


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r =0;
        int n = fruits.size();
        int maxLen = 0;
        unordered_map<int,int> mpp;

        while(r < n){
            mpp[fruits[r]]++;
            
            if(mpp.size()>2){
                mpp[fruits[l]]--;

                if(mpp[fruits[l]] == 0)
                mpp.erase(fruits[l]);

                l++;
            }

            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> fruits = {1,2,1,2,3};
    cout << sol.totalFruit(fruits) << endl;
    return 0;
}

