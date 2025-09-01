class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                
                int maxi = INT_MIN;
                int mini = INT_MAX;
                
                
                for (auto &p : mp) {
                    maxi = max(maxi, p.second);
                    mini = min(mini, p.second);
                }
                
                sum += (maxi - mini);
            }
        }
        
        return sum;
    }
};