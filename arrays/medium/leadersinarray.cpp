#include <iostream>
#include <vector>
using namespace std;

vector<int> findLeaders(vector<int> &elements, int n) {
    // Write your code here.
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = n-1;i>=0;i--){
        if(elements[i] > maxi){
            ans.push_back(elements[i]);
        }
        maxi = max(maxi,elements[i]);
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> nums = {10,22,12,3,0,6};
   int n = 6;
   vector<int> ans = findLeaders(arr,n);
   for(int i = 0; i<ans.size();i++){
    cout << ans[i] << " ";
   }

   cout << endl;
   
}