class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](auto &a, auto &b){
            if (a.size() != b.size()){
                return a.size() > b.size();
            }
            return a > b;
        });
        // int n = nums.size();
        // for (int i = 0; i < n; i++){
        //     cout << nums[i] << " ";
        // }
        return nums[k - 1];
    }
};