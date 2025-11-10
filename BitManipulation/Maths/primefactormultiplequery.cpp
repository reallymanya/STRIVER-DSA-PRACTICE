#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> primeFactors(vector<int> &queries)
{
    // your code goes here
    int num = 1e6;
    vector<int> SPF(num + 1);

    for (int i = 1; i <= num; i++)
    {
        SPF[i] = i;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (SPF[i] == i)
        {
            for (int j = i * i; j <= num; j += i)
            {
                if (SPF[j] == j)
                    SPF[j] = i;
            }
        }
    }

    vector<vector<int>> result;
    for (int n : queries)
    {
        vector<int> factors;
        while (n != 1)
        {
            factors.push_back(SPF[n]);
            n = n / SPF[n];
        }
        result.push_back(factors);
    }
    return result;
}

int main() {
    // Hardcoded queries
    vector<int> queries = {12, 15, 20, 100};
    
    vector<vector<int>> result = primeFactors(queries);
    
    for(int i = 0; i < result.size(); i++) {
        cout << "Prime factors of " << queries[i] << ": ";
        for(int factor : result[i]) {
            cout << factor << " ";
        }
        cout << endl;
    }
    
    return 0;
}
