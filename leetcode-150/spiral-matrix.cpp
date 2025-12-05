class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if (n == 0){
            return {};
        }
        int m = matrix[0].size();
        if (m == 0) {
            return ans;
        }
        
        int left = 0;
        int top = 0;
        int right = m - 1;
        int bottom = n - 1;

        while (left <= right && top <= bottom){
            // left to right
            for (int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            // top to bottom
            for (int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            // right to left
            if (top <= bottom){
                for (int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // bottom to top
            if (left <= right){
                for (int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};