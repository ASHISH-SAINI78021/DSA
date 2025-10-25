class Solution {
public:
    bool isPrime(int n){
        if (n <= 1) return false;
        if (n == 2 && n == 3) return true;

        for (int i = 2; i <= sqrt(n); i++){
            if (n % i == 0) return false;
        }

        return true;
    }
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long sumA = 0;
        long long sumB = 0;
        
        for (int i = 0; i < n; i++){
            if (isPrime(i)) sumA += nums[i];
            else sumB += nums[i];
        }

        return abs(sumA - sumB);
    }
};