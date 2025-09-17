#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int> a, int n, int k){
    int l = 0, h = n-1;
    int ans = n;
    while (l<= h){
        int m = (l + h)/2;
        if(a[m] >= k){
            ans = m;
            h =  m-1;
        }
        else l = m + 1;
    }
    return ans;
}

int upperBound(vector<int> a, int n, int k){
    int l = 0, h = n-1;
    int ans = n;
    while (l<= h){
        int m = (l + h)/2;
        if(a[m] > k){
            ans = m;
            h =  m-1;
        }
        else l = m + 1;
    }
    return ans;
}

int count(vector<int>& arr, int n, int x) {
	
	 int lb = lowerBound(arr, n,x);
    int ub = upperBound(arr, n,x);
    return ub - lb;
}

int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    int ans = count(arr, n, x);
    cout << "The number of occurrences is: "
         << ans << "\n";
    return 0;
}
