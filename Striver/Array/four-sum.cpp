class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> result;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                unordered_set<long long> st;
                for (int k = j + 1; k < n; k++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if (st.find(fourth) != st.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        result.insert(temp);
                    }
                    st.insert(nums[k]);
                }
            }
        }

        for (auto it : result){
            ans.push_back(it);
        }

        return ans;
    }
};