class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string ans = "";
        int count = 0;

        for (int i = 0; i < n; i++){
            if (s[i] == '('){
                if (count > 0){
                    ans.push_back(s[i]);
                }
                count++;
            }
            else {
                count--;
                if (count > 0) ans.push_back(s[i]);
            }
        }

        return ans;
    }
};


// count = 0
// s = (()())(())
// count = 1
// ans = ()()()