class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[nums1[i]]++;
        }
        for (int i = 0; i < m; i++){
            if (mp.find(nums2[i]) != mp.end()){
                ans.push_back(nums2[i]);
                mp.erase(nums2[i]);
            }
        }

        // for (auto it : mp){
        //     ans.push_back(it.first);
        // }

        return ans;
    }
};