class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();
        unordered_map<char, char> s_t;
        unordered_map<char, char> t_s;
        if (n != m) return false;

        for (int i = 0; i < n; i++){
            if (s_t.find(s[i]) == s_t.end() && t_s.find(t[i]) == t_s.end()){
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            }
            else {
                if ((s_t.find(s[i]) != s_t.end() && s_t[s[i]] == t[i]) || (t_s.find(t[i]) != t_s.end() && t_s[t[i]] == s[i])) continue ;
                return false;
            }
        }

        return true;
    }
};