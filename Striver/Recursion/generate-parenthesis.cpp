class Solution {
public:
    void solve(int open, int close, string &temp, vector<string> &ans){
        // base case
        if (close == 0 && open == 0){
            ans.push_back(temp);
            return ;
        }
        if (open < 0 || close < 0) return ;

        // solution for one case
        if (open > 0){
            temp.push_back('(');
            solve(open - 1, close, temp, ans);
            temp.pop_back();
        }
        if (close > open){
            temp.push_back(')');
            solve(open, close - 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        string temp;

        solve(open, close, temp, ans);
        return ans;
    }
};