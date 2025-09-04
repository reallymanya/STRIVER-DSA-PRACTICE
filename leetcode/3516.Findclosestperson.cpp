#include <iostream>
using namespace std;


 int findClosest(int x, int y, int z) {
        int dist1 = abs(x - z);
        int dist2 = abs(y - z);

        if (dist1 == dist2) return 0;
        else{
        int ans = dist1 < dist2 ? 1 : 2;
        return ans;
        }
    }

    int main(){
        int x = 4;
        int y = 2;
        int z = 7;
        cout << findClosest(x,y,z);
    }