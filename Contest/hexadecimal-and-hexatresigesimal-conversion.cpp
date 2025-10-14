class Solution {
public:
    string solve(long long n, int base){
        string result = "";
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        while (n > 0){
            int rem = n % base;
            result += digits[rem];
            n = n/base;
        }

        reverse(result.begin(), result.end());
        return result;
    }
    string concatHex36(int k) {
        long long n = k;
        long long square = n*n;
        long long cube = n*n*n;

        string ans1 = solve(square, 16);
        string ans2 = solve(cube, 36);

        return ans1 + ans2;
    }
};