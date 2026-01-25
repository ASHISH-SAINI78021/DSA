class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        if (n == 1) return s;
        string ans;
        unordered_map<int, int> mp;
        multimap<int, int> ml;
        for (int i = 0; i < n; i++) mp[s[i]]++;
        for (auto it : mp) ml.insert({it.second, it.first});
        for (auto it : ml){
            ans += string(it.first, it.second);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// k1 v1
// k2 v2
// k3 v1

// v1 > v2

// v1 k3
// v1 k1
// v2 k2

// k1 v1
// v1 k1