class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprice = 0;
        int mini = prices[0];

        for (int i = 0; i < n; i++){
            mini = min(mini, prices[i]);
            maxprice = max(maxprice, prices[i] - mini);
        }

        return maxprice;
    }
};