class Solution {
  public:
    bool solve(vector<int> &arr, int index, int sum, vector<vector<int>> &dp){
        // base case
        if (sum == 0) return true;
        if (index >= arr.size() || sum < 0) return false;
        if (dp[index][sum] != -1) return dp[index][sum];
        
        // solution
        bool include = solve(arr, index + 1, sum - arr[index], dp);
        bool exclude = solve(arr, index + 1, sum, dp);
        
        return dp[index][sum] = include || exclude;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1)); // ✅ fixed
        
        return solve(arr, 0, sum, dp);
    }
};