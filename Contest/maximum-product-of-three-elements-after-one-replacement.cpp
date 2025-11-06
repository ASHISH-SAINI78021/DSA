class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[n - 1]; int b = nums[n - 2]; int c = nums[n - 3];
        long long maxi = INT_MIN;
        for (int i = 0; i < 2; i++){
            int sign = (i == 0) ? 1 : -1;
            long long product1 = (long long)a*b*1e5*sign;
            long long product2 = (long long)a*c*1e5*sign;
            long long product3 = (long long)b*c*1e5*sign;

            maxi = max({maxi, product1, product2, product3});
        }

        a = nums[0]; b = nums[1]; c = nums[n - 1];
        for (int i = 0; i < 2; i++){
            int sign = (i == 0) ? 1 : -1;
            long long product1 = (long long)a*b*1e5*sign;
            long long product2 = (long long)a*c*1e5*sign;
            long long product3 = (long long)b*c*1e5*sign;

            maxi = max({maxi, product1, product2, product3});
        }

        return maxi;
    }
};