#include <iostream>
using namespace std;

// Function to calculate maximum score by trying all combinations
int maxScore(vector<int> &cardPoints, int k)
{

    int n = cardPoints.size();

    int maxSum = 0;

    for (int i = 0; i <= k; i++)
    {
        int tempSum = 0;

        for (int j = 0; j < i; j++)
        {
            tempSum += cardPoints[j];
        }

        // Sum of (k - i) cards from the back
        for (int j = 0; j < k - i; j++)
        {
            tempSum += cardPoints[n - 1 - j];
        }

        // Update max if this is a better combination
        maxSum = max(maxSum, tempSum);
    }

    // Return the best total found
    return maxSum;
}

int main()
{
    vector<int> cards = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << maxScore(cards, k) << endl;
    return 0;
}
