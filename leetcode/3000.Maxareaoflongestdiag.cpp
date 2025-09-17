#include <iostream>
#include <vector>
using namespace std;

 int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        int maxd = 0;

        for (auto it : dimensions) {
            int l = it[0];
            int w = it[1];

            int d = (l * l) + (w * w);

            if (d == maxd) {
                if (l * w > area)
                    area = l * w;
            }

            if (d > maxd) {
                maxd = d;
                area = l * w;
            }
        }
        return area;
    }
    
int main(){
     vector<vector<int>> dimensions = {
        {3, 4},   
        {6, 8},  
        {5, 12}, 
        {9, 12}   
    };

    cout << "Area of rectangle with maximum diagonal = "
         << areaOfMaxDiagonal(dimensions) << endl;

    return 0;
}