#include <iostream>
using namespace std;

void numberCrown(int n) {
    // Write your code here.
int space = 2 * (n-1);
    for(int i =1; i<=n;i++){
        //num
        for(int j = 1;j<=i;j++){
            cout << j;
        }
        //space
        for(int j = 1;j<=space;j++){
            cout << " ";
        }


        //num
         for(int j = i;j>=1;j--){
            cout << j;
        }
        cout << endl;
        space = space - 2;
    }
}

int main() {
    int n;
    cin >> n;
    numberCrown(n);
    return 0;
}