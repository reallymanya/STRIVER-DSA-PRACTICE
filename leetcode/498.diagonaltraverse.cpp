#include <iostream>  
#include <vector>   

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
 int row = mat.size();
    int col = mat[0].size();
    vector<int> ans;

    int i = 0, j = 0;
    bool upward = true;

    while(ans.size() < row * col) {
        ans.push_back(mat[i][j]);

        if(upward) {
            if(j == col - 1) {      // right boundary
                i++;
                upward = false;
            } else if(i == 0) {     // top boundary
                j++;
                upward = false;
            } else {
                i--; j++;           // move upward
            }
        } else {
            if(i == row - 1) {      // bottom boundary
                j++;
                upward = true;
            } else if(j == 0) {     // left boundary
                i++;
                upward = true;
            } else {
                i++; j--;           // move downward
            }
        }
    }
    return ans;
}

int main() {
 
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = findDiagonalOrder(mat);

    cout << "Diagonal Traversal: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}