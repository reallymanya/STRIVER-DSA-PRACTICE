#include <iostream>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if(n == 0) return 0;

    vector<int> left_max(n);
    left_max[0] = height[0];

    for(int i = 1; i<n;i++){
        left_max[i] = max(height[i],left_max[i-1]);
    }

    int right_max = 0;
    int totalwater = 0;

    for(int i = n-1; i>=0;i--){
        right_max = max(right_max,height[i]);

        int waterlevel = min(left_max[i],right_max);
        totalwater += waterlevel - height[i];
    }

    return totalwater;
}

int main() {
    
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    int result = trap(height);
    
    cout << "Trapped Rainwater: " << result << endl;
    
    return 0;
}