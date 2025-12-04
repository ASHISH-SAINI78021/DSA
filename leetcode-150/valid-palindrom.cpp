class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string temp = "";
        for (int i = 0; i < n; i++){
            if (isalnum(s[i])) temp += tolower(s[i]);
        }

        // is palindrome function

        // cout << temp << endl;
        int i = 0; int j = temp.size() - 1;
        while (i <= j){
            if (temp[i] != temp[j]) return false;
            i++;j--;
        }
        
        return true;
    }
};