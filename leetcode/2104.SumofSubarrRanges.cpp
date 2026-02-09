class Solution {
public:
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSEE(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            long long freq = left * right * 1LL;

            long long val = freq * arr[i] * 1LL;

            total += val;
        }
        return total;
    }

    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPGEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumsubArrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge = findNGE(arr);
        vector<int> pge = findPGEE(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            int left = i - pge[i];
            int right = nge[i] - i;

            long long freq = left * right * 1LL;

            long long val = freq * arr[i] * 1LL;

            total += val;
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return (sumsubArrayMaxs(nums) - sumSubarrayMins(nums));
    }
};