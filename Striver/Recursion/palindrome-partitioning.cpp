class Solution {
public:
    vector<vector<string>> results;
    bool isPalindrome(string &s, int left, int right){
        while (left <= right){
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
    void solve(string &s, int i, int j, vector<string> &current){
        // base case
        if (i >= j){
            results.push_back(current);
            return ;
        }

        // solution for one case
        for (int end = i; end < j; end++){
            if (isPalindrome(s, i, end)){
                string temp = s.substr(i, end - i + 1);
                current.push_back(temp);
                solve(s, end + 1, j, current);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        int i = 0;
        int j = n;
        vector<string> current;
        solve(s, i, j, current);
        return results;
    }
};