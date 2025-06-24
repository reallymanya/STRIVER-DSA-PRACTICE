#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum = 0;
    int dup = n;
    while(dup > 0){
        int dig = dup % 10;
        sum = sum + (dig*dig*dig);
        dup = dup/10;
    }
    if(sum == n){
        cout <<  "true";
    }else{
        cout << "false";
    }

}