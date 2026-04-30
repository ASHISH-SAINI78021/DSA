class Solution {
public:
    // int solve(vector<int> &coins, int index, int amount, vector<vector<int>> &dp){
    //     // base case
    //     if (index >= coins.size()) return INT_MAX - 1;
    //     if (amount == 0) return 0;
    //     if (dp[index][amount] != -1) return dp[index][amount];

    //     // solution for one case
    //     int ans1 = INT_MAX - 1;
    //     if (coins[index] <= amount){
    //         ans1 = 1 + solve(coins, index, amount - coins[index], dp);
    //     }
    //     int ans2 = solve(coins, index + 1, amount, dp);

    //     return dp[index][amount] = min(ans1, ans2);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int index = 0;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX - 1));
        for (int i = n; i >= 0; i--){
            dp[i][0] = 0;
        }

        for (int i = n - 1; i >= 0; i--){
            for (int j = 0; j <= amount; j++){
                int ans1 = INT_MAX - 1;
                if (coins[i] <= j){
                    ans1 = 1 + dp[i][j - coins[i]];
                }
                int ans2 = dp[i + 1][j];

                dp[i][j] = min(ans1, ans2);
            }
        }
        

        int ans = dp[0][amount];
        return (ans == INT_MAX - 1) ? -1 : ans;
    }
};