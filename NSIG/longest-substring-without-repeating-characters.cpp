class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        int r = 0;
        int maxi = 0;
        unordered_map<char, int> mp;

        while (r < n){
            mp[s[r]]++;
            while (mp.size() < r - l + 1){
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};


// s = abcabcbb -> longest substring without repeating character.
// Brute force
// all the strings -> check one by one -> longest substring -> using map I can check

// T.C -> O(n*n) -> O(n*n*n)
// S.C -> O(n)


// Better / Optimal one
// start = 0
// right -> by 1 in every iteration
// abc -> 3 mp.size() > r - l + 1 -> there would be a repeating character.
// b -> 3 abc

// T.C -> O(n)
// S.C -> O(n) assuming distinct characters in worst case