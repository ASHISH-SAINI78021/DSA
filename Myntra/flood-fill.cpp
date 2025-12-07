class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int n = image.size();
        if (n == 0){
            return ans;
        }
        int m = image[0].size();

        vector<vector<int>> visited(n , vector<int> (m , 0));
        queue<pair<int , int>> q;

        q.push({sr , sc});
        visited[sr][sc] = 1;
        int startingColor = image[sr][sc];

        while (!q.empty()){
            auto front = q.front();
            int row = front.first;
            int col = front.second;
            q.pop();

            ans[row][col] = color;

            int drow[] = {-1 , 0 , 1 , 0};
            int dcol[] = {0 , 1 , 0 , -1};

            for (int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && image[nrow][ncol] == startingColor){
                    q.push({nrow , ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        return ans;
    }
};