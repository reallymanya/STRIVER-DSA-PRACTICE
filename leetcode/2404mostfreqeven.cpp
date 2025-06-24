#include <iostream>
#include <map>
using namespace std;

    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mpp;
        for(int i = 0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        int maxfreq = 0;
        int maxEle = -1;
        for(auto it = mpp.begin(); it != mpp.end(); ++it){

            int count = it->second;
            int element = it->first;

            if(element % 2 == 0){
            if(count > maxfreq){
                maxEle = element;
                maxfreq = count;
            }
            }
        }
        return maxEle;
    }

    int main() {
        vector<int> nums = {1, 2, 2, 3, 4, 4, 4};
        int result = mostFrequentEven(nums);
        cout << "Most Frequent Even Element: " << result << endl;
        return 0;
    }
