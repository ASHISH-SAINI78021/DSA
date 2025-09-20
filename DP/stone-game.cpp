class Solution {
public:
    int solve(vector<int> &piles, int left, int right, int turn, vector<vector<vector<int>>> &dp){
        // base case
        if (left > right) return 0;
        if (dp[left][right][turn] != -1) return dp[left][right][turn];

        // solution for one case
        int ans1 = 0;
        int ans2 = 0;
        if (turn == 0){
            ans1 = max(piles[left] + solve(piles, left + 1, right, !turn, dp), piles[right] + solve(piles, left, right - 1, !turn, dp));
        }
        else {
            ans2 = max(piles[left] + solve(piles, left + 1, right, !turn, dp), piles[right] + solve(piles, left, right - 1, !turn, dp));
        }

        return dp[left][right][turn] = ans1 > ans2;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int left = 0;
        int right = n - 1;
        int turn = 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (n + 1, vector<int>(2, -1)));
        bool ans = solve(piles, left, right, turn, dp);

        return ans;
    }
};