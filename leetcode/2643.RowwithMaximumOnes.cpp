#include <iostream>
#include <vector>
using namespace std;

 vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxCnt = 0, ind = 0;
    for(int i = 0; i<n;i++){
        int cntRow = 0;

        for(int j = 0; j<m;j++){
            cntRow += mat[i][j];
        }

        if(cntRow > maxCnt){
            maxCnt = cntRow;
            ind = i;
        }
    }
    return {ind, maxCnt};
    }
  
int main()
{
vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
int n = 3, m = 3;
vector<int> result = rowAndMaximumOnes(matrix);
cout << "The row with maximum no. of 1's is: " << result[0] << " (Count: " << result[1] << ")" << '\n';
}