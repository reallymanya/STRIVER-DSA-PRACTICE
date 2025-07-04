#include <iostream>
#include <vector>
#include <map>
using namespace std;

// when there is positives and zeroes

//problem link: 
/*https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
*/
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();
    long long sum = a[0];
    int left = 0;
    int right = 0;
    int maxlen = 0;
    while(right < n){
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen,right-left+1);
        }
        right++;
        if(right < n){
            sum += a[right];
        }
           
    }
    return maxlen;
}



int main(){
    vector <int> a = {2,0,0,0,3};
    long long k = 3;
    cout << longestSubarrayWithSumK(a,k);
}