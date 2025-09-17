#include <iostream>
#include <vector>        
#include <algorithm>       // for max_element
#include <numeric>         // for accumulate
using namespace std;

int countPartitions(vector<int> & a, int maxSum){
    int n = a.size();
    int partitions = 1;
    long long subarrsum = 0;
    
    for(int i = 0; i<n;i++){
        if(subarrsum + a[i] <= maxSum)
        subarrsum += a[i];
        
        else{
            partitions++;
            subarrsum = a[i];
        }
        
    }
    return partitions;
}


    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
       
        while (low <= high) {
            int mid = (low + high) / 2;
            int partitions = countPartitions(nums, mid);
            if (partitions > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
    
int main(){
     vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = splitArray(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}