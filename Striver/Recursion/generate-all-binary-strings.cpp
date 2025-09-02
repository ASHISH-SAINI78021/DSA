// User function Template for C++

class Solution {
  public:
    void solve(int size, int prev, string temp, vector<string> &ans){
        // base case
        if (size == 0){
            ans.push_back(temp);
            return ;
        }
        
        // solution for one case
        solve(size - 1, 0, temp + '0', ans);
        if (prev == -1 || prev != 1){
            solve(size - 1, 1, temp + '1', ans);
        }
    }
    vector<string> generateBinaryStrings(int num) {
        vector<string> ans;
        int prev = -1;
        string temp = "";
        
        solve(num, prev, temp, ans);
        
        return ans;
    }
};