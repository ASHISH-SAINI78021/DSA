class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans  = 0;
        for (int i = 0; i < n; i++){
            int start = i; int end = i;
            while (start >= 0 && end < n && s[start] == s[end]){
                ans++;
                start--; end++;
            }
            start = i; end = i + 1;
            while (start >= 0 && end < n && s[start] == s[end]){
                ans++;
                start--;end++;
            }
        }

        return ans;
    }
};