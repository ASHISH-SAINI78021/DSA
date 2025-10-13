class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int singleDigitSum = 0;
        int doubleDigitSum = 0;
        int sum = 0;

        for (int i = 0; i < n; i++){
            if (nums[i] >= 0 && nums[i] <= 9){
                singleDigitSum += nums[i];
            }
            else {
                doubleDigitSum += nums[i];
            }
            sum += nums[i];
        }

        if (singleDigitSum > sum - singleDigitSum) return true;
        else if (doubleDigitSum > sum - doubleDigitSum) return true;
        else return false;
    }
};