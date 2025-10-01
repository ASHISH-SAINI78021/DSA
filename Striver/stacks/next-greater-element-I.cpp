class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> mp;

        for (int j = 0; j < m; j++){
            mp[nums2[j]] = j;
        }
        for (int i = 0; i < n; i++){
            int index = mp[nums1[i]];
            for (int j = index; j < m; j++){
                if (nums2[j] > nums2[index]){
                    ans[i] = nums2[j];
                    break ;
                }
            }
        }

        return ans;
    }
};