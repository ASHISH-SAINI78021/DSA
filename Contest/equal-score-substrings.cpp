class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.length();
        vector<int> prefix(n, 0);
        unordered_map<char, int> mp;
        int count = 1;
        for (char ch = 'a'; ch <= 'z'; ch++) mp[ch] = count++;
        prefix[0] = mp[s[0]];
        for (int i = 1; i < n; i++){
            prefix[i] = mp[s[i]] + prefix[i - 1];
        }
        for (int i = 0; i < n - 1; i++){
            if (prefix[i] == prefix[n - 1] - prefix[i]) return true;
        }

        return false;
    }
};©leetcode