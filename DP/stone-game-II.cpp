class Solution {
public:
    int solve(vector<int> &arr, int index, int m, int turn, vector<vector<vector<int>>> &dp){
        // base case
        if (index >= arr.size()) return 0;
        if (dp[index][m][turn] != -1) return dp[index][m][turn];

        // solution for one case
        int ans;
        if (turn == 0){
            // alice turn
            ans = INT_MIN;
            int sum = 0;
            for (int x = 0; x < 2*m && index + x < arr.size(); x++){
                sum += arr[index + x];
                ans = max(ans, sum + solve(arr, index + x + 1, max(x + 1, m), 1, dp));
            }
        }
        else {
            // bob turn
            ans = INT_MAX;
            for (int x = 0; x < 2*m && index + x < arr.size(); x++){
                ans = min(ans, solve(arr, index + x + 1, max(x + 1, m), 0, dp));
            }
        }

        return dp[index][m][turn] = ans;
    }
    int stoneGameII(vector<int>& arr) {
        int n = arr.size();
        int index = 0;
        int m = 1;
        int turn = 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2*n + 1, vector<int>(2, -1)));
        int ans = solve(arr, index, m, turn, dp);

        return ans;
    }
};