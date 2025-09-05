#include <iostream>
#include <vector>
#include <set>
using namespace std;

 //brute
 //tc = O(n3) * O(log no of unique triplets)
 //sc = O(2 * no of unique triplets)
 
 vector<vector<int>> triplet(int n, vector<int> &nums){
     set <vector<int>> st;
     for(int i = 0; i<n;i++){
         for(int j = i+1;j<n;j++){
             for(int k = j+1;k<n;k++){
                 if(nums[i] + nums[j] + nums[k] == 0){
                     vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                 }
             }
         }
     }
     
     vector<vector<int>> ans(st.begin(),st.end());
     return ans;
 }
int main()
{
      vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}