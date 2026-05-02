int ninjaTraining(int n, vector<vector<int>> &points)
{
    int ans = 0;

    // ? Fix DP size
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));

    // ? Fill DP bottom-up
    for (int index = n - 1; index >= 0; index--){
        for (int j = 3; j >= 0; j--){
            int maxi = 0;

            for (int i = 0; i < 3; i++){
                if (j != i){
                    int result = points[index][i] + dp[index + 1][i];
                    maxi = max(maxi, result);
                }
            }

            dp[index][j] = maxi;
        }
    }

    // ? Final answer
    ans = dp[0][3];

    return ans;
}