#include <bits/stdc++.h> 
int findMinCost(vector<vector<int>> arr, int n, int m) {
  vector<vector<int>> dist(n + 1, vector<int> (m + 1, 1e9));
  priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
  pq.push({0, {0,0}});
  int d[3][2] = {
        {0,1}, {1,0}, {1,1}
    };
  dist[0][0] = 0;

  while (!pq.empty()){
    auto top = pq.top(); pq.pop();
    int dis = top.first;
    int row = top.second.first;
    int col = top.second.second;

    if (row == n - 1 && col == m - 1) return dis;
    for (int i = 0; i < 4; i++){
      int nrow = row + d[i][0];
      int ncol = col + d[i][1];

      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
        int diff = abs(arr[row][col] - arr[nrow][ncol]);
        if (dis + diff < dist[nrow][ncol]){
          dist[nrow][ncol] = dis + diff;
          pq.push({dist[nrow][ncol], {nrow, ncol}});
        }
      }
    }
  }

  return -1;
}