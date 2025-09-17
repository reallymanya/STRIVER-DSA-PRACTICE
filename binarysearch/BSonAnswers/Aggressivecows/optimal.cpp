#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool canWeplace(vector<int> &a, int dist, int cows){
   int cntcows = 1 , last = a[0];
   int n = a.size();
   for(int i = 1; i<n;i++){
       if(a[i] - last >= dist){
       cntcows++;
       last = a[i];
       }
       if(cntcows >= cows) return true;
   }
   return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int low = 1, high = stalls[n-1] - stalls[0];
    while(low <= high){
        int mid = (low + high)/2;
        if(canWeplace(stalls,mid,k) == true)
        low = mid + 1;
        else
        high = mid - 1;
    }
    return high;
}
int main()
{
  vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}