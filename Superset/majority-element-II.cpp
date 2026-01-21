class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if (n == 1) return nums;

        int candidate1 = -1;
        int count1 = 0;
        int candidate2 = -1;
        int count2 = 0;
        for (int i = 0; i < n; i++){
            if (count1 == 0){
                count1 = 1;
                candidate1 = nums[i];
            }
            else if (candidate1 == nums[i]) count1++;
            else if (count2 == 0){
                count2 = 1;
                candidate2 = nums[i];
            }
            else if (candidate2 == nums[i]) count2++;
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0; count2 = 0;
        int threshold = n/3;
        for (int i = 0; i < n; i++){
            if (candidate1 == nums[i]) count1++;
            else if (candidate2 == nums[i]) count2++;
        }

        if (count1 > threshold) ans.push_back(candidate1);
        if (count2 > threshold) ans.push_back(candidate2);

        return ans;
    }
};


// n/3 n/3 n/3
// 1 2