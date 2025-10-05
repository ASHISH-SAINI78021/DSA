#include<iostream>
#include<vector>
using namespace std;
void dfs(int row, int col, const vector<vector<int>> &grid, vector<vector<int>> &visited){
    // base case
    visited[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    // solution for one case
    int arr[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    for (int i = 0; i < 4; i++){
        int nrow = row + arr[i][0];
        int ncol = col + arr[i][1];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0){
            dfs(nrow, ncol, grid, visited);
        }
    }
}
int numberOfConnectedComponents(const vector<vector<int>> &grid){
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));

    int components = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1 && visited[i][j] == 0){
                dfs(i, j, grid, visited);
                components++;
            }
        }
    }

    return components;
}
int main(){
    const vector<vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
    };
    int ans = numberOfConnectedComponents(grid);
    cout << "Distinct active clusters : " << ans << endl;
    return 0;
}