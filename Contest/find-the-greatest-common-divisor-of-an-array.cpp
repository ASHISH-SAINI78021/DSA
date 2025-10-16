class Solution {
public:
    int gcd(int a, int b){
        while (b){
            a = a % b;
            swap(a, b);
        }

        return a;
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        return gcd(maxi, mini);
    }
};