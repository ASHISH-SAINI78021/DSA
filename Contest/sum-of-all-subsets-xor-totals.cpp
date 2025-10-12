class Solution {
public:
    void solve(vector<int> &nums, int index, int currXor, int &sum){
        // base case
        if (index >= nums.size()){
            sum += currXor;
            return ;
        }

        // solution for one case
        solve(nums, index + 1, currXor^nums[index], sum);
        solve(nums, index + 1, currXor, sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int currXor = 0;
        int sum = 0;
        solve(nums, index, currXor, sum);

        return sum;
    }
};