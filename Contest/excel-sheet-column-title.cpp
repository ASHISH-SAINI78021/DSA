class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        unordered_map<int, char> mp;
        int count = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) mp[count++] = ch;
        while (n > 0){
            int rem = (n - 1) % 26;
            ans.push_back(mp[rem]);
            n--;
            n = n / 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};