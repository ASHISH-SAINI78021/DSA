class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int maxi = 0;
        while (r < n){
            mp[s[r]]++;
            if (mp.size() == r - l + 1){
                maxi = max(maxi, r - l + 1);
            }
            while (mp.size() < r - l + 1){
                mp[s[l]]--;
                if (mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }

            r++;
        }

        return maxi;
    }
};