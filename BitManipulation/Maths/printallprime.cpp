#include <iostream>
using namespace std;

vector<int> countPrimes(int n)
{
    // Write your code here.
    vector<int> ls;
    for(int i = 2; i*i <= n;i++){
        if(n%i == 0){
            ls.push_back(i);
        }
        while(n%i == 0){
            n = n/i;
        }
    }
    if(n != 1) ls.push_back(n);
    return ls;
}

int main()
{
    int n = 15;

    vector<int> primes = countPrimes(n);

    cout << "Prime factors are: ";
    for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << " ";
    }
    cout << endl;

    return 0;
}