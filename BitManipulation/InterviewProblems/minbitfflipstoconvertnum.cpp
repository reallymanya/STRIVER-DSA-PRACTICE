#include <iostream>
using namespace std;

int minBitFlips(int start, int goal) {
        int ans = (start ^ goal);
        int cnt = 0;
        for(int i = 0; i<32;i++){
            if(ans & (1<<i))
            cnt = cnt + 1;
        }
        return cnt;
    }

int main() {
    int start = 10, goal = 7;
 
    int ans = minBitFlips(start, goal);
    
    cout << "The minimum bit flips to convert number is: " << ans;
    
    return 0;
}