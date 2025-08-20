int longestRepeatingSubstring(string &str, int k) {
    int n = str.size();
    int maxf = 0;
    int maxi = 0;
    int freq[26] = {0};
    int l = 0; 
    int r = 0;
    while (r < n){
        freq[str[r] - 'A']++;
        maxf = max(maxf, freq[str[r] - 'A']);
        while (r - l + 1 - maxf > k){
            freq[str[l] - 'A']--;
            l++;
        }

        maxi = max(maxi, r - l + 1);
        r++;
    }

    return maxi;
}