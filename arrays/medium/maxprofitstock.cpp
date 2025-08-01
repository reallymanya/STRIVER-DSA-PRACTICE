#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//using if else 
//tc = O(N)
//SC = O(1)
int maxprofit(vector<int>& prices) {
int buy = prices[0];         // initial minimum (buying price)
int profit = 0;
for (int i = 1; i < prices.size(); i++) {
    if (prices[i] < buy) {
        buy = prices[i];     // update if current price is lower
    } else if (prices[i] - buy > profit) {
        profit = prices[i] - buy;   // update max profit
    }
}
return profit;
}

//striver approach 
//tc = O(N)
//SC = O(1)
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxprofit = 0;
        for(int i = 1; i<n;i++){
            int cost = prices[i] - mini;
            maxprofit = max(maxprofit,cost);
            mini = min(mini,prices[i]);
        }
          return maxprofit;
    }


//brute force
//tc = O(N2)
//SC = O(1)


#include<bits/stdc++.h>
using namespace std;

int maxProfitBrute(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
            maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
        }

    return maxPro;
}

//for zero based indesing
int maxProfitzerobased(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

     for (int i = 0; i < n; i++) {
        minPrice  = min(minPrice,a[i]);
        maxPro = max(maxPro,a[i] - mini);

}
return maxPro;
}



int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}

