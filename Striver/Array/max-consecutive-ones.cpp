class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int count = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == 1){
                count++;
            }
            else {
                maxi = max(maxi, count);
                count = 0;
            }
        }
        maxi  = max(maxi, count);
        return maxi;
    }
};