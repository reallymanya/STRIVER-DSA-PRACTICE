#include <iostream>
using namespace std;

bool checkprime(int n){
    int count = 0;
    for(int i = 1; i<= sqrt(n); i++){
        if(n%i == 0){
            count++;

            if(n != (n/i)){
                count++;
            }
             if (count > 2) {
                break;
            }
        }
    }

    // if(count == 2){
    //     return true;
    // }else{
    //     return false;
    // }
     return (count == 2);
}

int main() {
    int n = 1483;
    bool isPrime = checkprime(n);
    if(isPrime){
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
    