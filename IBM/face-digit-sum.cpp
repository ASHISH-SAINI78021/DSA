#include <bits/stdc++.h> 
string factDigitSum(int target) {
 	string ans;
	if (target == 0) return "0";
	vector<pair<int,int>> arr;
	int fac = 1;
	for (int i = 1; i <= 9; i++){
		fac = fac*i;
		arr.push_back({fac, i});
	}

	for (int i = 8; i >= 0; i--){
		while (arr[i].first <= target){
			target -= arr[i].first;
			ans += (char)(arr[i].second + '0');
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}