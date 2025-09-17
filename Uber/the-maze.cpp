#include <bits/stdc++.h> 
using namespace std;
bool reachDestination(vector<vector<int>> &maze, int m, int n, int startX, int startY, int destX, int destY)
{
    vector<vector<int>> visited(m + 1, vector<int>(n + 1, 0));
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = 1;

    while (!q.empty()){
        auto front = q.front(); q.pop();
        int row = front.first;
        int col = front.second;
        if (row == destX && col == destY) return true;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for (int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            int x = nrow;
            int y = ncol;
            while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0){
                x += drow[i];
                y += dcol[i];
            }
            x -= drow[i];
            y -= dcol[i];
            if (visited[x][y] == 0){
                visited[x][y] = 1;
                q.push({x, y});
            }
        }
    }

    return false;
}