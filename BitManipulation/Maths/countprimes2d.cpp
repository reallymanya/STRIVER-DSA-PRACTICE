#include <iostream>
#include <vector>
using namespace std;

vector<int> getSeive(int n)
{
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    return isPrime;
}
vector<int> primesInRange(vector<vector<int>> &queries)
{
    // your code goes here

    int maxVal = 0;
    for (const auto &query : queries)
    {
        maxVal = max(maxVal, query[1]);
    }

    vector<int> prime = getSeive(maxVal);

    for (int i = 2; i <= maxVal; i++)
    {
        prime[i] += prime[i - 1];
    }

    vector<int> result;
    for (auto &q : queries)
    {
        int L = q[0], R = q[1];
        if (L < 2)
            L = 2;

        int ans = prime[R] - prime[L - 1];
        result.push_back(ans);
    }
    return result;
}

int main()
{
    // Example queries: each pair is {L, R}
    vector<vector<int>> queries = {
        {2, 5},
        {4, 7}};

    auto result = primesInRange(queries);

    cout << "The number of primes in the given ranges are: ";
    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
