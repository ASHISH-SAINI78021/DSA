class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string ans;
        for (int i = 0; i < n; i++){
            if (isalnum(s[i])){
                ans += tolower(s[i]);
            }
        }

        int i = 0; 
        int j = ans.size() - 1;
        while (i <= j){
            if (ans[i] != ans[j]) return false;
            i++;j--;
        }

        return true;
    }
};