class Solution {
public:
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
};