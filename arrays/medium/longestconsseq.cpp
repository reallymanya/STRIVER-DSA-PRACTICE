//better one  -- > sorting
//optimal in leetcode --> set

#include <iostream>
#include <vector>
using namespace std;
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    sort(a.begin(),a.end());
    int longest = 1;
    int curcnt = 0;
    int lastsmaller = INT_MIN;

    for(int i = 0; i<n;i++){
        if(a[i] - 1 == lastsmaller){
            curcnt++;
            lastsmaller = a[i];
        }
        else if(a[i] != lastsmaller){
            curcnt = 1;
            lastsmaller = a[i];
        }

        longest = max(longest,curcnt);
    }
return longest;
}

int main(){
       vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}