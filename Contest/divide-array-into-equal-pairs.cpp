class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        bitset<501> parity = 0;
        for (int i = 0; i < n; i++){
            parity.flip(nums[i]);
        }

        return parity.none();
    }
};