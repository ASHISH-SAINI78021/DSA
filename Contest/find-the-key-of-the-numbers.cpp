class Solution {
public:
    string solve(int num){
        string temp = "";
        while (num > 0){
            int rem = num % 10;
            temp += (rem + '0');
            num = num/10;
        }
        reverse(temp.begin(), temp.end());
        if (temp.length() != 4){
            int requiredZeroes = 4 - temp.length();
            temp = string(requiredZeroes, '0') + temp;
        }

        return temp;
    }
    int generateKey(int num1, int num2, int num3) {
        string a; string b; string c;
        a = solve(num1); b = solve(num2); c = solve(num3);
        int ans = 0;
        for (int i = 0; i < 4; i++){
            int x = (a[i] - '0'); int y = (b[i] - '0'); int z = (c[i] - '0');
            int minValue = min({x, y, z});
            ans = ans*10 + minValue;
        }

        return ans;
    }
};©leetcode