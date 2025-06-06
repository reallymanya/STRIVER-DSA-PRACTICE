//parametrised way

#include <iostream>
using namespace std;

void summ(int i, int sum){
    if(i<1){
        cout << sum << endl;
        return;
    }
    summ(i-1, sum+i);
}

//functional wau

int sum2(int n){
    if(n == 0){
        return 0;
    }
    return n + sum2(n-1);
}

int main(){
    int n;
    cin >> n;
    summ(n, 0);
    cout << sum2(n) << endl;
    return 0;
}