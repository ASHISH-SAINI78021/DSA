#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &visited, vector<vector<int>> &ans, int &originalColor, int &p){
    // base case
    int n = image.size();
    int m = image[0].size();
    visited[row][col] = 1;
    ans[row][col] = p;

    // solution for one case
    int drow[] = {-1 , 0 , 1 , 0};
    int dcol[] = {0 , 1 , 0 , -1};
    for (int i = 0; i < 4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && image[nrow][ncol] == originalColor){
            dfs(nrow, ncol, image, visited, ans, originalColor, p);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) {
    vector<vector<int>> ans = image;
    vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
    int originalColor = image[x][y];
    image[x][y] = p;
    
    dfs(x, y, image, visited, ans, originalColor, p);
    return ans;
}