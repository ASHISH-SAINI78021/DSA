class Solution {
public:
    void solve(string s, int len, int prev, vector<string> &ans){
        // base case 
        if (len == 0){
            ans.push_back(s);
            return ;
        }

        // solution for one case
        if (prev == -1 || prev == 1){
            solve(s + '0', len - 1, 0, ans);
        }
        solve(s + '1', len - 1, 1, ans);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        int prev = -1;
        string temp;
        solve(temp, n, prev, ans);

        return ans;
    }
};