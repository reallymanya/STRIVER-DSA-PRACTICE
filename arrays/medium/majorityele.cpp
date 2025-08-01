#include <iostream>
#include <vector>
using namespace std;


//using hashing
int findMajorityElement(int arr[], int n) {
	// Write your code here.
	map<int,int> mpp;
	for(int i = 0;i<n;i++){
		mpp[arr[i]]++;
	}
	for(auto it : mpp){
		if(it.second > n/2)
		return it.first;
	}
	return -1;
}

//tc = O(nlogn) + O(n)
//sc = O(n)


//Moore's voting algorithm 
//tc = O(n)
//sc = O(1)
int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el = 0;
        for(int i = 0; i<nums.size();i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            } else if(nums[i] == el){
                cnt++;
            }else{
                cnt--;
            }

        }
        int cnt1 = 0;
        for(int i = 0; i<nums.size();i++){
            if(nums[i] == el){
                cnt1++;
            }
            if(cnt1 > (nums.size()/2)){
                return el;
            }

        }
        return -1;
    }

int main(){
    vector<int> a = {2,2,1,1,1,2,2};
    cout << majorityElement(a);
}