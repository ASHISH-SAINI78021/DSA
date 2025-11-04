class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int maxi = 0;
        for (int i = 0; i < n; i++) st.insert(nums[i]);
        for (auto it : st){
            int num = it;
            if (st.find(num - 1) == st.end()){
                int len = 0;
                while (st.find(num) != st.end()){
                    num = num + 1;
                    len++;
                }
                maxi = max(maxi, len);
            }
        }

        return maxi;
    }
};