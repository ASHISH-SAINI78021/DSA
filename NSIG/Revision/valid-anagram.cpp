class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if (n != t.length()) return false;
        int freq[26] = {0};
        for (char ch : s) freq[ch - 'a']++;

        for (int i = 0; i < n; i++){
            freq[t[i] - 'a']--;
            if (freq[t[i] - 'a'] < 0) return false;
        }
        
        return true;
    }
};