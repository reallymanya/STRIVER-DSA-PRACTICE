#include <iostream>
#include <unordered_map>
using namespace std;

void count(int arr[], int n){
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    int maxfreq = 0, minfreq = n;
    int maxEle = 0, minEle = 0;


    for(auto it : mpp){
        int count = it.second;
        int element = it.first;

        if(count > maxfreq){
            maxfreq = count;
            maxEle = element;
        }

        if(count < minfreq){
            minfreq = count;
            minEle = element;
        }
}
    cout << "Max Frequency: " << maxfreq << "\nElement(s): " << maxEle << endl;
    cout << "Min Frequency: " << minfreq << "\nElement(s): " << minEle << endl;
}

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Frequency(arr, n);
    return 0;
}












/*Time Complexity: O(N), The insertion and retrieval operation in the map takes O(1) time.
Space Complexity:  O(N), It is for the map we are using.*/