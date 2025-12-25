class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int newN = 2*n;
        ans.resize(newN, -1);
        stack<int> st;
        for (int i = newN - 1; i >= 0; i--){
            int k = i % n;
            while (!st.empty() && nums[k] >= st.top()) st.pop();
            if (!st.empty()) ans[i] = st.top();
            st.push(nums[k]);
        }
        ans.resize(n);

        return ans;
    }
};




// nums = 1 2 1 -> 1 2 1 1 2 1 
// -> Applying normal algo ->  2 -1 2 2 -1 -1 -> 2 -1 2
// normal algo -> 2 -1 -1 
// ans -> 2 -1 2


// T.C -> O(n)
// S.C -> O(n)