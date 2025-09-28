class Solution {
public:
    bool solve(string &pattern, string temp, string &ans, int index, vector<bool> &used){
        // base case
        if (index >= pattern.size() + 1){
            ans = temp;
            return true;
        }

        // solution for one case
        for (char ch = '1'; ch <= '9'; ch++){
            if (used[ch - '1']) continue;
            if (index > 0 && pattern[index - 1] == 'I' && temp.back() >= ch) continue ;
            if (index > 0 && pattern[index - 1] == 'D' && temp.back() <= ch) continue ;
            used[ch - '1'] = true;
            temp.push_back(ch);
            if (solve(pattern, temp, ans, index + 1, used)) return true;
            used[ch - '1'] = false;
            temp.pop_back();
        }

        return false;
    }
    string smallestNumber(string pattern) {
        string ans;
        int n = pattern.size();
        string temp;
        int index = 0;
        vector<bool> used(9, false);
        solve(pattern, temp, ans, index, used);

        return ans;
    }
};