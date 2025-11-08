class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> result;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n;  j++){
                unordered_map<long long, int> mp;
                for (int k = j + 1; k < n; k++){
                    long long ans1 = (long long)nums[i] + (long long)nums[j];
                    long long ans2 = ans1 + (long long)nums[k];
                    long long fourth = target - ans2;
                    if (mp.find(fourth) != mp.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        result.insert(temp);
                    }
                    mp[nums[k]] = 1;
                }
            }
        }

        vector<vector<int>> ans;
        for (auto it : result){
            ans.push_back(it);
        }

        return ans;
    }
};