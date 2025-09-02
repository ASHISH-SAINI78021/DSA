void dfs(int** arr, int n, int m, vector<vector<int>> &visited, int row, int col, int dir[8][2]){
   // base case
   visited[row][col] = 1;

   // solution for one case
   for (int i = 0; i < 8; i++){
      int nrow = row + dir[i][0];
      int ncol = col + dir[i][1];

      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && arr[nrow][ncol] == 1 && visited[nrow][ncol] == 0){
         // if (visited[nrow][ncol] == 0){
            dfs(arr, n, m, visited, nrow, ncol, dir);
         // }
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   int count = 0;
   vector<vector<int>> visited(n + 1, vector<int> (m + 1, 0));
   int dir[8][2] = {
      {-1,0}, {-1,1}, {0, 1}, {1,1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}
   };

   for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
         if (visited[i][j] == 0 && arr[i][j] == 1){
            dfs(arr, n, m, visited, i, j, dir);
            count++;
         }
      }
   }

   return count;
}
