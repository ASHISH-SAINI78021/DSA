class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        int m = t.length();
        if (n != m) return -1;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        int count = 0;
        for (int i = 0; i < m; i++){
            if (mp.find(t[i]) == mp.end()){
                count++;
            }
            else {
                mp[t[i]]--;
                if (mp[t[i]] == 0){
                    mp.erase(t[i]);
                }
            }
        }

        return count;
    }
};