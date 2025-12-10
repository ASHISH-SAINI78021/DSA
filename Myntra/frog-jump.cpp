class Solution {
  public:
    int solve(vector<int> &height, int index, vector<int> &dp){
        // base case
        int n = height.size();
        if (index >= n - 1) return 0;
        if (dp[index] != -1) return dp[index];
        
        // solution for one case
        int jumpOne = abs(height[index] - height[index + 1]) + solve(height, index + 1, dp);
        int jumpTwo = INT_MAX;
        if (index + 2 < n){
            jumpTwo = abs(height[index] - height[index + 2]) + solve(height, index + 2, dp);
        }
        
        return dp[index] = min(jumpOne, jumpTwo);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        int index = 0;
        vector<int> dp(n + 1, -1);
        int ans = solve(height, index, dp);
        
        return ans;
    }
};