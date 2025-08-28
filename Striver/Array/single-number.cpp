class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int Xor = 0;
        for (int i = 0; i < n; i++){
            Xor = nums[i]^Xor;
        }

        return Xor;
    }
};