class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n , -1);
        for (int i = 0; i < n; i++) nums.push_back(nums[i]);
        stack<int> st;
        int newN = nums.size();
        for (int i = newN - 1; i >= 0; i--){
            while (!st.empty() && st.top() <= nums[i]) st.pop();
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }

        

        vector<int> result;
        for (int i = 0; i < n; i++) result.push_back(ans[i]);

        return result;
    }
};