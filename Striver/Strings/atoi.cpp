class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int sign = 1;
        while (s[i] == ' ') i++;

        if (s[i] == '-'){
            sign = -1;
            i++;
        }
        else if (s[i] == '+'){
            sign = 1;
            i++;
        }
        while (s[i] == '0') i++;
        long long value = 0;
        while (i < n){
            if (!isdigit(s[i])) break ;
            value = value*10 + (s[i] - '0');
            if (value > INT_MAX && sign == 1) return INT_MAX;
            if (value > INT_MAX && sign == -1) return INT_MIN;
            i++;
        }

        return value*sign;
    }
};