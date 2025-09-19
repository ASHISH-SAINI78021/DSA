class Solution {
public:
    int solve(vector<int> &arr, int index, int k, vector<vector<int>> &dp){
        // base case
        if (k == 0) return 1;
        if (index >= arr.size()) return 0;
        if (dp[index][k] != -1) return dp[index][k];

        // solution for one case
        int include = solve(arr, index, k - 1, dp);
        int exclude = solve(arr, index + 1, k, dp);

        return dp[index][k] = include + exclude;
    }
    int countVowelStrings(int n) {
        vector<int> arr = {1,2,3,4,5};
        int index = 0;
        vector<vector<int>> dp(arr.size() + 1, vector<int>(n + 1, -1));
        int ans = solve(arr, index, n, dp);

        return ans;
    }
};