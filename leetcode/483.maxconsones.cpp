#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int cnt = 0;
        for(int i = 0; i<n;i++){
            if(nums[i] == 1){
                cnt++;
                maxi = max(maxi,cnt);
            }
            else{
                cnt = 0;
            }
        }
        return maxi;
        
    }

    int main(){
        vector<int> nums = {1,1,0,1,1,1};
        cout << "Maximum consecutive ones: " << findMaxConsecutiveOnes(nums) << endl;
        return 0;
    }