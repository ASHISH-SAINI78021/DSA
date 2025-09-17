class Solution {
public:
    string decimalToBinary(int num){
        string s = "";
        if (num == 0) return "0";
        while (num > 0){
            s = char('0' + num % 2) + s;
            num = num / 2;
        }

        return s;
    }
    bool isPalindrome(string &s){
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (i <= j){
            if (s[i] != s[j]) return false;
        }

        return true;
    }
    bool isStrictlyPalindromic(int n) {
        string s = decimalToBinary(n);
        return isPalindrome(s);
    }
};