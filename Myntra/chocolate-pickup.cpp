#include <bits/stdc++.h>
int solve(vector<vector<int>> &grid, int &n, int &m, int j1, int j2, int i){
    // base case 
    if (j1 >= m || j2 >= m || i >= n || j1 < 0 || j2 < 0){
        return -1e9;
    }
    if (i == n - 1){
        if (j1 == j2){
            return grid[i][j1];
        }
        else {
            return grid[i][j1] + grid[i][j2];
        }
    }

    int ans = INT_MIN;
    int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
    for (int d1 = -1; d1 <= 1; d1++){
        for (int d2 = -1; d2 <= 1; d2++){
            int result = curr + solve(grid, n, m, j1 + d1, j2 + d2, i + 1);
            ans = max(ans, result);
        }
    }

    return ans;
} 
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    int j1 = 0;
    int j2 = m - 1;
    int i = 0;
    int ans = solve(grid, n, m, j1, j2, i);
    return ans;
}