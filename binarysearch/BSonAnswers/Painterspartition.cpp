#include <iostream>
#include <vector>        
#include <algorithm>       // for max_element
#include <numeric>         // for accumulate
using namespace std;


int countPainters(vector<int> &boards, int time){
    int n = boards.size();
    int painters = 1;
    long long boardsPainter = 0;

    for(int i = 0; i<n;i++){
        if (boardsPainter + boards[i] <= time) {
            boardsPainter += boards[i];
        }
        else {
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
   int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while (low <= high) {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}