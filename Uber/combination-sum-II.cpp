#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, int index, int target, vector<int> &temp, vector<vector<int>> &ans){
	// base case
	if (target == 0){
		ans.push_back(temp);
		return ;
	}
	if (index >= arr.size() || target < 0) return ;

	// solution for one case
	for (int i = index; i < arr.size(); i++){
		if (i > index && arr[i] == arr[i - 1]) continue ;
		temp.push_back(arr[i]);
		solve(arr, i + 1, target - arr[i], temp, ans);
		temp.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	vector<int> temp;
	int index = 0;
	solve(arr, index, target, temp, ans);

	return ans;
}
