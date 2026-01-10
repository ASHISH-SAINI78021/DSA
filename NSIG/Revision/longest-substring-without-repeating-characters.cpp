class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0; 
        int r = 0;
        unordered_map<char, int> mp;
        int maxi = 0;

        while (r < n){
            char ch = s[r];
            mp[ch]++;
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