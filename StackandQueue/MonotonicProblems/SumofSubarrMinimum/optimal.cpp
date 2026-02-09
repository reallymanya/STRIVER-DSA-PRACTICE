#include <iostream>
#include <stack>
using namespace std;

    vector<int> findNSE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

   vector<int> findPSEE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;
        for(int i = 0; i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

     int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEE(arr);

        int total = 0;
        int mod = 1e9 + 7;

        int sum = 0;

        for(int i = 0; i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            long long freq = left*right*1LL;

            int val = (freq*arr[i]*1LL) % mod;

            total = (total + val) % mod;
        }
        return total;
     }

    
int main() {
    vector<int> arr = {3, 1, 2, 5};
    
    
    int ans = sumSubarrayMins(arr);
    
    cout << "The sum of minimum value in each subarray is: " << ans;
    
    return 0;
}