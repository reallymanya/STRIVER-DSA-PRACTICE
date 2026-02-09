#include <iostream>
#include <stack>
using namespace std;

class Solution{
    private:

    vector<int> findPGE(vector<int> arr){
        int n = arr.size();

        vector<int> ans(n);

        stack<int> st;

        for(int i = 0; i<n;i++){
            int currele = arr[i];

            while(!st.empty() && arr[st.top()] <= currele){
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);

        }
        return ans;
    }

    public:
    vector <int> stockSpan(vector<int> arr, int n) {
        
        vector<int> PGE = findPGE(arr);
        
        vector<int> ans(n);
    
        for(int i=0; i < n; i++) {
            ans[i] = i - PGE[i];
        }
        
        return ans;
}
};

int main() {
    int n = 7;
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};

    Solution sol; 

    vector<int> ans = sol.stockSpan(arr, n);
    
    cout << "The span of stock prices is: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}