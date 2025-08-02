#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxSum(vector<int>& nums) {
           int maxNumForDigit[10] = {0};
        int ans = -1;
        for(auto num : nums){
            int maxD = 0;
            int temp = num;
            while(temp){
                maxD = max(maxD, temp % 10);
                temp /= 10;
            }
             if(maxNumForDigit[maxD])
                ans = max(ans, maxNumForDigit[maxD] + num);

                if(num > maxNumForDigit[maxD])
                maxNumForDigit[maxD] = num;
        }
        return ans;
    }


int main(){
    vector<int> nums = {2536,1613,3366,162};
    cout << maxSum(nums);
}