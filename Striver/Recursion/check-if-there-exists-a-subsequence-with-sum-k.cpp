class Solution {
  public:
    bool solve(vector<int> &arr, int index, int target, vector<vector<int>> &dp){
        // base case
        if (target < 0) return false;
        if (target == 0) return true;
        if (index >= arr.size()) return false;
        if (dp[index][target] != -1) return dp[index][target];
        
        // solution for one case
        bool include = solve(arr, index + 1, target - arr[index], dp);
        bool exclude = solve(arr, index + 1, target, dp);
        
        return dp[index][target] = include || exclude;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        int index = 0;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        bool ans = solve(arr, index, k, dp);
        
        return ans;
    }
};