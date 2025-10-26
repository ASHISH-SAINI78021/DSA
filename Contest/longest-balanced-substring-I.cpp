class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxi = 0;
        for (int i = 0; i < n; i++){
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++){
                mp[s[j]]++;
                if (mp.empty()) continue;
                int check = true;
                int t = mp.begin()->second;
                for (auto it : mp){
                    if (t != it.second){
                        check = false; break;
                    }
                }

                if (check){
                    maxi = max(maxi, j - i + 1);
                }
            }
        }

        return maxi;
    }
};