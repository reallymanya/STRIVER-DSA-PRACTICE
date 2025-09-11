#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> diag;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = i - j;
                diag[d].push_back(grid[i][j]);
            }
        }

        for (auto& entry : diag) {
            int d = entry.first;
            if (d >= 0) {
                sort(entry.second.begin(), entry.second.end(), greater<int>());
            } else {
                sort(entry.second.begin(), entry.second.end());
            }
        }

        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = i - j;
                grid[i][j] = diag[d][idx[d]++];
            }
        }

        return grid;
    }


int main() {
   
    vector<vector<int>> matrix = {
        {5, 3, 1, 2},
        {4, 8, 7, 6},
        {9, 12, 11, 10},
        {13, 16, 15, 14}
    };

    vector<vector<int>> sortedMatrix = sortMatrix(matrix);

   
    cout << "Sorted Matrix:" << endl;
    for (auto& row : sortedMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

} 