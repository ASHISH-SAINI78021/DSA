class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        multimap<int, char> mm;

        for (int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        for (auto it : mp){
            mm.insert({it.second, it.first});
        }
        string ans = "";
        for (auto it : mm){
            ans += string(it.first, it.second);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};