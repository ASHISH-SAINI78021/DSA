class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int freq[26] = {0};
        int l = 0;
        int r = 0;
        int maxi = 0;
        int maxf = 0;
        while (r < n){
            freq[s[r] - 'A']++;
            maxf = max(maxf, freq[s[r] - 'A']);
            while (r - l + 1 - maxf > k){
                freq[s[l] - 'A']--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};


// s = ABAB
// k = 2

// replacement needed = window length - number of most occurred element