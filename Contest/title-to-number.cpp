class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int k = 0;
        int ans = 0;
        int count = 1;
        unordered_map<char, int> mp;
        for (char ch = 'A'; ch <= 'Z'; ch++) mp[ch] = count++;
        for (int i = n - 1; i >= 0; i--){
            ans += pow(26, k++)*mp[s[i]];
        }

        return ans;
    }
};