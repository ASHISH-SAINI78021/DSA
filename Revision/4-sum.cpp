class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<long long>> result;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                unordered_set<long long> st;
                for (int k = j + 1; k < n; k++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if (st.find(fourth) != st.end()){
                        vector<long long> temp = {nums[i], nums[j], nums[k], fourth};
                        sort(temp.begin(), temp.end());
                        result.insert(temp);
                    }
                    st.insert(nums[k]);
                }
            }
        }

        for (auto it : result){
            vector<int> temp;
            for (auto i : it){
                temp.push_back(i);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};