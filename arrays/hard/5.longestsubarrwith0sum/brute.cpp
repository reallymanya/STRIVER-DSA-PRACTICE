#include <iostream>
#include <vector>
using namespace std;
//brute
//tc = O(n2)
//sc = O(1)
int longestZeroSumSubarray(vector<int>& arr) {
    int n = arr.size();
    int maxLen = 0; 

   
    for (int i = 0; i < n; i++) {
        int sum = 0; 
        
       
        for (int j = i; j < n; j++) {
            sum += arr[j]; 

            
            if (sum == 0) {
                int len = j - i + 1;
                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
    }
    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2, -2, 4};
    cout << "Length of longest subarray with sum 0: " 
         << longestZeroSumSubarray(arr) << endl;
    return 0;
}
