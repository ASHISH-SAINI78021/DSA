class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi = 0;

        for (int num : st) {
            // if num-1 does NOT exist → num is a START of a sequence
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int count = 1;

                // count full sequence
                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    count++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};
