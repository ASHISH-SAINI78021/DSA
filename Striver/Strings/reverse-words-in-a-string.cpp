class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result = "";
        stack<string> st;

        for (int i = 0; i < n; i++){
            if (s[i] == ' '){
                if (!result.empty()){
                    st.push(result);
                    result.clear();
                }
            }
            else {
                result += s[i];
            }
        }
        if (!result.empty()) st.push(result);
        result = "";
        while (!st.empty()){
            result += st.top();st.pop();
            result += " ";
        }
        result.pop_back();
        return result;
    }
};