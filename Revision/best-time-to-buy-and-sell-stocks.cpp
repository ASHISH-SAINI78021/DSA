class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < n; i++){
            mini = min(mini, prices[i]);
            maxProfit = max(maxProfit, prices[i] - mini);
        }

        return maxProfit;
    }
};