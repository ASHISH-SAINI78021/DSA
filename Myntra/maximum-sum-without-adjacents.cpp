// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int solve(vector<int> &arr, int index, vector<int> &dp){
        // base case
        int n = arr.size();
        if (index >= n) return 0;
        if (dp[index] != -1) return dp[index];
        
        int ans1 = arr[index] + solve(arr, index + 2, dp);
        int ans2 = solve(arr, index + 1, dp);
        
        return dp[index] = max(ans1, ans2);
    }
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        int index = 0;
        if (n == 1) return arr[0];
        if (n == 2) return max(arr[0], arr[1]);
        vector<int> dp(n + 1, -1);
        int ans = solve(arr, index, dp);
        
        return ans;
    }
};