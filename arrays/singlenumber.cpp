//Find the number that appears once, and the other numbers twice

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int getSingleElement(vector<int> &arr) {


    int n = arr.size();

    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

   
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }

 
    return -1;  // If no single element is found, return -1
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}

