#include <iostream>
using namespace std;

int rev(int n)
{
    int revn = 0;
    while (n > 0)
    {
        int lastdigit = n % 10; 
        revn = revn * 10 + lastdigit;
        n = n/10;
        
}
    return revn;

}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = rev(n);
    cout << "Reversed number: " << result << endl;

    return 0;
}