#include <bits/stdc++.h>
using namespace std;
int solveHelper(string &a, string &b, int i, int j, vector<vector<int>> &dp){
    // base case
    if (i == 0 && j == 0) return 0;
    if (i < 0 || j < 0) return 1e9;
    if (dp[i][j] != -1) return dp[i][j];
    
    // solution for one case
    if (a[i - 1] == b[j - 1]){
        return dp[i][j] = solveHelper(a, b, i - 1, j - 1, dp);
    }
    else {
        int ans1 = 1 + solveHelper(a, b, i - 1, j, dp);
        int ans2 = 1 + solveHelper(a, b, i - 1, j - 1, dp);
        int ans3 = 1 + solveHelper(a, b, i, j - 1, dp);
        
        return dp[i][j] = min({ans1, ans2, ans3});
    }
}
void solve(){
    string a;
    string b;
    cin >> a;
    cin >> b;
    vector<vector<int>> dp(a.length()  + 1, vector<int> (b.length() + 1, -1));
    int ans = solveHelper(a, b, a.length(), b.length(), dp);
    
    cout << ans << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
