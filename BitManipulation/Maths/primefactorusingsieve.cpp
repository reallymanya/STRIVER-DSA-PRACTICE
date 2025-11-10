#include <iostream>
#include <vector>
using namespace std;

vector<int> primeFac(int n) {
    int num = 1e6;
        vector<int> SPF(num+1);
        
        
        for(int i = 1; i<= num; i++){
            SPF[i] = i;
        }
        
        for(int i = 2; i*i <= num;i++){
            if(SPF[i] == i){
                for(int j = i*i; j<=num;j += i){
                    if(SPF[j] == j)
                    SPF[j] = i;
                }
            }
        }
        
        vector<int> list;
        while(n != 1){
            list.push_back(SPF[n]);
            n = n/SPF[n];
        }
        return list;
    }
    int main() {
    int n = 84;
    vector<int> res = primeFac(n);
    for (int x : res) cout << x << " ";
    return 0;
}