class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        if (n == 1 && s[0] == ' ') return 0;
        if (n == 1) return 1;

        int i = n - 1;
        while (s[i] == ' ')i--;
        int count = 0;
        while (i >= 0 && s[i] != ' '){
            count++;
            i--;
        }

        return count;
    }
};