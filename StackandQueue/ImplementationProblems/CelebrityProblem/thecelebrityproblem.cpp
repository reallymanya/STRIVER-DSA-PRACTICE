
#include <iostream>
using namespace std;

    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int top = 0;
        int down = n - 1;
        
        while(top < down){
            if(mat[top][down] == 1)
            top = top + 1;
            else if(mat[down][top] == 1)
            down = down - 1;
            else{
                top ++;
                down--;
            }
        }
        
        if(top > down) return -1;
        for(int i = 0; i<n;i++){
            if(i == top) continue;
    
            if(mat[top][i] == 1 || mat[i][top] == 0)
            return -1;
            
        }
        return top;
    }



int main() {
    vector<vector<int>> M = {
         {0, 1, 1, 0}, 
         {0, 0, 0, 0}, 
         {1, 1, 0, 0}, 
         {0, 1, 1, 0}
    };
    
   
    int ans = celebrity(M);
    
    cout << "The index of celebrity is: " << ans;
    
    return 0;
}