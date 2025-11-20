class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if (!st.empty()){
                mp[nums2[i]] = st.top();
            }
            else mp[nums2[i]] = -1;

            st.push(nums2[i]);
        }

        for (auto it : nums1){
            ans.push_back(mp[it]);
        }

        return ans;
    }
};