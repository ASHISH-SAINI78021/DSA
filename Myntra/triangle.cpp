class Solution {
public:
    int solve(vector<vector<int>> &arr, int i, int j){
        // base case
        if (i == arr.size() - 1) return arr[i][j];
        if (j >= arr.size()) return 1e9;
        
        int ans1 = solve(arr, i + 1, j);
        int ans2 = solve(arr, i + 1, j + 1);

        return arr[i][j] + min(ans1, ans2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int i = 0;
        int j = 0;

        int ans = solve(triangle, i, j);
        return ans;
    }
};