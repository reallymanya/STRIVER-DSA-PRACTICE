/*An Alpha-Triangle is represented by the triangular pattern of alphabets in reverse order.

For every value of ‘N’, help sam to print the corresponding Alpha-Triangle.

Example:
Input: ‘N’ = 3

Output: 
C
C B 
C B A
*/

#include <iostream>
using namespace std;

void alphaTriangle(int n) {
    // Write your code here.
    for(int i = 0; i<n;i++){
        char ch = 'A' + n -1;
    for(int j = 0; j<=i;j++){
cout << ch<<" ";
ch--;
    }
    cout << endl;
    }
}

/*E
D E
C D E
B C D E*/

void print18(int n){
    for(int i = 0; i<n;i++){
        for(char ch = 'E' - i; ch <= 'E'; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    alphaTriangle(n);
    print18(n);
    return 0;
}