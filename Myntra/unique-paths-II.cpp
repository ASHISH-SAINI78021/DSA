class Solution {
public:
    int solve(vector<vector<int>> &arr, int n, int m){
        // base case
        if (n == 0 && m == 0) return 1;
        if (n < 0 || m < 0 || arr[n][m] == 1) return 0;

        int ans1 = solve(arr, n - 1, m);
        int ans2 = solve(arr, n, m - 1);

        return ans1 + ans2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        if (arr[0][0] == 1 || arr[n - 1][m - 1] == 1) return 0;

        int ans = solve(arr, n - 1, m - 1);
        return ans;
    }
};