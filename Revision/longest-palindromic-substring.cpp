class Solution {
public:
    string longestPalindrome(string s) {
        string ans = s;
        int n = s.length();
        if (n == 0 || n == 1) return ans;
        int maxi = 0;

        for (int i = 0; i < n; i++){
            int start = i;
            int end = i;
            while (start >= 0 && end < n && s[start] == s[end]){
                if (maxi < end - start + 1){
                    maxi = end - start + 1;
                    ans = "";
                    for (int j = start; j <= end; j++){
                        ans += s[j];
                    }
                }
                start--;
                end++;
            }
            start = i;
            end = i + 1;
            while (start >= 0 && end < n && s[start] == s[end]){
                if (maxi < end - start + 1){
                    maxi = end - start + 1;
                    ans = "";
                    for (int j = start; j <= end; j++){
                        ans += s[j];
                    }
                }
                start--;
                end++;
            }
        }

        return ans;
    }
};