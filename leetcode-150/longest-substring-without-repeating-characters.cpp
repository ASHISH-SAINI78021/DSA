class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        if (n == 1) return 1;
        unordered_map<char,int> mp;
        int l = 0;
        int r = 0;
        int maxi = 0;
        while (r < n){
            mp[s[r]]++;
            while (mp.size() < r - l + 1){
                mp[s[l]]--;
                if (mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};