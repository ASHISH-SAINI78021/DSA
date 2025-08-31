class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string result = "";
        int count = 0;

        for (int i = 0; i < n; i++){
            if (s[i] == '('){
                if (count > 0){
                    result.push_back(s[i]);
                }
                count++;
            }
            else {
                count--;
                if (count > 0){
                    result.push_back(s[i]);
                }
            }
        }


        return result;
    }
};