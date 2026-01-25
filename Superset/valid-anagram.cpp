class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m) return false;

        int freq[26] = {0};
        for (int i = 0; i < n; i++) freq[s[i] - 'a']++;
        for (int i = 0; i < n; i++){
            freq[t[i] - 'a']--;
            if (freq[t[i] - 'a'] < 0) return false;
        }

        return true;
    }
};