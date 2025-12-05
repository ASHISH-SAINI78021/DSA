class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m) return false;

        unordered_map<char, int> mp;
        for (auto it : s) mp[it]++;

        for (int i = 0; i < n; i++){
            if (mp.find(t[i]) == mp.end()) return false;
            mp[t[i]]--;
            if (mp[t[i]] == 0) mp.erase(t[i]);
        }

        return true;
    }
};