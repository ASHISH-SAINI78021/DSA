class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(); int m = t.length();
        int k = 0;
        for (int i = 0; i < m; i++){
            if (s[k] == t[i]) k++;
            if (k == n) return true;
        }

        if (k == n) return true;
        return false;
    }
};