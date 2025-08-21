#include <bits/stdc++.h> 
int solve(string &a, string &b, int n, int m, vector<vector<int>> &dp){
	// base case
	if (m == 0) return 1;
	if (n == 0) return 0;
	if (dp[n][m] != -1) return dp[n][m];

	// solution for one case
	if (a[n - 1] == b[m - 1]){
		int ans1 = solve(a, b, n - 1, m - 1, dp);
		int ans2 = solve(a, b, n - 1, m, dp);
		return dp[n][m] = ans1 + ans2;
	}
	else {
		return dp[n][m] = solve(a, b, n - 1, m, dp);
	}
}
int distinctOccurences(string &a, string &b, int n, int m) {
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	int ans = solve(a, b, n, m, dp);

	return ans;
}