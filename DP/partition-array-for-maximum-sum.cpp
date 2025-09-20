class Solution {
public:
    int solve(vector<int> &arr, int index, int k, vector<int> &dp){
        // base case
        if (index >= arr.size()){
            return 0;
        }
        if (dp[index] != -1) return dp[index];

        // solution for one case
        int ans = INT_MIN;
        int mx = 0;
        for (int i = 1; i <= k && index + i - 1 < arr.size(); i++){
            mx = max(mx, arr[index + i - 1]);
            int sum = mx*i + solve(arr, index + i, k, dp);
            ans = max(ans, sum);
        }
        return dp[index] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int index = 0;
        vector<int> dp(n + 1, -1);
        int ans = solve(arr, index, k, dp);
        return ans;
    }
};