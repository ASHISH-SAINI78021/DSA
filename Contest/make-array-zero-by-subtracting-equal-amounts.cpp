class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int zeroes = 0;
        for (int i = 0; i < n; i++) if (nums[i] == 0) zeroes++;
        int count = 0;
        while (zeroes < n){
            int minElement = 1e9;
            for (int i = 0; i < n; i++){
                if (nums[i] != 0 && nums[i] < minElement) minElement = nums[i];
            }
            for (int i = 0; i < n; i++){
                if (nums[i] != 0){
                    nums[i] = max(0, nums[i] - minElement);
                    if (nums[i] == 0) zeroes++;
                }
            }
            count++;
        }
        
        return count;
    }
};