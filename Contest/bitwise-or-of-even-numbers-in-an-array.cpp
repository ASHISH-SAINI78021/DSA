class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            if(!(nums[i] & 1)){
                ans = ans | nums[i];
            }
        }

        return ans;
    }
};