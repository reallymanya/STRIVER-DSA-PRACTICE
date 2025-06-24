#include <iostream>
using namespace std;

void count(int arr[], int n){
    vector<bool> visited(n, false);
    int maxfreq = 0, minfreq = n;
    int maxEle = 0, minEle = 0;

    for(int i = 0; i<n;i++){
        if(visited[i] == true){
            continue;
        }

        int count = 1;
        for(int j = i+1; j<n;j++){
            if(arr[i] == arr[j]){
                visited[j] = true;
                count++;
            }
        }

        if(count > maxfreq){
            maxfreq = count;
            maxEle = arr[i];
        }
        if(count < minfreq){
            minfreq = count;
            minEle = arr[i];
        }
    }
    cout << "Max Frequency: " << maxfreq << "\nElement(s): " << maxEle << endl;
    cout << "Min Frequency: " << minfreq << "\nElement(s): " << minEle << endl;
}

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}

/*Time Complexity: O(N*N), We are using the nested loop to find the frequency.
Space Complexity:  O(N),  It is for the visited array we are using.*/