// dutch national flag algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0;
        int high = n-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }

    int main(){
        vector<int> a = {1,1,2,0,0,0,0,1,1,2,2};
        sortColors(a);
        for(int i = 0; i<a.size();i++){
            cout << a[i]<<" ";
        }
    }