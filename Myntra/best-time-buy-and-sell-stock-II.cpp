class Solution {
public:
    int solve(vector<int> &prices, int index, int buy){
        // base case
        if (index >= prices.size()) return 0;

        // solution for one case
        if (buy){
            int ans1 = -prices[index] + solve(prices, index + 1, 0);
            int ans2 = solve(prices, index + 1, buy);
            return max(ans1, ans2);
        }
        else {
            int ans1 = prices[index] + solve(prices, index + 1, 1);
            int ans2 = solve(prices, index + 1, buy);

            return max(ans1, ans2);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int index = 0;
        int buy = 1;
        int ans = solve(prices, index, buy);

        return ans;
    }
};