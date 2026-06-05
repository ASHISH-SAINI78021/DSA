#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxP = 0;
        int mini = prices[0];
        for (int i = 1; i < n; i++){
            mini = min(mini, prices[i]);
            maxP = max(maxP, prices[i] - mini);
        }

        return maxP;
    }
};

// prices = 7 1 5 3 6 4

int main() {
    Solution obj;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = obj.maxProfit(prices);

    cout << "Maximum Profit: " << ans << endl;

    return 0;
}