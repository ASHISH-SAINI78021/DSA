class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++){
            if (i == 0){
                if (prefix[n - 1] - prefix[i] == 0) return 0;
            }
            else if (i == n - 1){
                if (prefix[i - 1] == 0) return n - 1;
            }
            else if (prefix[i - 1] == prefix[n - 1] - prefix[i]){
                return i;
            }
        }

        return -1;
    }
};