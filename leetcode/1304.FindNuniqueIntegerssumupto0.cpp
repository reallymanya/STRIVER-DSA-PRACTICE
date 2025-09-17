#include <iostream> 
#include <vector>   
using namespace std;

vector<int> sumZero(int n)
{
    vector<int> ans;

    for (int i = 1; i <= n / 2; i++)
    {
        ans.push_back(i);
        ans.push_back(-i);
    }

    if (n % 2 == 1)
        ans.push_back(0);
    return ans;
}

int main()
{

    vector<int> result = sumZero(5);

    cout << "Result: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}