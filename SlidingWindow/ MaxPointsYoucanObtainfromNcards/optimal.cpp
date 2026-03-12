
#include <iostream>
#include <algorithm>
using namespace std;



int maxPoints(vector<int>&arr , int K){
    // Write your code here.
    int n = arr.size();
    int lSum = 0, rSum = 0, maxSum = 0;

    for(int i = 0; i<K;i++){
        lSum += arr[i];
        maxSum = lSum;
    }
        int rInd = n - 1;

        for(int i = K-1; i>=0;i--){
            lSum = lSum - arr[i];
            rSum = rSum + arr[rInd];

            rInd = rInd - 1;

            maxSum = max(maxSum, lSum + rSum);
    
        }
        return maxSum;
    
}


int main() {

    vector<int> cards = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;



    cout << maxPoints(cards, k) << endl;

    return 0;
}