class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<int , int> s_t;
        unordered_map<int , int> t_s;

        for (int i = 0; i < n; i++){
            if (s_t.find(s[i]) != s_t.end()){
                if (s_t[s[i]] != t[i]){
                    return false;
                }
            }
            else {
                s_t[s[i]] = t[i];
            }

            if (t_s.find(t[i]) != t_s.end()){
                if (t_s[t[i]] != s[i]){
                    return false;
                }
            }
            else {
                t_s[t[i]] = s[i];
            }
        }

        return true;
    }
};