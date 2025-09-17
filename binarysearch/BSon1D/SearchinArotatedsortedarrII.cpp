#include <iostream>
#include <vector>
using namespace std;


bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.
    int n = A.size();
    int low = 0;
    int high = n -1;
    while(low <= high){
        int mid = (low + high)/2;

        if(A[mid] == key)
        return true;

        if(A[mid] == A[low] && A[mid] == A[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }

        if(A[low] <= A[mid]){
            if(A[low] <= key && key <= A[mid]){
                high = mid -1;
            }
            else
            low = mid + 1;
        }
        else{
            if(A[mid] <= key && key <= A[high]){
             low = mid + 1;
            }
            else
          high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;
    bool ans = searchInARotatedSortedArrayII(arr, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}