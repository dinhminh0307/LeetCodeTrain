#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <bits/stdc++.h>
// C++ program to find the max
// of Array using *max_element() in STL
 
#include <bits/stdc++.h>
using namespace std;
 
int minPathSum( vector<int>& a, vector<int>& b) {
        vector<vector<int>> grid;
        grid.push_back(a);
        grid.push_back(b);

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> local = grid;
        vector<int> result;
        result.push_back(grid[0][0]);
        //src = 00 target = [m-1][n-1]
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                {
                    result.push_back(grid[i][j]);
                    continue;
                }
                    
                if (i == m - 1) {
                    grid[i][j] += grid[i][j + 1];
                } else if (j == n - 1) {
                    grid[i][j] += grid[i + 1][j];
                } else {
                    if(grid[i][j + 1] > grid[i + 1][j])
                    {
                        result.push_back(local[i + 1][j]);
                        grid[i][j] += grid[i + 1][j];
                    } else if(grid[i][j + 1] < grid[i + 1][j]){
                        result.push_back(local[i][j + 1]);
                        grid[i][j] += grid[i][j + 1];
                    }
                }
            }
        }


        return *max_element(result.begin(), result.end());
    }

 
int main()
{
    vector<int> a = {3,4,6}; 
    vector<int> b = {6,5,4};
    vector<vector<int>> matrix;
    matrix.push_back(a);
    matrix.push_back(b);
 
    // Find a route in the matrix from source cell (0, 0) to
    // destination cell (N-1, N-1)
    // For debugging or validation purposes, you can print the stored indices
    // vector<pair<int, int>> store = minPathSum(matrix);
    // for (const auto& p : store) {
    //     cout << "Selected minimum from index: (" << p.first << ", " << p.second << ")" << endl;
    // }
    cout << minPathSum(a,b);
    return 0;
}