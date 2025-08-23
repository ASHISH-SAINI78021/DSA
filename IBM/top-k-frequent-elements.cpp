class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        for (auto it : mp){
            pq.push({it.second, it.first});
        }

        while (k--){
            auto top = pq.top();pq.pop();
            ans.push_back(top.second);
        }

        return ans;        
    }
};