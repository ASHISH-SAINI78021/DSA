#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &arr, int row, int col, vector<vector<int>> &visited, vector<pair<int, int>> &Island) {
    int n = arr.size();
    int m = arr[0].size();

    visited[row][col] = 1;
    Island.push_back({row, col});

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            visited[nrow][ncol] == 0 && arr[nrow][ncol] == 1) {
            dfs(arr, nrow, ncol, visited, Island);
        }
    }
}

int shortestBridge(vector<vector<int>> &arr, int n, int m) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<pair<int, int>> Island1;
    vector<pair<int, int>> Island2;

    // Find first island
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            if (arr[i][j] == 1 && visited[i][j] == 0) {
                dfs(arr, i, j, visited, Island1);
                found = true;
            }
        }
    }

    // Find second island
    found = false;
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            if (arr[i][j] == 1 && visited[i][j] == 0) {
                dfs(arr, i, j, visited, Island2);
                found = true;
            }
        }
    }

    // Calculate minimum bridge
    int mini = INT_MAX;
    for (size_t i = 0; i < Island1.size(); i++) {
        int x1 = Island1[i].first;
        int y1 = Island1[i].second;
        for (size_t j = 0; j < Island2.size(); j++) {
            int x2 = Island2[j].first;
            int y2 = Island2[j].second;
            mini = min(mini, abs(x1 - x2) + abs(y1 - y2) - 1);
        }
    }
    return mini;
}

