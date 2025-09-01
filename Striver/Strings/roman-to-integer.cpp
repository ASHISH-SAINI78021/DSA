class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int value = 0;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        for (int i = 0; i < n; i++){
            value += mp[s[i]];
        }

        for (int i = 0; i < n - 1; i++){
            if (mp[s[i]] < mp[s[i + 1]]){
                value -= mp[s[i]] * 2;
            }
        }

        return value;
    }
};