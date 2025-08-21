#include <bits/stdc++.h> 
vector<vector<int>> leftRotationsOfArray(vector<int> arr, vector<int> queries) {
    vector<vector<int>> ans;
    int n = arr.size();
    if (n == 0) return ans;
    for (int i = 0; i < queries.size(); i++){
        int k = (n - queries[i]%n) % n;
        vector<int> nums = arr;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
        ans.push_back(nums);
    }

    return ans;
}