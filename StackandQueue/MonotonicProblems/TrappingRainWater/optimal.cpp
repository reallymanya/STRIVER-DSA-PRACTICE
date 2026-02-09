#include <iostream>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if(n == 0) return 0;

    int left = 0;
    int right = n-1;

    int maxleft = 0;
    int maxright = 0;

    int totalwater = 0;

    while(left <= right){
        if(height[left] <= height[right]){
            if(maxleft > height[left]){
                totalwater += maxleft - height[left];
            }
            else{
                maxleft = height[left];
            }
            left++;
        }
        else{
            if(height[right] >= maxright){
                maxright = height[right];
            }else{
                totalwater += maxright - height[right];
            }   
            right--;     
        }
    }
    
}

int main() {
    
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    int result = trap(height);
    
    cout << "Trapped Rainwater: " << result << endl;
    
    return 0;
}