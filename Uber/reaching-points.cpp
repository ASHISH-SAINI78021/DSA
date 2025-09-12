bool solve(int startX, int startY, int endX, int endY, vector<vector<int>> &dp){
	// base case
	if (startX == endX && startY == endY){
		return true;
	}
	if (startX > endX || startY > endY) return false;
	if (dp[startX][startY] != -1) return dp[startX][startY];

	// solution for one case
	int ans1 = solve(startX + startY, startY, endX, endY, dp);
	int ans2 = solve(startX, startX + startY, endX, endY, dp);

	return dp[startX][startY] = ans1 || ans2;
}
bool isReachable(int startX, int startY, int endX, int endY) {
	vector<vector<int>> dp(endX + 1, vector<int> (endY + 1, -1));
	bool ans = solve(startX, startY, endX, endY, dp);
	return ans;
}