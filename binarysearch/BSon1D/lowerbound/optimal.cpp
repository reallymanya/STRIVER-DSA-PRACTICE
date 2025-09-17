#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low = 0;
	int high = n-1;
	int ans = n;
	while(low<=high){
int mid = (low+high)/2;
if(arr[mid] >= x){
	ans = mid;
	high = mid - 1; //look for smaller index on left 
}
else
low =  mid + 1; // look for right
	}
	return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}