class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < 32; i++){
            int bitCount = 0;
            for (auto num : nums){
                if (num & (1 << i)) bitCount++;
            }

            if (bitCount % 3 != 0){
                result |= (1 << i);
            }
        }

        return result;
    }
};