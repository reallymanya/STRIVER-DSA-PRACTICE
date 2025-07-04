#include <iostream>
using namespace std;

int lowerBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	 int lb = lowerBound(arr, x);
    int ub = upperBound(arr, x);
    return ub - lb;
	
}

int main(){
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the element to count: ";
    cin >> x;

    int result = count(arr, n, x);
    
    cout << "Count of " << x << " in the array: " << result << endl;

    return 0;   
}