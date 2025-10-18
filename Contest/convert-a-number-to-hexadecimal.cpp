class Solution {
public:
    string toHex(int n) {
        if (n == 0) return "0";
        string digits = "0123456789abcdef";
        unsigned int num = n;
        cout << num << endl;
        string ans = "";
        while (num > 0){
            int index = num & 15;
            ans += digits[index];
            num = num >> 4;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};