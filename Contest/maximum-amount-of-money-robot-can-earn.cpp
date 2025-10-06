class Solution {
public:
    int maximumAmount(std::vector<std::vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        int k = 2;

        const int UNREACHABLE = -1e9;
        std::vector<std::vector<std::vector<int>>> dp(
            m, std::vector<std::vector<int>>(n, std::vector<int>(k + 1, UNREACHABLE)));

        int start_val = coins[0][0];
        if (start_val >= 0) {
            dp[0][0][0] = start_val;
        } else {
            dp[0][0][0] = start_val;
            if (k >= 1) {
                dp[0][0][1] = 0;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l <= k; ++l) {
                    if (dp[i][j][l] == UNREACHABLE) continue;
                    if (j + 1 < n) {
                        int next_val = coins[i][j + 1];
                        if (next_val >= 0) {
                            dp[i][j + 1][l] = std::max(dp[i][j + 1][l], dp[i][j][l] + next_val);
                        } else {
                            dp[i][j + 1][l] = std::max(dp[i][j + 1][l], dp[i][j][l] + next_val);
                            if (l + 1 <= k) {
                                dp[i][j + 1][l + 1] = std::max(dp[i][j + 1][l + 1], dp[i][j][l]);
                            }
                        }
                    }

                    if (i + 1 < m) {
                        int next_val = coins[i + 1][j];
                        if (next_val >= 0) {
                            dp[i + 1][j][l] = std::max(dp[i + 1][j][l], dp[i][j][l] + next_val);
                        } else {
                            dp[i + 1][j][l] = std::max(dp[i + 1][j][l], dp[i][j][l] + next_val);
                            if (l + 1 <= k) {
                                dp[i + 1][j][l + 1] = std::max(dp[i + 1][j][l + 1], dp[i][j][l]);
                            }
                        }
                    }
                }
            }
        }

        int ans = UNREACHABLE;
        for (int l = 0; l <= k; ++l) {
            ans = std::max(ans, dp[m - 1][n - 1][l]);
        }
        
        return ans;
    }
};©leetcode