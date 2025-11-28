class Solution {
public:
    int solve(vector<int> &prices, int index, int buy, vector<vector<int>> &dp){
        // base case
        if (index >= prices.size()) return 0;
        if (dp[index][buy] != -1) return dp[index][buy];

        // solution for one case
        if (buy){
            int ans1 = -prices[index] + solve(prices, index + 1, 0, dp);
            int ans2 = solve(prices, index + 1, buy, dp);

            return dp[index][buy] = max(ans1, ans2);
        }
        else {
            int ans1 = prices[index] + solve(prices, index + 1, 1, dp);
            int ans2 = solve(prices, index + 1, 0, dp);

            return dp[index][buy] = max(ans1, ans2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int index = 0;
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        int ans = solve(prices, index, buy, dp);

        return ans;
    }
};